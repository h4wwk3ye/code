#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Mar/20 11:11:51 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define        int                    long long
#define        ve                     vector
#define        pb                     push_back
#define        endl                   "\n"
#define        ff                     first
#define        ss                     second
#define        pii                    pair<int, int>
#define        len(v)                 (int)v.size()
#define        all(v)                 v.begin(), v.end()
#define        reset(a, b)            memset(a, b, sizeof(a));
#define        fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define        dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, m;
	cin >> n >> m;
	set< ve< int > > a;
	ve< int > mx (m, 0);
	fr (i, 0, n) {
		ve< int > x (m);
		fr (j, 0, m) {
			cin >> x[j];
			mx[j] = max (mx[j], x[j]);
		}
		a.insert (x);
	}
	ve< ve< int > > arr;
	for (auto& i : a) {
		arr.pb (i);
	}
	sort (all (arr),
		  [](ve< int >& x, ve< int >& y) { return *max_element (all (x)) < *max_element (all (y)); });

	n = len (arr);

	if (n == 1) {
		int ans = 1e10;
		fr (i, 0, m) {
			ans = min (ans, arr[0][i]);
		}
		pr (ans);
		return 0;
	}

	int ans = 0;

	dfr (i, n - 1, -1) {
		int mx = -1;
		fr (j, 0, m) mx = max (mx, arr[i][j]);
		if (mx < ans) continue;

		int a = 0;
		fr (l, i, n) {
			int curr = 1e10;
			fr (j, 0, m) {
				curr = min (curr, max (arr[i][j], arr[l][j]));
			}
			a = max (a, curr);
		}
		ans = max (ans, a);
	}
	pr (ans);


	return 0;
}