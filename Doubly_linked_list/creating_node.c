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
struct node * insert_spec_pos(struct node *head, int data, int position){
    int pos, i=1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos==1){
        insert_beg(head, data);
    }
    else{
        struct node *new_node, *temp=head;
        new_node=malloc(sizeof(struct node));
        printf("Enter a data you want to insert at %dth position:", pos);
        scanf("%d", &new_node->data);

        while(1<pos-1){
            temp=temp->next;
        }
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next->prev=new_node;
        temp->next=new_node;
    }
}
int main(){
    int data, position;
struct node *head;
head=createNode(head, data);
head=insert_beg(head, data);
insert_last(head, data);
insert_spec_pos(head, data, position);

while(head!=NULL){
printf("Data is %d\n",head->data);
head=head->next;
}
    return 0;
}
