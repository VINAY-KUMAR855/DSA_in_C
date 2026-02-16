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
struct node* delete_end(struct node* head){
    if (head==NULL){
        printf("List is empty.\n");
        return head;
    }
    // check if 1 node
    if (head->next==NULL){
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
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
    head = delete_end(head);
    print_list(head);
    head = delete_end(head);
    print_list(head);
    head = delete_end(head);
    print_list(head);
    head = delete_end(head);
    print_list(head);

    return 0;
}