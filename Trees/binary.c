    #include <stdio.h>
    #include <stdlib.h>
    struct node
    {
        int data;
        struct node *left, *right;
    };
    struct node *create()
    {
        int data;
        struct node *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data(-1 for no node)");
        scanf("%d", &data);
        if (data == -1)
        {
            return 0;
        }
        newNode->data = data;
        printf("Enter left child of %d\n", data);
        newNode->left = create();

        printf("Enter right child of %d\n", data);
        newNode->right = create();

        return newNode;
    }

    int main()
    {
        create();
        return 0;
    }