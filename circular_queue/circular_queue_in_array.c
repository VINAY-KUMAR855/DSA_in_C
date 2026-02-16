#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front =-1, rear =-1;
void enQueue(int value){
    if((rear+1)%SIZE==front){
        printf("Queue overflow\n");
        return;
    }
    if(front==-1){
        front = rear = 0;
        queue[rear]=value;
        return;
    }
    rear = (rear+1)%SIZE;
    queue[rear]= value;
}
void deQueue(){
    if(front==-1){
        printf("Queue underflow\n");
        return;
    }
    if(front==rear){
        front= rear=-1;
    }else{
        front = (front+1)%SIZE;
    }

}
void display(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for(int i=front;i!=rear;i=(i+1)%SIZE){
        printf("[%d] ",queue[i]);
    }
    printf("[%d]\n",queue[rear]);
}
int main(){
    display();
    enQueue(10);
    enQueue(20);
    enQueue(30);
    display();
    deQueue();
    display();
     enQueue(40);
    enQueue(50);
    enQueue(60);
    display();
     enQueue(70);
     deQueue();
    enQueue(80);
    display();
    deQueue();
    display();
    deQueue();
    display();
}