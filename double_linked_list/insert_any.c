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
struct node* insert_any(struct node* head, int value, int pos){
    if(pos<1){
        printf("invalid position.\n");
        return head;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    // check empty list 
    if (head==NULL){
        if (pos==1){
            return newNode;
        }
        else{
            printf("Index out of range.\n");
            free(newNode);
            return head;
        }
        
    }
    // insert at begin
    if(pos==1){
        newNode->next = head;
        head->prev = newNode;
        // head = newNode;
        // return head;
        return newNode;
        }
    struct node* temp = head;
    // traverse
    for(int i= 1;i<pos-1 && temp!=NULL;i++){
        temp = temp->next;
    }
    if (temp==NULL){
        printf("Index out of range.\n");
        return head;
    }
    newNode->prev= temp;
    newNode->next = temp->next;
    if (temp->next!=NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
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
    head = insert_any(head,50,4);
    print_list(head);
    head = insert_any(head,25,1);
    print_list(head);
    head = insert_any(head,26,2);
    print_list(head);
    head = insert_any(head,26,20);
    print_list(head);
    head = insert_any(head,36,4);
    print_list(head);

    return 0;
}