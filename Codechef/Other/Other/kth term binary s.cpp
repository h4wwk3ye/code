/*
				C++
				encoding: UTF-8
				Modified: <08/Sep/2019 03:45:59 PM>

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
#define int long long
int p, q, r, s;


int solve (int a, int b, int c, int k) {
	p = (a * b) / __gcd (a, b);
	q = (b * c) / __gcd (b, c);
	r = (c * a) / __gcd (c, a);
	s = (a * q) / __gcd (a, q);

	int low = 1, high = 1e18;
	while (low < high) {
		int mid = low + (high - low) / 2;

		int curr = ((mid / a) + (mid / b) + (mid / c) - (mid / p) - (mid / q) - (mid / r) + (mid / s));

		if (curr < k)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		int ans = solve (a, b, c, k);
		cout << ans << "\n";
	}
	return 0;
}
