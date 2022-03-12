/*
				C++
				encoding: UTF-8
				Modified: <12/Oct/2019 11:28:04 PM>

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
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 (int)v.size()
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, k, s;
	cin >> n >> k >> s;
	if ((k * (n - 1)) < s or s < k) {
		pr ("NO");
	} else {
		int x = n - 1;
		ve< int > op;
		int f = 1;
		int flag = -1;
		while (s - x >= k) {
			s -= x;
			k--;
			if (f)
				op.pb (n);
			else
				op.pb (1);
			f = 1 ^ f;
			flag = 1;
		}
		// pr (op);
		int y = (s - k);
		int idx;
		if (flag == -1) f = 1;
		if (!f) {
			op.pb (n - y - 1);
			idx = n - y - 1;
			k--;
		} else {
			op.pb (1 + y + 1);
			idx = 1 + y + 1;
			k--;
		}
		f = 0;
		while (k--) {
			if (f) {
				op.pb (idx);
			} else {
				if (idx - 1 == 0) {
					op.pb (idx + 1);
				} else {
					op.pb (idx - 1);
				}
			}
			f = (1 ^ f);
		}
		pr ("YES");
		for (int i : op) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
