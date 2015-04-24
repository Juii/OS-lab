#include<stdio.h>

void main()
{

 int N,i,k;
 
 printf("\nEnter total number of processes:");
 scanf("%d",&N);
 
 int burstT[N],arrivalTime[N],endTime[N], flag[N];
 for(i=0;i<N;i++)
	flag[N] = 0;
 
 
 for(i=0;i<N;i++)
 {
 	printf("\nEnter ArrivalTime, burstT time and endTime for process %d:",i+1);
 	scanf("%d %d %d", &arrivalTime[i], &burstT[i], &endTime[i]);
 }
	
 int q = 0;
 int possible = 1;
 int Sblock = 10000;
 int index = -1;
 int count = 0;
 while(possible)
 {
	for(i = 0; i< N;i++)
	{
	
		if(arrivalTime[i] == q || burstT[index] == 0)
		{
			
			
			if(flag[i] != 1)
			{
				if(((endTime[i] - q) - burstT[i]) < Sblock)
				{
					Sblock = (endTime[i] - q);
					index            = i;
				}
			}
		}
		
		
	}
	if(burstT[index] == 0)
			{
				Sblock = 10000;
				index=-1;
			}
	if(index!=-1)
	{
	printf("\n From time quantum %d to %d, process %d will get executed", q,q+1, index+1);
	burstT[index]--;
	if(burstT[index] == 0)
	{
		flag[index]=1;
		count++;
	}
	}
	if(count == N)
		possible = 0;
	
 q++;
 }
 
}
