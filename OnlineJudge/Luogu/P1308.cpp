// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
string a;string b;
int main()
{
	getline(cin,a);getline(cin,b);
	for(int i=0;i<a.length();++i) a[i]=tolower(a[i]);
	for(int i=0;i<b.length();++i) b[i]=tolower(b[i]);
	a=' '+a+' ';b=' '+b+' ';
	if(b.find(a)==string::npos) cout<<"-1";
	else
	{
		int q=b.find(a),w=b.find(a),s=0;
		while(w!=string::npos)
		{
			++s;
			w=b.find(a,w+1);
        }
        cout<<s<<" "<<q;
    }
}
