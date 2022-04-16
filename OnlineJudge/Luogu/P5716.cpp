#include <bits/stdc++.h>
int y,m;
bool f;
using namespace std;
int main() 
{
    cin>>y>>m;
    if(y%4==0) 
	{
    	if (y%100==0) 
		{
            if (y%400==0) f=true;
            else f=false;
        }
        else f=true;
    } 
	else f=false;
	switch(m) 
	{
        case 1:
            cout<<"31";
            break;
        case 2:
            {
            	if(f==true) cout<<"29";
            	else cout<<"28";
				break;
			}
        case 3:
            cout<<"31";
            break;
        case 4:
            cout<<"30";
            break;
        case 5:
            cout<<"31";
            break;
        case 6:
            cout<<"30";
            break;
        case 7:
            cout<<"31";
            break;
        case 8:
            cout<<"31";
            break;
        case 9:
            cout<<"30";
            break;
        case 10:
            cout<<"31";
            break;
        case 11:
            cout<<"30";
            break;
        case 12:
            cout<<"31";
            break;
        
    }
	return 0;
}
