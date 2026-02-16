#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* front =NULL, *rear=NULL;

void enQueue(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if(rear==NULL){
        rear = front = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;

}
void deQueue(){
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    struct node* temp = front;
    if(front==rear){
        front=rear=NULL;
    }else{
        front = front->next;
    }
    free(temp);
    
}
void display(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = front;
    printf("Queue: ");
    while(temp!=NULL){
        printf("[%d] ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    }

int main(){
    display();
    enQueue(10);
    enQueue(20);
    enQueue(30);
    display();
    deQueue();
    display();
    deQueue();
    display();
    deQueue();
    display();
    deQueue();

    return 0;
}