mode(-1);
function[]= ANN_train(layers,epochs,batchsize)
    
    dataset = uigetfile(["*.csv"],"~", "Choose a dataset file", %t);
    label = input("Enter label column:","string");
    disp('Training...');
    unix("python3.8 KerasANN.py "+dataset+" "+label+" "+layers+" "+string(epochs)+" "+string(batchsize))

    
endfunction

function[output]= ANN_test_sample(test_sample)
    model_d= unix_g("pwd")+"/models";
    model_file = uigetfile(["neural*.ml"],model_d,"Choose a model file", %t);
    output= ANN_test(test_sample,int32(length(test_sample)),model_file)
endfunction

function[output]= image_model(epochs)
    image_dir = uigetdir("~","Choose an image directory");
    disp("Training...");
    output = image_train_tl(image_dir,epochs);
    printf("Training accuracy: %0.2f",(output*100));
endfunction

function[output]= image_model_test()
    model_d= unix_g("pwd")+"/models";
    model_file = uigetfile(["image*.ml"],model_d, "Choose a model file", %t);
    image_file = uigetfile(["*.jpeg";"*.jpg";"*.png"],"~", "Choose an image file", %t);
    output = image_test_tl(image_file,model_file);
    
    disp('The selected image is of:')
    disp(output)

endfunction

function[]=plotTrainingAccuracy()
    unix_w("python3.8 GetSessionInfo.py accuracy")
    unix_w("xdg-open plots/AccuracyPlot.png");
endfunction

function[]=plotTrainingLoss()
    unix_w("python3.8 GetSessionInfo.py loss")
    unix("xdg-open plots/LossPlot.png");
endfunction

function[]=plotConfusionMatrix()
    unix_w("python3.8 GetSessionInfo.py cmat")
    unix_w("xdg-open plots/ConfusionMatrixPlot.png");   
endfunction

