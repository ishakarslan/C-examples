/*
 *  * C program to convert the given binary ip address to decimal ip address, convert binary ip to decimal
 *   */
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <error.h>
#define ARRLEN 4 

int todecimal(int num);
//char is_valid_ip(char *ipAddress);
int convertoip();

main(){
	convertoip();
}


int convertoip() {
	int array[4] = {}; //four octet binary value
	int ip,i;
	printf("Enter binary address :\t");

	for (i = 0; i< ARRLEN;i++){
		scanf("%d", &array[i]);
		ip = todecimal(array[i]);
		//check if given binary is valid
		if(ip < 0 || ip > 255 || array[i] % 10 != 0 && array[i] % 10 != 1){
			printf("Error!!  please enter a valid binary address\n");
			exit(EXIT_FAILURE);
		}
        printf("%d", ip);
		if(i<3){
			printf(".");
		}
	}
	printf("\n");
}

int todecimal(int num){ 
	int i, k, decimal_val, given, bol, base = 1;
	decimal_val = 0;
	//given = num;
		while(num>0){
			bol = num % 10;
			decimal_val = decimal_val + bol * base;
			num = num / 10;
			base = base * 2; //while num = 0 continue multiplication
	}
	return decimal_val;
}

/*
char is_valid_ip(char *ipAddress)
{
    	struct sockaddr_in sa;
    	int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    	return result != 0;
}
*/
//you can use this function to is ip valid or invalid
