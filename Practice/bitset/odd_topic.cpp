//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 12/Feb/20 10:26:25 PM
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

const int N = 1e5 + 5;
const int M = 4e3 + 5;
int n, m, q;
bitset< M > a[N], b[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> q;
	fr (i, 1, n + 1) {
		int x;
		cin >> x;
		a[i] = a[i - 1];
		a[i][x] = 1 ^ a[i - 1][x];
	}
	fr (i, 1, m + 1) {
		int x;
		cin >> x;
		b[i] = b[i - 1];
		b[i][x] = 1 ^ b[i - 1][x];
	}
	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		bitset< M > ans = a[r1] ^ a[l1 - 1] ^ b[r2] ^ b[l2 - 1];
		pr (ans.count ());
	}

	return 0;
}