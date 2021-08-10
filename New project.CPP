#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream infile ("file data.txt");
int Mileage[100], Years[100], Sequence[100], PNumber[100], NewSeq[100];
int i, j, temp;

struct Node
{
    string x;
    struct Node *next;
};

struct Head
{
    int count;
    struct Node *front;
    struct Node *rear;
    struct Node *p;
};

struct customer
{
     int p;
     string n;
};

struct customer record[11];

struct Head *queue;
struct Head *head;

void Queue_create()
{
    queue = (struct Head*)malloc(sizeof(struct Head));
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}


void Head_create()
{
    head = (struct Head*)malloc(sizeof(struct Head));
    head->p = NULL;
    head->count = 0;
}


void enqueue(string value)
{
    struct Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));
    node->next = NULL;
    node->x = value;

    if(queue->count == 0)
    {
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

void push_stack(string value)
{
    struct Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));
    node->x = value;
    node->next = head->p;
    head->p = node;
    head->count++;
}


void file_read()
{
    for(i=0; i<11; i++)
    {
        infile >> Mileage[i] >> Years[i] >> Sequence[i];
    }
}


void priority_number()
{
    for(i=0; i<11; i++)
    {
        record[i].p = ( ( Mileage[i]/1000 ) + ( Years[i]-Sequence[i] ) );
    }

    record[0].n = "Bryan Devaux";
    record[1].n = "Amanda Trapp";
    record[2].n = "Baclan Nguyen";
    record[3].n = "Sarah Gilley";
    record[4].n = "Warren Rexroad";
    record[5].n = "Jarge Gonzales";
    record[6].n = "Paula Hung";
    record[7].n = "Lou Mason";
    record[8].n = "Steve Chu";
    record[9].n = "Dave Lightfool";
    record[10].n = "Joanne Brown";

    //Short priority number data.

    for(i=0;i<11;i++)
	{
		for(j=i+1;j<11;j++)
		{
			if(record[i].p<record[j].p)
			{
				int temp1;
				string temp2;

				temp1  = record[i].p;
				temp2  = record[i].n;
				record[i].p=record[j].p;
				record[i].n=record[j].n;
				record[j].p=temp1;
				record[j].n=temp2;
			}
		}
	}

    for(i=0; i<11; i++)
    {
        cout<<record[i].n<<"           Priority number: "<<record[i].p<<endl;
    }


    printf("\n");

	for(i=0; i<11; i++)
    {
        enqueue(record[i].n);
        push_stack(record[i].n);

    }
}

void waiting_customers_list()
{
    struct Node *temp;
    temp = queue->front;
    while(temp!=NULL)
    {

        cout<<temp->x<<endl;
        temp = temp->next;
    }
}

void took_ticket_letter()
{

    struct Node *temp;
    temp = head->p;
    while(temp!=NULL)
    {
       cout<<temp->x<<endl;
        temp = temp->next;
    }
}


int main()
{
    struct customer record[11];



    Queue_create();
    Head_create();

    file_read();
    priority_number();

    printf("\nPriority Sequence of waiting customers: \n\n");
    waiting_customers_list();

    printf("\n");

    printf("\nCustomers detail who took flight ticket letter: \n\n");
    took_ticket_letter();


    printf("\n");
}



