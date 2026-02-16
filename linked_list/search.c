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
void search(struct node* head,int key){
    if (head==NULL){
        printf("Empty list.\n");
        return;
    }
    int pos=1;
    struct node* temp = head;
    while(temp!=NULL){
        if (temp->data== key){
            printf("Key found at %d position.\n",pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Key not found.\n");
    return;
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
    search(head,10);
    search(head,100);
    search(head,20);


    return 0;
}