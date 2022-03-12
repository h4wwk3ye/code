//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 12/Dec/19 08:55:47 PM
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

const int N = 2e5 + 5;
int arr[N];
int n;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	int ans = 0, curr1 = 0, curr2 = 0;
	bool f = 0;
	fr (i, 1, n + 1) {
		if (arr[i] > arr[i - 1]) {
			if (!f)
				curr1++;
			else
				curr2++;

		} else {
			if (f) {
				curr1 = curr2;
				curr2 = 1;
			} else {
				curr2 = 1;
			}
			f = 1 ^ f;
		}
		// pr (curr1, curr2);
		if (curr2 == 0)
			ans = max (ans, curr1 + curr2);
		else
			ans = max (ans, curr1 + curr2 - 1);
	}
	pr (ans);
	return 0;
}