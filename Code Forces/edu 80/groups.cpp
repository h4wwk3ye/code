//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 15/Jan/20 10:03:20 PM
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
		ve< int > arr (n);
		for (auto& i : arr)
			cin >> i;
		int m;
		cin >> m;

		auto check = [&](int mid) -> bool {
			int p = 1, s = arr[0];
			if (s > mid) return false;
			fr (i, 1, len (arr)) {
				if (arr[i] > mid) return false;
				s += arr[i];
				if (s > mid) {
					s = arr[i];
					p++;
				} else {
					s += arr[i];
				}
			}
			return p <= m;
		};

		int low = 0, high = 1e9, mid;
		int ans;
		while (low <= high) {
			mid = (low + high) >> 1;
			if (check (mid)) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		pr (ans);
	}
	return 0;
}