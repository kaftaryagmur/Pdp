#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"

struct KISI{
	char* isim;
	int yas;
	double kilo;
	double boy;
};
typedef struct KISI* Kisi;

Kisi new_Kisi(char*,int,double,double);
void yemekYe(const Kisi,double );
void yaslan(const Kisi); //mesaji alan nesne belli degil, o yuzden const Kisi verildi.
char* getIsim(const Kisi);
double getKilo(const Kisi);
double getBoy(const Kisi);
void delete_kisi(const Kisi);

#endif