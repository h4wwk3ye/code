#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 29/Dec/19 12:41:39 AM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

int n, m;
const int N = 2e5 + 5;
int a[N], b[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	fr (i, 1, n + 1) cin >> a[i];
	set< int > s;
	for (auto& i : a)
		s.insert (i);
	sort (a + 1, a + n + 1);
	ve< pii > points;

	fr (i, 0, n + 1) {
		if (i == 0) {
			points.pb ({-2e9 + 1, a[1] - 1});
		} else if (i == n) {
			points.pb ({a[i] + 1, 2e9 - 1});
		} else {
			if (a[i] + 1 <= a[i + 1] - 1) {
				points.pb ({a[i] + 1, a[i + 1] - 1});
			}
		}
	}
	// pr (points);
	int cnt = 0;
	int ans = 0;
	int dist = 1;
	ve< int > op;
	while (cnt < m) {
		for (int i = 0; i < len (points); ++i) {
			pii& x = points[i];
			if (x.ff > x.ss) continue;

			if (x.ff == -2e9 + 1) {
				op.pb (x.ss);
				x.ss--;

				ans += dist;
				cnt++;

			} else if (x.ss == 2e9 - 1) {
				op.pb (x.ff);
				x.ff++;
				ans += dist;
				cnt++;
			} else {
				op.pb (x.ff);
				ans += dist;
				cnt++;
				if (cnt == m) break;
				if (x.ff != x.ss) {
					op.pb (x.ss);
					cnt++;
					ans += dist;
				}
				x.ff++;
				x.ss--;
			}

			if (cnt == m) break;
		}

		// ve< pii > tmp;
		// for (auto& i : points) {
		// 	if (i.ff <= i.ss) tmp.pb (i);
		// }
		// if (len (tmp) != len (points)) points = tmp;
		dist++;
	}
	pr (ans);
	for (auto i : op)
		cout << i << " ";
	return 0;
}