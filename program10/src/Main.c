#include "Kisi.h"

int main(){
	Kisi k = new_Kisi("Mehmet",15,70,178);
	yemekYe(k,1500);
	yaslan(k);
	printf("isim: %s",getIsim(k));
	printf("kilo: %lf",getKilo(k));
	printf("boy: %lf",getBoy(k));
	delete_kisi(k);
	return 0;
	
}