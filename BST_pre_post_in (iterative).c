#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node
{
	int n;
	struct node* lc;
	struct node* rc;
};

struct tree
{
	struct node* root;
};

struct node* insert(struct node* p,int k)
{
	if(p==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node*));
		p->n=k;
		p->lc=NULL;
		p->rc=NULL;
		return p;
	}

	if(k<=(p->n))
		p->lc=insert(p->lc,k);
	else
		if(k>(p->n))
			p->rc=insert(p->rc,k);

	return p;
}

void displayPreorder(struct node* p)
{
	stack<struct node*> s;
	s.push(p);
	while(!s.empty())
	{
		struct node* p=s.top();
		s.pop();
		printf("%d ",p->n);
		
		if((p->rc) != NULL)s.push(p->rc);
		if((p->lc) != NULL)s.push(p->lc);
	}
}

void displayInorder(struct node* p)
{
	

	stack<struct node*> s;

	while((p!=NULL) || (!s.empty()))
	{
		while(p!= NULL)
		{
			s.push(p);
			p=p->lc;
		}
		
		struct node* temp=s.top();
		s.pop();
		printf("%d ",temp->n);
		p=temp->rc;
	}
}


void displayPostorder(struct node* p)
{
	stack<struct node*> s;
	stack<struct node*> d;
	s.push(p);
	while(!s.empty())
	{
		struct node* p=s.top();
		s.pop();
		d.push(p);
		
		if((p->rc) != NULL)s.push(p->lc);
		if((p->lc) != NULL)s.push(p->rc);
	}
	while(!d.empty())
	{
		printf("%d ",d.top()->n);
		d.pop();
	}
}

int main()
{
	int x,y;
	struct node* root=NULL;
	while(1)
	{
		scanf("%d",&x);

		if(x==1)
		{
			scanf("%d",&y);
			root=insert(root,y);
		}

		if(x==2) { displayPreorder(root); printf("\n"); }

		if(x==3){ displayInorder(root); printf("\n"); }
		
		if(x==4){ displayPostorder(root); printf("\n");}

		if(x==5)exit(0);

	}

}



/* TEST CASE 
 
insert number x :   1 x
Display PreOrder :  2
Display InOrder :   3
Display PostOrder : 4
1 50
1 25
1 100
1 15
1 35
1 75
1 150
1 60
1 90
1 125
1 180
2
5
50 25 15 35 100 75 60 90 150 125 180 
3
15 25 35 50 60 75 90 100 125 150 180 
4
15 35 25 60 90 75 125 180 150 100 50 
Observation : InOrder gives the sorted list of numbers
*/


