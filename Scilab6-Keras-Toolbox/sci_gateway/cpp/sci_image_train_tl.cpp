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
#include <sciprint.h>
#include "localization.h"
#include "c_transfer.h"




static const char fname[] = "image_train_tl";
int sci_image_train_tl(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{

	wchar_t* in1 = NULL;
	double* in2 = NULL;
	int n_epochs;
	char *arg1 = (char *)malloc(500);
	
	double out1 = 0.0;
  
if (nin < 2)
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
    const wchar_t * c_in1 = in1;
    scilab_getDoubleArray(env, in[1], &in2);

    n_epochs = *in2;
    wcstombs(arg1,c_in1,500);

    
    
    out1=image_train_tl(arg1,n_epochs);

    out[0] = scilab_createDouble(env,out1);
    return 0;
}
}
