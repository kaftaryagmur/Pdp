#ifndef KOLEKSIYON_H
#define KOLEKSIYON_H

#include "Topluluk.h"

struct KOLEKSIYON{
	Topluluk super;
	double (*ortalama)(struct KOLEKSIYON*);
	void (*yaz)(struct KOLEKSIYON*);
	void (*delete_Koleksiyon)(struct KOLEKSIYON*);
};

typedef struct KOLEKSIYON* Koleksiyon;
//fonk overloading yok, ayni isimde fonk yazilamaz
Koleksiyon new_Koleksiyon(int*,int);
double ortalama(const Koleksiyon);
void yaz(const Koleksiyon);
void delete_Koleksiyon(Koleksiyon);

#endif