#ifndef __LIBKERAS_TOOLBOX_GW_HXX__
#define __LIBKERAS_TOOLBOX_GW_HXX__

#ifdef _MSC_VER
#ifdef LIBKERAS_TOOLBOX_GW_EXPORTS
#define LIBKERAS_TOOLBOX_GW_IMPEXP __declspec(dllexport)
#else
#define LIBKERAS_TOOLBOX_GW_IMPEXP __declspec(dllimport)
#endif
#else
#define LIBKERAS_TOOLBOX_GW_IMPEXP
#endif

extern "C" LIBKERAS_TOOLBOX_GW_IMPEXP int libkeras_toolbox(wchar_t* _pwstFuncName);






#endif /* __LIBKERAS_TOOLBOX_GW_HXX__ */
