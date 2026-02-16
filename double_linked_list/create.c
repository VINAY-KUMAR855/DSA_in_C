#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node* prev;
    int data;
    struct node* next;
};

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* n1 = (struct node* )malloc(sizeof(struct node));
    struct node* n2 = (struct node* )malloc(sizeof(struct node));
    head->data = 10;
    head->prev = NULL;
    head->next = n1;

    n1->data = 20;
    n1->next = n2;
    n1->prev = head;

    n2->prev = n1;
    n2->data = 30;
    n2->next = NULL;
    printf("head:%d\n",n1->prev->data);
    printf("n1:%d\n",n1->data);
    printf("n2:%d\n",n1->next->data);
    return 0;
}