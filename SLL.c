#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void append(struct node*,int);
void addAtBeg(struct node*,int);
void addAfter(struct node*,int,int);
void del(struct node*,int);
void reverse(struct node*);
void checkLoop(struct node*);
void printList(struct node*);
int main()
{
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    append(head,10);
    append(head,20);
    printList(head);
    return 0;
}
void printList(struct node* q)
{
    while(q!=NULL)
    {
        printf("%d",q->data);
        q=q->next;
    }
}
void append(struct node *q,int data)
{
    struct node *temp,*r;
    if(q->next == NULL)
    {
        q->data=data;
        q->next=NULL;
    }
    else
    {
        temp=q;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        r=(struct node*)malloc(sizeof(struct node));
        r->data=data;
        r->next=NULL;
        temp->next=r;
    }
}
