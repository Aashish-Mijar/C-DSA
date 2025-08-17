#include<stdio.h>
#include<stdlib.h>
struct node{ 
    int data;
    struct node *prev;
    struct node *next;
};

struct node * create_node(struct node * head, int data){
    struct node *temp;
    struct node *new_node=malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d", &new_node->data);
    new_node->prev=NULL;
    new_node->next=NULL;

    if(head==NULL){
        head=temp=new_node;
    }
    else{
        temp->next=new_node;
        new_node->prev=temp;
        temp=new_node;
    }
return head;
}

struct node *add_beg(struct node *head, int data){
    struct node *temp=head;
    struct node *new_node=malloc(sizeof(struct node));
    printf("Enter a data you want to add at beginning : ");
    scanf("%d", &new_node->data);

    new_node->next=temp;
    temp->prev=new_node;
    head=new_node;
    return head;
}

struct node *add_last(struct node *head, int data){
    struct node *temp=head;
    struct node *new_node=malloc(sizeof(struct node));
    printf("Enter a data you want to add at last: ");
    scanf("%d", &new_node->data);

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
    temp=head; 
    return head;
}
int main(){
     int data;
    struct node *head;
    head=create_node(head, data);
    head=add_beg(head, data);
    head=add_last(head, data);

    while(head!=NULL){
        printf("Data is %d\n", head->data);
        head=head->next;
    }

    return 0;
}