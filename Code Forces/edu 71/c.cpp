/*
				C++
				encoding: UTF-8
				Modified: <22/Aug/2019 09:19:36 PM>

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

const int N = 2e5 + 5;
int n, a, b;
int dp[N][2];
string s;

int solve (int i, int j) {
	if (i == n) return b;
	int& ans = dp[i][j];
	if (ans != -1) return ans;
	if (s[i] == '1') {
		ans = 2 * b + a + solve (i + 1, 1);
	} else {
		if (i + 1 < n) {
			if (s[i + 1] == '1') {
				if (j == 1)
					ans = 2 * b + a + solve (i + 1, 1);
				else
					ans = b + 2 * a + solve (i + 1, 1);
			} else {
				if (j == 0)
					ans = b + a + solve (i + 1, 0);
				else
					ans = min (2 * b + 2 * a + solve (i + 1, 0), 2 * b + a + solve (i + 1, 1));
			}
		} else {
			if (j == 1) {
				ans = 2 * b + 2 * a + solve (i + 1, 0);
			} else
				ans = b + a + solve (i + 1, 0);
		}
	}
	return ans;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> a >> b;
		fr (i, 0, n + 2) {
			dp[i][0] = -1;
			dp[i][1] = -1;
		}
		cin >> s;
		pr (solve (0, 0));
	}
	return 0;
}
