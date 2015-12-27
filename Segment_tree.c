#include <stdio.h>

void build(int t[],int n)
{
	int i;
	for(i=n-1;i>0;i--)
		t[i]=t[2*i]+t[2*i+1];
}

void modify(int p,int x,int t[],int n)
{
	p+=n;
	t[p]=x;
	while(p>1)
	{
		t[p/2]=t[p]+t[p^1];
		p>>=1;
	}
	
}

int query(int l,int r,int t[],int n)
{
	int sum=0;
	l+=n;
	r+=n;
	while(l<r)
	{
		if(l&1)
		{
			sum+=t[l];
			l++;
		}
		if(!(r&1))
		{
			sum+=t[r];
			r--;
		}
		l>>=1;
		r>>=1;
	}
	sum+=t[l];

	return sum;
}



int main()
{
	int n,i;
       	printf("Array size : ");	
	scanf("%d",&n);



	int t[2*n];

	printf("Enter array elements\n");
	for(i=n;i<2*n;i++)
		scanf("%d",&t[i]);

	build(t,n);


	for(i=1;i<2*n;i++)
		printf("%d  ",t[i]);

	printf("\nNow enter queries\n");

	while(1)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(x==1)
		{
			modify(y,z,t,n);
		}
		else
			printf("query [%d,%d] :  %d\n",y,z,query(y,z,t,n));
	}
}













