#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node * createNode(struct node * head, int data){
    struct node *new_node, *temp=head;
    new_node=malloc(sizeof(struct node ));
    printf("Enter your data: ");
    scanf("%d",&new_node->data);
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
}

struct node * insert_beg(struct node *head, int data){
    struct node *temp;
    struct node *new_node=malloc(sizeof(struct node));
    printf("Enter the data you want to insert at beginning: ");
    scanf("%d", &new_node->data);
    new_node->next=temp;
    temp->prev=new_node;
    head=new_node;
    return head;
}

struct node * insert_last(struct node *head, int data){
    struct node *temp=head;
    struct node *new_node=malloc(sizeof(struct node));
    printf("Enter the data you want to insert at last: ");
    scanf("%d", &new_node->data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    new_node->prev=temp;
    temp->next=new_node;
    temp=head;
    return head;
}
struct node * del_from_beg(struct node *head){
    struct node* temp;
    if(head==NULL){
        printf("List is empty.");
    }
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        temp=NULL;
    }
    return head;
}

struct node * del_from_last(struct node *head){
    struct node *temp=head;
    struct node *temp2;
    if(head==NULL){
        printf("List is empty");
    }
    else{
    while(temp->next!=NULL){
          temp2=temp;
        temp=temp->next;
    }
    if(temp2==NULL){
        free(temp);
        head=NULL;
    }
    else{
    free(temp);
    temp=NULL;
      temp2->next=NULL;
    }
    }
    return head;
}
int main(){
    int data;
struct node *head;
head=createNode(head, data);
head=insert_beg(head, data);
insert_last(head, data);

head=del_from_beg(head);
head=del_from_last(head);

while(head!=NULL){
printf("Data is %d\n",head->data);
head=head->next;
}
    return 0;
}
