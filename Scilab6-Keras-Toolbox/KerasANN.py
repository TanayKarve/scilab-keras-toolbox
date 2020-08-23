import numpy as np
import pandas
from keras.models import Sequential,load_model
from keras.layers import Dense
from keras.wrappers.scikit_learn import KerasClassifier
from keras.utils import np_utils
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import KFold
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.metrics import confusion_matrix
import pickle
import copy
import os
import sys
import datetime


MODEL_DIR="models/"

sys.stdout = open('.keras-status.log','w')

class Session():
    def __init__(self,classes,history,matrix):
        self.classes=classes
        self.accuracy=history.history['accuracy']
        self.loss=history.history['loss']
        self.matrix=matrix
    def plotConfusionMatrix(self):
        plot_confusion_matrix(self.matrix,self.classes)
    def plotAccuracy(self):
        plt.plot(self.accuracy)
        plt.scatter([i for i in range(len(self.accuracy))],self.accuracy)
        plt.title('model accuracy')
        plt.ylabel('accuracy')
        plt.xlabel('epoch')
        plt.legend(['train'], loc='upper left')
        plt.savefig("plots/AccuracyPlot.png")
        plt.clf()
    def plotLoss(self):
        plt.plot(self.loss)
        plt.scatter([i for i in range(len(self.loss))],self.loss)
        plt.title('model loss')
        plt.ylabel('loss')
        plt.xlabel('epoch')
        plt.legend(['train'], loc='upper left')
        plt.savefig("plots/LossPlot.png")
        plt.clf()
    def save(self,filename="session.dat"):
        if ".session" not in os.listdir():
            os.mkdir(".session")
        with open(".session/"+filename,"wb") as f:
            pickle.dump(self,f)
        
# load dataset
class DLModel():

    def __init__(self,estimator=None,classes=None):
        self.estimator = estimator
        self.classes = classes
    
    estimator=None
    classes=None

def layerParse(layers="3,5,6,4"):
    
    layers = layers.split(",")
    if '' in layers:
        print("Error in layer format")
        return None
    
    return layers


def ANN_test(toPredict,modelFile):
    
    with open(modelFile,'rb') as f:
        model = pickle.load(f)
    result = model.estimator.predict_classes(np.array([toPredict]))
    
    return str.encode(model.classes[result[0]])
    
    
    
    
        

def ANN(fileName,layers,label,nEpochs,nBatchSize):
    print("in ANN")
    print(nEpochs,nBatchSize)
    def baseline_model(layers,nClasses):
        # create model
        if nClasses>2:
            mode = "categorical_crossentropy"
        else:
            mode = "binary_crossentropy"
            
        layers = [int(i) for i in layers]
        model = Sequential()
        model.add(Dense(layers[0], input_dim=layers[0], activation='relu'))
        for i in range(1,len(layers)-1):
            model.add(Dense(layers[i], activation='relu'))
        model.add(Dense(layers[-1],activation='softmax'))
        # Compile model
        model.compile(loss=mode, optimizer='adam', metrics=['accuracy'])
        return model
        
    dataframe = pandas.read_csv(fileName.decode())
    dataframe = dataframe.sample(frac=1)
    xLen = len(dataframe.columns) -1
    
    Y = dataframe[label.decode()].values
    
    layers = layerParse(layers.decode())
    layers.insert(0,xLen)
    layers.append(len(np.unique(Y)))
    
    model = DLModel()
    
    
    dataset = dataframe.values
    
    X = dataset[:,:-1].astype(float)
    # encode class values as integers
    encoder = LabelEncoder()
    encoder.fit(Y)
    model.classes = encoder.classes_
    
    encoded_Y = encoder.transform(Y)
    
    # convert integers to dummy variables (i.e. one hot encoded)
    dummy_y = np_utils.to_categorical(encoded_Y)
    X_train, X_test, y_train, y_test = train_test_split(X, dummy_y, test_size=0.3)
    # define baseline model
    model.estimator = baseline_model(layers,len(model.classes))

    os.system("./status.sh")

    history=model.estimator.fit(X_train,y_train,epochs=nEpochs,validation_split=0.2,batch_size=nBatchSize)
    
    time = str(datetime.datetime.now())
    time = time.replace(" ","")
    #estimator.save("neural_network"+time+".h5")
    
    with open(MODEL_DIR+"neural_network"+time+".ml",'wb') as pkl:
        pickle.dump(model,pkl)
    
    print(model.estimator.evaluate(X_test,y_test))
    y_pred = model.estimator.predict(X_test)
    
    y_pred=np.argmax(y_pred, axis=1)
    y_test=np.argmax(y_test,axis=1)
    
    cfMat = confusion_matrix(y_test,  y_pred)
    session = Session(model.classes,history,cfMat)
    session.save()
    print("Session saved")
    open(".keras-status.log","w").write("Training done, you may now close this terminal")
    print("Model saved as: neural_network"+time+".ml in "+MODEL_DIR+" folder")
    return (history.history['accuracy'][-1])

if __name__ == "__main__":
    file = sys.argv[1]#input("Enter csv file path for training:")
    col = sys.argv[2]#input("Enter label column:")
    file = file.encode('utf-8')
    col=col.encode('utf-8')
    layers=sys.argv[3].encode('utf-8')
    accuracy=ANN(file,b"3,5,6,4",col,int(sys.argv[4]),int(sys.argv[5]))
    #print(ANN_test([6.5,3.0,5.2,2.0],input()))
