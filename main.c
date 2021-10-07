#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void) {
	
  printf("Please input a Double Precision Floating Point Value:");
	double t;

	scanf("%lf", &t);
	

	uint64_t data,fraction,exponent,sign;
	data = *((uint64_t*)(&t)); 
	
	uint64_t expMask =  0x7FF0000000000000;
	uint64_t fracMask = 0x000FFFFFFFFFFFFF;

	sign = (data>>63);
	//1023 = bias
	exponent = ((data & expMask)>>52) - 1023;
	fraction = (data & fracMask);



	printf("Sign: %lX\n",sign);
	printf("Base: 2\n");
	printf("Exponent: 0x%lX\n",exponent);
	printf("Fraction: 0x%lX\n", fraction);



}