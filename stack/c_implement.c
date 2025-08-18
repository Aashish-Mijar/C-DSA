#include<stdio.h>
int MAXSIZE=7;
int stack[6];
int top=-1;

int isfull(){
    if(top==MAXSIZE)
    return 1;
    else 
    return 0;
}

int isempty(){
    if(top==-1)
    return 1;
    else
    return 0;
}

int push(int data){
    if(!isfull()){
        top=top+1;
        stack[top]=data;
    }
    else{
        printf("Could not insert data\n");
    }
}

int pop(){
    int data;
    if(!isempty()){
    data=stack[top];
    top=top-1;
    return data;
    }
}

int peek(){
    return stack[top];
}

int main(){

     push(23);
     push(45);
     push(76);
     push(56);

     
    printf("Data at the top is %d\n", peek());

    while(!isempty()){
        int data=pop();
        printf("Data is %d\n", data);
    }

    printf("Stack full: %s\n", isfull()? "True": "False");
    printf("Stack empty: %s\n", isempty()? "True": "False");

    return 0;
}

