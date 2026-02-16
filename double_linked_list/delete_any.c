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
struct node* delete_any(struct node* head,int pos){
    if(pos<1){
        printf("Invalid position.\n");
        return head;
    }
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
    // cj=heack for 1st node
    if (pos==1){
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;
    }
    for (int i =1;i<pos&&temp!=NULL;i++){
        temp = temp->next;
    }
    if (temp==NULL){
        printf("Out of range.\n");
        return head;
    }
    temp->prev->next = temp->next;
    if (temp->next!=NULL){ // don't execute if node is last
        temp->next->prev = temp->prev;
    }
    
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
    // for last node
    print_list(head);
    head = delete_any(head,3);
    print_list(head);
    head = delete_any(head,2);
    print_list(head);
    // for 1st node
    head = delete_any(head,1);
    print_list(head);
    head = delete_any(head,1);
    print_list(head);
    return 0;
}