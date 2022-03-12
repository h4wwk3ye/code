/*
				C++
				encoding: UTF-8
				Modified: <31/Aug/2019 12:05:53 PM>

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

ll n, p;
const ll N = 1e4 + 5;
ll dp[N][N];
ll arr[N];

ll solve (ll i, ll j) {
	if (j > p) return 2e18;
	if (i == n + 1) {
		if (j == p) return 0;
		return 2e18;
	}
	ll& ans = dp[i][j];
	if (ans != 1e18) return ans;
	if (j == 0) {
		ans = arr[i] * (j + 1) + solve (i + 1, j + 1);
	} else
		ans = min (arr[i] * (j + 1) + solve (i + 1, j + 1), solve (i + 1, j) + arr[i] * j);

	return ans;
}

signed main () {
	/*chrono::time_point< chrono::high_resolution_clock > start, end;
	start = chrono::high_resolution_clock::now ();*/


	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	// freopen ("inp.txt", "r", stdin);
	cin >> n >> p;
	fr (i, 1, n + 1) cin >> arr[i];
	fr (i, 0, n + 3) fr (j, 0, p + 3) {
		dp[i][j] = 1e18;
	}
	pr (solve (1, 0));


	/*end = chrono::high_resolution_clock::now ();
	ll elapsed_time = chrono::duration_cast< chrono::milliseconds > (end - start).count ();
	cout << "\nElapsed Time: " << elapsed_time << "ms\n";*/
	return 0;
}
