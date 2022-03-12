/*
				C++
				encoding:UTF-8
				Modified: <27/Mar/2019 10:04:42 PM>

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
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (int i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e5 + 5;
ve< int > graph[N];
int visited[N];
bool cycle = false;

void dfs (int node, int parent) {
	visited[node] = 1;
	for (int to : graph[node]) {
		if (visited[to] and to != parent) {
			cycle = true;
		}
		if (!visited[to]) {
			dfs (to, node);
		}
	}
}


int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, m;
	cin >> n >> m;
	fr (i, 0, m) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	int ans = 0;
	fr (i, 1, n + 1) {
		if (!visited[i]) {
			cycle = false;
			dfs (i, i);
			if (!cycle) ans++;
		}
	}
	pr1 (ans);
	return 0;
}
