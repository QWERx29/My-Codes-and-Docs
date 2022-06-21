#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int MAXN=961100;
int n,fa[MAXN],rr,bk;
char s[MAXN];
long long sum[MAXN],ans[MAXN],tot;
stack<int> bra;
vector<int> child[MAXN];
void tree(int node)
{
    bool tmp=false;
    if(s[node]=='(') bra.push(node);
    else if(!bra.empty())
    {
        bk=bra.top();
        tmp=true;
        sum[node]=sum[fa[bk]]+1;
        bra.pop();
    }
    ans[node]=ans[fa[node]]+sum[node];
    for(int i=0;i<child[node].size();i++)
    {
        if(!bra.empty())
        {
            int u=bra.top();
            tree(child[node][i]);
            bra.pop();
            bra.push(u);
        }
        else tree(child[node][i]);    
    }
    if(s[node]=='(') bra.pop();
    else if(tmp) bra.push(bk);
}
int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    scanf("%d\n%s",&n,s+1);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&rr);
        fa[i]=rr;
        child[rr].push_back(i);
    }
    tree(1);
    tot=ans[1];
    for(int i=2;i<=n;i++) tot^=i*ans[i];
    printf("%lld",tot);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
