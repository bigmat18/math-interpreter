#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "eval.h"


int main(int argc, char *argv[]){
    if(argc != 2) {
        printf("Error params");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if(!file){
        printf("Error open file\n");
        return 1;
    }

    int size = 10, index = 0;
    char* character = malloc(size*sizeof(char));

    while(!feof(file)){
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

    printf("%d", Eval(Parser(character, size)));
    
    return 0;
}
