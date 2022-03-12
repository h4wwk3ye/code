//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Dec/19 09:36:08 PM
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
int arr[N], dp[N][2];
int n, p, k, o;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> p >> k;
		fr (i, 1, n + 1) cin >> arr[i];
		sort (arr + 1, arr + n + 1);

		int i = 1;
		o = p;

		while (p > 0 and i < n) {
			if (arr[i + 1] <= p) {
				p -= (arr[i + 1]);
				i += 2;
			} else {
				break;
			}
		}

		int ans = i - 1;
		if (i == 1) {
			if (arr[1] <= p) {
				pr (1);
				continue;
			}
			pr (0);
			continue;
		}
		if (i > n) {
			pr (n);
			continue;
		}


		p += (arr[i - 1] - arr[i - 2]);

		if (p >= arr[i]) {
			ans++;
		}

		p = o;

		i = 2;
		while (p > 0 and i < n) {
			if (arr[i + 1] <= p) {
				p -= arr[i + 1];
				i += 2;
			} else {
				break;
			}
		}
		int x = i - 2;

		if (i > n) {
			if (p >= arr[1]) {
				x = n;
			}
			pr (max (ans, x));
			continue;
		}

		if (p >= arr[1]) {
			x++;
		} else {
			p += (arr[i - 1] - arr[i - 2]);
			if (p >= arr[i]) {
				x++;
				p -= arr[i];
			}
			if (p >= arr[1]) {
				x++;
			}
		}
		pr (max (x, ans));
	}
	return 0;
}

/*
1
7 33 2
2 3 14 14 17 17 18
*/