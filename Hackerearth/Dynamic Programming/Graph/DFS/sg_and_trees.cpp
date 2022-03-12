/*
				C++
				encoding:UTF-8
				Modified: <21/Mar/2019 09:31:58 AM>

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
ve< int > graph[N];
int pre[N], post[N];
int t;

void dfs (int node, int parent) {
	t++;
	pre[node] = t;
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
	}
	t++;
	post[node] = t;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	int n, q;
	cin >> n >> q;

	int u, v;
	fr (i, 0, n - 1) {
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dfs (1, -1);
	fr (i, 0, q) {
		cin >> u >> v;

		if (pre[u] > pre[v] and post[u] < post[v])
			pr1 ("YES");
		else if (pre[v] > pre[u] and post[v] < post[u])
			pr1 ("YES");
		else
			pr1 ("no");
	}

	return 0;
}
