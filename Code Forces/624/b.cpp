//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Feb/20 08:19:25 PM
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


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		int arr[n + 1];
		int x[n + 1];
		set< int > s;
		fr (i, 1, n + 1) {
			cin >> arr[i];
			x[i] = arr[i];
		}
		fr (i, 1, m + 1) {
			int c;
			cin >> c;
			s.insert (c);
		}
		sort (x + 1, x + n + 1);

		auto solve = [&](int i, int t) {
			int j = 0, o = 0;

			fr (k, i, n + 1) {
				if (arr[k] == t) {
					j = k;
					o = k;
					break;
				}
			}
			bool flag = 0;
			while (true) {
				if (j <= i) {
					flag = 1;
					break;
				}
				if (s.find (j - 1) == s.end ()) {
					break;
				} else {
					j--;
				}
			}
			if (!flag) {
				return 0;
			} else {
				swap (arr[i], arr[o]);
				return 1;
			}
		};
		bool f = 1;
		fr (i, 1, n + 1) {
			int p = solve (i, x[i]);
			if (!p) {
				f = 0;
				break;
			}
		}
		if (f) {
			pr ("YES");
		} else {
			pr ("NO");
		}
	}
	return 0;
}