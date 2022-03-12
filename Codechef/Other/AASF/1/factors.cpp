//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Mar/20 11:32:31 AM
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
int factor[N], ans[N];
pii dp[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	auto seive = [&]() {
		factor[1] = 1;

		for (int i = 2; i < N; i++)
			factor[i] = i;
		for (int i = 4; i < N; i += 2)
			factor[i] = 2;
		for (int i = 3; i * i < N; i++) {
			if (factor[i] == i) {
				for (int j = i * i; j < N; j += i) {
					if (factor[j] == j) factor[j] = i;
				}
			}
		}
	};

	seive ();

	auto no_of_factors = [&](int n) -> int {
		if (n == 1) return 1;

		int ans = 1;
		int dup = factor[n];
		int c = 1;
		int j = n / factor[n];

		while (j != 1) {
			if (factor[j] == dup)
				c++;
			else {
				dup = factor[j];
				ans = ans * (c + 1);
				c = 1;
			}
			j = j / factor[j];
		}
		ans = ans * (c + 1);

		return ans;
	};
	dp[0] = {0, 0};
	fr (i, 1, N) {
		ans[i] = no_of_factors (i);
		if (dp[i - 1].ff > ans[i] and ((dp[i - 1].ff * dp[i - 1].ss) + (i - dp[i - 1].ss)) > (ans[i] * i)) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = {ans[i], i};
		}
	}


	int tc;
	cin >> tc;
	while (tc--) {
		int i;
		cin >> i;
		int ans = (dp[i].ff * dp[i].ss) + (i - dp[i].ss);
		pr (ans);
	}

	return 0;
}