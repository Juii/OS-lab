#include<stdio.h>
void main()
{

 int N;
 int i,k;
 
 printf("\nEnter Total Number of processes:");
 scanf("%d",&N);
 
 int burst[N],arrivalTime[N],endTime[N],temp1[N];
 for(i=0;i<N;i++)
	temp1[N] = 0;
 
  
 for(i=0;i<N;i++)
 {
 	printf("\nEnter arrivalTime time, burst time and endTime for process %d:",i+1);
 	scanf("%d %d %d", &arrivalTime[i], &burst[i], &endTime[i]);
 }
	
 int q = 0;
 int flag = 1;
 int Nendline = 10000;
 int index = -1;
 int count = 0;
 while(flag)
 {
	for(i = 0; i< N;i++)
	{
	
		if(arrivalTime[i] == q || burst[index] == 0)
		{	
			if(temp1[i] != 1)
			{
				if((endTime[i] - q) < Nendline)
				{
					Nendline = (endTime[i] - q);		
					index            = i;
				}
			}
		}
		
		
	}
	if(burst[index] == 0)
			{
				Nendline = 10000;
				index=-1;
			}
	if(index!=-1)
	{
	printf("\n from time quantum %d to %d, process %d will get executed", q, q+1, index+1);
	burst[index]--;
	
	if(burst[index] == 0)
	{
		temp1[index]=1;
		count++;
	}
	}
	if(count == N)
		flag = 0;
	
 q++;
 }
 
}
