// Copyright (C) 2019 - IIT Bombay - FOSSEE
//
// This file must be used under the terms of the CeCILL.
// This source file is licensed as described in the file COPYING, which
// you should have received as part of this distribution.  The terms
// are also available at
// http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
// Author: Rupak Rokade
// Organization: FOSSEE, IIT Bombay
// Email: toolbox@scilab.in
extern "C"
{
#include<Scierror.h>
#include<api_scilab.h>
#include <stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include "localization.h"
#include "c_transfer.h"




static const char fname[] = "ANN_test";
int sci_ANN_test(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{
puts("ok");
	wchar_t* in1 = NULL;
	wchar_t* in_model_file = NULL;
	wchar_t ret[100] ;
	double* in4 = NULL;
	double* in5 = NULL;
	int to_predict_n=0,i;
	char model_file_mbs[500];
	double * to_predict;
	double* out1 = NULL;
	double ar[1];
	puts("ok");
  
if (nin < 3)
    {
        Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 5);
        return 1;
    }
/*
if (nout != 1)
    {
        Scierror(77, _("%s: Wrong number of output argument(s): %d expected.\n"), fname, 1);
        return 1;
    }
*/puts("ok");
    scilab_getDoubleArray(env, in[0], &to_predict);
    scilab_getInteger32(env, in[1], &to_predict_n);
    scilab_getString(env, in[2], &in_model_file);
printf("%d",to_predict_n);
    const wchar_t * model_file = in_model_file;
    puts("ok");
    wcstombs(model_file_mbs,model_file,500);
    puts(model_file_mbs);
    
   const char * ret_c = ANN_test(to_predict,to_predict_n,model_file_mbs);
   
    //mbstowcs(ret,ret_c,100);
    
    swprintf(ret,100, L"%hs",ret_c);
    
    out[0]   = scilab_createString(env,ret);
    
  

    return 0;
}
}
