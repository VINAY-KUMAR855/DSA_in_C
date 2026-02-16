#include<stdio.h>
struct Student{
    int roll;
    float cgpa ;
    struct address{
        int pin;
    } add;
};//s1;
struct node{
    int data;
    struct node *next;
};
int main(){
    // struct Student s2 = {2,3.3,{23}};
    // struct Student *s3 = &s2;
    // s1.cgpa = 2;
    // printf("roll: %d\n",s2.roll);
    // printf("CGPA: %f\n",s1.cgpa);
    // printf("cgpa:%f",s3->cgpa);
    // printf("%d",s3->add.pin);
    struct node n1,n2;
    n1.data = 10;
    n1.next = &n2;
    n2.data = 20;
    n2.next = NULL;
    printf("n1:%d\n",n1.data);
    printf("n2:%d\n",n2.data);
    printf("n2:%d\n",n1.next->data);
}