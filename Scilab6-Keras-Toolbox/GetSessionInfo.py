import matplotlib.pyplot as plt
import numpy as np
import itertools
import pickle
import sys

def plot_confusion_matrix(cm,
                          target_names,
                          title='Confusion matrix',
                          normalize=True):
   
    

    accuracy = np.trace(cm) / float(np.sum(cm))
    misclass = 1 - accuracy

    
    cmap = plt.get_cmap('Blues')

    plt.figure(figsize=(8, 6))
    plt.imshow(cm, interpolation='nearest', cmap=cmap)
    plt.title(title)
    plt.colorbar()

    if target_names is not None:
        tick_marks = np.arange(len(target_names))
        plt.xticks(tick_marks, target_names, rotation=45)
        plt.yticks(tick_marks, target_names)

    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]


    thresh = cm.max() / 1.5 if normalize else cm.max() / 2
    for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
        if normalize:
            plt.text(j, i, "{:0.4f}".format(cm[i, j]),
                     horizontalalignment="center",
                     color="white" if cm[i, j] > thresh else "black")
        else:
            plt.text(j, i, "{:,}".format(cm[i, j]),
                     horizontalalignment="center",
                     color="white" if cm[i, j] > thresh else "black")


    plt.tight_layout()
    plt.ylabel('True label')
    plt.xlabel('Predicted label\naccuracy={:0.4f}; misclass={:0.4f}'.format(accuracy, misclass))
    plt.savefig("plots/ConfusionMatrixPlot.png")
    plt.clf()
    

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
        plt.title('model accuracy')
        plt.ylabel('accuracy')
        plt.xlabel('epoch')
        plt.legend(['train'], loc='upper left')
        plt.savefig("plots/AccuracyPlot.png")
        plt.clf()
    def plotLoss(self):
        plt.plot(self.loss)
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
     
        

def getSessionInfo():
	try:
	    	with open(".session/session.dat","rb") as f:    
    	   		session = pickle.load(f)
    		return session
	except:
		return None
		
def main(plotType):
	session = getSessionInfo()
	if session is None:
		return "Please complete training first."
	
	if(plotType=="cmat"):
		session.plotConfusionMatrix()
		return "Confusion matrix saved in plots/"
	elif plotType == "loss":
		session.plotLoss()
		return "Loss plot saved in plots/"
	elif plotType == "accuracy":
		session.plotAccuracy()
		return "Accuracy plot saved in plots/"
	else:
		return "Unknown plot"

print(main(sys.argv[1]))
