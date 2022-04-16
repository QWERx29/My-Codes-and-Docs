#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n,x,y;
    scanf("%lf%lf%lf",&n,&x,&y);
    printf("%d",(int)max(n-y/x,0.0));
    return 0;
}
