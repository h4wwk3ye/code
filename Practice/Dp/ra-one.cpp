/*
				C++
				encoding: UTF-8
				Modified: <21/Aug/2019 03:43:37 PM>

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

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on

string l, r;
int dp[9][2][2][100][2];

int solve (int idx, int largerThanMin, int smallerThanMax, int diff, int f) {
	if (idx == len (r)) {
		return diff == 1;
	}
	int& ans = dp[idx][largerThanMin][smallerThanMax][diff][f];
	if (ans != -1) return ans;
	ans = 0;
	fr (i, 0, 10) {
		if (!largerThanMin and (i < l[idx] - '0')) continue;
		if (!smallerThanMax and (i > r[idx] - '0')) continue;
		if (!f) {
			ans +=
			solve (idx + 1, largerThanMin | i > l[idx] - '0', smallerThanMax | i < r[idx] - '0', diff + i, 1 - f);
		} else
			ans +=
			solve (idx + 1, largerThanMin | i > l[idx] - '0', smallerThanMax | i < r[idx] - '0', diff - i, 1 - f);
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		reset (dp, -1);
		cin >> l >> r;
		string tmp = "";
		int x = len (r) - len (l);
		while (x--) {
			tmp += "0";
		}
		l = tmp + l;
		pr (solve (0, 0, 0, 0, len (r) % 2 == 1));
	}
	return 0;
}
