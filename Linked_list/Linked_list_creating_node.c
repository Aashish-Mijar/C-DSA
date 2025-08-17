#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
int main(){
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=95;
    newnode->link=NULL;

    head->link->link=newnode;

    newnode=malloc(sizeof(struct node));
    newnode->data=78;
    newnode->link=NULL;

    head->link->link->link=newnode;

    while(head->link!=NULL){
            printf("------Data in head is %d\n", head->data);
    printf("-------Address of head is %d\n", head);
    head=head->link;
    }
    return 0;
}
