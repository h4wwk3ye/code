//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 21/Apr/20 08:31:33 PM
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
		ve< int > arr (n);
		fr (i, 0, n) cin >> arr[i];

		bool flag = 0;
		int ans = 0;
		int curr = arr[0];
		if (arr[0] < 0) flag = 1;
		ve< int > val;
		fr (i, 0, n) {
			if (!flag) { // selecting +ve
				if (arr[i] > 0)
					curr = max (curr, arr[i]);
				else {
					val.pb (curr);
					flag = !flag; // have to select -ve now
					curr = arr[i];
				}
			} else {
				if (arr[i] < 0) {
					curr = max (curr, arr[i]);
				} else {
					val.pb (curr);
					flag = !flag;
					curr = arr[i];
				}
			}
		}
		val.pb (curr);
		// select pairs only if their cumm sum is +ve
		// pr (val);
		for (int i = 0; i < val.size () - 1; i += 2) {
			ans += val[i] + val[i + 1];
		}
		if (len (val) & 1) { // last val +ve
			ans += val.back ();
		}
		pr (ans);
	}
	return 0;
}