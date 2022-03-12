/*
				C++
				encoding: UTF-8
				Modified: <23/Jul/2019 11:10:39 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#	include <prettyprint.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

int n, m, source;
const int N = 1e5 + 5;
ve< int > graph[N];
int arr[N], vis[N], ans[N];

void init () {
	fr (i, 1, n + 1) {
		graph[i].clear ();
		ans[i] = 1e9;
		vis[i] = 0;
	}
}

void dijkstra () {
	multiset< pii > s;
	s.insert ({arr[source], source});
	ans[source] = arr[source];
	while (!s.empty ()) {
		auto x = *s.begin ();
		s.erase (s.begin ());
		int w = x.ff, node = x.ss;
		if (vis[node]) continue;
		vis[node] = 1;
		for (int to : graph[node]) {
			if (ans[to] > w) {
				ans[to] = max (arr[to], w);
				s.insert ({ans[to], to});
			}
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> source;
		init ();
		fr (i, 1, n + 1) cin >> arr[i];
		fr (i, 0, m) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
		}
		dijkstra ();
		fr (i, 1, n + 1) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
