//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 15/Jan/20 11:18:12 PM
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
		int n;
		cin >> n;
		ve< ve< int > > arr (n + 1);
		arr[0].resize (1);
		arr[0][0] = 1;
		fr (i, 1, n + 1) {
			arr[i].resize (2 * i + 1, 0);
			fr (j, 0, 2 * i + 1) {
				if (j == 0 or j == 2 * i) {
					arr[i][j] = 1;
				} else if (j == 1 and i != 1) {
					arr[i][j] = arr[i - 1][j];
				} else if (j == 2 * i - 1 and i != 1) {
					arr[i][j] = arr[i - 1][j - 2];
				} else if (i != 1) {
					arr[i][j] = arr[i - 1][j - 2] + arr[i - 1][j];
				}
			}
		}
		int ans = 0;
		fr (i, 1, n + 1) {
			if (i == 1)
				ans += 2;
			else {
				ans += arr[i][i];
			}
		}
		pr (ans);
	}
	return 0;
}