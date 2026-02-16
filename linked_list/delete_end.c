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

struct node* delete_end(struct node* head){
    if (head==NULL){
        printf("List is empty!\n");
        return head;
    }
    // check if only one node.
    if (head->next==NULL){
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
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