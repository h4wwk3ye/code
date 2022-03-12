//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 20/Jan/20 08:56:41 PM
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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	ve< int > arr;
	fr (i, 0, 2020) arr.pb (i);

	int i = 0;

	arr.erase (arr.begin () + (n + 1) % len (arr));

	i = (n + 2) % len (arr);
	while (len (arr) > 1) {
		int j = (i + n - 1) % len (arr);
		arr.erase (arr.begin () + j);
		i = (j) % len (arr);
	}
	pr (arr[0] + 1);
	return 0;
}