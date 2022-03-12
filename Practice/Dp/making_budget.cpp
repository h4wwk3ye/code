/*
				C++
				encoding: UTF-8
				Modified: <27/Aug/2019 11:21:52 PM>

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

int agency, salary, fire;
int workers[25];
int dp[25][305];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		cout << "Case " << tc << ", cost = $";
		cin >> agency >> salary >> fire;
		int mx = 0;
		fr (i, 1, n + 1) {
			cin >> workers[i];
			mx = max (mx, workers[i]);
		}
		fr (i, 0, n + 1) fr (j, 0, mx + 1) dp[i][j] = 1e18;

		fr (i, workers[1], mx + 1) dp[1][i] = (salary * i) + (agency * i);

		fr (i, 2, n + 1) {
			fr (j, 0, mx + 1) {
				if (j < workers[i]) continue;
				fr (k, 0, mx + 1) {
					if (k >= j) {
						dp[i][j] = min (dp[i][j], dp[i - 1][k] + (fire * (k - j)) + (salary * j));
					} else {
						dp[i][j] = min (dp[i][j], dp[i - 1][k] + (agency * (j - k)) + (salary * j));
					}
				}
			}
		}

		int ans = 1e9;
		fr (i, workers[n], mx + 1) ans = min (ans, dp[n][i]);
		cout << ans << endl;
		tc++;
	}
	return 0;
}
