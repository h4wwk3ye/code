//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jan/20 03:33:44 PM
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

int n, d, p, k;
int dist[55], petr[55];
int dp[6000][200];

int solve (int curr_dist, int petrol) {
	int idx = upper_bound (dist, dist + n, curr_dist) - dist;
	if (idx >= n) {
		if (petrol <= d - dist[n - 1]) {
			return petrol + (d - dist[n - 1] - petrol) * 5;
		}
		return d - dist[n - 1];
	}

	int& ans = dp[curr_dist][petrol];
	if (ans != -1) return ans;

	int cost = dist[idx] - curr_dist;

	if (petrol > cost) {
		petrol -= cost;
		ans = cost + min (k + solve (dist[idx], petrol + petr[idx]), solve (dist[idx], petrol));
	} else {
		cost = petrol + (cost - petrol) * 5;
		petrol = 0;
		ans = cost + min (k + solve (dist[idx], petr[idx]), solve (dist[idx], 0));
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> d >> p >> k;
	fr (i, 0, n) cin >> dist[i];
	fr (i, 0, n) cin >> petr[i];
	reset (dp, -1);
	int ans = solve (0, p);
	pr (ans);
	return 0;
}