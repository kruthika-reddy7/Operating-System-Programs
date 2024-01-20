#include<stdio.h>
#include<conio.h>
int available[10];
int finish[10];
int work[10];
int max[10][10];
int allocation[10][10];
int need[10][10];
int resourcerequest(int n,int m);
int safety(int n,int m);
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
printf("the need matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
need[i][j]=max[i][j]-allocation[i][j];
printf("%d ",need[i][j]);
}
printf("\n");
}
check=resourcerequest(n,m);
if(check==0)
printf("request  cannot be granted system is unsafe\n");
else
printf("request  granted system is safe\n");
getch();
}


int safety(int n,int m)
{
int i,j,k,count;
for(j=0;j<m;j++)
work[j]=available[j];
for(i=0;i<n;i++)
finish[i]=0;
count=0;
while(count<n)
{
for(i=0;i<n;i++)
{
count++;
if(finish[i]==0)
{
for(j=0;j<m;j++)
if(need[i][j]>work[j])
break;
if(j==m)
{
count=0;
for(j=0;j<m;j++)
work[j]=work[j]+allocation[i][j];
finish[i]=1;
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
return(0);
else
return(1);
}
int resourcerequest(int n,int m)
{
int i,j,check;
int request[10];
printf("enter the process number which had made request\n");
scanf("%d",&i);
printf("enter the request vector by the process %d \n",i);
for(j=0;j<m;j++)
scanf("%d",&request[j]);
for(j=0;j<m;j++)
if(request[j]>need[i][j])
{
printf("error condition process is exceeding its maximum claim\n");
return(0);
}
for(j=0;j<m;j++)
if(request[j]>available[j])
{
printf("resourses are not available process must wait\n");
return(0);
}
for(j=0;j<m;j++)
{
available[j]=available[j]-request[j];
allocation[i][j]=allocation[i][j]+request[j];
need[i][j]=need[i][j]-request[j];
}
check=safety(n,m);
return(check);
}


