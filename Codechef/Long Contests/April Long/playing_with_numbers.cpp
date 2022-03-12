/*
				C++
				encoding:UTF-8
				Modified: <07/Apr/2019 04:24:51 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     int64_t
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
#define		 pr1(x)                 cout<<x<<"\n";
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n";
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e5 + 5;
ve< int > graph[N];
int n;
ll v[N], m[N];
ve< int > leaves;

void init () {
	fr (i, 0, N) {
		graph[i].clear ();
		v[i] = 0;
		m[i] = 0;
	}
	leaves.clear ();
}

void dfs (int node, int parent) {
	bool leaf = true;
	for (int to : graph[node]) {
		if (to == parent) continue;
		leaf = false;
		v[to] = __gcd (v[to], v[node]);
		dfs (to, node);
	}
	if (leaf) leaves.pb (node);
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init ();
		fr (i, 0, n - 1) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph[v].pb (u);
		}
		fr (i, 1, n + 1) cin >> v[i];
		fr (i, 1, n + 1) cin >> m[i];
		dfs (1, 1);
		ve< ll > ans;
		sort (all (leaves));
		for (int i : leaves) {
			ll a = __gcd (v[i], m[i]);
			ans.pb (m[i] - a);
		}
		for (auto i : ans)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
