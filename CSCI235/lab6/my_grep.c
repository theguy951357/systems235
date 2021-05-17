#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_file(char *string, char *filename){
    if(string == NULL){
        fprintf(stderr, "String argument not provided.\n");
        exit(1);
    }else if(filename == NULL){
        fprintf(stderr, "Text file argument not provided.\n");
        exit(1);
    }
    FILE *fp = fopen(filename, "r");
    char buffer[100];
    int c = fscanf(fp, "%s", buffer);
    while(c != EOF){
        if(strcmp(string, buffer) == 0){
            printf("String \'%s\' found in the file \'%s\'\n",string, filename);
            exit(0);
        }
        c = fscanf(fp, "%s", buffer);
    }
    fclose(fp);
}

int main(int argC, char *argV[]) {
    search_file(argV[1], argV[2]);
    exit(0);
}
