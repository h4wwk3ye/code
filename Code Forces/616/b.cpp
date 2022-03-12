//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Feb/20 08:42:14 PM
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
		int arr[n];
		fr (i, 0, n) cin >> arr[i];
		int f = 0;
		int c = 0;
		int i = 0;
		for (; i < n - 1; i++) {
			if (n - i - 1 <= arr[i]) {
				f = 2;
				break;
			}

			if (arr[i] >= arr[i + 1]) {
				if (i > 0 and arr[i + 1] - arr[i - 1] > 1) {
					arr[i] = min (arr[i], arr[i + 1] - 1);

				} else {
					f = 1;
					break;
				}
			} else {
				arr[i] = min (arr[i], arr[i + 1] - 1);
			}
		}
		if (f == 2) {
			pr ("Yes");
			continue;
		}
		if (f == 0) {
			pr ("Yes");
			continue;
		}
		++i;

		f = 0;
		for (; i < n; ++i) {
			arr[i] = min (arr[i], arr[i - 1] - 1);
			if (arr[i] < 0) {
				f = 1;
				break;
			}
		}

		if (f) {
			pr ("No");
		} else {
			pr ("Yes");
		}
	}
	return 0;
}