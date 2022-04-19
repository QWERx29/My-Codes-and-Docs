#include<bits/stdc++.h>
using namespace std;
int main()
{
   double m,p;
   char q;
   cin>>m>>q;
   if(m<=1000) p=8;
   else p=ceil((m-1000)/500)*4+8;
   if(q=='y') p+=5;
   cout<<p;
   return 0;
}