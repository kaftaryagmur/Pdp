#include "Koleksiyon.h"
Koleksiyon new_Koleksiyon(int* sayilar,int uzunluk){
	Koleksiyon this;
	this = (Koleksiyon)malloc(sizeof(struct KOLEKSIYON));
	this->super = new_Topluluk(sayilar,uzunluk); //arka planda topluluk nesnesi olusturmali (kalitim benzeri)
	
	this->ortalama = &ortalama;
	this->yaz = &yaz;
	this->delete_Koleksiyon=&delete_Koleksiyon;
	return this;
}
double ortalama(const Koleksiyon this){
	double toplam =0;
	for (int index=0;index<this->super->uzunluk;index++) {
		toplam += this->super->sayilar[index];
	}
	return toplam/this->super->uzunluk;
}
void yaz(const Koleksiyon this){
	this->super->yaz(this->super); //fonks gostericisi cagirildi VE this->super Topluluk'tur.
	printf("\nOrtalama :%lf",this->ortalama(this));
}
void delete_Koleksiyon(Koleksiyon this){
	if(this!=NULL) return;
	if(this->super != NULL)
		this->super->delete_topluluk(this->super);
	free (this);
}