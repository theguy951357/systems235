#include <stdio.h>
#include <stdlib.h>

void print_file(char *string){
    if(string == NULL){
     fprintf(stderr, "Text file argument not provided.\n");
     exit(1);
    }
    FILE *fp = fopen(string, "r");
    int c = getc(fp);
    while(c != EOF){
        printf("%c",c);
        c = getc(fp);
    }
    printf("\n");
    fclose(fp);
}

int main(int argC, char *argV[]) {
    print_file(argV[1]);
	exit(0);
}
