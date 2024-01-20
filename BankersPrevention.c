#include<stdio.h>
int main()
{
       int n,r;
       printf("Enter Number of Processes\n");
       scanf("%d",&n);
       printf("Enter Number of Resources\n");
       scanf("%d",&r);
       int temp[10];
       int finish[10];
       int allocate[10][10];
       int max[10][10];
       int need[10][10];
       int available[10];
       int work[10];
       int i,j,a=0,m;
       for(i=0;i<n;i++)
       finish[i]=0;
       printf("Enter Allocation of Processes\n");
       for(i=0;i<n;i++)
       {
       	 printf("Allocation of P%d:",i+1);
       	for(j=0;j<r;j++)
       	{
       		scanf("%d",&allocate[i][j]);
		   }
	   }
	   printf("Enter Max of Processes\n");
       for(i=0;i<n;i++)
       {
       	 printf("Maximum of P%d:",i+1);
       	for(j=0;j<r;j++)
       	{
       		scanf("%d",&max[i][j]);
		   }
	   }
       for(i=0;i<n;i++)
       {
       	for(j=0;j<r;j++)
       	{
       		need[i][j]=max[i][j]-allocate[i][j];
		   }
	   }
	   printf("Enter Available OF Processes\n");
	   	for(j=0;j<r;j++)
	   	{
	   		scanf("%d",&available[j]);
	   		work[j]=available[j];
	     }

	   int count=0;
    while (a < n) {
       for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            if (need[i][j] <= available[j] && finish[i] == 0) {
                	count++;
                	if(count==r-1 && finish[i]==0){
                    for (m = 0; m < r; m++) {
                        available[m] += allocate[i][m];
                        finish[i] = 1;
                        temp[a] = i;
                        a++;
                        printf("%d\n", i);
                    }
                    
                }
            } 
        }
    }
}
// Print the order of execution
printf("Order of execution\n");
for (i = 0; i < n; i++) {
    printf("P%d", (temp[i] + 1));
}  
     return 0;
}

