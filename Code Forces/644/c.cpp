//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/May/20 07:19:21 PM
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
		multiset< int > e, o;
		fr (i, 0, n) {
			cin >> arr[i];
			if (arr[i] & 1)
				o.insert (arr[i]);
			else
				e.insert (arr[i]);
		}

		if (len (e) % 2 == 0 and len (o) % 2 == 0) {
			pr ("YES");
			continue;
		}
		string ans = "NO";
		for (auto& i : e) {
			if (o.find (i - 1) != o.end () or o.find (i + 1) != o.end ()) {
				ans = "YES";
				break;
			}
		}
		pr (ans);
	}
	return 0;
}