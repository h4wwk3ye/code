//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 01/Mar/20 05:39:00 PM
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
	int arr[3][3];
	fr (i, 0, 3) fr (j, 0, 3) cin >> arr[i][j];
	int n;
	cin >> n;
	fr (i, 0, n) {
		int k;
		cin >> k;
		fr (p, 0, 3) fr (q, 0, 3) if (arr[p][q] == k) arr[p][q] = -1;
	}
	bool flag = 0;
	fr (i, 0, 3) {
		if (arr[i][0] == -1 and arr[i][1] == -1 and arr[i][2] == -1) flag = 1;
	}
	fr (i, 0, 3) {
		if (arr[0][i] == -1 and arr[1][i] == -1 and arr[2][i] == -1) flag = 1;
	}

	if (arr[0][0] == -1 and arr[1][1] == -1 and arr[2][2] == -1) flag = 1;
	if (arr[0][2] == -1 and arr[1][1] == -1 and arr[2][0] == -1) flag = 1;
	pr (flag ? "Yes" : "No");
	return 0;
}