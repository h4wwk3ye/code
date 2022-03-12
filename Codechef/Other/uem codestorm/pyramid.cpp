//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Nov/19 09:24:04 PM
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
		ve< int > arr (n), left (n, 0), right (n, 0);
		fr (i, 0, n) {
			cin >> arr[i];
		}
		left[0] = min (arr[0], 1LL);
		fr (i, 1, n) {
			left[i] = min (arr[i], min (left[i - 1] + 1, i + 1));
		}
		right[n - 1] = min (arr[n - 1], 1LL);
		dfr (i, n - 2, -1) {
			right[i] = min (arr[i], min (right[i + 1] + 1, n - i));
		}
		ve< int > tot (n);
		fr (i, 0, n) tot[i] = min (right[i], left[i]);

		int max_ind = 0;
		for (int i = 0; i < n; ++i)
			if (tot[i] > tot[max_ind]) max_ind = i;

		int cost = 0;
		int height = tot[max_ind];

		for (int x = max_ind; x >= 0; --x) {
			cost += arr[x] - height;
			if (height > 0) --height;
		}

		height = tot[max_ind] - 1;
		for (int x = max_ind + 1; x < n; ++x) {
			cost += arr[x] - height;
			if (height > 0) --height;
		}
		pr (cost);
	}

	return 0;
}