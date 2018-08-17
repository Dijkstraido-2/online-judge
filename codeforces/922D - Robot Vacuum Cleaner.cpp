//============================================================================
// Judge    : 922D - Robot Vacuum Cleaner
// Category : Sortings
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string> vs;

struct cad {
    ll i,s,h;
};

bool operator < (const cad &a, const cad &b) {
    return a.s * b.h > b.s * a.h;
}

typedef vector<cad> vc;
vc v;
vs s;
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll ans,cont;
    string t;
    while(cin >> n)
    {
        s = vs(n); v = vc(n);
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
            v[i].i = i; v[i].s = v[i].h = 0;
            for(char c : s[i])
                if(c == 's')
                    v[i].s++;
                else if(c == 'h')
                    v[i].h++;
        }
        sort(v.begin(), v.end());
        t = "";
        for(int i = 0; i < n; i++)
            t += s[v[i].i];
        ans = cont = 0;
        for(char c : t)
            if(c == 's')
                cont++;
            else if(c == 'h')
                ans += cont;
        cout << ans << '\n';
    }
    return 0;
}