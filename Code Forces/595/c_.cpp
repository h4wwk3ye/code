/*
				C++
				encoding: UTF-8
				Last Modified: 22/Oct/2019 10:18:39 PM
*/

#include <bits/stdc++.h>


using namespace std;

// clang-format off

#define		 int                    long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n"
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 (int)v.size()
#define		 aint(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

long long power (long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

#define ll long long
ll freq[40];
ll pref_sum[40];
signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	freq[1] = 1, freq[0] = 0;
	fr (i, 2, 40) freq[i] = freq[i - 1] * 3;

	pref_sum[0] = 0;
	fr (i, 1, 40) pref_sum[i] = freq[i] + pref_sum[i - 1];
	int tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;
		ll idx = upper_bound (freq, freq + 40, n) - freq - 1;
		ll ans = 0;
		while (n) {
			if (n > pref_sum[idx]) {
				ans += freq[idx + 1];
				break;
			}
			ans += freq[idx];
			n -= freq[idx];
			ll idx2 = upper_bound (freq, freq + 40, n) - freq - 1;

			if (idx2 == idx) {
				break;
			}
			idx = idx2;
		}
		pr (ans);
	}
	return 0;
}
