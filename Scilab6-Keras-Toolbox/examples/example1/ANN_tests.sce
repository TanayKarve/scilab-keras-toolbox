mode(-1)
train_acc=ANN_train(layers="5,6",epochs=15,batchsize=1);
printf("\n\nTraining accuracy:%0.2f%%\n\n",train_acc*100);
disp('Saved models from training:')
files=listfiles("*neural*");
disp(files)
done = 0;
while done==0
    err=0;
    if err==0 then
        disp("Running test on the sample:")
        sample=[5.4,3.4,1.5,0.4];
        disp(sample);
        
        pred=ANN_test_sample(test_sample=sample);
        disp("Prediction on sample is:");
        disp(pred);   
        done=1 ;
    end
    if err==-2 then
        disp("cant find file: ");
        disp(model_file);
    end
end
