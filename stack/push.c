#include<stdio.h>
int MAXSIZE=8;
int stack[8];
int top=-1;


int isFull(){
    if(top==MAXSIZE){
        printf("Stack is full\n");
        return 1;
    }
    else return 0;
}

int push(int data){
    if(!isFull()){
    top=top+1;
    stack[top]=data;
    }
    else{
        printf("Could not insert\n");
    }
}

int peek(){
    return stack[top];
}

int main(){
    int i;
    push(25);
    push(5);
    push(2);
    push(252);
    push(252);
    push(252);
    push(22);
    
    printf("Elements of Stack :\n");
    for(i=0; i<8; i++){
        printf("%d\n",stack[i]);
    }

printf("\nElement of top most is:%d\n", peek());

    return 0;
}