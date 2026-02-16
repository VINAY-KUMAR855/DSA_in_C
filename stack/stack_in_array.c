#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;
// insert
void push(int value){
    if(top==SIZE-1){
        printf("Stack overflow\n");
        return;
    }
    top ++;
    stack[top] = value;
    printf("%d pushed into stack\n",value);
}
// delete
void pop(){
    if (top==-1){
        printf("Stack underflow\n");
        return; 
    }
    int removed = stack[top];
    top--;
    printf("%d popped from stack\n",removed);
}
// see the top element
void peek(){
    if (top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n",stack[top]);

}
//display
void display(){
    if (top==-1){
        printf("Stack is empty\n");
        return;
    }
    int temp = top;
    printf("Stack: ");
    while(temp!=-1){
        printf("[%d] ",stack[temp]);
        temp--;
    }
    printf("\n");
}
int main(){
    int optn, value;
    do{
        printf("Stack operations:\n1.Push element\n2.Pop element\n");
        printf("3. Display stack \n4.Exit\n");
        scanf("%d",&optn);
        if(optn==1){
            printf("Enter element: ");
            scanf("%d",&value);
            push(value);
        }else if(optn==2){
            pop();
        }else if(optn==3){
            display();
        }
    }while(optn!=4);
    // push(10);
    // push(20);
    // push(30);

    // display();
    // peek();

    // pop();
    // display();

    // push(40);
    // push(50);
    // push(60);   
    // push(70);   // overflow test

    // display();
    return 0;
}



