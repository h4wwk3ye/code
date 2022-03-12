/*
				C++
				encoding: UTF-8
				Modified: <07/Jul/2019 06:33:08 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

ll n, k;
const int N = 1e5 + 5;
ve< ll > graph[N];
ll ans = 1;

void dfs (ll node, ll parent) {
	if (node == 1) {
		ans *= k;
	}
	ll curr = 1;
	if (node != 1) curr += 1;
	for (ll to : graph[node]) {
		if (to == parent) continue;
		ans *= (k - curr);
		curr++;
		ans %= mod;
		dfs (to, node);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> k;
	fr (i, 1, n) {
		ll u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}

	dfs (1, 1);
	pr1 (ans);
	return 0;
}
