#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
// insert
void push(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Head overflow (memory was not available)\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top=newNode;

    printf("%d pushed into stack\n",value);
}
// delete
void pop(){
    if (top==NULL){
        printf("Stack underflow\n");
        return;
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp=top;
    int removed = temp->data;
    top = top->next;
    free(temp);
    printf("%d popped from stack\n", removed);
}
// return top value
void peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n",top->data);
}
// print elements
void display(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    printf("Stack(top to bottom):");
    while(temp!=NULL){
        printf("[%d] ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    push(10);
    push(20);
    push(30);

    display();
    peek();

    pop();
    display();

    pop();
    pop();
    pop();   // underflow test

    push(40);
    push(50);
    display();

    return 0;
}