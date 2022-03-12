/*
				C++
				encoding: UTF-8
				Modified: <31/Aug/2019 11:00:34 PM>

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
	map< pii, ve< int > > ans;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		if (ans.find ({n, m}) != ans.end ()) {
			for (auto i : ans[{n, m}]) {
				cout << i << " ";
			}
			cout << endl;
			continue;
		}
		vector< int > tmp;
		tmp.pb (n * m);
		// cout << n * m << " ";

		fr (k, 2, n * m + 1) {
			set< pii > s;
			int x = k;
			int i = 1, j = 1;
			// s.insert ({1, 1});
			while (i <= n) {
				while (j <= m) {
					s.insert ({i, j});
					if (j + k > m) {
						int inc = ((k + j - 1) / m);
						if (inc == 0) inc++;
						i += inc;
						j = (j + k) % m;
						if (j == 0) j = m;
						break;
					} else {
						j += k;
					}
				}
			}
			// pr (k);
			// pr (s);
			i = 1;
			j = 1;
			int cnt = 0;
			int f = 0;
			while (i <= m) {
				while (j <= n) {
					s.insert ({j, i});
					// pr (j, i, k);
					if (j + k > n) {
						int inc = ((k + j - 1) / n);
						if (inc == 0) inc++;
						i += inc;
						j = (j + k) % n;
						if (j == 0) j = n;
						break;
					} else {
						j += k;
					}
				}
			}
			// pr (k);
			// pr (s);
			tmp.pb (len (s));
			// cout << len (s) << " ";
		}
		for (auto i : tmp) {
			cout << i << " ";
		}
		ans[{n, m}] = tmp;
		cout << endl;
	}
	return 0;
}
