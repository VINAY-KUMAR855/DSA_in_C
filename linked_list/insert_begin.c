#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
void print_list(struct node* head){
    struct node* temp = head;
    while (temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct node* insert_begin(int value,struct node* head){
    struct node* newNode = (struct node* )malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}
int main(){
    struct node* head = (struct node* )malloc(sizeof(struct node));
    struct node* n1 = (struct node* )malloc(sizeof(struct node));
    head->data = 10;
    head->next = n1;
    n1->data = 20;
    n1->next = NULL;
    print_list(head);
    head = insert_begin(0,head);
    print_list(head);

    return 0;
}