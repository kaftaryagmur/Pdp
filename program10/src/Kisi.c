#include "Kisi.h"
Kisi new_Kisi(char* isim,int yas,double kilo,double boy){
	Kisi this;
	this=(Kisi)malloc(sizeof(struct KISI));//bellekten belirtilen kadar yer ayırır
	this->isim=isim;
	this->yas=yas;
	this->kilo=kilo;
	this->boy=boy;
	return this;
}
void yemekYe(const Kisi this,double kalori){
	this->kilo += (kalori/1000);
}
void yaslan(const Kisi this){ //mesaji alan nesne belli degil, o yuzden const Kisi verildi.
	this->yas++;
		if (this->yas<18) {
			this->boy+= 0.5;
		}
}
char* getIsim(const Kisi this){
	return this->isim;
}
double getKilo(const Kisi this){
	return this->kilo;
}
double getBoy(const Kisi this){
	return this->kilo;
}
void delete_kisi(const Kisi this){
	if(this != NULL) free(this);
}