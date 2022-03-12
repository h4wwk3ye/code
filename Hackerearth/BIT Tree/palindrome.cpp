/*
				C++
				encoding: UTF-8
				Modified: <04/Oct/2019 04:45:05 PM>

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
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
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

const int N = 1e5 + 5;
int arr[N];
int bit[N][26];
string s;
int n, q;

void update (int i, int c, int val) {
	while (i <= n) {
		bit[i][c] += val;
		i += (i & (-i));
	}
}

ve< int > query (int i) {
	ve< int > sum (26, 0);
	while (i > 0) {
		fr (j, 0, 26) {
			sum[j] += bit[i][j];
		}
		i -= (i & (-i));
	}
	return sum;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	cin >> s;
	fr (i, 1, n + 1) {
		arr[i] = s[i - 1] - 'a';
		update (i, arr[i], 1);
	}

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i;
			char x;
			cin >> i >> x;
			update (i, arr[i], -1);
			arr[i] = x - 'a';
			update (i, arr[i], 1);
		} else {
			int l, r;
			cin >> l >> r;
			ve< int > a = query (l - 1);
			ve< int > b = query (r);
			ve< int > c (26, 0);
			fr (i, 0, 26) c[i] = b[i] - a[i];
			string ans = "yes";
			int cnt = 0;
			for (auto i : c) {
				if (i & 1) cnt++;
			}
			if (cnt > 1) ans = "no";
			pr (ans);
		}
	}

	return 0;
}
