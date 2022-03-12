/*
				C++
				encoding: UTF-8
				Modified: <09/Aug/2019 04:37:09 PM>

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

int n, m, k;
int arr[25];
int cost[25][25], rating[25][25];
int dp[25][1005][2];


signed main () {
    ios_base::sync_with_stdio (false), cin.tie (nullptr);
    int tc;
	cin >> tc;
	while (tc--) {
		reset (dp, -1);
		cin >> n >> m >> k;
		fr (i, 0, n) cin >> arr[i];
		fr (i, 0, n) fr (j, 0, m) cin >> cost[i][j];
		fr (i, 0, n) fr (j, 0, m) cin >> rating[i][j];
	}
    return 0;
}
