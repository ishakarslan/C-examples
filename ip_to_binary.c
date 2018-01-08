#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_8BIT 255

int binary_conv(int);

int main(void) {

    	int num, bin;
    	char  *str =  malloc(sizeof(char) * 16), *str2;
    	int value[4] = {0};
    	size_t index = 0;

	printf("Enter an IP Address: \n");
	scanf("%16s", str);

    	str2 = str;
    	while (*str) {
        	if (isdigit((unsigned char)*str)) {
            	value[index] *= 10;
            	value[index] += *str - '0';
        } else {
         	index++;
        }
        	str++;
    	}

	printf("\nBinary Conv is :\n\n", str);

	for (num = 0; num < 4; ++num){
		if(value[num] > MAX_8BIT){
			printf("Invalid IP Address"); break;
		} else {
		bin = binary_conv(value[num]);
	printf("%08d ", bin);
  		}
	}

	printf("\n");
	return 0;
}


int binary_conv(int num)
{
    	if (num == 0){
        	return 0;
    	} else {
        	return (num % 2) + 10 * binary_conv(num / 2);
    	}
}
