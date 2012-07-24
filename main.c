#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp,*fp1;
    char dir[100],dir1[100],t[5],t1[5];
    char a;
    int i,j=0,k=0;

    system("wget -O /root/newhosts https://smarthosts.googlecode.com/svn/trunk/hosts");
    system("cp /etc/hosts /root/oldhosts");

    if((fp=fopen("/root/oldhosts","r"))==NULL)
           {
               perror("fail to read oldhosts");
               exit(1);
           }

     fgets(dir,100,fp);

     fclose(fp);

     if((fp1=fopen("/root/newhosts","r"))==NULL)
           {
               perror("fail to read newhosts");
               exit(2);
           }

     fgets(dir1,100,fp1);

     fclose(fp1);

     if(dir[0]!='#')
     {
         printf("检测到您的hosts处于初始状态！是否更换hosts？(y/n):");
         a=getchar();
         if(a=='y'||a=='Y')
         {
             system("cat /root/newhosts > /etc/hosts");
             printf("结束！");
         }
         else if(a=='n'||a=='N')
         {
             printf("已取消！");
         }
         else printf("输入错误,请重新运行程序！");
     }
     if(dir[0]=='#')
     {
         for(i=0;i<17;i++)
         {
             if(dir[i]>='0'&&dir[i]<='9')
             {
                 t[j]=dir[i];
                 j++;
             }
             if(j==7)break;

         }

         for(i=0;i<17;i++)
         {
            if(dir1[i]>='0'&&dir1[i]<='9')
            {
                 t1[k]=dir1[i];
                 k++;
            }
            if(k==7)break;
         }

         if(strcmp(t,t1)>0)
         {
             printf("错误!");
         }
         if(strcmp(t,t1)<0)
         {
             printf("发现已更新的hosts，是否更新(y/n):");
             a=getchar();
             if(a=='y'||a=='Y')
             {
                 system("cat /root/newhosts > /etc/hosts");
                 printf("结束！");
             }
             else if(a=='n'||a=='N')
             {
                 printf("已取消");
             }
             else
                 printf("输入错误,请重新运行程序！");
         }
         if(strcmp(t,t1)==0)
         {
             printf("您的hosts已经是最新的了！");
         }

     }

     system("rm /root/newhosts oldhosts");

    printf("\n感谢使用!\n");
    return 0;
}

