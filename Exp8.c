/*Experiment 8: 

*/

#include <stdio.h>
#include <stdlib.h>

struct graph
{
	int data;
	struct graph *next;
}*root[10];

void insert(int i, int j)
{
	struct graph *q, *p = (struct graph *)malloc(sizeof(struct graph));
	p->data = j;
	p->next = NULL;
	if(root[i] == NULL)
	{
		root[i] = p;
	}
	else
	{
		q = root[i];
		while(q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}

void remove1(int adj, int j)
{
	struct graph *p, *q = root[adj];
	while(q->data!=j)
	{
		p = q;
		q=q->next;
	}
	p->next = q->next;
	free(q);
}

void deleteVertex(int j)
{
	struct graph *t, *q = root[j];
	int adj;
	while(q!=NULL)
	{
		t = q;
		adj = q->data;
		remove1(adj, j);
		q = q->next;
		free(t);
	}
	root[j] = NULL;
}

void displayGraph(int v)
{
	int i;
	struct graph *p = root[i];
	for(i=0;i<v;i++)
	{
		printf("\n");
		display(i ,root[i]);
	}
}

int main()
{
	int i, j, ch, v, vd;
	printf("Enter number of vertices: ");
	scanf("%d", &v);
	for(i=0;i<v;i++)
	{
		for(j=i+1;j<v;j++)
		{
			printf("Enter 0 or 1 for edge from %d to %d: ", i, j);
			scanf("%d", &ch);
			if(ch==1)
			{
				insert(i,j);
				insert(j,i);
			}
		}
	}
	displayGraph(v);
	printf("\nEnter the vertex to be deleted: ");
	scanf("%d", &vd);
	deleteVertex(vd);
	displayGraph(v);
	return 0;
}



