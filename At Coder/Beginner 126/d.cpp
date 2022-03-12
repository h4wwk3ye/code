/*
				C++
				encoding:UTF-8
				Modified: <19/May/2019 05:58:43 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e5 + 5;
ve< int > graph[N];
map< pii, int > mp;
int n;
int c[N];

void dfs (int node, int parent) {
	for (int to : graph[node]) {
		if (to == parent) continue;
		if (mp[{node, to}] % 2 == 0)
			c[to] = c[node];
		else
			c[to] = 1 - c[node];
		dfs (to, node);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 0, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].pb (v);
		graph[v].pb (u);
		mp[{u, v}] = w;
		mp[{v, u}] = w;
	}
	dfs (1, 1);
	fr (i, 1, n + 1) pr1 (c[i]);
	return 0;
}
