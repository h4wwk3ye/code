//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Jan/20 08:00:13 PM
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
		ve< pii > arr (n);
		fr (i, 0, n) {
			int x;
			cin >> x;
			arr[i] = {x, i + 1};
		}

		sort (all (arr));

		ve< pii > pairs;

		int i = n - 1, j = n - 2;
		while (j >= 0) {
			if (arr[j].ff * 2 >= arr[i].ff) {
				pairs.pb ({arr[j].ss, arr[i].ss});
				i -= 2;
				j -= 2;
			} else {
				i--;
				j--;
			}
		}

		sort (all (pairs));
		pr (len (pairs) * 2);
		for (auto& p : pairs)
			pr (p.ff, p.ss);
	}
	return 0;
}