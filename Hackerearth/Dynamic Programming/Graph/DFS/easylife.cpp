/*
				C++
				encoding:UTF-8
				Modified: <15/Apr/2019 10:35:01 PM>

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
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 2e5 + 5;
ve< int > graph[N];
int visited[N];
int n, m;
int ver, edges;
long double mx;

void dfs (int node, int parent) {
	visited[node] = 1;
	ver++;
	edges += len (graph[node]);
	for (int to : graph[node]) {
		if (!visited[to]) dfs (to, node);
		// if (to != parent) edges++;
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> m;
	if (m == 0) {
		cout << 0 << "/" << 1 << endl;
		return 0;
	}
	fr (i, 0, m) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	int v, e;
	fr (i, 1, n + 1) {
		if (!visited[i]) {
			ver = 0;
			edges = 0;
			dfs (i, i);
			edges /= 2;
			if (edges > ver) {
				// pr3 (edges, ver, i);
				pr1 (">1");
				return 0;
			}
			// pr2 (edges, ver);
			if (mx < (double) edges / ver) {
				e = edges, v = ver;
				mx = (double) edges / ver;
			}
		}
	}
	int g = __gcd (e, v);
	e /= g;
	v /= g;
	cout << e << "/" << v << endl;
	return 0;
}
