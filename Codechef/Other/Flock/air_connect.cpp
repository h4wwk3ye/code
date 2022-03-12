//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jan/20 04:13:48 PM
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

#define ld long double

const int N = 1e3 + 5;
int Parent[N], Size[N], color[N];
int n;
int scc;

int find (int x) {
	if (Parent[x] == x) return x;
	return Parent[x] = find (Parent[x]);
}

int merge (int x, int y) {
	int x_id = find (x);
	int y_id = find (y);
	if (x_id == y_id) return 0;
	x = x_id, y = y_id;
	scc--;
	if (Size[x] < Size[x]) {
		swap (x, y);
	}
	Parent[y] = x;
	Size[x] += Size[y];
	return 1;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	auto init = [&]() -> void {
		fr (i, 0, n + 5) {
			Size[i] = 1;
			Parent[i] = i;
		}
		scc = n;
	};

	auto manhattan = [&](pii& a, pii& b) -> int { return abs (a.ff - b.ff) + abs (a.ss - b.ss); };

	auto eucledian = [&](pii& a, pii& b) -> ld {
		ld ans = sqrt (pow ((a.ff - b.ff), 2) + pow ((a.ss - b.ss), 2));
		return ans;
	};

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init ();
		pii arr[n + 1];
		fr (i, 1, n + 1) cin >> arr[i].ff >> arr[i].ss;
		ve< pair< ld, pii > > edges;
		fr (i, 1, n + 1) {
			fr (j, i + 1, n + 1) {
				if (manhattan (arr[i], arr[j]) <= 1) {
					edges.pb ({0, {i, j}});
				} else {
					ld dist = eucledian (arr[i], arr[j]);
					edges.pb ({dist, {i, j}});
				}
			}
		}
		ld dist = 0;
		sort (all (edges));
		for (auto& edge : edges) {
			int x = edge.ss.ff;
			int y = edge.ss.ss;
			ld d = edge.ff;
			int chk = merge (x, y);
			if (chk) dist += d;
		}
		cout << fixed << setprecision (6) << dist << "\n";
	}
	return 0;
}