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
struct node* insert_any(struct node* head,int pos,int value){
    if(pos<1){
        printf("Invalid position!\n");
        return head;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL; // should this. for last pos
    if(pos==1){
        newNode->next = head;
        // head = newNode;
        // return head;
        return newNode;
    }
    struct node* temp= head;
    for (int i=1;i<pos-1 && temp!=NULL;i++){ // temp!=NULL checks if pos is out of range
        temp = temp->next;
    }
    if (temp==NULL){
        printf("position out of range.\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
int main(){
    struct node* head = (struct node* )malloc(sizeof(struct node));
    struct node* n1 = (struct node* )malloc(sizeof(struct node));
    struct node* n2 = (struct node* )malloc(sizeof(struct node));
    head->data = 10;
    head->next = n1;
    n1->data = 20;
    n1->next = n2;
    n2->data = 20;
    n2->next = NULL;
    print_list(head);
    head = insert_any(head,3,25);
    print_list(head); 
    head = insert_any(head,3,24); 
    print_list(head);
    // 1st position
    head = insert_any(head,1,0); 
    print_list(head);
    // last position
    head = insert_any(head,7,30);
    print_list(head);
    // out of range
    head = insert_any(head,10,30);
    print_list(head);

}