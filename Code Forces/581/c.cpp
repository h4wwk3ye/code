/*
				C++
				encoding: UTF-8
				Modified: <21/Aug/2019 09:56:05 AM>

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

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int adj[n + 1][n + 1];
	int dist[n + 1][n + 1];
	fr (i, 1, n + 1) {
		fr (j, 1, n + 1) {
			char ch;
			cin >> ch;
			int c = ch - '0';
			adj[i][j] = c;

			dist[i][j] = 1e9;
			if (i == j)
				dist[i][j] = 0;
			else if (adj[i][j] == 1)
				dist[i][j] = 1;
		}
	}
	int m;
	cin >> m;
	int p[m + 1];
	fr (i, 1, m + 1) cin >> p[i];

	fr (k, 1, n + 1) {
		fr (i, 1, n + 1) {
			fr (j, 1, n + 1) {
				dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	ve< int > ans;
	int i = 1, j = 1;
	while (i <= m and j <= m - 1) {
		ans.pb (p[i]);
		while (j <= m and dist[p[i]][p[j]] == j - i)
			j++;
		j--;
		i = j;
	}
	ans.pb (p[m]);
	pr (len (ans));
	for (int x : ans)
		cout << x << " ";
	return 0;
}
