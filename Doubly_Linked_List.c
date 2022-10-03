#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void create();
void display();
void insert();
void delete();
void del1();
void del2();
void del3();

//GLOBAL 
struct node *head=0,*newnode,*temp;
void main()
{
    int i,choice;
    while(i != 0)
    {
        create();
        printf("Do you want to contonue:");
        scanf("%d",&i);

    }
    printf("\n Enter the choice :");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        {
            insert();
            display();
            break;
        }

        case 2:
        {
            delete();
            break;
        }

        default:
        {
            printf("\n Invalid cridientials");
        }
    }
}

void create()
{
    newnode =(struct node *)malloc(sizeof(struct node));
    printf("Enter the node: ");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==NULL)
    {
        head = newnode;
        temp = newnode;
    }

    else
    {
        temp->next = newnode;
        temp->prev = newnode;
        temp= newnode;
    }
}

void display()
{
temp = head;
while(temp != NULL)
{
    printf("%d \n", temp->data);
    temp = temp->next;
}
}

void insert()
{
    struct node *hello;
    int data,c,element;
    printf("\nEnter data you want to insert: ");
    scanf("%d", &data);
    printf("Enter the choice :");
    scanf("%d", &c);
    switch(c)
    {
        case 1 :
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->prev = NULL;
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
            break;
        }

        case 2 :
        {
            printf("Enter the element in which where you want to insert : ");
            scanf("%d",&element);
            newnode = (struct node *)malloc(sizeof(struct node));
            hello =temp = head;
            while(temp->next != NULL)
            {
                if(temp->data == element)
                {
                    newnode->data = data;
                    newnode->prev = temp;
                    newnode->next = temp->next;
                    temp->next = newnode;
                    break;
                }


                temp = temp->next;
                if(hello == NULL)
                {
                    printf("The element does not exist");
                }
            }
            break;
        }

        case 3 :
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
                if(temp->next == NULL)
                {
                    newnode->data = data;
                    newnode->next = NULL;
                    newnode->prev = temp;
                    temp->next = newnode;
                    break;
                }

            }
            break;
        }

        default :
        {
            printf("Invalid");
            return;
        }
    }


}

void delete()
{
    int choice;

    printf("\nEnter the delete choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1 :
        {
            del1();
            break;
        }

        case 2 :
        {
            del2();
            break;
        }

        case 3 :
        {
            del3();
            break;
        }

        default :
        {
            printf("Invalid cridientials");
        }
    }
}

void del1()
{
    struct node *dell;
    dell = head;
    head = head->next;
    free(dell);
    head->prev = NULL;
    display();
}

void del2()
{
    struct node *current , *swap1 , *swap2 , *swap3;
    int data;
    printf("Enter the data want to delete :");
    scanf("%d", &data);
    temp = head;
    while (temp->next != NULL)
    {
        if(temp->data == data)
        {
            printf("\n The data is available");
            swap1 = swap2 = swap3 = temp;
            current->next = swap1->next;
            swap3 = swap3->next;
            swap3->prev = current;
            free(swap2);
            display();
            break;
        }
        current = temp;
        temp= temp->next;

        if(temp->next == NULL)
        {
            printf("\n The data does not exist");
        }
    }
}

void del3()
{
    struct node *previous;
    temp = head;
    while(temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }

    previous->next = NULL;
    free(temp);
    display();
}