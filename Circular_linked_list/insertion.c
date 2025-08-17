#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
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
    printf("Enter your choice: ");
    scanf("%d", &choice);
    }

}

void insert_beg(int data){
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    printf("\nEnter a data you want to insert at beginning : ");
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

void insert_end(int data){
    struct node * new_node;
    new_node=malloc(sizeof(struct node));
    printf("\nEnter a data you want to add at end: ");
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

void insert_spec_pos(int data, int position){
    struct node *new_node, *temp;
    int pos;
   int i=1;
   printf("Enter position :");
   scanf("%d", &pos);
//    l=getlength();
//    if(pos<0 || pos>l);

if(pos==1){
    insert_beg(data);
}
else{
    new_node=malloc(sizeof(struct node));
    printf("Enter a data your want to insert at given position: ");
    scanf("%d", &new_node->data);
    new_node->next=NULL;
    temp=tail->next;

    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

}

 void display(){
  struct node *temp=tail;

    if(tail==NULL){
        printf("List is empty!");
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
    int data, position;
    create_cll(data);
     insert_beg(data);
     insert_end(data);
     insert_spec_pos(data, position);
    display();

    return 0;
}