//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Feb/20 08:51:09 PM
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
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	int arr[n];
	fr (i, 0, n) cin >> arr[i];

	int p = a + b;
	int ans = 0;
	ve< int > t;
	fr (i, 0, n) {
		int x = arr[i] % p;
		if (x <= a and x != 0)
			ans++;
		else {
			if (x == 0) x = p;
			t.pb (x);
		}
	}
	ve< int > q;
	for (auto& i : t) {
		int x = ceil (i / (a * 1.0));
		q.pb (x - 1);
	}

	sort (all (q));

	fr (i, 0, len (q)) {
		k -= q[i];
		if (k >= 0)
			ans++;
		else
			break;
	}
	pr (ans);
	return 0;
}