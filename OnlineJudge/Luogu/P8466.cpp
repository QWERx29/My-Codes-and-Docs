#include <bits/stdc++.h>
using namespace std;
int T;
char str[20];
bool judge(char str[])
{

    int len = 18;
    if (str[0] == 'D' && str[1] == 'X')
        return true;
    for (int i = 0; i < len - 3; i++)
    {
        if ((str[i] == str[i + 1]) && (str[i] == str[i + 2]) && (str[i] == str[i + 3]))
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> str;
        if (judge(str))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}