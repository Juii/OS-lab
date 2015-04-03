#include<stdio.h>

int main()
{
	int n;
	printf("Enter total number of processes");
	scanf("%d",&n);
	int burstT[n],waitingT[n],turnAroundT[n];
	int i, j;
	
	printf("Enter burst time for each process");
	for(i=0;i<n;i++)
	{
		printf("P[%d]",i+1);
		scanf("%d",&burstT[i]);
	}
	
	waitingT[0]=0;
	
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnAround Time");
	
	for(i=1;i<n;i++)
	{
		waitingT[i]=0;
		for(j=0;j<i;j++)
		waitingT[i]+=burstT[j];
	}
	
	for(i=0;i<n;i++)
	{
		turnAroundT[i]=burstT[i]+waitingT[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\n",i+1,burstT[i],waitingT[i],turnAroundT[i]);
	}
	
	return 0;
}
