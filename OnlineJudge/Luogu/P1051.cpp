// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
struct stu
{
	char cc,wp;//�Ƿ��ɲ�&����ʡ�� 
	string name;
	int faa,cra,pn;//��ĩƽ���ɼ� �༶����ɼ� �����������
	int tns=0;//��ѧ������ 
};
int main()
{
	stu a[101];
	int n,ans=0,maxtns=0,max=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].name;
		cin>>a[i].faa>>a[i].cra>>a[i].cc>>a[i].wp>>a[i].pn;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].faa>80&&a[i].pn>=1) a[i].tns+=8000;
		if(a[i].faa>85&&a[i].cra>80) a[i].tns+=4000;
		if(a[i].faa>90) a[i].tns+=2000;
		if(a[i].faa>85&&a[i].wp=='Y') a[i].tns+=1000;
		if(a[i].cra>80&&a[i].cc=='Y') a[i].tns+=850;
		ans+=a[i].tns;
	}	
	for(int i=2;i<=n;i++)
	{
		if(a[i].tns>maxtns)
		{
			max=i;
			maxtns=a[i].tns;
		}
		else continue;
	}
	cout<<a[max].name;
	cout<<endl<<a[max].tns<<endl<<ans;
}
