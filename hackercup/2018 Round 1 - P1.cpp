#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string M[3];
int n;
const ll MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
   	int T,ntest=1;
   	cin >> T;
   	while(T--)
   	{
   		cin >> n;
   		for(int i = 0; i < 3; i++)
   			cin >> M[i];
   		int ok = (n % 2 == 0 && M[0][0] == '.' && M[2][n-1] == '.');
   		for(int i = 0; i < n; i++)
   			if(M[1][i] == '#')
   				ok = 0;
   		ll ans = 1;
   		if(n % 2 == 0 && ok) 
   		{
   			for(int i = 1; i < n-1; i += 2)
   			{
   				int cont = 0;
   				if(M[0][i] == '.' && M[0][i+1] == '.')
   					cont++;
   				if(M[2][i] == '.' && M[2][i+1] == '.')
   					cont++;
   				ans = (ans * cont) % MOD;
   			}
   		}
   		cout << "Case #" << ntest++ << ": " << (!ok? 0 : ans) << '\n';
   	}
    return 0;
}