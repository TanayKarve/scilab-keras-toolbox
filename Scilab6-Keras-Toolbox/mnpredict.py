#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import sys
import pickle
import argparse
import numpy as np
from PIL import Image
from io import BytesIO
from keras.preprocessing import image
from keras.models import load_model
from keras.applications.inception_v3 import preprocess_input
from mntransfer import TransferLearn

target_size = (224, 224) 



def predict(img,model_file):
    print("NEW")
    model_file=model_file.decode()
    img=img.decode()
    with open(model_file,"rb") as f:
    	estimator = pickle.load(f)
    pred =  _predict(estimator,img)
    print(pred)
    return pred.encode('utf-8')

def _predict(estimator, img):
    target_size = (224, 224)
    """Run model prediction on image
    Args:
        model: keras model
        img: PIL format image
        target_size: (w,h) tuple
    Returns:
        list of predicted labels and their probabilities 
    """
    img = Image.open(img)
    if img.mode != "RGB":
    	img=img.convert("RGB")
    	
    if img.size != target_size:
        img = img.resize(target_size)

    x = image.img_to_array(img)	
    x = x/255
    x = np.expand_dims(x, axis=0)
    preds = estimator.model.predict(x)
    print(estimator.classes)
    print(preds)
    print(estimator.classes[preds[0].argmax(axis=-1)])
    return estimator.classes[preds[0].argmax(axis=-1)]



if __name__=="__main__":
    s=input(":>>")
    s=s.encode('utf-8')
    pred=predict(b"/home/osboxes/tests/animals/dogs/dog.3372.jpg",s)
    
    print(pred)
