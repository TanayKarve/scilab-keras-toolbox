
function [y]=ANN_train()
    //   This function is used to train the neural network on a dataset.
    //   It returns the training accuracy.
    //
    //   Syntax
    //   y = ANN_train(in1,in2,in3);
    //
    //   Parameters
    //   y : training accuracy
    //   in1 : hidden layers, the architecture of the neural network which must contain a string of comma-separated numbers of hidden layers.
    //   in2 : Total training epochs for the neural network.
    //   in3 : Batch size
    //
    //   Description
    //   Upon calling this function, a dialog box will open which will ask you to 
	//   choose the '.csv' file containing the dataset.
	//   The dataset must have headers and a label column.
	//   An input will be requested on the scilab console asking you to input the name
	//   of the the column in the dataset which is to be predicted.
	//   When the dialog box appears, select this "iris.csv" file for the dataset.
	//   When the input is requested on the scilab console, enter "name".
    //
    //
    // Examples
    // //Training a neural network with first hidden layer containing 5 neurons and second containing 6 neurons, with 20 epochs having batch size as 1
    // y = ANN_train(layers="5,6",epochs=20,batchsize=1);
    //
//Authors
//Tanay Karve
endfunction
