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
#include "localization.h"
#include "c_transfer.h"




static const char fname[] = "ANN";
int sci_ANN(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{
	wchar_t* in1 = NULL;
	wchar_t* in2 = NULL;
	wchar_t* in3 = NULL;
	double* in4 = NULL;
	double* in5 = NULL;
	int n_epochs,bSize;
	char *arg1 = (char *)malloc(100);
	char *arg2 = (char *)malloc(100);
	char *arg3= (char *)malloc(100);
	double out1 = 0.0;
	double ar[1];
  
if (nin < 5)
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
*/
    scilab_getString(env, in[0], &in1);
    scilab_getString(env, in[1], &in2);
    scilab_getString(env, in[2], &in3);
    const wchar_t * c_in1 = in1;
    const wchar_t * c_in2 = in2;
    const wchar_t * c_in3 = in3;
    scilab_getDoubleArray(env, in[3], &in4);
    scilab_getDoubleArray(env, in[4], &in5);
    n_epochs = *in4;
    bSize = *in5;
    wcstombs(arg1,c_in1,100);
    wcstombs(arg2,c_in2,sizeof(arg2));
    wcstombs(arg3,c_in3,sizeof(arg3));

    out1=ANN(arg1,arg2,arg3,n_epochs,bSize);

    out[0] = scilab_createDouble(env,out1);
    //scilab_getDoubleArray(env, out[0], &out1);
    //out1[0] = ar[0];
    return 0;
}
}
