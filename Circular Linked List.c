#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;


void createNode(int val,node** h)
{
     node*ptr;
     if(*h==NULL)
     {
        ptr=(node*)malloc(sizeof(node));
        ptr->data=val;
        ptr->next=ptr;
        *h=ptr;
     }
     else
 printf("List already exists\n");
  }
  void addFront(int val,node**h)
  {
  if(*h!=NULL)
  {
  node*ptr, *prev=*h;
 ptr=(node*)malloc(sizeof(node));
 while(prev->next!=*h)
 prev=prev->next;
 prev->next=ptr;
 ptr->data=val;
 ptr->next=*h;
*h=ptr;
 }
 else
 createNode(val,h);
 }
 void addEnd(int val, node** h)
 {
 if(*h!=NULL)
 {
 node* ptr, *tail=*h;
 ptr=(node*)malloc(sizeof(node));
 ptr->data=val;
 while(tail->next!=*h)
tail=tail->next;
 tail->next=ptr;
 ptr->next=*h;
 }
 else
 createNode(val,h);
 }
 void addBetween(int val, node **h, int pos)
 {
 if(pos==1)
 {
 addFront(val,h);
 return;
 }
 int i=1;
 node *prev=*h, *ptr;
 while(i++<pos-1 && prev->next!=*h)
 prev=prev->next;
 if(i<pos)
 {
 printf("Position out of range");
 return;
 }
 if(prev->next==*h)
 {
 addEnd(val,h);
 return;
 }
 
 ptr=(node*)malloc(sizeof(node));
 ptr->data=val;
 ptr->next=prev->next;
 prev->next=ptr;
 }
 void delFront(node**h)
 {
 if((*h)->next==*h)
 {
 free(*h);
 *h=NULL;
 }
 else
 {
 node*tail=*h,*ptr;
 while(tail->next!=*h)
 tail=tail->next;
 tail->next=(*h)->next;
 ptr=*h;
 *h=(*h)->next;
 printf("\nDeleted value is:%d\n",(ptr->data));
 free(ptr);
 }
}
 void delLast(node **h)
 {
 if((*h)->next==*h)
 {
 free(*h);
 *h=NULL;
 }
 else
 {
node*tail=*h;
 while(tail->next->next!=*h)
 tail=tail->next;
 printf("\nDeleted value is:%d\n",(tail->next->data));
 free(tail->next);
 tail->next=*h;
}
 }
 void delBetween(node** h, int pos)
 {
 if(pos==1)
 {
 delFront(h);
 return;
 }
 node* prev=*h, *ptr;
 int i=1;
 while(i++<pos-1 && prev->next!=*h)
 prev=prev->next;
 if(i<pos)
 {
 printf("Position out of range");
 return;
 }
 if(prev->next==*h)
 {
 delLast(h);
 return;
 }
 ptr=prev->next;
 prev->next=prev->next->next;
 printf("\nDeleted value is:%d\n",(ptr->data));
 free(ptr);
 }
 void displayList(node*h)
 {
 node *ptr=h;
 int c=0;
 do
 {
 printf("%d\t",ptr->data);
 ptr=ptr->next;
c++;
 }while(ptr!=h);
 printf("\nThe list has %d elements",c);
 }
 int main()
{
 node*h=NULL;
 int val,pos;
 while(1)
 {
printf("Enter 1 to create the list\n2 to insert an element at the front\n3 to insert element at the end\n4 to insert element at any intermediate position");
 printf("\n5 to delete an element from the front\n6 to delete an element from the end\n7 to delete an element from any intermediate position");
 printf("\n8 to display the list elements\nAny other key to exit");
 int choice;
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: printf("Enter the value");
 scanf("%d",&val);
 createNode(val,&h);
 break;
 case 2: printf("Enter the value");
 scanf("%d",&val);
 addFront(val,&h);
 break;
 case 3: printf("Enter the value");
 scanf("%d",&val);
 addEnd(val,&h);
 break;
 case 4: printf("Enter the position");
 scanf("%d",&pos);
 printf("Enter the value");
 scanf("%d",&val);
 addBetween(val,&h,pos);
 break;
 case 5: delFront(&h);
 break;
 case 6: delLast(&h);
break;
 case 7: printf("Enter the position");
 scanf("%d",&pos);
 delBetween(&h,pos);
 break;
 case 8: displayList(h);
 break;
 default: return 0;
 }
 }
 return 0;
 }
 
