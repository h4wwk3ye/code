/*
				C++
				encoding: UTF-8
				Modified: <15/Oct/2019 01:11:50 PM>

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

//#define         int                    long long
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

const int N = 1e5 + 5;
ve< int > adj[N];
int arr[N];
pii edges[N];
ve< int > query;
ve< int > ans;
int n, d;

ordered_set s;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> d;
	fr (i, 1, n + 1) {
		cin >> arr[i];
	}
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		edges[i] = {u, v};
	}
	fr (i, 1, n) {
		int x;
		cin >> x;
		query.pb (x);
	}
	reverse (all (query));
	int c = 0;
	for (auto e : query) {
		int u = arr[edges[e].ff];
		int v = arr[edges[e].ss];
		int a = s.order_of_key (u + d + 1);
		int b = s.order_of_key (u);

		c += (a - b);
		a = s.order_of_key (u - d);
		c += (b - a);
		s.insert (u);

		pr (a, b, c);

		a = s.order_of_key (v + d + 1);
		b = s.order_of_key (v);

		c += (a - b);
		a = s.order_of_key (v - d);
		c += (b - a);

		pr (a, b, c);

		s.insert (v);
		ans.pb (c);
	}
	reverse (all (ans));
	pr (ans);
	return 0;
}
