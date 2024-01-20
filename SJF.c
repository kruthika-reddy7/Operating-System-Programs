#include <stdio.h>
struct process
{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
int main() {
    struct process p[20],temp;
    int n,i,j,pos,x=0;
    printf("Enter number of processes:\n");
    scanf("%d",&n);
    printf("Enter Id's of Processes\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].id);
    }
    printf("Enter Arrival times of Processes\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].at);
    }
    printf("Enter Burst times of Processes\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].bt);  
    }
     //sorting according to Arrival times
    for(i=0;i<n;i++)
    {
    	pos=i;
    	for(j=i+1;j<n;j++)
    	{
    		if(p[j].at<p[pos].at)
    		pos=j;
		}
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;	
	}
    //sorting according to BURST TIMES
    for(i=1;i<n;i++)
    {
    	pos=i;
    	for(j=i+1;j<n;j++)
    	{
    		if(p[j].bt<p[pos].bt)
    		pos=j;
		}
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;	
	}
	if( p[0].at != 0)
	  x=p[0].at;
	//calculating completion times
	p[0].ct=x+p[0].bt;
	for(i=1;i<n;i++)
	{
		if(p[i-1].ct>p[i].at)
		p[i].ct=p[i].bt+p[i-1].ct;
		else
		p[i].ct=p[i].bt+p[i-1].ct+(p[i].at-p[i-1].ct);
		
	}
	//calculating turn around time
   int sumtat=0;
   float avgtat;
   for(i=0;i<n;i++)
   {
     p[i].tat=p[i].ct-p[i].at;
     sumtat=sumtat+p[i].tat;
   }
   avgtat=(float)sumtat/n;
   //calculating waiting time
   int sumwt=0;
   float avgwt;
   for(i=0;i<n;i++)
   {
     p[i].wt=p[i].tat-p[i].bt;
     sumwt=sumwt+p[i].wt;
   }
   avgwt=(float)sumwt/n;
   printf("Process		Arrivaltime     Bursttime       TAT	        WT	  \n");
   for(i=0;i<n;i++)
   {
     printf("P%d\t\t",p[i].id);
     printf("%d\t\t",p[i].at);
     printf("%d\t\t",p[i].bt);
     printf("%d\t\t",p[i].tat);
     printf("%d\t\t",p[i].wt);
     printf("\n");
     }
     
     printf("Average TAT\n");
     printf("%f\n",avgtat); 
     printf("Average WT\n");
     printf("%f\n",avgwt);
    return 0;
}

