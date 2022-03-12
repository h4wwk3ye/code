/*
				C++
				encoding: UTF-8
				Modified: <31/Aug/2019 10:55:53 AM>

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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		string a, b;
		string c = "";
		cin >> a >> b;
		reverse (all (a));
		reverse (all (b));
		int n = len (a);
		int m = len (b);
		int carry = 0;
		if (n < m) {
			swap (a, b);
			swap (n, m);
		}
		int i = n - 1, j = m - 1;
		while (1) {
			if (j < 0) break;
			int rem = (a[i] - '0' + b[j] - '0' + carry) % 10;
			c += to_string (rem);
			if ((a[i] - '0' + b[j] - '0') + carry >= 10) {
				carry = 1;
			} else {
				carry = 0;
			}
			i--;
			j--;
		}
		while (1) {
			if (i < 0) break;
			int rem = (a[i] - '0' + carry) % 10;
			c += to_string (rem);
			if ((a[i] - '0') + carry >= 10) {
				carry = 1;
			} else {
				carry = 0;
			}
			i--;
		}
		if (carry) c += "1";
		reverse (all (c));
		while (c.back () == '0')
			c.pop_back ();
		reverse (all (c));
		pr (c);
	}
	return 0;
}
