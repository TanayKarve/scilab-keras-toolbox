
function [y]=image_model()
    //   This function is used to develop a transfer-learning image recognition model.
	//   It returns the training accuracy of the model.
    //
    //   Syntax
    //   y = image_model(in1);
    //
    //   Parameters
    //   y : training accuracy of the model
    //   in1 : Number of epochs
    //
    //   Description
    //   Upon calling this function, a dialog box will open which will ask you to choose a directory containing 
	//   image files used to train the model. The image directory structure should by as follows.
    //
	//   example:
	//
    //     pets/
    //
    //    &#160;&#160;dogs/
    //
    //    &#160;&#160;&#160;&#160;dog001.jpg
    //
    //    &#160;&#160;&#160;&#160;dog002.jpg
    //
    //    &#160;&#160;&#160;&#160;...
    //
    //    &#160;&#160;cats/
    //
    //    &#160;&#160;&#160;&#160;cat001.jpg
    //
    //    &#160;&#160;&#160;&#160;cat002.jpg
    //
	//   
    //   where dogs and cats are the names of your image.
	//   Both class names and image names must be unique.
    //   So if such a directory structure is present, the folder "pets" must be selected.
	//   Supported image formats are jpg, jpeg and png.
	//   The folder 'alphabets' is provided with this zip, containing image dataset of A, B and C letters.
	//   Select this folder when asked for image directory by the dialog boox.
    //
    // Examples
    // //Testing the neural network for input values sample to guess class name
    // y = image_model(10)
    //
//Authors
//Tanay Karve
endfunction
