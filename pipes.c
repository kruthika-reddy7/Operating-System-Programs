#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
pid_t pid,p1,p2;
int fd1[2],fd2[2],n;
char str[100],buff[100];
p1=pipe(fd1);
if(p1<0)
{
perror("failed pipe1\n");
exit(1);
}
p2=pipe(fd2);
if(p2<0)
{
perror("failed pipe2\n");
exit(1);
}
pid=fork();
if(pid<0)
{
perror("fork failed\n");
exit(1);
}
else
if(pid==0)
{
printf("child executes\n");
close(fd1[1]);
close(fd2[0]);
printf("enter the string for parent\n");
scanf("%s",str);
write(fd2[1],str,sizeof(str));
sleep(1);
n=read(fd1[0],buff,sizeof(buff));
buff[n]='\0';
printf("parent says");
fputs(buff,stdout);
}
else
{
printf("parent executes\n");
sleep(1);
close(fd1[0]);
close(fd2[1]);
sleep(5);
printf("enter the string for child\n");
scanf("%s",str);
write(fd1[1],str,sizeof(str));
sleep(1);
n=read(fd2[0],buff,sizeof(buff));
buff[n]='\0';
printf("child says");
fputs(buff,stdout);
}
}


