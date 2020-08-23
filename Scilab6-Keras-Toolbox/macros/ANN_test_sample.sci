
function [y]=ANN_test_sample()
    //   This function is used to test the trained neural network.
	//   It returns the label which it has guessed according to the provided test sample.
    //
    //   Syntax
    //   y = ANN_test(in1);
    //
    //   Parameters
    //   y : class guessed by the neural network
    //   in1 : test sample values (excluding the label column.)
    //
    //   Description
    //   Upon calling this function, a dialog box will open which will ask you to choose the model file
	//   which has been saved to disk after training completion by ANN_train(). 
	//   The model files are saved inside the 'models' folder
	//   It is of the format 'neural_network ###.ml'.
    //
    //
    // Examples
    // //Testing the neural network for input values sample to guess class name
    // y = ANN_test_sample(test_sample=[5.4,3.4,1.5,0.4]);
    //
//Authors
//Tanay Karve
endfunction
