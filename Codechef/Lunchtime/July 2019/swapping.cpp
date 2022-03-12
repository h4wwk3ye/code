/*
				C++
				encoding: UTF-8
				Modified: <27/Jul/2019 07:57:28 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettyprint.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

const int N = 1e5 + 5;
ll arr[N], n, dp[N];

ll solve (ll i) {
	if (i == n + 1) return 0;
	if (dp[i] != -1) return dp[i];
	if (i + 1 <= n) {
		dp[i] = max (arr[i] * i + solve (i + 1), arr[i] * (i + 1) + arr[i + 1] * i + solve (i + 2));
	} else
		dp[i] = (arr[i] * i + solve (i + 1));
	return dp[i];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 1, n + 1) {
			cin >> arr[i];
			dp[i] = -1;
		}
		print (solve (1));
	}
	return 0;
}
