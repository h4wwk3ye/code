/*
				C++
				encoding: UTF-8
				Modified: <07/Oct/2019 09:35:52 PM>

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
ve< int > graph[N];
int parent[N];
int n;
ve< int > roots;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	auto init = [&]() -> void {
		fr (i, 0, n + 1) {
			graph[i].clear ();
			parent[i] = 0;
		}
	};
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init ();
		fr (i, 1, n + 1) {
			int x, y;
			cin >> x >> y;
			if (y == 0) {
				roots.pb (x);
			} else {
				parent[x] = y;
				graph[x].pb (y);
				graph[y].pb (x);
			}
		}
	}
	return 0;
}
