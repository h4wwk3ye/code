//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Mar/20 09:19:11 PM
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

const int N = 1e5 + 5;
int Parent[N], Rank[N];

int find_set (int v) {
	if (v == Parent[v]) return v;
	return Parent[v] = find_set (Parent[v]);
}


void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (Rank[a] < Rank[b]) swap (a, b);
		Parent[b] = a;
		if (Rank[a] == Rank[b]) Rank[a]++;
	}
}

pii points[N];
map< int, int > X, Y;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	fr (i, 1, n + 1) {
		Parent[i] = i;
		Rank[i] = 0;
	}
	fr (i, 1, n + 1) {
		int x, y;
		cin >> x >> y;
		points[i] = {x, y};
		if (X.find (x) != X.end ()) {
			int j = X[x];
			union_sets (i, j);
		} else {
			X[x] = i;
		}
		if (Y.find (y) != Y.end ()) {
			int j = Y[y];
			union_sets (i, j);
		} else {
			Y[y] = i;
		}
	}
	set< int > s;
	fr (i, 1, n + 1) {
		int j = find_set (i);
		s.insert (j);
	}
	pr (len (s));

	return 0;
}