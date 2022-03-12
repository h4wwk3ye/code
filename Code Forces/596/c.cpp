/*
				C++
				encoding: UTF-8
				Last Modified: 26/Oct/2019 06:33:11 PM
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

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
#define		 all(v)                 v.begin(), v.end()
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


ve< string > str;

long long binpow (long long a, long long b) {
	if (b == 0) return 1;
	long long res = binpow (a, b / 2);
	if (b % 2)
		return res * res * a;
	else
		return res * res;
}

int solve (int n) {
	string b = bitset< 33 > (n).to_string ();
	for (string& s : str) {
		pr (s, b);
		int f = 0;
		int j;
		dfr (i, 33, -1) {
			if (s[i] == '1') {
				j = i;
				break;
			}
		}
		dfr (x, j, -1) {
			if (s[x] == 1 and b[x] == 0) {
				f = 1;
				break;
			}
		}

		if (!f) {
			int x = stoll (s, nullptr, 2);
			pr (s, b, x, f);
			n -= x;
			return n;
		}
	}
}


signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, p;
	cin >> n >> p;
	if (p >= n) {
		pr (-1);
		return 0;
	}
	string s = "";
	dfr (i, 33, -1) {
		int c = (n >> i) & 1;
		if (c)
			s += '1';
		else
			s += '0';
	}


	dfr (i, 32, -1) {
		int j = binpow (2, i);
		j += p;
		string b = bitset< 33 > (j).to_string ();
		str.pb (b);
	}
	sort (all (str));
	reverse (all (str));
	// pr (str);
	int ans = 0;
	n += p;
	while (n) {
		ans++;
		n = solve (n);
		// pr (n);
	}
	pr (ans);
	return 0;
}
