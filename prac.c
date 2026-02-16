#include<stdio.h>
#include<stdlib.h>

// create self ref structure
struct node {
    int data;
    struct node *next;
};
void print_list(struct node *Node){
    while (Node!=NULL){
        printf("%d->",Node->data);
        Node = Node->next;
    }
    printf("NULL");
}
void insert_begin(int a){
    struct node *Node = (struct node *)malloc(sizeof(struct node *));
    Node->data = a;
    
}


int main(){
    struct node *head=NULL;
    struct node *second = NULL;
    head = (struct node *)malloc(sizeof(struct node *));
    second = (struct node *)malloc(sizeof(struct node *));
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = NULL;
    printf("Data1:%d\n",head->data);
    printf("Data2:%d\n",second->data);
    printf("Data2:%d\n",head->next->data);
    print_list(head);
    // insert_begin(0);

}