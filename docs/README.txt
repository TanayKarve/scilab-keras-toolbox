This is the post presentation submission for STH.

The functions ANN_train, ANN_test_sample,  image_model() and image_model_test() called in scilab.

**Version 1.1:
	New additions:
		Demo video:  https://youtu.be/LXIa_y5pnmw
		
		functions:
		
		plotTrainingAccuracy()
		plotTrainingLoss()
		plotConfusionMatrix()

**Please check the youtube video for an in-depth tutorial of the toolbox:**
https://youtu.be/0fRcLE1uolM

To install the necessary modules:

run:
	source install.sh
	
To install the toolbox:

Navigate to the Scilab6-Keras-Toolbox directory from scilab.
To build the toolbox:
	run:
		exec builder.sce

To load the toolbox:
	run:
		exec loader.sce
		exec keras_definitions.sce


NOTE: It is necessary to run install.sh before starting scilab. Else, the toolbox may not work.

The script keras_tests.sce is a scilab script which walks through the functions ANN_train and ANN_test_sample of the keras library.
To test it in scilab:


The functions ANN_train and ANN_test_sample can be used as follows:

ANN_train:
	This function is used to train the neural network on a set of values;
	It returns the training accuracy of the neural network.
	
	syntax:
	
		ANN_train(layers=<HIDDEN_LAYERS>,epochs=<NO_OF_EPOCHS>,batchsize=<BATCH_SIZE>);
		
	where:
		
		HIDDEN_LAYERS: the architecture of the neural network which must 
				contain a string of comma-separated numbers of hidden layers.
		NO_OF_EPOCHS: Total training epochs for the neural network.
		BATCH_SIZE: Batch size for training.
		
	Upon calling this function, a dialog box will open which will ask you to 
	choose the '.csv' file containing the dataset.
	The dataset must have headers and a label column.
	An input will be requested on the scilab console asking you to input the name
	of the the column in the dataset which is to be predicted.
	When the dialog box appears, select this "iris.csv" file for the dataset.
	When the input is requested on the scilab console, enter "name".
	
	example:
		ANN_train(layers="5,6",epochs=20,batchsize=1);		
	
		
	
ANN_test_sample:
	This function is used to test the trained neural network.
	It returns the label which it has guessed according to the provided test sample.
	
	syntax:
		ANN_test_sample(test_sample=<ARRAY_OF_SAMPLE_VALUES>);
	
	where:
		ARRAY_OF_SAMPLE_VALUES: test sample from the dataset (excluding the label column.)
		
	example:
		ANN_test_sample(test_sample=[5.4,3.4,1.5,0.4]);
		
	Upon calling this function, a dialog box will open which will ask you to choose the model file
	which has been saved to disk after training completion by ANN_train(). 
	The model files are saved inside the 'models' folder
	It is of the format 'neural_network ###.ml'.
	e.g. "neural_network2020-06-1506:36:57.078316.ml"
	
plotTrainingAccuracy():
	This function is used to create a line diagram for the training accuracy of the model.
	This plot gives information about how the model learned the data over time.
	
	example:
		plotTrainingAccuracy()
	
	This diagram is saved as a png file in the 'plots' folder.
	
plotTrainingLoss():
	This function is used to create a line diagram for the training loss of the model.
	This plot gives information about how the model's error decreased over time.
	
	
	example:
		plotTrainingLoss()
	
	This diagram is saved as a png file in the 'plots' folder.
	
plotConfusionMatrix():
	This function is used to create a confusion matrix diagram of the model's performance.
	It evaluates the model on unseen data and shows how the model gets confused with different classes.
	
	example:
		plotConfusionMatrix()
	
	This diagram is saved as a png file in the 'plots' folder.
	
	
image_model:
	This function is used to develop a transfer-learning image recognition model.
	It returns the training accuracy of the model.
	
	syntax:
		image_model(<NO_OF_EPOCHS>)
	
	where:
		NO_OF_EPOCHS: Total training epochs for the image recognition model.
	
	example:
		image_model(10)
	
	Upon calling this function, a dialog box will open which will ask you to choose a directory containing 
	image files used to train the model. The structure of the training directory must be as follows:
	
	example:
		    pets/
       		 	dogs/
            			dog001.jpg
            			dog002.jpg
         			 ...
        		 cats/
            			cat001.jpg
            			cat002.jpg
            			...
	where dogs and cats are the names of your image.
	Both class names and image names they must be unique.
	
	So if such a directory structure is present, the folder "pets" must be selected.
	Supported image formats are jpg, jpeg and png.
	The folder 'alphabets' is provided with this zip, containing image dataset of A, B and C letters.
	Alternatively the folder 'alphabets' is also provided , containing image dataset of cats and dogs.
	Select any of these folders when asked for image directory by the dialog boox.

image_model_test:
	This function is used to test the trained image recognition model.
	It returns the label which it has guessed according to the provided test image.
	
	syntax:
		image_model_test()
	
	Upon calling this function, a dialog box will open which will ask you to choose the model file
	which has been saved to disk after training completion by image_model(). 
	The model files are saved inside the 'models' folder
	It is of the format 'image_model###.ml'.
	e.g. "image_model2020-06-2205:39:49.639904.ml"
	Another dialog box will open asking you to select an image to test the image recognition model with.
	An image having an extension png,jpg or jpeg must be selected.
	


The 'iris.csv' file is a dataset of the dimensions of different species of the iris flow which is provided as an example for neural networks.
The 'alphabets' folder is a dataset of images of the letters A, B and C, which is provided as an example of image recognition using transfer learning.
The 'pets' folder is a dataset of images of cats and dogs which is also provided as an example of image recognition using transfer learning.
The KerasANN.py, mntransfer.py and mnpredict.py are python scripts which provide interface to the keras library so that their usage is simplified in C.

Directory structure:
The 'examples' directory contains sample scripts to run examples
The 'models' directory contains saved models after training ANN
The 'plots' directory contains diagrams of the models performance obtained after calling any of the plot functions
The 'assets' directory contains an essential file for image_model to run
The 'src' directory contains C source files requires to interface the sci_gateway to python
The thirdparty/linux/include/c_transfer.h is the header file for the C gateway
The thirdparty/linux/lib/x64/libscikeras.so is the shared object file for the C gateway

Please call me on 9284113194 or email at tanaykarve@gmail.com for any questions.
