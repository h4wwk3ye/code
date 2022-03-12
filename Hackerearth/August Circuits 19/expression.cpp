/*
				C++
				encoding: UTF-8
				Modified: <27/Aug/2019 09:48:19 AM>

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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	fr (i, 0, n) cin >> a[i];
	fr (i, 0, n) cin >> b[i];
	fr (i, 0, n) cin >> c[i];
	ve< int > d (n, 0);
	fr (i, 0, n) {
		string ans = "";
		int a_bit, b_bit, c_bit;
		for (int bit = 31; bit >= 0; bit--) {
			a_bit = (a[i] >> bit) & 1;
			b_bit = (b[i] >> bit) & 1;
			c_bit = (c[i] >> bit) & 1;

			if (a_bit == 1 and b_bit == 1) {
				if (c_bit)
					ans += "1";
				else
					ans += "0";
			} else if (a_bit == 1 and b_bit == 0) {
				ans += "0";
			} else if (a_bit == 0 and b_bit == 1) {
				ans += "0";
			} else {
				if (c_bit)
					ans += "1";
				else
					ans += "0";
			}
		}

		reverse (all (ans));
		int base = 1;
		for (char bit : ans) {
			if (bit == '1') d[i] += base;
			base *= 2;
		}

		if (d[i] == 0) {
			fr (bit, 0, 32) {
				if ((c[i] >> bit) & 1) {
					d[i] = 1 << bit;
					break;
				}
			}
		}
	}
	int ans = 0;
	fr (i, 0, n) ans += a[i] ^ b[i] ^ d[i];
	pr (ans);
	return 0;
}
