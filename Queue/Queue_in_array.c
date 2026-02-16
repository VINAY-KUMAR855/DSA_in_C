#include<stdio.h>
#define SIZE 10
int queue[SIZE];
int front =-1,rear =-1;
void enQueue(int value){
    if (rear==SIZE-1){
        printf("Queue overflow.\n");
        return;
    }
    if(front==-1){
        front++;
    }
    queue[++rear] = value;
}
void deQueue(){
    if(front==-1|| front>rear){
        printf("Queue underflow\n");
        return;
    }
    front++;
    // reset queue when it becomes empty
    if (front>rear){
        front=rear=-1;
    }
}

void display(){
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for(int i=front;i<=rear;i++){
        printf("[%d] ",queue[i]);
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
    return 0;
}