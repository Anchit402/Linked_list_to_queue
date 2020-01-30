#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int *link;
}*front = NULL,*rear = NULL;//starting with front and rear being empty as in queue.
main()
{
    while(1)//using infinite loop as we dont know what and how many times the user wants the do which operation.
    {
        printf("\nEnter 1 for Inserting node: ");
        printf("\nEnter 2 for Deleting node: ");
        printf("\nEnter 3 for Finding a node");
        printf("\nEnter 4 for displaying the stack: ");
        printf("\nEnter 5 for exiting: \n");
        int n;
        scanf("%d",&n);
        if(n == 1)
            insert();//calling insert function.
        else if(n == 2)
            delete();//calling delete function
        else if(n == 3)
            find();//calling find function
        else if(n == 4)
            display();//calling display function
        else if(n == 5)
            break;//breaking the loop as soon as the user wants
    }
}
void insert()
{
    printf("Enter no you want to insert: ");
    int n;
    scanf("%d",&n);
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));//dynamically allocation memory for temp
    temp->data = n;
    temp->link = NULL;
    if(front == NULL && rear == NULL)//checking weather the queue is empty
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->link = temp;//if not empty, previous node's link part will change from NULL to pointer of next node.
        rear = temp;
    }
}
void delete()
{
    if(front == NULL)
        printf("Queue underflow");
    else
    {
        struct node *temp = front;
        front = temp->link;
        free(temp);//freeing up the memory created by the element.
    }
}
void find()
{
    printf("\nEnter node to be found: ");
    int n;
    int count = 0;
    int c = 0;
    scanf("%d",&n);
    struct node *temp = front;
    while(temp->link!=NULL)//checking till last node,excluding last node
    {
        if(temp->data == n)
        {
            printf("%d found. It is in %d node",n,count);
            c = 1;
            break;
        }
        count++;
        temp = temp->link;
    }
    if(temp->link == NULL)//checking in last node
    {
        if(temp->data == n)
            c = 2;
        if(c == 2)
            printf("%d found. It is in %d node",n,count);
        else
            printf("Not Found");
    }

}
void display()
{
    if(front == NULL)
        printf("Queue is empty");
    else
    {
        struct node *temp = front;
        while(temp->link!=NULL)//print till last node,excluding last node.
        {
            printf("\n%d",temp->data);
            temp = temp->link;
        }
        printf("\n%d",temp->data);//printing in last node
    }
}
