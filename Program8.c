#include "stdio.h"
#include "stdarg.h"

/*double topla(double,double);//imza olmadan hata verir, fonk altta tanımlanamaz
//turu int olursa int bir istisnadır calısır
int main(){
	double a = 10, b=25;
	double sonuc = topla(a,b);
	printf("sonuc:%lf",sonuc);
	return 0;
}
double topla(double x, double y){
	return x+y;
}*/

typedef enum BOOL{
	false,true
}boolean;

boolean asalMi(int parametreSayisi,...){ //c dizi uzunlugu okuyamadıgı icin parametre sayisini gondermek gerekir
	va_list valist;
	va_start(valis,parametreSayisi);
	int sayi = va_arg(valist,int);
	if(parametreSayisi==1){
		va_end(valist);
		return asalMi(2,sayi,2); //ilk 2: kac parametre, sayi: sayinin kendisi, diger 2:bolen
	}
	int bolen = va_arg(valist,int);
	va_end(valist);
	if(sayi == bolen) return true;
	if(sayi % bolen == 0) return false;
	return asalmi(2,sayi,bolen+1);
}
int main(){
	printf("Sayi: ");
	int s;
	scanf("%d",&s);
	if (asalmi(1,s)==true)) printf("sayi asal");
	else  printf("sayi asal degil");
	
	/*
	double a=10,b=20;
	double sonuc = topla(a,b);
	printf("sonuc:%lf",sonuc);
	return 0;
	*/
}