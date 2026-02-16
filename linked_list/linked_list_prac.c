#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void print_li(struct node* Node){
    while (Node!=NULL){
        printf("%d-->",Node->data);
        Node = Node->next;
    }
    printf("NULL\n");
}

int main(){
    // // pointer nodes
    // // create a pointer it points to nothing
    // struct node* head=NULL;
    // struct node* second = NULL;
    // // allocate memory for each node
    // head = (struct node*)malloc(sizeof(struct node));
    // second = (struct node*)malloc(sizeof(struct node));
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    // assign data
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = NULL;
    printf("n1:%d\n",head->data);
    printf("n2:%d\n",head->next->data);
    print_li(head);

    return 0;

}