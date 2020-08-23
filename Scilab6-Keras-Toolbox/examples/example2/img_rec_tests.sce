y=image_model(3);
printf('Training accuracy of image model: %f%%',(y*100));
y=image_model_test();
printf('Guessed class for this image:')
disp(y)
