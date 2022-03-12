/*
				C++
				encoding: UTF-8
				Modified: <17/Oct/2019 06:41:21 PM>

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

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int a[N];
int aux[N];

int n, mx;
void init () {
	fr (i, 0, mx + 5) aux[i] = 0;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		reset (aux, 0);
		int maxx = 0;
		unordered_set< int > s;
		// s.max_load_factor (0.25);
		fr (i, 0, n) {
			cin >> a[i];
			maxx = max (maxx, a[i]);
			s.insert (a[i]);
		}
		init ();
		sort (a, a + n);
		int ans = 0;
		fr (i, 0, n) {
			aux[a[i]]++;
			aux[a[i]] %= mod;
			for (int j = 2 * a[i]; j < maxx + 5; j += a[i]) {
				if (s.find (j) == s.end ()) continue;
				aux[j] += aux[a[i]];
				aux[j] %= mod;
			}
			ans += aux[a[i]];
			ans %= mod;
		}
		pr (ans);
	}
}
