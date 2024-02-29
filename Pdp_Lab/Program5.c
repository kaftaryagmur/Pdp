#include "stdio.h"
#include "stdlib.h" //heapte olusturmak icin

const char* f1(){
	const char* str = "Sakarya";
	return str;
}

char* f2(){
	char str[] = "Sakarya";
	return str;
}

int main(){
	/*int a[]={100,200,300};
	int *p = a;
	p++;
	printf("%d",*p);*/
	
	/*int a=100;
	int *p;
	p=&a;
	printf("%d",*p);*/
	
	//char pointer
	 
	/*const char* str = "Sakarya"; //stringin tam karsiligi const char'dır
	printf("%c",*str); //ekrana bir karakter yaz
	printf("%s",str); //ekrana string yazar*/
	
	/*printf("f1: %s",f1());
	printf("\nf2: %s",f2());*/
	
	
	//swap işlemi pointerin gösterdigi asresler degistirilerek oldu
	/*int *p,*r;
	int a=100,b=200;
	p=&a;
	r=&b;
	
	int *tmp;
	printf("a: %d",*p);
	printf("\nb: %d",*r);
	tmp=p;
	p=r;
	r=tmp;
	printf("\na: %d",*p);
	printf("\nb: %d",*r);*/
	
	
	/*int *p;
	p=(int*)malloc(sizeof(int));  //heapte alan olusturur
	*p=200;
	printf("p: %d",*p);
	free(p);*/ 
	
	
	void* obj;   //void* javadaki object gibi
	int a = 125;
	obj=&a;
	printf("%d",*((int*)obj));
	char* str = "Sakarya";
	obj = str;
	printf("%s",(char*)obj);
	
	return 0;
}