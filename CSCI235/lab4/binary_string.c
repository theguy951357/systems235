#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* unsigned_to_binary(unsigned x) 
{
    int max = 32;
    for(int i = max; i > 0; i--)
    {
        double power = pow(2, i);
        if(x > power)
        {
            max = i + 1;
            break;
        }
    }

    char *str = (char *) malloc((max + 1) * sizeof(char));

    unsigned x_cpy = x;
    for(int i = max - 1; i >= 0; i--)
    {
        int remainder = 0;
        if(x_cpy % 2 == 1) {
            remainder = 1;
        }

        x_cpy /= 2;

        str[i] = (char) (remainder + '0'); // todo: test
    }

    str[max + 1] = '\0';
    return str;
}

unsigned binary_to_unsigned(char* str)
{
    unsigned total = 0;
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }

    for(int i = 0; i < len; i++) {
        if(str[i] == '1')
        {
            double power = pow(2, len - i);
            total += (unsigned) power;
        }
    }

    return total / 2;
}

char* add_binary(char* str1, char* str2)
{
    const int max = 32;
    int len1 = 0;
    int len2 = 0;

    // Get length of both arrays
    while(str1[len1] != '\0')
    {
        len1++;
    }

    while(str2[len2] != '\0')
    {
        len2++;
    }

    int greatest = len1 > len2
            ? len1
            : len2;

    if(greatest > max)
    {
        greatest = max;
    }

    // Shift position of smallest string to match below loop.
    if(len1 != len2)
    {
        int delta;
        if(len1 < len2)
        {
            delta = len2 - len1;
            char *str1Cpy = (char *) malloc(len1 + delta);

            // Initialize first elements
            for(int i = 0; i < delta; i++)
            {
                str1Cpy[i] = '0';
            }

            // Shift the rest of the elements
            for(int i = 0; i < len1; i++)
            {
                char temp = str1[i];
                int idx = delta + i;

                str1Cpy[idx] = temp;
            }

            str1 = str1Cpy;
        }
        else
        {
            delta = len1 - len2;
            char *str2Cpy = (char *) malloc(len2 + delta);

            // Initialize first elements
            for(int i = 0; i < delta; i++)
            {
                str2Cpy[i] = '0';
            }

            // Shift the rest of the elements
            for(int i = 0; i < len1; i++)
            {
                char temp = str2[i];
                int idx = delta + i;

                str2Cpy[idx] = temp;
            }

            str2 = str2Cpy;
        }
    }

    // Allocate 2 extra bits in the event of max overflow.
    char* retString = (char *) malloc(greatest + 2);

    // Least -> most significant bits
    int remainder = 0;
    for(int i = greatest - 1; i >= 0; i--)
    {
        char cur1 = str1[i];
        char cur2 = str2[i];

        int bit = 0;

        int bit1 = cur1 - '0';
        int bit2 = cur2 - '0';

        if(bit1 < 0)
        {
            bit1 = 0;
        }
        if(bit2 < 0)
        {
            bit2 = 0;
        }

        // If there is an invalid value, set to 0.
        bit = bit1 + bit2 + remainder;

        if(bit <= 1)
        {
            remainder = 0;
            retString[i] = bit + '0';
        }
        if(bit == 2)
        {
            remainder = 1;
            retString[i] = 0 + '0';
        }
        if(bit == 3)
        {
            remainder = 1;
            retString[i] = 1 + '0';
        }
    }

    retString[greatest + 2] = '\0';
    return retString;
}

int main() {
    unsigned x = 347;
    char* str1 = unsigned_to_binary(x);
    printf("str1=%s\n",str1);
    printf("unsigned of str1=%u\n",binary_to_unsigned(str1));

    unsigned y = 9652;
    char* str2 = unsigned_to_binary(y);
    printf("str2=%s\n",str2);
    printf("unsigned of str2=%u\n",binary_to_unsigned(str2));

    char* str3 = add_binary(str1,str2);
    unsigned sum = binary_to_unsigned(str3);
    printf("sum is %s, %u\n",str3, sum);

    free(str1);
    free(str2);
    free(str3);
}

