//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jan/20 08:19:42 PM
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

const int N = 1e6 + 5;
pii arr[N];
int a[N];
int n, q;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		arr[l].ff += l;
		arr[r + 1].ff -= l;
		arr[l].ss++;
		arr[r + 1].ss--;
	}

	fr (i, 1, n + 1) {
		arr[i].ss += arr[i - 1].ss;
		arr[i].ff += arr[i - 1].ff;
		a[i] = arr[i].ss * (i + 1);
	}

	fr (i, 1, n + 1) {
		a[i] -= arr[i].ff;
	}

	int m;
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		cout << a[x] << " ";
	}
	cout << endl;

	return 0;
}