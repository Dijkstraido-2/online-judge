//============================================================================
// Problem  : 978G - Petyas Exams
// Category : Greedy + Priority Queue
//============================================================================
#include <bits/stdc++.h>
using namespace std;

struct exam {
    int i,d,p; // id, day exam, prep left
};

bool operator > (const exam &a, const exam &b) {
    return a.d > b.d;
}

const int MAX = 105;
int s[MAX],d[MAX],c[MAX],ans[MAX];
int n,m;
priority_queue<exam,vector<exam>,greater<exam>> pq;
unordered_set<int> st;
int ex[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        memset(ans, 0, sizeof ans); memset(ex, -1, sizeof ex);
        for(int i = 0; i < m; i++)
        {
            cin >> s[i] >> d[i] >> c[i];
            s[i]--; d[i]--; 
            ans[d[i]] = m+1;
            ex[d[i]] = i;
        }
        st.clear(); int posible = 1;
        while(!pq.empty()) pq.pop();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                if(s[j] == i)
                {
                    pq.push({j,d[j],c[j]});
                    st.insert(j);
                }
            if(ex[i] != -1)
            {
                if(st.find(ex[i]) != st.end())
                    posible = 0;
                continue;
            }
            if(pq.empty())
                ans[i] = 0;
            else
            {
                exam e = pq.top(); pq.pop();
                st.erase(e.i);
                ans[i] = e.i + 1;
                e.p--;
                if(e.p > 0)
                {
                    pq.push(e);
                    st.insert(e.i);
                }
            }
        }
        if(!posible || !pq.empty())
            cout << -1 << '\n';
        else
        {
            for(int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}