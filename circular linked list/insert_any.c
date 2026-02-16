#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
void print_list(struct node* head){
    struct node* temp = head;
    do{
        printf("%d->",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("%d\n",head->data);
}
struct node* insert_any(struct node* head, int value, int pos){
    if (pos<1){
        printf("Invalid position!\n");
        return head;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    // case 1: if list is empty
    if (head==NULL){
        if (pos==1){
            newNode->next = newNode;
            return newNode;
        }else{
            printf("Position out of range!\n");
            free(newNode);
            return head;
        }
    }
    // case 2: head position
    if (pos==1){
        struct node* temp = head;
        // move to last position
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return head;
    }
    // case 3: end or middle position
    struct node* temp = head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
        if (temp==head){
            printf("Position out of range\n");
            free(newNode);
            return head;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
    
}
int main(){
    struct node* head = NULL;
    head = insert_any(head, 10, 1);
    head = insert_any(head, 20, 2);
    head = insert_any(head, 30, 3);
    print_list(head);
    head = insert_any(head,5,1); // head position
    print_list(head);
    head = insert_any(head, 25, 4);  // middle
    print_list(head);

    head = insert_any(head, 40, 10); // invalid
    print_list(head);

    return 0;
}