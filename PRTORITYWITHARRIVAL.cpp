#include <stdio.h>
struct process
{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int pt;
    int cput;
};
int main() {
    struct process p[20],temp;
    int n,i,j,pos,min,t,k,x;
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
    printf("Enter Priority's of Processes\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].pt);  
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
     //sorting according to Priority's
  /*  for(i=1;i<n;i++)
    {
    	pos=i;
    	for(j=i+1;j<n;j++)
    	{
    		if(p[j].pt<p[pos].pt)
    		pos=j;
		}
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;	
    }
    */
   
    //Calculating CompletionTime
    for(i=0;i< n;i++)
    {
    p[i].cput=p[i].bt;
    }
    j=0;
    k=0;
    while(j!=n)
	{
      t=n;
      for(i=0;i< n;i++)
	  {
        if(p[i].at<=k && p[i].pt< p[t].pt && p[i].cput>0)
		{
          t=i;
        }
      }
      p[t].cput--;
      if(p[t].cput==0)
	  {
        j++;
        p[t].ct=k+1;
      }
      k++;
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
   printf("Process		Arrivaltime     Bursttime		     TAT             WT  \n");
   for(i=0;i<n;i++)
   {
     printf("P%d\t\t",p[i].id);
     printf("%d\t\t",p[i].at);
     printf("%d\t\t",p[i].bt);
      printf("%d\t\t",p[i].ct);
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
