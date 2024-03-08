#include "stdio.h"
#include "conio.h"

typedef enum{false,true}boolean;

int main(){
	float a = 10;
		float b = 3;
		double x = 10;
		double y = 3;
		float c = a / b;
		double z = x / y;
		if (c == z) {
			printf("sayilar esit");
		} else {
			printf("Sayilar esit degildir");
		}
	return 0;
}