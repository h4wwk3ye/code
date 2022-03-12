/*
				C++
				encoding: UTF-8
				Modified: <19/Aug/2019 12:16:14 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         int                    long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on
const int N = 1e5 + 5;
ve< int > graph[N];
int vis[N], dist[N], par[N];
int n;

void init () {
	fr (i, 0, n + 1) {
		vis[i] = 0;
		dist[i] = -1;
		par[i] = -1;
	}
}

int bfs (int root) {
	init ();
	dist[root] = 0;
	queue< int > q;
	q.push (root);
	while (!q.empty ()) {
		int v = q.front ();
		q.pop ();
		for (int to : graph[v]) {
			if (dist[to] == -1) {
				dist[to] = 1 + dist[v];
				q.push (to);
				par[to] = v;
			}
		}
	}
	int ans = 1e9;
	fr (i, 0, n) {
		if (dist[i] == -1) continue;
		for (int to : graph[i]) {
			if (par[i] == to or par[to] == i) continue;
			ans = min (ans, dist[i] + dist[to] + 1);
		}
	}
	return ans;
}
signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	ve< int > arr;
	fr (i, 0, n) {
		int x;
		cin >> x;
		if (x) arr.pb (x);
	}
	n = arr.size ();
	int bits[63];
	reset (bits, 0);
	for (auto i : arr) {
		fr (j, 0, 62) {
			int curr_bit = (i >> j) & 1;
			if (curr_bit) bits[j]++;
			if (bits[j] == 3) {
				pr (3);
				return 0;
			}
		}
	}

	fr (i, 0, n) {
		fr (j, i + 1, n) {
			if (arr[i] & arr[j]) {
				graph[i].pb (j);
				graph[j].pb (i);
			}
		}
	}
	int ans = 1e9;
	fr (i, 0, n) {
		ans = min (ans, bfs (i));
	}
	if (ans >= 1e8) ans = -1;
	pr (ans);
	return 0;
}
