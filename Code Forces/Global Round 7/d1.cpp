#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 20/Mar/20 10:10:30 AM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

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
	int tc;
	cin >> tc;

	auto ispalindrome = [](string& t) -> bool {
		int i = 0, j = len (t) - 1;
		while (i < j) {
			if (t[i] != t[j]) return false;
			i++;
			j--;
		}
		return true;
	};

	// chrono::time_point< chrono::high_resolution_clock > start, end;
	// start = chrono::high_resolution_clock::now ();
	while (tc--) {
		string s;
		//string s(5000,'1');
		cin >> s;
		string ans;
		fr (i, 0, len (s)) {
			string tmp = s.substr (0, i + 1);
			if (ispalindrome (tmp)) {
				if (len (ans) < len (tmp)) ans = tmp;
			}
			tmp = s.substr (i, len (s) - i);
			if (ispalindrome (tmp)) {
				if (len (ans) < len (tmp)) ans = tmp;
			}
		}
		fr (i, 0, len (s)) {
			fr (j, i + 1, len (s)) {
				if (i + 1 + len(s) - j <= len(ans)) continue;
				string tmp = s.substr (0, i + 1) + s.substr (j, len (s) - j);
				if (ispalindrome (tmp)) {
					if (len (ans) < len (tmp)) ans = tmp;
				}
			}
		}
		pr (ans);
	}
	// end = chrono::high_resolution_clock::now ();
	// int elapsed_time = chrono::duration_cast< chrono::milliseconds > (end - start).count ();
	// cout << "\nElapsed Time: " << elapsed_time << "ms\n";


	return 0;
}