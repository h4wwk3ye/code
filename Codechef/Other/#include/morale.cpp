//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 29/Mar/20 09:41:30 PM
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
	int n, k, m;
	cin >> n >> k >> m;
	ve< int > arr (n);
	fr (i, 0, n) cin >> arr[i];
	bool flag = 0;
	fr (i, 0, n) {
		int j = i;
		int cnt = 0;
		while (j < n and !arr[j]) {
			j++;
			cnt++;
		}
		if (cnt >= k) flag = 1;
	}
	if (flag) {
		pr (-1);
		return 0;
	}
	ve< int > p (n);
	int x = -1;
	fr (i, 0, n) {
		if (arr[i]) x = i;
		p[i] = x;
	}
	int curr = 0, ans = 0;
	int cnt = 0;
	fr (i, 0, n) {
		if (cnt < k) {
			curr += arr[i];
		} else {
			if (curr < m) { // update from  previous non zero index to +k
				ans++;
				i = p[i - 1] + k - 1 + k - 1;
				if (i < n) curr = arr[i];
				cnt = 1;
				continue;
			}
		}
		cnt++;
	}

	pr (ans);

	return 0;
}