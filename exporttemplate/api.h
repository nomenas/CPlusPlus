//
// Created by Naum Puroski on 10/1/16.
//

#ifndef EXPORTTEMPLATE_APITYPE_H
#define EXPORTTEMPLATE_APITYPE_H

#ifdef _WIN32
#ifdef DLL_EXPORT // Set to true when you build the dll
        #define API __declspec(dllexport)
    #else
        #define API __declspec(dllimport)
    #endif
#else
#define API
#endif

#endif //EXPORTTEMPLATE_APITYPE_H
