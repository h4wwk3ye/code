/*
				C++
				encoding:UTF-8
				Modified: <20/Mar/2019 08:44:32 AM>

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
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 2e5 + 5;
ve< pair< int, int > > graph[N];
int n;
int deg[N], colors[N];
int ans;

void dfs (int node, int parent, int par_col) {
	int curr = 1;
	for (auto p : graph[node]) {
		int to = p.ff;
		if (to == parent) continue;
		if (curr == par_col) {
			curr++;
			if (curr > ans) curr -= ans;
		}
		colors[p.ss] = curr;
		dfs (to, node, curr);
		curr++;
		if (curr > ans) curr -= ans;
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int k;
	cin >> n >> k;

	fr (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		graph[u].pb ({v, i});
		graph[v].pb ({u, i});
		deg[u]++;
		deg[v]++;
	}

	sort (deg + 1, deg + n + 1, greater<> ());

	ans = deg[k + 1];

	dfs (1, 1, 0);

	pr1 (ans);
	fr (i, 0, n - 1) cout << colors[i] << " ";
	cout << endl;
	return 0;
}
