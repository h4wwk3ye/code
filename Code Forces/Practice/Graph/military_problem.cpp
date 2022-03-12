/*
				C++
				encoding:UTF-8
				Modified: <27/Mar/2019 10:51:02 PM>

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

const int N = 2e5 + 5;
ve< int > graph[N];
int t = 0;
int visited[N], pre[N], post[N];

bool fnc (const pair< int, int > a, int b) {
	return a.ff < b;
}

void dfs (int node) {
	visited[node] = 1;
	pre[node] = t++;
	for (int to : graph[node]) {
		if (!visited[to]) dfs (to);
	}
	post[node] = t;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, q;
	cin >> n >> q;
	fr (i, 2, n + 1) {
		int p;
		cin >> p;
		graph[p].pb (i);
	}
	fr (i, 1, n + 1) sort (all (graph[i]));
	fr (i, 1, n + 1) {
		if (!visited[i]) {
			dfs (i);
		}
	}

	ve< pair< int, int > > order;

	fr (i, 1, n + 1) {
		order.pb ({pre[i], i});
	}

	sort (all (order));

	while (q--) {
		int u, v;
		cin >> u >> v;
		int x = pre[u] + v - 1;
		int index = lower_bound (all (order), x, fnc) - order.begin ();
		// pr1 (index);
		if (index == n)
			pr1 (-1);
		else if (pre[order[index].ss] < pre[u] or post[order[index].ss] > post[u])
			pr1 (-1);
		else
			pr1 (order[index].ss);
	}

	return 0;
}
