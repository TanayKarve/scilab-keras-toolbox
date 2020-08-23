
function [y]=image_model_test()
    //   This function is used to test the trained image recognition model.
	//   It returns the label which it has guessed according to the provided test image.
    //
    //   Syntax
    //   y = image_model_test();
    //
    //   Parameters
    //   y : class guessed by the image recognition model
    //
    //   Description
    //   Upon calling this function, a dialog box will open which will ask you to choose the model file
	//   which has been saved to disk after training completion by image_model (). 
	//   The model files are saved inside the 'models' folder
	//   It is of the format 'image_model ###.ml'.
    //   Another dialog box will open asking you to select an image to test the image recognition model with.
    //   An image having an extension png,jpg or jpeg must be selected.
    //
    // Examples
    // //Testing the image recognition model for input image to guess class name
    // y = image_model_test()
    //
//Authors
//Tanay Karve
endfunction
