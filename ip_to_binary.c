#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <error.h>
#include <arpa/inet.h>

#define MAX_8BIT 255

char isValidIpAddress(char *ipAddress);
int binary_conv(int);

int main(void) {

    	int num, bin, k;
    	char  *str =  malloc(sizeof(char) * 16), *str2;
    	int value[4] = {0};
    	size_t index = 0;

	printf("\nEnter an IP Address: \n");
	scanf("%16s", str);

    	str2 = str;

	if(!isValidIpAddress(str2)){
		printf("Please enter a valid IP Address ...\n");
		exit(EXIT_FAILURE);
	}

    	while (*str) {
        	if (isdigit((unsigned char)*str)) {
            	value[index] *= 10;
            	value[index] += *str - '0';
        	} else {
         		index++;
        	}
       		str++;
    	}

	printf("\nBinary format is: \n");

	for (num = 0; num < 4; ++num){
		bin = binary_conv(value[num]);
		printf("%08d ", bin);
	}

      	printf("\n");
	printf("\nHexadecimal format is: \n");
	printf("0x");

	for (num = 0; num < 4; ++num){
		printf("%02x", value[num]);
	}



	printf("\n\n");

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

char isValidIpAddress(char *ipAddress)
{
    	struct sockaddr_in sa;
    	int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    	return result != 0;
}
