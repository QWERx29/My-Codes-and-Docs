#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if((n/3+27+23)<n/1.2) cout<<"Bike";
    else if((n/3+27+23)==n/1.2) cout<<"All";
    else cout<<"Walk";
    return 0;
}