#include <stdio.h>
#include <stdlib.h>

struct node
{
	int n;
	struct node* next;
};

struct list
{
	struct node* head;
};

struct Graph
{
	int V;
	struct list* array;
};

struct Graph create(int V)
{
	struct Graph g;
	g.V=V;
	g.array=(struct list*)malloc(V*sizeof(struct list*));
	int i;
	for(i=0;i<V;i++)
		g.array[i].head=NULL;
	return g;
}

void addEdge(struct Graph g,int s,int d)
{
	struct node* x=malloc(sizeof(struct node*));
	(*x).n=d;
	(*x).next=g.array[s].head;
	g.array[s].head=x;
}

void display(struct Graph g)
{
	int i;
	for(i=0;i<g.V;i++)
	{
		printf("%d\t",i);
		struct node* x=g.array[i].head;
		while(x!=NULL)
		{
			printf("%d ",(*x).n);
			x=(*x).next;
		}

		printf("\n");
	}
}

int main()
{
	struct Graph g=create(3);
	addEdge(g,1,2);
	addEdge(g,0,1);
	addEdge(g,1,0);
	display(g);
}

	








