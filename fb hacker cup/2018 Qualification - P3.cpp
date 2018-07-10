#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b)
{
    int i = 0, j = 0;
    while(1)
    {
        if(i >= a.size()) return 1;
        else if(j >= b.size()) return 0;
        else if(a[i] == b[j]) { i++; j++; }
        else if(i == 0) { j++; }
        else i = 0; 
    }
    return 0;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,n,ntest=1;
    string s,ans;
    cin >> T;
    while(T--)
    {
        cin >> s; n = s.size();
        ans = "Impossible";
        for(int i = 1; i <= n; i++) {
            if(!solve(s, s.substr(0,i) + s)) {
                ans = s.substr(0,i) + s;
                break;
            }
        }
        cout << "Case #" << ntest++ << ": " << ans << '\n';
    }
    return 0;
}