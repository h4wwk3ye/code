/*
				C++
				encoding:UTF-8
				Modified: <01/Jun/2019 07:38:35 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    987654319
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<ll, ll>
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

// clang-format on

const ll N = 3e5 + 5;
ll n, W;
ve< ll > graph[N];
map< pii, ll > weights;
ll value[N];
ve< ll > depth[N];

void dfs (ll node, ll parent) {
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> W;
	fr (i, 0, n - 1) {
		ll u, v, w;
		cin >> u >> v >> w;
		graph[u].pb (v);
		graph[v].pb (u);
		weights[{u, v}] = w;
		weights[{v, u}] = w;
	}

	return 0;
}
