#include <bits/stdc++.h>
using namespace std;
int t, x;
int main()
{
    while (scanf("%d", &t)!=EOF)
    {
        priority_queue<int, vector<int>, less<int>> a;
        priority_queue<int, vector<int>, greater<int>> b;
        a.push(t);
        while (scanf("%d", &x) && x)
        {
            if(x!=-1)
            {
                if(x>=a.top())
                    b.push(x);
                else
                    a.push(x);
            }
            else
            {
                while (b.size() >= a.size() + 1)
                    a.push(b.top()), b.pop();
                while(a.size()>b.size()+1)
                    b.push(a.top()), a.pop();
                printf("%d\n", a.top());
                a.pop();
            }
        }
    }
    return 0;
}