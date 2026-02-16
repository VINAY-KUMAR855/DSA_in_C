#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void printList(struct node* Node){
    while (Node!=NULL){
        printf("%d-->",Node->data);
        Node = Node->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    // assign data
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = NULL;
    printList(head);
    head = second;
    printList(head);
    
    return 0;

}