/*
				C++
				encoding: UTF-8
				Modified: <14/Aug/2019 05:44:35 PM>

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

int w, h;
char arr[105][105];
int dp[105][105][105]; // x1, y1, x2. Since x1 + y1 = x2 + y2. Rduces dp states from 4 to 3

int cost (int x, int y) {
	if (arr[x - 1][y - 1] == '#') return -1 * 1e9;
	if (arr[x - 1][y - 1] == '*') return 1;
	return 0;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		reset (dp, 0);
		cin >> w >> h;
		fr (i, 0, h) {
			cin >> arr[i];
		}

		fr (i, 1, h + 1) {
			fr (j, 1, w + 1) {
				if (cost (i, j) == -1 * 1e9) continue;
				int x = min (100, i + j);
				fr (k, i, x + 1) {
					dp[i][j][k] = max (max (dp[i - 1][j][k], dp[i][j - 1][k]),
									   max (dp[i - 1][j][k - 1], dp[i][j - 1][k - 1])) +
								  cost (i, j);
					if (i != k) dp[i][j][k] += cost (k, i + j - k);
				}
			}
		}
		pr (dp[h][w][h]);
	}
	return 0;
}
