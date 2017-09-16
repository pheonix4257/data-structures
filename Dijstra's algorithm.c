/* CODE BY B.G AKSHAYA
           148W1A0504
           CSE-1
*/
#include <cstdio>
#include <stdlib.h>
const int MAXval=1000;


void printSolution(int dist[], int n){
//A function to print the constructed distance array
    for (int i = 0; i < n; i++)
      printf("%d:%d\n",i,dist[i]);
}
int* shortestDist(int** graph, int src, int no_of_vertices);

int main()
{
  int no_of_vertices;
  scanf("%d", &no_of_vertices);
  int sourcevertex;
  scanf("%d", &sourcevertex);
  int** graph = new int*[no_of_vertices];
  for(int i = 0; i < no_of_vertices; ++i)
     graph[i] = new int[no_of_vertices];
  for(int i = 0; i <no_of_vertices; ++i)
    for(int j = 0; j < no_of_vertices; ++j)
      scanf("%d", &graph[i][j]);
    
  int* dist=shortestDist(graph, sourcevertex,no_of_vertices);
 // print the constructed distance array
  printSolution(dist, no_of_vertices);
 
    return 0;
}
int count=0;
int min(int** graph, int src, int no_of_vertices,int *s,int *dis,int *V_s)
{
  int i,k=0,min=32766,j;
  for(i=0;i<no_of_vertices;i++)
  {
    for(j=0;j<count;j++)
    {
      if(i==s[j])
        goto p;
    }
    V_s[k++]=i;
    p:;
  }

  min=V_s[0];
  for(i=1;i<no_of_vertices-count;i++)
  {
    if(dis[V_s[i]]<dis[min])
      min=V_s[i];
  }
 
  return min;         
 }

int* shortestDist(int** graph, int src, int no_of_vertices)
{
  
   int *dis=(int *)malloc(sizeof(int)*no_of_vertices);
   int i,j,k=0,V_s[no_of_vertices],w;
   
   int min(int** graph, int src, int no_of_vertices,int *s,int *dis,int *V_s);
  
   int s[no_of_vertices];
   count=1;
   s[k++]=src;

   
   for(i=0;i<no_of_vertices;i++)
   {
       dis[i]=graph[src][i];
       if(dis[i]==0)
       dis[i]=1000;
       if(i==src)
       dis[i]=0;
   } 
   
     for(i=0;i<no_of_vertices;i++)
     {
      if(i==src)
      continue;
      for(j=0;j<no_of_vertices;j++)
	  {
	  	if(j!=s[j])
	  	goto l;
	  }
	  return dis;
      l:w=min(graph,src,no_of_vertices,s,dis,V_s);
      s[count]=w;
      for(j=0;j<no_of_vertices;j++)
      {
      	 if(j==src)
      	 continue;
         if((dis[j]>dis[w]+graph[w][j])&&graph[w][j]!=0)
         {
		   
           dis[j]=dis[w]+graph[w][j];
           if(graph[w][j]==0)
		   dis[j]=1000;
         }
         
      }
      count++;
     /* for(int t=0;t<no_of_vertices;j++)
      printf("distance is %d",dis[t]); */
    }
   
    
    return dis;
}
/*
Sample Test Cases
Input	Output
Test Case 1	
3
0 
0 4 0
4 0 1
0 1 0
0:0
1:4
2:5
Test Case 2	
3
2
0 4 0
4 0 1
0 1 0
0:5
1:1
2:0
Test Case 3	
5
0
0 4 1 0 0
0 0 0 0 4
0 2 0 4 0
0 0 0 0 4
0 0 0 0 0
0:0
1:3
2:1
3:5
4:7
Test Case 4	
5
4
0 4 1 0 0
0 0 0 0 4
0 2 0 4 0
0 0 0 0 4
0 0 0 0 0
0:1000
1:1000
2:1000
3:1000
4:0
Test Case 5	
5
3
0 4 1 0 0
0 0 0 0 4
0 2 0 4 0
0 0 0 0 4
0 0 0 0 0
0:1000
1:1000
2:1000
3:0
4:4
*/