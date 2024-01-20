#include<stdio.h>
#include<conio.h>
int available[10];
int finish[10];
int work[10];
int request[10][10];
int max[10][10];
int allocation[10][10];
int detect(int m,int n);


void main()
{
int m,n,i,j,k,check;
//clrscr();
printf("enter number of processes\n");
scanf("%d",&n);
printf("enter number of resource types\n");
scanf("%d",&m);
printf("enter available \n");
for(j=0;j<m;j++)
{
scanf("%d",&k);
available[j]=k;
}
printf("enter the max matrix\n");
//printf("enter the max matrix\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
scanf("%d",&max[i][j]);
}
printf("enter the allocation matrix\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
scanf("%d",&allocation[i][j]);
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
request[i][j]=max[i][j]-allocation[i][j];
}
}
check=detect(m,n);
if(check==0)
printf("system is not deadlocked\n");
else
printf("system is deadlocked\n");
getch();
}


int detect(int m,int n)
{
int i,j,k,count;
for(j=0;j<m;j++)
work[j]=available[j];
for(i=0;i<n;i++)
{
finish[i]=1;
for(j=0;j<m;j++)
if(allocation[i][j]!=0)
finish[i]=0;
}
printf("process sequence are  ");
count=0;
while(count<n)
{
for(i=0;i<n;i++)
{
count++;
if(finish[i]==0)
{
for(j=0;j<m;j++)
if(request[i][j]>work[j])
break;
if(j==m)
{
count=0;
for(j=0;j<m;j++)
work[j]=work[j]+allocation[i][j];
finish[i]=1;
printf("P%d ",i);
}
}
}
}
count=0;
for(i=0;i<n;i++)
{
if(finish[i]==1)
count++;
}
if(count<n)
return(1);
else
return(0);
}

