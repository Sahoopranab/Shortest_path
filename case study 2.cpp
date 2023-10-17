#include<stdio.h>
#include<conio.h>
#define INFINITY 99
#define MAX 10
#define startnode 0

void dijkstra(int cost[MAX][MAX],int n);
int main()
{
	printf("\n node 0: NBH");
    printf("\n node 1: GSH");
    printf("\n node 2: DSW");
    printf("\n node 3: ACC.DEPT");
    printf("\n node 4: OBH");
	int cost[MAX][MAX],i,j,n,u;
	printf("\n Enter the no. of vertices : ");
	scanf("%d",&n);
	printf("\n Enter the cost matrix: \n");
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the cost[%d][%d] = ",i,j);
			scanf("%d",&cost[i][j]);
		}
	} // input from keyboard
	dijkstra(cost,n);
	return 0;
}
void dijkstra(int cost[MAX][MAX],int n)
{
	int distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;   //initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;   //it is decladed as 0
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)     //nextnode gives the node at minimum distance
		{
			if(distance[i]<mindistance && !visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if(mindistance+cost[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];   // updatation of minimum distance for every node 
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}
	for(i=0;i<n;i++)
	{
		if(i!=startnode)
		{
			printf("\n Distance of node%d=%d",i,distance[i]);
			printf("\n path =%d",i);
			j=i;
			do
			{
				j=pred[j];
				printf("<---%d",j);
			}while(j!=startnode); // for printing path from source 
		}
	}
}