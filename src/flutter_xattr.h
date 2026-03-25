#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define FFI_PLUGIN_EXPORT

// get an attribute on a file
FFI_PLUGIN_EXPORT char *get_attribute(char *path, char *attribute);

// free a string
FFI_PLUGIN_EXPORT void free_string(char *str);
