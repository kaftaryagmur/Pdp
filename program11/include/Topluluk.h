#ifndef TOPLULUK_H
#define TOPLULUK_H

#include "stdio.h"
#include "stdlib.h"

struct TOPLULUK{
	int* sayilar;
	int uzunluk;
	
	int* (*sirala)(struct TOPLULUK*); //fonk. gostericisi
	void (*yaz)(struct TOPLULUK*);
	void (*delete_topluluk)(struct TOPLULUK*);
};

typedef struct TOPLULUK* Topluluk;

Topluluk new_Topluluk(int*,int); // kurucu fonk. nesne uretip adres dondurur.
int* sirala(const Topluluk); //const:mesaji alan nesne degisemez
void ekranaYaz(const Topluluk);
void delete_topluluk(Topluluk);

#endif