//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Mar/20 01:29:54 PM
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

const int N = 1e3 + 5;
int n;
int arr[N];


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	auto check = [&](int mid) -> bool {
		vector< pii > ar (n + 1);
		fr (i, 1, n + 1) ar[i] = {arr[i], 0};
		bool f = 0;
		fr (i, 2, n + 1) {
			if (ar[i - 1].ss) {
				if (ar[i - 1].ff >= ar[i].ff + mid) return false;
				if (ar[i].ff <= ar[i - 1].ff) {
					ar[i].ss = 1;
				}
				ar[i].ff = 1 + ar[i - 1].ff;
			} else {
				if (ar[i].ff + mid <= ar[i - 1].ff - mid) return false;
				if (ar[i].ff <= ar[i - 1].ff - mid) {
					ar[i].ss = 1;
				}
				ar[i].ff = 1 + ar[i - 1].ff - mid;
			}
		}
		return true;
	};

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 1, n + 1) cin >> arr[i];
		int ans = 1e9;
		int low = 0, high = 1e9;
		while (low <= high) {
			int mid = (low + high) >> 1;

			if (check (mid)) {
				high = mid - 1;
				ans = mid;
			} else {
				low = mid + 1;
			}
		}
		pr (ans);
	}
	return 0;
}