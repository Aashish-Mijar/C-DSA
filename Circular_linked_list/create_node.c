#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
} *head, *tail;

//------------using head and tail pointer--------
void create_cll(int data){
    int choice=1;
struct node *new_node;
head=NULL;
while(choice==1){
new_node=malloc(sizeof(struct node));
printf("Enter a data: ");
scanf("%d", &new_node->data);

if(head==NULL){
    head=tail=new_node;
}
else{
    tail->next=new_node;
    tail=new_node;
}
tail->next=head;
printf("Enter your choice: ");
scanf("%d", &choice);
}
}

int main(){
    int data;
    create_cll(data);

    // while(head->next!=tail->next)
    do{
        printf("Data is %d\n", head->data);
        head=head->next;
    }
    while(head!=tail->next);
    // printf("Data is %d\n", head->data);
    return 0;
}