#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *prev_link;
        struct node *next_link;
    };
int main(){
    int choice, item;

    // struct node *head;
    do{
        printf("\nEnter the data you want to insert: \n");
        scanf("%d\n",&item);
    }

    return 0;
}