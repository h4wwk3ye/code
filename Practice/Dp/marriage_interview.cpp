/*
				C++
				encoding: UTF-8
				Modified: <09/Aug/2019 01:35:29 PM>

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
    cout << t << "";
    pr (tail...);
}

// clang-format on

typedef unsigned __int64 datatype;
datatype cnt;

datatype dp[65][65];

datatype trib (int n, unsigned int back) {
	datatype sum = 0;
	int i;
	cnt++;
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (dp[n][back] != -1) {
		// cnt += (back * back);
		return dp[n][back];
	}
	for (i = 1; i <= back; i++)
		sum += trib (n - i, back);
	// dp[n][back] = sum;
	return sum;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	datatype n, back;
	int tc = 1;
	while (1) {
		// reset (dp, -1);
		cin >> n >> back;
		if (n > 60) break;
		if (n == 1) {
			pr ("Case ", tc, ": ", 1);
			continue;
		}
		n--;
		datatype ans = 2 + (n + 1) * pow (2, n - 1) - 1;
		pr ("Case ", tc, ": ", ans);
		tc++;
	}
	return 0;
}
