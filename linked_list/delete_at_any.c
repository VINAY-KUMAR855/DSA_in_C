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

struct node* delete_any_pos(struct node* head, int pos){
    // cheack if head is null
    if (head == NULL){
        printf("List is empty!\n");
        return head;
    }
    struct node* temp = head;
    // for head
    if (pos==1){
        head = head->next;
        free(temp);
        return head;
    }
    for (int i = 1; i<pos-1 && temp!=NULL ;i++){
        temp = temp->next;
    }
    if (temp==NULL || temp->next==NULL){ // temp->next==NULL invalid position
        printf("Out of range.\n");
        return head;
    }
    // temp->next = temp->next->next;
    // return head;
    struct node* todel = temp->next; // create node to delete
    temp->next = temp->next->next; // unlink
    free(todel);
    
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
    head = delete_any_pos(head,2);
    print_list(head);
    head = delete_any_pos(head,1);
    print_list(head);
    head = delete_any_pos(head,10);
    print_list(head);
    head = delete_any_pos(head,1);
    print_list(head);
    head = delete_any_pos(head,1);
    print_list(head);

    return 0;
}