#include<stdio.h>

int main()
{
	int n;
	printf("Enter total number of processes");
	scanf("%d",&n);
	int burstT[n],waitingT[n],turnAroundT[n], arrivalT[n], P_id[n];
	int i, j;
	
	printf("Enter burst time for each process\n");
	for(i=0;i<n;i++)
	{
		printf("Burst time of process P_id[%d]: ",i+1);
		scanf("%d",&burstT[i]);
	}
	

	
	for(i=0;i<n;i++)
	{
		P_id[i]=i+1;
	}
	
	printf("\nPROCESS  \tBURST TIME\n");
     for( i=0; i<n; i++)
     {
         printf("\n    %d\t\t   %d\t\t \n",P_id[i],burstT[i]);
     }

	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(burstT[j]>burstT[i]) {
			int temp = burstT[i];
			burstT[i] = burstT[j];
			burstT[j] = temp;
			
		
/*			int temp2 = P_id[i];
			P_id[i] = P_id[j];
			P_id[j] = temp2;*/
			}
			
		}
	}
	
	printf("\nPROCESS  \tBURST TIME");

	for(i=0;i<n;i++)
	{
		printf("\n	%d\t\t %d\t\t \n",P_id[i],burstT[i]);	
	}
	//----Waiting time----
	waitingT[0]=0;
	for(i=1;i<n;i++)
	{
		waitingT[i]=waitingT[i-1]+burstT[i-1];
	}
	
	printf("\n------Waiting Time for each process---------\n");
	for(i=0;i<n;i++)
	{
		printf("\nwaiting time of process%d is %d\n",i+1,waitingT[i]);
	}

	//----Turnaround time----
	for(i=1;i<n;i++)
	{
		turnAroundT[0]=burstT[0];
		turnAroundT[i]=turnAroundT[i-1]+burstT[i];	
	}
	printf("\n------Turnaround Time for each process--------\n");
	for(i=0;i<n;i++)
	{
		printf("\nTurnaround time of process%d is %d\n",i+1,turnAroundT[i]);
	}

	return 0;
}
