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




static const char fname[] = "image_test_tl";
int sci_image_test_tl(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{
	
	wchar_t* in1 = NULL;
	wchar_t* in2 = NULL;
	wchar_t ret[100] ;
	int n_epochs;
	char *arg1 = (char *)malloc(500);
	char *arg2 = (char *)malloc(500);
	
  
if (nin < 2)
    {
        Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 5);
        return 1;
    }

    scilab_getString(env, in[0], &in1);
    scilab_getString(env, in[1], &in2);
    const wchar_t * c_in1 = in1;
    const wchar_t * c_in2 = in2;
    

    wcstombs(arg1,c_in1,500);
    wcstombs(arg2,c_in2,500);    
    
    const char * ret_c=image_test_tl(arg1,arg2);

    swprintf(ret,100, L"%hs",ret_c);
    
    out[0]   = scilab_createString(env,ret);
    
    return 0;
}
}
