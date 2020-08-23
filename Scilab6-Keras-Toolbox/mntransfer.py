#!/usr/bin/env python

# -*- coding: utf-8 -*-
#@Maintainer: Tanay Karve

import os
import sys
import glob
import argparse
import pickle
import datetime
from keras import backend as K
from keras import __version__
from keras.applications.mobilenet_v2 import MobileNetV2, preprocess_input
from keras.models import Model
from keras.layers import Dense, AveragePooling2D, GlobalAveragePooling2D, Input, Flatten, Dropout
from keras.preprocessing.image import ImageDataGenerator
from keras.optimizers import SGD

MODEL_DIR = "models/"
if __name__!="__main__":
	sys.stdout = open('.keras-status.log','w')

sys.stdout.write("Initializing training...\n")
class TransferLearn():
	def __init__(self,model):
		self.model=model
		self.classes=None

IM_WIDTH, IM_HEIGHT = 224, 224 #fixed size for MOBILE NET
NB_EPOCHS = 3
BAT_SIZE = 32
FC_SIZE = 1024



def get_nb_files(directory):
    """Get number of files by searching directory recursively"""
    if not os.path.exists(directory):
        return 0
    cnt = 0
    for r, dirs, files in os.walk(directory):
        for dr in dirs:
            cnt += len(glob.glob(os.path.join(r, dr + "/*")))
    return cnt


def setup_to_transfer_learn(model, base_model):
    """Freeze all layers and compile the model"""
    for layer in base_model.layers:
        layer.trainable = False
    model.compile(optimizer='adam',
                  loss='categorical_crossentropy',
                  metrics=['accuracy'])


def add_new_last_layer(base_model, nb_classes):
    """Add last layer to the convnet
    
    Args:
        base_model: keras model excluding top
        nb_classes: # of classes
        
    Returns:
        new keras model with last layer
    """
    x = base_model.output
    x = GlobalAveragePooling2D()(x)
    x = Dense(1024,activation='relu')(x)
    x = Dense(512,activation='relu')(x)
    activation='softmax'
   
    	
    predictions = Dense(nb_classes, activation=activation)(x)
    model = Model(inputs=base_model.input, outputs=predictions)
    return model
    

def train(train_img,nb_epoch):
    """Use transfer learning and fine-tuning to train a network on a new dataset"""
    
    train_img=train_img.decode()
    nb_epoch = int(nb_epoch)
    nb_train_samples = get_nb_files(train_img)
    nb_classes = len(glob.glob(train_img + "/*"))
    
    # data prep
    train_datagen = ImageDataGenerator(
        width_shift_range=0.2,
        height_shift_range=0.2,
        rescale=1./255,
        shear_range=0.2,
        zoom_range=0.2,
        horizontal_flip=True,
        fill_mode='nearest')
        
    
    train_generator = train_datagen.flow_from_directory(
			train_img,
			target_size=(224, 224),
			class_mode='categorical'
		)
    
    
    input_tensor = Input(shape=(224, 224, 3))
    
    # setup model
    
    base_model = pickle.load(open("assets/mnet.pkl","rb"))
    model = add_new_last_layer(base_model, nb_classes)
   
    # transfer learning
    setup_to_transfer_learn(model, base_model)
    
    estimator = TransferLearn(model)
    estimator.classes= dict([(value, key) for key, value in train_generator.class_indices.items()])
    
    os.system("./status.sh")
    
    history_tl = estimator.model.fit_generator(train_generator,
                                   steps_per_epoch=10,
                                   epochs=nb_epoch) 
                                   
    
    currTime = str(datetime.datetime.now()).replace(" ", "")
    modelFile = MODEL_DIR+"image_model"+currTime+".ml"
    with open(modelFile,"wb") as f:
    	pickle.dump(estimator,f)
    print("image model saved to "+modelFile)
    
    open(".keras-status.log","w").write("Training done, you may now close this terminal")
    print(history_tl.history['accuracy'][-1])
    return history_tl.history['accuracy'][-1]
 
  





if __name__=="__main__":
    imagedir = input("Enter directory path for training:")
    imagedir=imagedir.encode('utf-8')
    epochs = int(input("Enter number of epochs") )
    train(imagedir,epochs)
