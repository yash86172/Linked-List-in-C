#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int ele;
    struct node* next;
}node;

node* top=NULL;

int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void peek()
{
    if(isEmpty(top))
    {
        printf("Stack is Empty\n");
        return;
    }
    else
        printf("Top element is:%d\n",top->ele);
}

void push(int n)
{
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->ele=n;
    if(top==NULL)
    {
        top=temp;
        top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

void pop()
{
    node* temp;
    if(isEmpty(top))
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        temp=top;
        top=top->next;
        printf("Removed element is:%d\n",temp->ele);
        free(temp);
    }
}

void display(node* ptr)
{
    if(isEmpty(top))
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ",ptr->ele);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int c,num;
    while(1)
    {
        printf("1.PUSH 2.POP 3.PEEK 4.DISPLAY:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("Enter the number:");
                    scanf("%d",&num);
                    push(num);
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display(top);
                    break;
            default:exit(0);
        }
    }
    return 0;
}
