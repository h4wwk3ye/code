//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/Nov/19 07:29:59 PM
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

int minSwaps (ve< pii > a, int n) {
	int ans = 0;
	fr (i, 0, n) {
		if (a[i].ss != i) {
			int count = 0;
			while (a[i].ss != i) {
				if (a[i].ff != a[a[i].ss].ff) {
					count++;
				}
				swap (a[i], a[a[i].ss]);
			}
			ans += count;
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	ve< pii > arr (n);
	fr (i, 0, n) cin >> arr[i].ss;
	fr (i, 0, n) cin >> arr[i].ff;

	int cnt = 0;
	fr (i, 0, n) {
		if (arr[i].ss > arr[i].ff) cnt++;
	}
	if (cnt == 0) {
		pr ("Yes");
		return 0;
	}
	sort (all (arr));

	ve< int > a (n), b (n);
	fr (i, 0, n) a[i] = arr[i].ss, b[i] = arr[i].ff;
	ve< pii > A (n);
	fr (i, 0, n) A[i] = {a[i], i};

	sort (all (A));
	int ans = minSwaps (A, n);
	sort (all (a));
	sort (all (b));
	fr (i, 0, n) {
		if (a[i] > b[i]) {
			pr ("No");
			return 0;
		}
	}
	// pr (ans);
	cnt = 0;
	fr (i, 0, n) {
		if (arr[i].ss > arr[i].ff) cnt++;
	}
	if (cnt < n / 2) {
		pr ("Yes");
		return 0;
	}
	pr (ans <= n - 2 ? "Yes" : "No");
	return 0;
}