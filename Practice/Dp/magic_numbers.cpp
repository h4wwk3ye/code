/*
				C++
				encoding: UTF-8
				Modified: <17/Aug/2019 07:25:02 PM>

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

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

int m, d;
string a, b;
const int mod = 1e9 + 7;
int dp[2005][2005][2][2];

int solve (int idx, int num, int largerThanMin, int smallerThanMax) {
	if (idx == len (a)) return num == 0;
	int& ans = dp[idx][num][largerThanMin][smallerThanMax];
	if (ans != -1) return ans;
	ans = 0;

	fr (i, 0, 10) {
		if (idx % 2 == 1 and i != d) continue;
		if (idx % 2 == 0 and i == d) continue;
		if (!largerThanMin and (i < a[idx] - '0')) continue;
		if (!smallerThanMax and (i > b[idx] - '0')) continue;

		ans +=
		solve (idx + 1, (num * 10 + i) % m, largerThanMin | (i > a[idx] - '0'), smallerThanMax | (i < b[idx] - '0'));
		ans %= mod;
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	reset (dp, -1);
	cin >> m >> d;
	cin >> a;
	cin >> b;
	pr (solve (0, 0, 0, 0));
	return 0;
}
