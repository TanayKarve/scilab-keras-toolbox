#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include<stdlib.h>
#include "c_transfer.h"



char * ANN_test( double to_predict[],int to_predict_n,char* model_file){
	int i,n=to_predict_n;
	printf("ANN_TEST");
	Py_Initialize();
	PyRun_SimpleString("import sys;sys.path.append('.')");
	PyObject *pName, *pModule, *pFunc,*pArgs, *pValue;
	PyObject * toPredict = PyList_New(n);
	for(i=0;i<n;i++){
		PyList_SetItem(toPredict,i,PyFloat_FromDouble(to_predict[i]));
		
	}
	pName = PyUnicode_DecodeFSDefault("KerasANN");
	pModule = PyImport_Import(pName);
	Py_DECREF(pName);
	if (pModule != NULL) {
		
		pFunc = PyObject_GetAttrString(pModule,"ANN_test");
		pArgs = PyTuple_New(2);
		
		PyTuple_SetItem(pArgs, 0, toPredict);
		
		pValue = PyBytes_FromString(model_file);
		PyTuple_SetItem(pArgs, 1, pValue);
		
		pValue = PyObject_CallObject(pFunc, pArgs);
		Py_DECREF(pArgs);
	}
	if (pValue != NULL) {
                printf("Prediction: %s\n", PyBytes_AsString(pValue));
                return PyBytes_AsString(pValue);
                Py_DECREF(pValue);
                
        }
        else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed!!\n");
                return "Call failed!!";
        }
	
}

double ANN(char  * file_name,char *label,char *layers,int n_epochs,int n_batch_size){
	
	Py_Initialize();
	PyRun_SimpleString("import sys;sys.path.append('.')");
	system("pwd");
	PyObject *pName, *pModule, *pFunc,*pArgs, *pValue;
	pName = PyUnicode_DecodeFSDefault("KerasANN");
	pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule,"ANN");
		if (pFunc && PyCallable_Check(pFunc)) {
			pArgs = PyTuple_New(5);
			
			pValue = PyBytes_FromString(file_name);
			PyTuple_SetItem(pArgs, 0, pValue);
			
			pValue = PyBytes_FromString(layers);
			PyTuple_SetItem(pArgs,1,pValue);
			
			pValue = PyBytes_FromString(label);
			PyTuple_SetItem(pArgs,2,pValue);
			
			pValue = PyLong_FromLong(n_epochs);
			PyTuple_SetItem(pArgs,3,pValue);
			
			pValue = PyLong_FromLong(n_batch_size);
			PyTuple_SetItem(pArgs,4,pValue);
			
			pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Accuracy of neural network: %f\n", PyFloat_AsDouble(pValue));
                
                return PyFloat_AsDouble(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return -1;
            }
		}
    }else{
    	PyErr_Print();
    	printf("MODULE is NULL!!");
    }
    return -1;
}



double image_train_tl(char * dir_name,int n_epochs){
	printf("image train");
	Py_Initialize();
	printf("image train");
	PyRun_SimpleString("import sys;sys.path.append('.')");
	PyObject *pName, *pModule, *pFunc,*pArgs, *pValue;
	pName = PyUnicode_DecodeFSDefault("mntransfer");
	pModule = PyImport_Import(pName);
    	Py_DECREF(pName);
    	if (pModule != NULL) {
       	pFunc = PyObject_GetAttrString(pModule,"train");
		if (pFunc && PyCallable_Check(pFunc)) {
			pArgs = PyTuple_New(2);
			
			pValue = PyBytes_FromString(dir_name);
			PyTuple_SetItem(pArgs, 0, pValue);
			pValue = PyLong_FromLong(n_epochs);
			PyTuple_SetItem(pArgs,1,pValue);
			printf("image train");
			pValue = PyObject_CallObject(pFunc, pArgs);
			printf("image train");
		
			Py_DECREF(pArgs);
        		if (pValue != NULL) {
         	        	printf("Accuracy of image recognition model: %f\n", PyFloat_AsDouble(pValue));
            	    		
           	     		return PyFloat_AsDouble(pValue);
      	 		}
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return -1;
            }
		}
    }else{
    	PyErr_Print();
    	printf("MODULE is NULL!!");
    }
    return -1;
}

char * image_test_tl(char *image,char * model_file){
	Py_Initialize();
	PyRun_SimpleString("import sys;sys.path.append('.')");
	PyObject *pName, *pModule, *pFunc,*pArgs, *pValue;
	pName = PyUnicode_DecodeFSDefault("mnpredict");
	pModule = PyImport_Import(pName);
    	Py_DECREF(pName);
    	if (pModule != NULL) {
       	 pFunc = PyObject_GetAttrString(pModule,"predict");
		if (pFunc && PyCallable_Check(pFunc)) {
			pArgs = PyTuple_New(2);
			
			pValue = PyBytes_FromString(image);
			PyTuple_SetItem(pArgs, 0, pValue);
			pValue = PyBytes_FromString(model_file);
			PyTuple_SetItem(pArgs,1,pValue);
			pValue = PyObject_CallObject(pFunc, pArgs);
			
		
			Py_DECREF(pArgs);
        		if (pValue != NULL) {
        			
         	        	printf("Image is of: %s\n",  PyBytes_AsString(pValue));
            	    		
           	     		return  PyBytes_AsString(pValue);
      	 		}
      	 	else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return "-1";
            }
		}
    }else{
    	PyErr_Print();
    	printf("MODULE is NULL!!");
    }
    return "-1";
}

