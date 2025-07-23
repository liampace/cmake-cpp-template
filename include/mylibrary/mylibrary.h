//
// Created by dev on 7/22/2025.
//

#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include "mylibrary/export.h"

namespace mylibrary
{
    /**
     * @brief Print "Hello World" to the standard output
     */
    MYLIBRARY_EXPORT void printHelloWorld();

    /**
     * @brief Print the value of the __cplusplus macro to the standard output
     */
    MYLIBRARY_EXPORT void printCPlusPlus();
}

#endif //MYLIBRARY_H
