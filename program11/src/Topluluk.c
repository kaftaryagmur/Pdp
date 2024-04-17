#include "Topluluk.h"

Topluluk new_Topluluk(int* sayilar,int uzunluk){  
	Topluluk this;
	this=(Topluluk)malloc(sizeof(struct TOPLULUK));
	this->sayilar = malloc(sizeof(int)*uzunluk);
	this->uzunluk = uzunluk;
	for (int i = 0; i < this->uzunluk; i++) {
		this->sayilar[i]= sayilar[i];
	}
	this->sirala = &sirala;
	this->yaz = &ekranaYaz;
	this->delete_topluluk = &delete_topluluk;
	return this;
}

int* sirala(const Topluluk this){
	for (int i = 0; i <this->uzunluk-1; i++) {
		for (int j = 1; j <this->uzunluk-i; j++) {
			if(this->sayilar[j]<this->sayilar[j-1]) {
				int yedek = this->sayilar[j];
				this->sayilar[j]=this->sayilar[j-1];
				this->sayilar[j-1]=yedek;
			}
		}
			
	}
	int *sirali = malloc(sizeof(int)*this->uzunluk);
	for (int i = 0; i < this->uzunluk; i++) {
		sirali[i]=this->sayilar[i];
	}
	return sirali;
}
void ekranaYaz(const Topluluk this){
	int *p = this->sirala(this); //cop olusmamali icin pointer kullan
	for (int i = 0; i < this->uzunluk; i++) {
		printf("%d ", this->sayilar[i]);

	}
	free(p);
}
void delete_topluluk(Topluluk this){
	if(this->sayilar != NULL) free(this->sayilar);
	if(this != NULL) free(this);
}