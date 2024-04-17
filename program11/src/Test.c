#include "Koleksiyon.h"

int main(){
	int sayilar[]= {10,20,30,40,5,6};
	Koleksiyon k = new_Koleksiyon(sayilar,6);
	k->yaz(k);
	k->delete_Koleksiyon(k);
	return 0;
}