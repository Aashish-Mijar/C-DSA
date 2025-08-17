#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
} *tail;

void create_cll(int data){
    int choice=1;
    struct node *new_node;
    tail=NULL;
    while(choice==1){
    new_node=malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d", &new_node->data);

    if(tail==NULL){
        tail=new_node;
        tail->next=new_node;
    }
    else{
        new_node->next=tail->next;
        tail->next=new_node;
        tail=new_node;
    }
    printf("Enter your choice(0 to stop, 1 to continue): ");
    scanf("%d", &choice);    
}
}

void add_beg(int data){
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    printf("\nEnter a data you want to insert at beginning: ");
    scanf("%d", &new_node->data);
    new_node->next=NULL;

    if(tail==NULL){
        tail=new_node;
        tail->next=new_node;
    }
    else{
        new_node->next=tail->next;
        tail->next=new_node;
    }
}

void add_end(int data){
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    printf("\nEnter a data you want to insert at end: ");
    scanf("%d", &new_node->data);
    new_node->next=NULL;

    if(tail==NULL){
        tail=new_node;
        tail->next=new_node;
    }
    else{
        new_node->next=tail->next;
        tail->next=new_node;
        tail=new_node;
    }
}

void add_spec_pos(int data, int pos){
    int position, i=1;
    printf("Enter a position: ");
    scanf("%d", &position);
    struct node *new_node, *temp;
    if(pos==1){
        add_beg(data);
    }
    else{
    new_node=malloc(sizeof(struct node));
    printf("Enter a data you want to insert at given position : ");
    scanf("%d", &new_node->data);
    new_node->next=NULL;
    temp=tail->next;

    while(1<pos-1){
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    }
}

void del_beg(){
    struct node *temp;
    temp=tail->next;
    if(tail==NULL){
        printf("List is empty!");
    }
    else{
        tail->next=temp->next;
        free(temp);
        temp=NULL;
    }
}

void del_end(){
    struct node* current, *previous;
    current=tail->next;
    if(tail==NULL){
        printf("list is empty!");
    }
    else if(current->next==current){
        tail=NULL;
        free(current);
    }
    else{
        while(current->next!=tail->next){
            previous=current;
            current=current->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(current);
        current=NULL;
    }
}

void del_spec_pos(){
     struct node* current, *nextnode;
     int position, i=1;
     current=tail->next;
     printf("Enter a position: ");
     scanf("%d", &position);

     if(position<1){
        printf("Invalid position!");
     }
     else if(position==1){
        del_beg();
     }
     else{
        while(i<position-1){
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
        nextnode=NULL;
     }
}


void display(){
    struct node *temp=tail;
    if(tail==NULL){
        printf("list is empty!");
    }
    else{
        temp=temp->next;
    }

    while(temp->next!=tail->next){
        printf("Data is %d\n", temp->data);
        temp=temp->next;
    }
    printf("Data is %d\n", temp->data);
}

int main(){
    int data, pos;
    create_cll(data);
    add_beg(data);
    add_end(data);
    // add_spec_pos(data, pos);
    del_beg();
    del_end();
    del_spec_pos();
    display();

    return 0;
}