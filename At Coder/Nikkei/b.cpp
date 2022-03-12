//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/Nov/19 06:41:36 PM
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

const int mod = 998244353;
const int N = 1e5 + 5;
int arr[N], d[N];
int n;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	cin >> n;
	fr (i, 1, n + 1) {
		cin >> arr[i];
		d[arr[i]]++;
		d[arr[i]] %= mod;
	}
	auto power = [&] (int a, int b) {
		int ans = 1;
		while (b) {
			if (b & 1) {
				ans = ans * a;
				ans %= mod;
			}
			a *= a;
			a %= mod;
			b >>= 1;
		}
		return ans;
	};

	int ans = 1;
	bool f = 0;
	if (arr[1] or d[0] > 1) {
		pr (0);
		return 0;
	}
	fr (i, 1, N) {
		if (!d[i]) {
			f = 1;
			continue;
		}
		if (f) {
			pr (0);
			return 0;
		}

		ans *= power (d[i - 1], d[i]);
		ans %= mod;
	}
	pr (ans);
	return 0;
}