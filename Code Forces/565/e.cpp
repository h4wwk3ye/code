/*
				C++
				encoding:UTF-8
				Modified: <09/Jun/2019 10:15:23 PM>

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

// clang-format on

const int N = 2e5 + 5;
int n, m;
ve< int > graph[N];
int vis[N], dist[N];

void init () {
	fr (i, 1, n + 1) {
		graph[i].clear ();
		vis[i] = 0;
		dist[i] = 0;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		init ();
		fr (i, 0, m) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph[v].pb (u);
		}
		queue< int > q;
		q.push (1);
		vis[1] = 1;
		while (!q.empty ()) {
			int node = q.front ();
			q.pop ();
			for (int to : graph[node]) {
				if (!vis[to]) {
					vis[to] = 1;
					dist[to] = 1 + dist[node];
					q.push (to);
				}
			}
		}
		int ans = 0;
		fr (i, 1, n + 1) {
			if (dist[i] % 2 == 0) ans++;
		}
		if (ans <= n / 2) {
			pr1 (ans);
			fr (i, 1, n + 1) {
				if (dist[i] % 2 == 0) cout << i << " ";
			}
			cout << endl;
		} else {
			pr1 (n - ans);
			fr (i, 1, n + 1) {
				if (dist[i] % 2 == 1) cout << i << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
