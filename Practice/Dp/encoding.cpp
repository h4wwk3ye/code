/*
				C++
				encoding: UTF-8
				Modified: <17/Aug/2019 09:58:41 PM>

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

int dp[100005][11][2][2], num[100005][11][2][2];
int l, r;
string a, b;
const int mod = 1e9 + 7;

int pow (int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = (r * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return r;
}

int solve (int idx, int previous, int largerThanMin, int smallerthanMax) {
	if (idx == r) return 0;
	int& ans = dp[idx][previous][largerThanMin][smallerthanMax];
	if (ans != -1) return ans;
	ans = 0;
	fr (i, 0, 10) {
		if (i == previous) continue;
		if (!largerThanMin and (i < a[idx] - '0')) continue;
		if (!smallerthanMax and (i > b[idx] - '0')) continue;

		// pr (idx, i, ans, previous, i * pow (10, r - idx - 1));
		ans += ((i * pow (10, r - idx - 1)) +
				solve (idx + 1, i, largerThanMin | (i > a[idx] - '0'), smallerthanMax | (i < b[idx] - '0')));
		ans %= mod;
		// pr (idx, i, ans, previous, i * pow (10, r - idx - 1));
	}
	return ans;
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		reset (dp, -1);
		cin >> l >> a >> r >> b;
		int cnt = 0;
		string tmp = "";
		while (l != r) {
			tmp += "0";
			l++;
		}
		a = tmp + a;
		pr (solve (0, 10, 0, 0));
	}
	return 0;
}
