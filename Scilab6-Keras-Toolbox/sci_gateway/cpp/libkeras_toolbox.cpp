#include <wchar.h>
#include "libkeras_toolbox.hxx"
extern "C"
{
#include "libkeras_toolbox.h"
#include "addfunction.h"
}

#define MODULE_NAME L"libkeras_toolbox"

int libkeras_toolbox(wchar_t* _pwstFuncName)
{
    if(wcscmp(_pwstFuncName, L"ANN") == 0){ addCFunction(L"ANN", &sci_ANN, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"ANN_test") == 0){ addCFunction(L"ANN_test", &sci_ANN_test, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"image_train_tl") == 0){ addCFunction(L"image_train_tl", &sci_image_train_tl, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"image_test_tl") == 0){ addCFunction(L"image_test_tl", &sci_image_test_tl, MODULE_NAME); }

    return 1;
}
