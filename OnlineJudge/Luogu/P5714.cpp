#include <bits/stdc++.h>
double m,h,bmi;
using namespace std;
int main() 
{
    cin>>m>>h;
    bmi=m/pow(h,2);
    if(bmi<18.5) cout<<"Underweight";
    if(bmi>=18.5&&bmi<24) cout<<"Normal";
    if(bmi>=24) cout<<bmi<<endl<<"Overweight";
	return 0;
}
