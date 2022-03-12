/*
				C++
				encoding: UTF-8
				Modified: <28/Sep/2019 07:45:40 PM>

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

int n;
const int N = 45;
int p[N], w[N], v[N];

map< pii, int > mp;

int solve (int i, int j) {
	if (i == n + 1) return 0;
	if (mp.find ({i, j}) != mp.end ()) return mp[{i, j}];

	int ans;
	if (w[i] >= j) {
		ans = max (solve (i + 1, j), solve (i + 1, j + p[i]) + v[i]);
	} else {
		ans = solve (i + 1, j);
	}
	mp[{i, j}] = ans;
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		mp.clear ();
		cin >> n;
		fr (i, 1, n + 1) {
			cin >> w[i] >> p[i] >> v[i];
		}
		pr (solve (1, 0));
	}
	return 0;
}
