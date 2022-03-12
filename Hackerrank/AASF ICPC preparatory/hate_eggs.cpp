/*
				C++
				encoding: UTF-8
				Modified: <15/Oct/2019 11:06:49 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         int                    long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 (int)v.size()
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

string a, b;
set< string > s;

// int dp[20][2][2];

int solve (int idx, int largerThanMin, int smallerThanMax) {
	if (idx == len (a)) {
	}
	int& ans = dp[idx][largerThanMin][smallerThanMax];
	if (ans != -1) return ans;
	ans = 0;

	fr (i, 0, 10) {
		if (!largerThanMin and (i < a[idx] - '0')) continue;
		if (!smallerThanMax and (i > b[idx] - '0')) continue;

		int ans = solve (idx + 1, largerThanMin | (i > a[idx] - '0'), smallerThanMax | (i < b[idx] - '0'));
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> a >> b;
	reset (dp, -1);
	while (len (n) != len (m)) {
		m = "0" + m;
	}
	solve (0, 0, 0);
	return 0;
}
