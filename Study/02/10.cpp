#include<cstdio>             
int  main()                 
{  
   int a,b,c;
   a=b=c=8;           
   a=a/2;b=b/2;c=a+b+c;     
   a=a/2;c=c/2;b=a+b+c;     
   b=b/2;c=c/2;a=a+b+c;     
   printf("%-5d%-5d%-5d\n",a,b,c);  
}
