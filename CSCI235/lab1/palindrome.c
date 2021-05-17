#include <stdio.h>

int is_palindrome(char str[]){
    int tf = 1;
    

    int size = 0;
    while(str[size]!= '\0'){
        size++;
    }



    for(int i = 0; i < size; i++){


	if(str[i] != str[size -1 - i]){
		tf = 0;
		break;
	}
    }
	return tf;
}

int main()
{

char array_1[] = {'a', 'p', 'p', 'l', 'e','\0'};
char array_2[] = {'r', 'o', 't', 'a', 't', 'o', 'r','\0'};
char array_3[] = {'o','\0'};

printf("palindrome = %d\n",is_palindrome(array_1));
printf("palindrome = %d\n",is_palindrome(array_2));
printf("palindrome = %d\n",is_palindrome(array_3));
return 0;
}
