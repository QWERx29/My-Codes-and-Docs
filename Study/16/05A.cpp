#include<iostream>
#include<cstdlib>
using namespace std;
struct node 
{
	short ch[4][4];
	short  si,sj;
	int dep,pnt;
};
node data[1000],temp;
int head,tail,dep,r,depth,i,j,k,ni,nj;
int di[5]={0,0,-1,0,1},dj[5]={0,-1,0,1,0};
short start[4][4],goals[4][4]; 
void  print()
{
	int buf[1000];
	int i,j,k,n;
	n=1;i=tail;buf[1]=i;
	do 
	{
	j=data[i].pnt;
	n++;buf[n]=j;i=j;
	}while (i>0);
	cout<<depth+1<<endl;
	exit(0);
}
bool goal()
{
	short i,j;
	bool go=true;
	for (i=1;i<=3;i++)
	{
		for (j=1;j<=3;j++)
		{
			if (data[tail].ch[i][j]!=goals[i][j]) go=false;
		}
	}
	return go;
}
void cop(short a[4][4],short b[4][4])
{
	short i,j;
	for (i=1;i<=3;i++)
	{
		for (j=1;j<=3;j++) a[i][j]=b[i][j];  
	}
}
bool check(int k)
{
	bool che=false;	
	ni=temp.si+di[k];nj=temp.sj+dj[k];
	if(((ni>=1)&&(ni<=3))&&((nj>=1)&&(nj<=3))) che=true;
	return che;
}

bool dupl()
{
	int i,j,k;
	bool buf;
	i=0;
	do
	{
		i++;buf=true;
		for(j=1;j<=3;j++)
		{
			for(k=1;k<=3;k++)
			{
				if(data[i].ch[j][k]!=data[tail].ch[j][k]) buf=false;
			}
		}
	}while  ((!buf) && (i<tail-1));
	return buf;
}
int main()
{
	for(int i=1;i<=3;i++)
 	{
	 	for(int j=1;j<=3;j++) cin>>start[i][j];
	}
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++) cin>>goals[i][j];
	}
	head=0;tail=1;
	cop(data[1].ch,start);data[1].si=3;data[1].sj=2;
	data[1].pnt=0;data[1].dep=0;
	do 
	{
		head++;temp=data[head];
		depth=temp.dep;
		for(r=1;r<=4;r++)
		{
			  if (check(r))
			  {
				tail++;data[tail]=temp;
				data[tail].ch[data[tail].si][data[tail].sj]=data[tail].ch[ni][nj];
				data[tail].ch[ni][nj]=0;
				data[tail].si=ni;data[tail].sj=nj;
				data[tail].pnt=head;
				data[tail].dep=depth+1;
				if(dupl()) tail--;
				else if(goal()) print();
				}
		}
	}while (head<tail);
	cout<<"no  solution";
	return 0;
}

