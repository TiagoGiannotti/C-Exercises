#include "string.h"
#include <stdio.h>
#include <stdlib.h>



//funcion para obtener longitud de una cadena
int my_strlen(const char* str){

int lengh=0;

while(str[lengh]!= '\0'){

    lengh ++;
}

return lengh;
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

//funcion para comparar dos cadenas hasta cierto n
int my_strncmp(const char* str1, const char* str2, int n){

for(int i=0; i<n; i++){

    if(*(str1+i)=='\0' && *(str2+i)=='\0'){
           return 0;
    }

    // Si uno de los dos caracteres es el carácter nulo, deja la comparación

    if (*(str1+i)=='\0' || *(str2+i)=='\0'){
       return (unsigned char)*(str1+i) - (unsigned char)*(str2+i);
    }

    if(*(str1+i) != *(str2+i)){
    return (unsigned char)*(str1+i) - (unsigned char)*(str2+i);
    }
}
return 0;
}

//funcion para comparar dos cadenas











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

