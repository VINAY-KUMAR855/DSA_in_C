#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
void print_list(struct node* head){
    if (head==NULL){
        printf("list is empty.\n");
        return; 
    }
    struct node* temp = head;
    // printf("%d->",temp->data);
    // temp = temp->next;
    // while(temp!=head){
    //     printf("%d->",temp->data);
    //     temp= temp->next;
    // }
    // printf("%d",head->data);
    do{
        printf("%d->",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("%d\n",head->data);

}
int main(){
    // struct node* head = (struct node*)malloc(sizeof(struct node));
    // head->data = 10;
    // head->next = head;
    // print_list(head);
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* n1 = (struct node* )malloc(sizeof(struct node));
    struct node* n2 = (struct node* )malloc(sizeof(struct node));
    head->data = 10;
    head->next = n1;
    n1->data = 20;
    n1->next = n2;
    n2->data = 30;
    n2->next = head; 
    print_list(head);

    return 0;
}