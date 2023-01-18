#include <stdio.h>
#include <stdlib.h>
//include "tokenize.h"


int main(int argc, char *argv[]){
    FILE* file = fopen(argv[1], "r");
    int size = 10, index = 0;
    char* character = malloc(size*sizeof(char));

    while(feof(file)){
        if(index < size) character[index] = getc(file);
        else {
            size += 10;
            character = realloc(character, size * sizeof(char));
            character[index] = getc(file);
        }
        index++;
    }
    
    size = index - 1;
    character = realloc(character, size * sizeof(char));

    for(int i = 0; i<size; i++)
        printf("%c", character[i]);
    return 0;
}
