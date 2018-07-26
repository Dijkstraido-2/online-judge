//============================================================================
// Problem  : 1011A - Stages
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    string s;
    while(cin >> n >> k >> s) 
    {
    	sort(s.begin(), s.end());
    	s.erase(unique(s.begin(), s.end()), s.end());
    	int last = -1, ans = 0, cont = 0;
    	for(int i = 0; i < n && cont < k; i++)
    		if(last == -1 || s[i] >= s[last]+2)
    		{
    			ans += s[i]-'a'+1;
    			last = i;
    			cont++;
    		}
    	cout << (cont < k? -1 : ans) << '\n';
    }
    return 0;
}