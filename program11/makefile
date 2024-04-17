hepsi: derle calistir

derle:
	gcc -I ./include/ -o./lib/Topluluk.o -c ./src/Topluluk.c
	gcc -I ./include/ -o./lib/Koleksiyon.o -c ./src/Koleksiyon.c
	gcc -I ./include/ -o./bin/Test ./lib/Topluluk.o ./lib/Koleksiyon.o ./src/Test.c
	
calistir:
	./bin/Test