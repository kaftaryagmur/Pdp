#include <stdio.h>

int x = 4;

void f3() {
    printf("%d", x);
}

void f1() {
    int x = 10;
    f3();
}

void f2() {
    x = 5;
    f3();
}


int main() {
    f1();
    f2();
    f3();
    return 0;
}
