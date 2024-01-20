#include<stdio.h>
#define MAX 50
int main()
{
int page[MAX],i,n,f,ps,off[MAX],pno[MAX];

printf("\nEnter the no of pages in memory");
scanf("%d",&n);
printf("\nEnter page size");
scanf("%d",&ps);
printf("\nEnter no of frames");
scanf("%d",&f);
for(i=0;i<n;i++)
page[i]=-1;
printf("\nEnter the page table\n");
printf("(Enter frame no as -1 if that page is not present in any frame)\n\n");
printf("\npageno\tframeno\n-------\t-------");
for(i=0;i<n;i++)
{
printf("\n\n%d\t\t",i);
scanf("%d",&page[i]);
}
printf("\n\nEnter the logical address(i.e,page no & offset):");
for(i=0;i<n;i++)
{
scanf("%d%d",&pno[i],&off[i]);
}
printf("Enter the page to be searched\n");
scanf("%d",&i);
if(pno[i]==-1)
printf("\n\nThe required page is not available in any of frames");
else
printf("\n\nPhysical address(i.e,frame no & offset):%d,%d",page[i],off[i]);

return 1;
}


