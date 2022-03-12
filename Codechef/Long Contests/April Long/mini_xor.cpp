/*
				C++
				encoding:UTF-8
				Modified: <15/Apr/2019 07:49:21 AM>

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
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, ll>
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

const int N = 2e5 + 5;
ve< int > graph[N];
int n;
int parent[N];
ll weight[N];
ll v, k, curr, mx, vertex;
map< pii, pii > mp;

void init () {
	fr (i, 1, n + 1) {
		graph[i].clear ();
		parent[i] = 0;
		weight[i] = 0;
	}
	mp.clear ();
}

void dfs_o (int node, int p) {
	for (int to : graph[node]) {
		if (to == p) continue;
		parent[to] = node;
		dfs_o (to, node);
	}
}

void dfs (int node, int p) {
	curr = weight[node] ^ k;
	if (curr > mx) {
		mx = curr;
		vertex = node;
	} else if (curr == mx and node < vertex) {
		mx = curr;
		vertex = node;
	}

	for (int to : graph[node]) {
		if (to == parent[node]) continue;
		if (to == p) continue;
		dfs (to, node);
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		int q;
		cin >> n >> q;
		init ();
		fr (i, 1, n + 1) cin >> weight[i];
		fr (i, 0, n - 1) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph[v].pb (u);
		}
		dfs_o (1, 1);
		ll xl = 0, vl = 0;
		ll a, b;
		while (q--) {
			cin >> a >> b;
			v = a ^ vl;
			k = b ^ xl;
			curr = 0;
			mx = -1;
			vertex = -1;
			if (mp.find ({v, k}) != mp.end ()) {
				vl = mp[{v, k}].ff;
				xl = mp[{v, k}].ss;
				cout << vl << " " << xl << endl;
				continue;
			}
			dfs (v, v);
			cout << vertex << " " << mx << "\n";
			mp[{v, k}] = {vertex, mx};
			vl = vertex;
			xl = mx;
		}
	}
	return 0;
}
