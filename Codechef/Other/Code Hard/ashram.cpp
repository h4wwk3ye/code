/*
				C++
				encoding: UTF-8
				Modified: <31/Aug/2019 12:25:43 PM>

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

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on
const int N = 1e5 + 5;
vector< int > v[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	ll n, m, Q, x, y, d, k, i;
	cin >> n >> Q;
	vector< ll > a (n + 1);
	vector< ll > lazy (n + 1, 0);
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++) {
		cin >> x >> y;
		v[x].push_back (y);
		v[y].push_back (x);
	}
	int t;
	while (Q--) {
		cin >> t >> x >> y;
		lazy[x] += y;
	}

	deque< int > q;
	vector< bool > visited (n + 1, false);
	q.push_back (1);
	visited[1] = true;
	while (!q.empty ()) {
		int x = q.front ();
		q.pop_front ();
		a[x] += lazy[x];
		for (i = 0; i < v[x].size (); i++) {
			int p = v[x][i];
			if (visited[p] == false) {
				q.push_back (p);
				visited[p] = true;
				lazy[p] += lazy[x];
			}
		}
	}
	return 0;
}
