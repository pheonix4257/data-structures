/*********** Prefix Code Begins*****************/

/*
CODE BY B.G AKSHAYA
           148W1A0504
           CSE-1
Given two linked list, create intersection and union lists that contain intersection and union of the elements of the two given lists respectively.  Print the sum of elements of union list, and intersection list.

You have to complete 
Union(struct listnode*, struct listnode *)
Intersectionstruct listnode*, struct listnode *)

Input Format
n1 is the number of elements in linked list 1
a1…...an1 elements in linked list 1
n2 is the number of elements in linked list 2
b1……bn2 elements in linked list 2

Output Format
Us1 
Is2 
Where s1 corresponds to the sum elements of the union list and s2 corresponds to the sum of elements of the intersection list

Input:
5
2 1 4 1 1
3
1 2 1

Output:
U7
I3

Explanation
Union list will have elements 2 1 4, hence sum 7
Intersection list will have elements 1 2, hence sum 3

Constraints:
1 <=  n1,n2       <= 100
0 <=  a1…..an1 <= 99
0 <=  b1…..bn2 <= 99
*/
#include <stdio.h>
#include <stdlib.h>
#define NUMS 100

struct listnode{
	int data;
	struct listnode *next;
};
typedef struct listnode    LNode;
typedef struct listnode *  LNodeP;
typedef struct listnode ** LNodePP;

LNodeP newnode(int data){

	LNodeP temp = (LNodeP) malloc(sizeof(LNode));
	if(!temp)
		return NULL;

	temp->data = data;
	temp->next = NULL;

	return temp;
}

void append(LNodePP head,int d){

	LNodeP temp = newnode(d);
	temp->next  = (*head);
	(*head)     = temp;
}

// function finds the union of the elements of the two list
LNodeP unionlist(LNodeP ,LNodeP );
// function finds the intersection of the elements of the two list
LNodeP intersection(LNodeP ,LNodeP );
// function prints the elements of the linked list
void print(LNodeP );
// function finds the sum of all the elements of the linked list
int findsum(LNodeP );

int main(void){

	LNodeP uni       = NULL;
	LNodeP intersect = NULL;
	LNodeP first     = NULL;
	LNodeP second    = NULL;

	int n1;
	scanf("%d",&n1);

	int temp,i;

	for(i = 1 ; i <= n1 ; i++){
		scanf("%d",&temp);
		append(&first,temp);
	}

	int n2;
	scanf("%d",&n2);

	for(i = 1 ; i <= n2 ; i++){
		scanf("%d",&temp);
		append(&second,temp);
	}


	uni  = unionlist(first,second);
	printf("U");
	printf("%d",findsum(uni));
	printf("\n");
	intersect = intersection(first,second);
	printf("I");
	printf("%d",findsum(intersect));
	return 0;
}

void print(LNodeP head){

	int count=0;
	LNodeP temp=head;
	while(temp){
		printf("%d  ",temp->data);
		temp = temp->next; count++;
	}
}

int findsum(LNodeP head){

	int count=0;
	LNodeP temp=head;
	while(temp){
		count += temp->data;
		temp   = temp->next;
	}

	return count;
}

/*************** Prefix Code Ends******************/
LNodeP unionlist(LNodeP x,LNodeP y )
{
   LNodeP p,z=NULL;
  
   int i=0,j,a[30],k;
   if(x==NULL)
     z=y;
   else
   {
     z=x;
     p=z;
     while(p->next!=NULL)
     p=p->next;
     p->next=y;
   } 
   p=z;
    for(i=0;z!=NULL;i++)   
    {
    	a[i]=z->data;
    	z=z->next;
	}
	for(j=0;j<i-1;j++)
	{
		if(a[j]==-1000)
		continue;
		for(k=j+1;k<i;k++)
		{
			if(a[j]==a[k])
            a[k]=-1000;
		}
	}
	z=NULL;
    
	for(j=0;j<i;j++)
	{
		if(a[j]!=-1000)
		append(&z,a[j]);
		
	}
	
	return z;
}

LNodeP intersection(LNodeP x ,LNodeP y)
{
   LNodeP z=NULL;
   int i=0,j,a[30],b[30],k,l;
    for(j=0;y!=NULL;j++)   
    {
    	b[j]=y->data;
    	y=y->next;
	}
	 for(i=0;x!=NULL;i++)   
    {
    	a[i]=x->data;
    	x=x->next;
	}
    for(k=i-j;k<i;k++)
	a[k]=-1000;	
	
	for(k=0;k<i-1;k++)
	{
		if(a[k]==-1000)
		continue;
		for(l=k+1;l<i;l++)
		{
			if(a[l]==a[k])
			a[l]=-1000;
		}
	}
	for(k=0;k<j-1;k++)
	{
		if(b[k]==-2000)
		continue;
		for(l=k+1;l<j;l++)
		{
			if(b[l]==b[k])
			b[l]=-2000;
		}
	}
	z=NULL;
	
    for(k=0;k<i-j;k++)
	{
		if((a[k]==-1000))
		continue;
		for(l=0;l<j;l++)
		{
			if((a[k]==b[l])&&(b[l]!=-2000))
            append(&z,a[k]);
		}
	}
	return z;
}  
  /*
  Sample Test Cases
Input	Output
Test Case 1	
10
22    6     3    16    11     7    17    14     8     5
10
7    15     9    10     5     20    8     13    17     3
U176
I40
Test Case 2	
10
5     4    10     1     8     6     9     3     2     7
5
2     3     4     1     5
U55
I15
Test Case 3	
4
3     4     2     1
5
8     5     9     3     1
U32
I4
Test Case 4	
5
43    19    94    95    72
7
12    90    11    66    39    32    47
U620
I0
Test Case 5	
3
30    29     8
3
8      29     30
U67
I67
*/
  
       