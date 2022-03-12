/*
				C++
				encoding: UTF-8
				Last Modified: 18/Oct/2019 08:45:25 PM

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

const int N = 1e5 + 5;
string s, arr[N];
int n, k;
string dp[(int)1e6 + 5][20];
ve< int > g (N);

void init () {
	fr (i, 0, n) {
		fr (j, 0, 20) {
			dp[i][j] = "";
		}
	}
	return;
}

void precompute () {
	fr (i, 0, n) {
		string tmp = "";
		set< int > mp;
		int j = i;
		while (len (tmp) != 20 and j < n) {
			if (mp.find (s[j]) == mp.end ()) {
				mp.insert (s[j]);
				tmp += s[j];
			}
			if (dp[i][len (mp)] == "") {
				dp[i][len (mp)] = tmp;
			}
			j++;
		}
	}
	fr (i, 1, k + 1) {
		string tmp = "";
		fr (j, 0, 20) {
			if (arr[i][j] - 'a') }
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		init ();
		cin >> s >> k;
		fr (i, 1, k + 1) {
			cin >> arr[i];
		}
		precompute ();

		fr (i, 0, n) {
			dfr (j, 20, 0) {
				if (i + j >= n) continue;
				string tmp = dp[i][j];
			}
		}
	}
	return 0;
}
