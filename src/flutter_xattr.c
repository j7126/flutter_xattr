#ifdef linux

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/xattr.h>
#include "flutter_xattr.h"

// get an attribute on a file
FFI_PLUGIN_EXPORT char *get_attribute(char *path, char *attribute)
{
    char value[1];
    // check the attribute size
    int expectedSize = getxattr(path, attribute, value, 0);
    if (expectedSize <= 0) {
        return "";
    }
    // Allocates native memory in C.
    char *attributeValue = (char *)malloc((expectedSize + 1) * sizeof(char));
    // get the attribute
    int actualSize = getxattr(path, attribute, attributeValue, expectedSize);
    if (actualSize != expectedSize) {
        free(attributeValue);
        return "";
    }
    attributeValue[expectedSize] = '\0';
    return attributeValue;
}

// free a string
void free_string(char *str)
{
    // Free native memory in C which was allocated in C.
    free(str);
}

#endif
