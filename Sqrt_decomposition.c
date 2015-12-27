#include <stdio.h>

void update(int p,int x,int A[],int B[],int K)
{
	B[p/K]=B[p/K]-A[p]+x;
	A[p]=x;
}

int query(int l,int r,int A[],int B[],int K)
{
	int x=l;
	int sum=0;


	while((x%K)&&(x<=r))
		sum+=A[x++];


	while((x+K-1)<=r)
	{
		sum+=B[x/K];
		x+=K;
	}

	while(x<=r)
		sum+=A[x++];

	return sum;
}


int main()
{
	int N=16; // setting array size
	int K=4; // setting bucket size
	int A[N];
	int B[K];
	int i;

	for(i=0;i<N;i++)
		A[i]=0;

	for(i=0;i<K;i++)
		B[i]=0;


	update(0,1,A,B,K);
	update(1,2,A,B,K);
	update(2,0,A,B,K);
	update(3,7,A,B,K);
	update(4,4,A,B,K);
	update(5,2,A,B,K);
	update(6,2,A,B,K);
	update(7,0,A,B,K);
	update(8,1,A,B,K);
	update(9,3,A,B,K);
	update(10,1,A,B,K);
	update(11,4,A,B,K);
	update(12,5,A,B,K);
	update(13,2,A,B,K);
	update(14,0,A,B,K);
	update(15,1,A,B,K);

	for(i=0;i<N;i++)
		printf("%d\t",A[i]);

	printf("\n");

	for(i=0;i<K;i++)
		printf("%d\t",B[i]);

	printf("\n");


	update(6,5,A,B,K);

	printf("query ( 2,14)  :  %d\n",query(2,14,A,B,K));
}




