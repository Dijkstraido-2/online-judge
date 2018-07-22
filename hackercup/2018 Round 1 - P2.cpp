#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
int n,k;
vi id;
// Union-find
vi pset;
int nsets;
void init() { pset = vi(n+1,0); nsets = n; iota(pset.begin(), pset.end(), 0); }
int findSet(int i) { return pset[i] == i? i : (pset[i] = findSet(pset[i])); }
int isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) { if(!isSameSet(i,j)) { nsets--; pset[findSet(i)] = findSet(j); } }

vi pre,pos;

void preorder(int v) 
{
	if(v == 0) return;
	pre.push_back(v);
	preorder(g[v][0]);
	preorder(g[v][1]);
}

void postorder(int v) 
{
	if(v == 0) return;
	postorder(g[v][0]);
	postorder(g[v][1]);
	pos.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
   	int T,ntest=1;
   	cin >> T;
   	while(T--)
   	{
   		cin >> n >> k;
   		g = vvi(n+1, vi(2, 0));
   		for(int i = 1; i <= n; i++)
   			cin >> g[i][0] >> g[i][1];
   		pre.clear(); preorder(1);
   		pos.clear(); postorder(1);
   		init();
   		for(int i = 0; i < n; i++)
   			unionSet(pre[i], pos[i]);
   		cout << "Case #" << ntest++ << ":";
   		if(nsets < k)
   			cout << " Impossible" << '\n';
   		else
   		{
   			int cont = 1;
   			id = vi(n+1,0);
   			for(int i = 1; i <= n; i++)
   				if(findSet(i) == i) 
   				{
   					id[i] = cont++;
   					if(cont == k+1)
   						cont = 1;
   				}
   			for(int i = 1; i <= n; i++)
   				cout << " " << id[findSet(i)];
   			cout << '\n';
   		}
   	}
    return 0;
}