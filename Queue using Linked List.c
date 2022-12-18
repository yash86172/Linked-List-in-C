#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;

void enqueue(int value)
{
    struct node * ptr;
    ptr = (struct node * ) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> next = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = ptr;
    } 
    else 
    {
        rear -> next = ptr;
        rear = ptr;
    }
    printf("Node is Inserted\n\n");
}


void dequeue() 
{
    if (front == NULL) 
    {
        printf("\nUnderflow\n");
    } 
    else 
    {
        struct node * temp = front;
        printf("Popped element is :%d\n",front -> data);
        front = front -> next;
        free(temp);
    }
}

void display()
 {
    struct node * temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty\n");
    } 
    else 
    {
        printf("The queue is \n");
        temp = front;
        while (temp) 
        {
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
    }
}

int main() 
{
    int choice, value;
    while (choice)
    {
        printf("\nEnter Choice:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", & choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                return 0;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
