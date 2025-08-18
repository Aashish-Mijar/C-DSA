#include<stdio.h>
 int MAXSIZE=5;
 int stack[5];
 int top=-1;

 int isEmpty(){
    if(top==-1)
    return 1;
    else
    return 0;
 }

 int isFull(){
    if(top==MAXSIZE)
    return 1;
    else
    return 0;
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

 int pop(){
    if(!isEmpty()){
    int data;
    data=stack[top];
    top=top-1;
    return data;
    }
 }

 int main(){
    int i;
    push(23);
    push(45);
    push(67);

    for(i=0; i<4; i++){
        printf("Data is %d\n",stack[i]);
    }

    pop();

    printf("------Data after poped top data-------\n");
    while(!isEmpty()){
        int data=pop();
        printf("The data is %d\n", data);
    }
 }