//============================================================================
// Problem  : 999C - Alphabetic Removals
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

vector<int> v[26];
vector<int> valid;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    string s;
    while(cin >> n >> k >> s)
    {
        for(int i = 0; i < 26; i++)
            v[i].clear();
        for(int i = 0; i < s.size(); i++)
            v[s[i]-'a'].push_back(i);
        for(int i = 0; i < 26; i++)
            reverse(v[i].begin(), v[i].end());
        valid = vector<int>(n, 1);
        for(int i = 0, cur = 0; i < k; i++)
        {
            while(v[cur].empty())
                cur++;
            valid[v[cur].back()] = 0;
            v[cur].pop_back();
        }
        for(int i = 0; i < n; i++)
            if(valid[i])
                cout << s[i];
        cout << '\n';
    }
    return 0;
}