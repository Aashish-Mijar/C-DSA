#include <stdio.h>
#include <stdlib.h>

// Linked List
void linked_list_example() {
    typedef struct Node {
        int data;
        struct Node* next;
    } Node;

    typedef struct LinkedList {
        Node* head;
    } LinkedList;

    void insert(LinkedList* list, int data) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->data = data;
        node->next = NULL;

        if (!list->head) {
            list->head = node;
        } else {
            Node* current = list->head;
            while (current->next) {
                current = current->next;
            }
            current->next = node;
        }
    }

    void print_list(LinkedList* list) {
        Node* current = list->head;
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }

    LinkedList list;
    list.head = NULL;

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    print_list(&list);  // Output: 1 2 3
}

// Stack
void stack_example() {
    typedef struct Stack {
        int* items;
        int top;
        int capacity;
    } Stack;

    void init_stack(Stack* stack, int capacity) {
        stack->items = (int*) malloc(sizeof(int) * capacity);
        stack->top = -1;
        stack->capacity = capacity;
    }

    void push(Stack* stack, int item) {
        if (stack->top < stack->capacity - 1) {
            stack->items[++stack->top] = item;
        }
    }

    int pop(Stack* stack) {
        if (stack->top >= 0) {
            return stack->items[stack->top--];
        } else {
            return -1;  // Stack is empty
        }
    }

    int peek(Stack* stack) {
        if (stack->top >= 0) {
            return stack->items[stack->top];
        } else {
            return -1;  // Stack is empty
        }
    }

    int is_empty(Stack* stack) {
        return stack->top == -1;
    }

    Stack stack;
    init_stack(&stack, 10);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("%d\n", peek(&stack));  // Output: 3
    printf("%d\n", pop(&stack));  // Output: 3
    printf("%d\n", is_empty(&stack));  // Output: 0
}

// Queue
void queue_example() {
    typedef struct Queue {
        int* items;
        int front;
        int rear;
        int capacity;
    } Queue;

    void init_queue(Queue* queue, int capacity) {
        queue->items = (int*) malloc(sizeof(int) * capacity);
        queue->front = 0;
        queue->rear = 0;
        queue->capacity = capacity;
    }

    void enqueue(Queue* queue, int item) {
        if ((queue->rear + 1) % queue->capacity != queue->front) {
            queue->items[queue->rear] = item;
            queue->rear = (queue->rear + 1) % queue->capacity;
        }
    }

    int dequeue(Queue* queue) {
        if (queue->front != queue->rear) {
            int item = queue->items[queue->front];
            queue->front = (queue->front + 1) % queue->capacity;
            return item;
        } else {
            return -1;  // Queue is empty
        }
    }

    int peek(Queue* queue) {
        if (queue->front != queue->rear) {
            return queue->items[queue->front];
        } else {
            return -1;  // Queue is empty
        }
    }

    int is_empty(Queue* queue) {
        return queue->front == queue->rear;
    }

    Queue queue;
    init_queue(&queue, 10);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    printf("%d\n", peek(&queue));  // Output: 1
    printf("%d\n", dequeue(&queue));  // Output: 1
    printf("%d\n", is_empty(&queue));  // Output: 0
}

// Recursion
void recursion_example() {
    int factorial(int n) {
        if (n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    printf("%d\n", factorial(5));  // Output: 120
}

// Searching
void searching_example() {
    int linear_search(int arr[], int size, int target) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;  // Not found
    }

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int result = linear_search(arr, size, target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
}

// Sorting
void sorting_example() {
    void bubble_sort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void print_array(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    int arr[] = {5, 2, 8, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);
    print_array(arr, size);  // Output: 1 2 3 5 8
}

int main() {
    linked_list_example();
    stack_example();
    queue_example();
    recursion_example();
    searching_example();
    sorting_example();

    return 0;
}