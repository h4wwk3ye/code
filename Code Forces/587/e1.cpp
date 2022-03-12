/*
				C++
				encoding: UTF-8
				Modified: <21/Sep/2019 01:54:46 PM>

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

signed main () {
	// chrono::time_point< chrono::high_resolution_clock > start, end;
	// start = chrono::high_resolution_clock::now ();


	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	const int N = 1e8 + 5;
	string s = "";
	string p = "";
	int l = 0;
	int i = 1;
	while (len (s) < N) {
		p += to_string (i);
		s += p;
		i++;
	}
	pr (len (s));
	unordered_map< char, ve< int > > mp;
	fr (i, 0, 200) {
		mp[s[i]].pb (i + 1);
	}
	fr (i, 0, 9) {
		char x = '0' + i;
		pr (x, mp[x]);
	}
	/*int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		cout << s[n - 1] << "\n";
	}*/

	// end = chrono::high_resolution_clock::now ();
	// ll elapsed_time = chrono::duration_cast< chrono::milliseconds > (end - start).count ();
	// cout << "\nElapsed Time: " << elapsed_time << "ms\n";


	return 0;
}
