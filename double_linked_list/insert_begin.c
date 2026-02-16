#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node* prev;
    int data;
    struct node* next;
};
void print_list(struct node* head){
    struct node* temp = head;
    printf("NULL <-> ");
    while (temp!=NULL){
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct node* insert_begin(struct node* head, int value){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->prev = NULL;
    new->next = head;
    // only if first node is not null
    if(head!=NULL){
        head->prev = new;
    }
    head = new;

    return head;
}
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

    print_list(head);
    head = insert_begin(head, 0);
    print_list(head);
    return 0;
}