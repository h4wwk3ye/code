/*
				C++
				encoding: UTF-8
				Modified: <16/Oct/2019 12:35:58 PM>

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

const int N = 4e5 + 5;
int n, d, k;
ve< int > graph[N];
int depth[N], deg[N];
set< int > s, chk;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> d >> k;
	if (d >= n) {
		pr ("NO");
		return 0;
	}
	int t = d;
	int x = 1;
	fr (i, 1, n + 1) {
		chk.insert (i);
	}
	depth[1] = 1;
	t--;
	while (t--) {
		graph[x].pb (x + 1);
		graph[x + 1].pb (x);
		deg[x]++;
		deg[x + 1]++;

		s.insert (x);
		s.insert (x + 1);
		if (deg[x] == k) {
			if (chk.find (x) != chk.end ()) {
				chk.erase (x);
			}
		}
		if (deg[x + 1] == k) {
			if (chk.find (x + 1) != chk.end ()) {
				chk.erase (x + 1);
			}
		}
		x++;
	}
	pr (x);
	deg[x] = k;
	chk.erase (x);
	int j = 1;
	while (deg[j] == k)
		j++;
	fr (i, 1, n + 1) {
		if (s.find (i) != s.end ()) continue;
		while (deg[j] == k)
			j++;

		s.insert (i);
		graph[i].pb (j);
		graph[j].pb (i);
		deg[i]++;
		deg[j]++;
		if (deg[i] == k) {
			if (chk.find (i) != chk.end ()) {
				chk.erase (i);
			}
		}
		if (deg[j] == k) {
			if (chk.find (j) != chk.end ()) {
				chk.erase (j);
			}
		}
	}
	fr (i, 1, n + 1) {
		cout << i << " " << graph[i] << "\n";
	}

	return 0;
}
