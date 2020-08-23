The example1 directory contains code for developing neural networks, and training them on a dataset.
The script ANN_tests.sce is a scilab script which walks through the functions ANN_train and ANN_test_sample of the keras library.

*Make sure the script keras_definitions.sce has been executed before proceeding below.

To test it in scilab:

	run:
		exec examples/example1/ANN_tests.sce

	*Note it is important that the examples are run from the Scilab6-Keras-Toolbox directory only.

	Upon executing this script the function ANN_train will be called, followed by ANN_test_sample.

	Firstly a dialog box will open which will ask you to 
	choose the '.csv' file containing the dataset.
	The dataset must have headers and a label column.
	When the dialog box appears, select this "iris.csv" file for the dataset.
	Next, an input will be requested on the scilab console asking you to input the name
	of the the column in the dataset which is to be predicted.
	When the input is requested on the scilab console, enter "name".

	After training is completed, the ANN_test_sample function will be called with a test sample from the dataset.
	A dialog box will appear requesting you to select a model file which was saved to disk during the execution of ANN_train.
	The model files are saved inside the 'models' folder
	It is of the format 'neural_network###.ml'.
	Finally, it will guess the class name and output it to the console.

The example2 directory contains code for developing a transfer learning based image recognition model, and training it on an image dataset.
The script image_rec_test.sce is a scilab script which walks through the functions image_model and image_model_test of the keras library.
To test it in scilab:
	
	run:
		exec examples/example1/image_rec_tests.sce

	*Note it is important that the examples are run from the Scilab6-Keras-Toolbox directory only.

	Upon executing this script the function image_model will be called, followed by image_model_test
	
	Firstly, a dialog box will open which will ask you to choose an image directory. 
	Choose the 'alphabets' folder provided in the zip file submission.
	
	After training is completed, the image_model_test function will be called.
	A dialog box will appear requesting you to select a model file which was saved to disk during the execution of image_model.
	The model files are saved inside the 'models' folder
	It is of the format 'image_model###.ml'.
	A dialog box will open which will ask you to select an image for testing.
	Choose any image from the A, B or C folders in the 'alphabet' directory.
	You may even test it on one of your own images.

The example3 directory contains code for plotting performance diagrams.
The script train_plots.sce os a scilab script used for getting all the 3 plots after training.
To test it in scilab:
	run:
		exec examples/example1/train_plots.sce
		
	*Note it is important that the examples are run from the Scilab6-Keras-Toolbox directory only.
	
	Upon executing this script the function ANN_train will be called, followed by the plotting functions.

	Firstly a dialog box will open which will ask you to 
	choose the '.csv' file containing the dataset.
	The dataset must have headers and a label column.
	When the dialog box appears, select this "iris.csv" file for the dataset.
	Next, an input will be requested on the scilab console asking you to input the name
	of the the column in the dataset which is to be predicted.
	When the input is requested on the scilab console, enter "name".

	Then you will see 3 plots of accuracy, error and confusion matrix.
