#include <stdio.h>
int count1=0;
int count2=0;
int count3=0;

int compare1=0;
int compare2=0;
int compare3=0;


	
void selectionSort(int X[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			compare1++;
			if(X[i]>X[j])
			{
				int temp=X[i];
				X[i]=X[j];
				X[j]=temp;
				count1++;
			}
		}
	}
}

void insertionSort(int Y[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		int temp=Y[i];
		j=i-1;
		while(j>=0&&Y[j]>temp)
		{
			compare2++;
			Y[j+1]=Y[j];
			j--;
			count2++;
		}
		Y[j+1]=temp;
	}
}

void bubbleSort(int Z[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			compare3++;
			if(Z[j]>Z[j+1])
			{
				int temp=Z[j];
				Z[j]=Z[j+1];
				Z[j+1]=temp;
				count3++;
			}
		}
	}
}


int main()
{
	int n,i;
	scanf("%d",&n);
	int A[n],X[n],Y[n],Z[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",A+i);
		X[i]=A[i];
		Y[i]=A[i];
		Z[i]=A[i];
	}
	
	selectionSort(X,n)
	insertionSort(Y,n);
	bubbleSort(Z,n);
	
	printf("Bubble Sort\n");

		
	printf("No. of Swaps : %d\n",count3);
	printf("No. of Comparisons : %d\n",compare3);
	
	
	printf("Selection Sort\n");

		
	printf("No. of Swaps : %d\n",count1);
	printf("No. of Comparisons : %d\n",compare1);
	
	
	printf("Insertion Sort\n");
	

		
	printf("No. of Swaps : %d\n",count2);
	printf("No. of Comparisons : %d\n",compare2);
	

	
	return 0;
}
	
