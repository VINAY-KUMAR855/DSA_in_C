#include<stdio.h>
int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 10, b = 20;
    int *c, *d;
    c = &a;
    printf("%d",*c);
    *c = 100;
    printf("%d",a);
}