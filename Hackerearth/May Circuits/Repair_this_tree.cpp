/*
				C++
				encoding:UTF-8
				Modified: <02/Jun/2019 11:04:05 AM>

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

int n, q;
const int N = 2e5 + 5;
ve< int > graph[N];
int parent[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, q;
	cin >> n >> q;
	fr (i, 2, n + 1) {
		int x;
		cin >> x;
		parent[i] = x;
		graph[x].pb (i);
		graph[i].pb (x);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y, w;
			cin >> x >> y >> w;
		} else {
			int v, p;
			cin >> v >> p;
		}
	}
	return 0;
}
