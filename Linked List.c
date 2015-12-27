#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {   int age;	 char name[15];		 int id_no; }  Student;

struct node;	typedef struct node NODE;	typedef NODE *link;

struct node {	Student data;	link next; } ;


typedef struct {	link head;	int size;	}	List;



List create()
{
	List l;
	l.head=NULL;
	l.size=0;
	return l;
}

List insert(Student s,int position,List L)
{
	if(position>L.size+1){	printf("Invalid position"); 	return L;	}

	NODE *temp=(struct node*)malloc(sizeof(NODE));
	(*temp).data.age=s.age;		strcpy((*temp).data.name,s.name); 		(*temp).data.id_no=s.id_no;

	if(position==1)
	{
	(*temp).next=L.head;
	L.size++;
	L.head=temp;
	return L;
	}
	int c=1;
	link p=L.head;
	while(++c)
	{
	 if(c==position){	(*temp).next=(*p).next;		(*p).next=temp; 	L.size++;	return L;	}
	 else p=(*p).next;
	}
}


List delete(char *c,List L)
{
	link temp=L.head;
	if(temp==NULL){ printf("List is empty"); return L;}
	if(strcasecmp((*temp).data.name,c)==0){		L.head=(*temp).next;	L.size--;	return L;}
	while((*temp).next!=NULL)
	{	link prev=temp;		temp=(*temp).next;	
		if(strcasecmp((*temp).data.name,c)==0){		(*prev).next=(*temp).next;	L.size--;	return L;}
	}
	printf("Element not found");
	return L;
}


link search(char *c,List L)
{
	link temp=L.head;
	if(temp==NULL) {	printf("List is empty\n");	return NULL;}
	while(temp!=NULL)	if(strcasecmp((*temp).data.name,c)==0){ printf("Element found\n"); return temp; } else temp=(*temp).next;
	printf("Element not found\n");
	return NULL;
}



void display(List l)
{
	if(l.head==NULL){printf("List is empty");return;}
	printf("\n\n AGE \t NAME \t ID_NO \n");
	link temp;
	temp=l.head;
	while(temp!=NULL)
	{
		printf("%d \t %s \t %d \n",(*temp).data.age,(*temp).data.name,(*temp).data.id_no);
		temp=(*temp).next;
	}
}


main()
{

	List L;
	L=create();
	int choice;
	while(1)
	{
		
		printf("\n 1:INSERT \t 2:DELETE \t 3:SEARCH \t 4:DISPLAY \t");
		scanf("%d",&choice);
		char b[15];
		switch(choice)


		{
			case 1:	;Student s;	int pos;
				printf("\n Enter \t age \t name \t id_no \t Position to enter \n");
				scanf("%d",&s.age);		scanf(" %[^\n]s",s.name);		scanf("%d",&s.id_no);
				scanf("%d",&pos);
				L=insert(s,pos,L);
				break;

			case 2:		printf("Enter key\t");
					scanf(" %[^\n]s",b);
					L=delete(b,L);
					break;

			case 3:  printf("Enter key\t");
				 scanf(" %[^\n]s",b);
				 link p=search(b,L);
				 if(p!=NULL)printf("%d \t %s \t %d \n",(*p).data.age,(*p).data.name,(*p).data.id_no);
				 break;

			case 4: 
				 display(L);
				 break;

			default: printf("Wrong input");
		}
	}




}

