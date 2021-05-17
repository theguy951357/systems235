#include <stdio.h>

void print_file(){
    FILE *fp = fopen("lab6.txt","r");
    int c = getc(fp);
    while(c != EOF){
        printf("%c",c);
        c = getc(fp);
    }
    printf("\n");
    fclose(fp);
}

int main() {
    print_file();

}
