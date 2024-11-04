#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char* str);
char* my_strcat(char* str1, const char*str2);
int my_strncmp(const char* str1, const char* str2, int n);
int countOcurrences(const char* text, const char* word);


#endif // STRING_H_INCLUDED
