//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 28/Dec/19 06:17:58 PM
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
	int n, m, v, p;
	cin >> n >> m >> v >> p;
	int arr[n];
	fr (i, 0, n) cin >> arr[i];
	sort (arr, arr + n, greater<> ());
	int x = arr[p];
    if (n-p+1<=v) x+=m;
	fr (i, 0, n) cout << arr[i] << " ";
	cout << endl;
	int i = p;
	while (i < n and (x - arr[i] <= m)) {
		i++;
	}
	pr (i);
	return 0;
}