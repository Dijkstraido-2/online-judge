//============================================================================
// Problem  : 1011B - Planning The Expedition
// Category : Brute Force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,x;
    map<int,int> mp;
    while(cin >> n >> m) 
    {
    	mp.clear();
    	for(int i = 0; i < m; i++)
    	{
    		cin >> x;
    		mp[x]++;
    	}
    	int ans = 0;
    	for(int k = 1; k <= 200; k++) 
    	{
    		int cont = 0;
    		for(auto p : mp)
    			cont += p.second / k;
    		if(cont >= n)
    			ans = k;
    	}
    	cout << ans << '\n';
    }
    return 0;
}