#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char* str);
char* my_strcpy(char* destino, char* origen);
char* my_strncpy(char* destino, char* origen,size_t bytes);
int my_strcmp(const char* str1,const char* str2);
int my_strncmp(const char* str1, const char* str2,size_t bytes);
int my_strchr(char *str, const char busqueda);
int my_strrchr(char *str, const char busqueda);
char* my_strcat(char* str1, const char*str2);
char* my_strstr(char* cadena,char* subcadena);
int countOcurrences(const char* text, const char* word);


#endif // STRING_H_INCLUDED
