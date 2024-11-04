#include "string.h"
#include <stdio.h>
#include <stdlib.h>


size_t my_strlen(const char* str){

size_t lengh=0;

char* auxP = str; //PARA NO PERDER EL PUNTERO ORIGINAL

while(*auxP){

    auxP++;
    lengh++;
}

return lengh;
}

char* my_strcpy(char* destino, char* origen){

char* ini= destino;

    while(*origen){

    *destino = *origen;
    destino++;
    origen++;


    }
    *destino = '\0';
    return ini;
}

char* my_strncpy(char* destino, char* origen,size_t bytes){

   char* ini= destino;

    while(*origen && bytes){

    *destino = *origen;
    destino++;
    origen++;
    bytes--;

    }
    *destino = '\0';
    return ini;
}

int strcmp(const char* str1,const char* str2){

while(*str1==*str2 && *str1 && *str2){

    str1++;
    str2++;
}
    return *str1 - *str2;
}



char* my_strcat(char* str1, const char*str2){

char*ini=str1;

while(*str1){

    str1++;
}

while(*str2){
    *str1=*str2;
    str2++;
    str1++;
}
*str1='\0';

return ini;
}



//Funcion para contar ocurrencias de una palabra dentro de una cadena
int countOcurrences(const char* text, const char* word){
int i;
int count=0;
int textlen, wordlen;

if (!text || !word) return 0; //verifica que los punteros no sean nulos

textlen= my_strlen(text);
wordlen= my_strlen(word);

if(wordlen==0) return 0;

if(wordlen>textlen) return 0;

for(i=0; i<=textlen-wordlen; i++){

        if(my_strncmp(text+i,word,wordlen)==0){
            ++count;
        }
    }
return count;
}

