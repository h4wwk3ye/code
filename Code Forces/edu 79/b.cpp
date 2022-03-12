//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 27/Dec/19 08:53:05 PM
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
int n, s;
int arr[N], pref[N], mx[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		pref[0] = 0;
		cin >> n >> s;
		fr (i, 1, n + 1) cin >> arr[i];
		int curr = 0;
		fr (i, 1, n + 1) {
			pref[i] = pref[i - 1] + arr[i];
			curr = max (curr, arr[i]);
			mx[i] = curr;
		}
		int i = 1;
		curr = 0;
		int ans = 0;
		while (i <= n and curr <= s) {
			curr += arr[i];
			if (curr <= s) ans++;
			if (curr >= s) break;
			i++;
		}
		if (i == n + 1) {
			pr (0);
			continue;
		}

		int x = i - 1;
		curr -= mx[i];

		int p = i;

		i++;
		// pr (ans, i, curr);
		while (i <= n and curr <= s) {
			curr += arr[i];
			i++;
			if (curr <= s) x++;
		}

		// pr (x, ans, i);

		if (x <= ans) {
			pr (0);
			continue;
		}

		int idx = 0;
		// pr (arr[idx]);
		fr (j, 1, p + 1) {
			if (arr[j] > arr[idx]) {
				idx = j;
			}
		}
		pr (idx);
	}
	return 0;
}