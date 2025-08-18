#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * link;
} * top=NULL;

void push(int data){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));

    if(new_node==NULL){
        printf("Stack overflow!\n");
        exit(1);
    }

    new_node->data=data;
    new_node->link=NULL;

    new_node->link=top;
    top=new_node;
}
void pop(){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("List in stack is empty OR stack underflow!\n");
        exit(1);
    }
     int val=temp->data;
    top=temp->link;
    free(temp);
    temp=NULL;
    printf("Deleted data is %d\n", val);
}

int peek(){
    if(top==NULL){
        printf("Stack underflow!\n");
        exit(1);
    }
    else
    printf("Data is TOP is %d\n", top->data);
}

void display(){
    struct node *temp=top;
    printf("The stack elements are:\n ");
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp=temp->link;
    }
}
int main(){
    int choice, data;
    while(1){
        printf("\n----------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("\n----------------------------\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(1);
            default: printf("Wrong Choice!\n");
            break;
        }
    }
    return 0;
}