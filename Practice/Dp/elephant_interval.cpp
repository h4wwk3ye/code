/*
				C++
				encoding: UTF-8
				Modified: <16/Oct/2019 06:54:43 PM>

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
#define         len(v)                 (int)v.size ()
#define         all(v)                 v.begin (), v.end ()
#define         reset(a, b)            memset(a, b, sizeof (a));
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

int l, r;
string str;
int dp[20][2][10][10];

int solve (int idx, int smallerThanNum, int f, int s) {
	if (idx == len (str)) {
		return f == s;
	}
	int& ans = dp[idx][smallerThanNum][f][s];
	if (ans != -1) return ans;
	ans = 0;
	fr (i, 0, 10) {
		if (!smallerThanNum and (i > str[idx] - '0')) continue;
		ans += solve (idx + 1, smallerThanNum | (i < str[idx] - '0'), (f == 0) ? i : f, i);
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> l >> r;

	reset (dp, -1);
	str = to_string (r);
	int ans = solve (0, 0, 0, 0);


	reset (dp, -1);
	str = to_string (l - 1);
	ans -= solve (0, 0, 0, 0);
	pr (ans);
	return 0;
}
