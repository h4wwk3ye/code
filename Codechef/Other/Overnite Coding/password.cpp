#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Feb/20 11:40:18 PM
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
ve< int > graph[N];
int n;
string arr[N];
map< string, int > r;
map< int, string > t;
unordered_map< int, int > mp[N];

void dfs (int node, int parent) {
	mp[node][r[arr[node]]] = 1;
	for (auto& to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
		for (auto& i : mp[to]) {
			mp[node][i.ff] += i.ss;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	int c = 0;
	fr (i, 1, n + 1) {
		cin >> arr[i];
		if (r.find (arr[i]) == r.end ()) {
			c++;
			r[arr[i]] = c;
			t[c] = arr[i];
		}
		mp[i].max_load_factor (0.25);
		mp[i].reserve (n + 1);
	}
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dfs (1, 1);

	auto isPrime = [](int x) -> bool {
		if (x < 2) return false;
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) return false;
		}
		return true;
	};

	fr (i, 1, n + 1) {
		ve< int > a (26, 0);
		ve< int > b (26);
		for (auto& j : mp[i]) {
			if (isPrime (j.ss)) {
				b.assign (26, 0);
				for (auto& k : t[j.ff]) {
					b[k - 'a']++;
					a[k - 'a'] = max (a[k - 'a'], b[k - 'a']);
				}
			}
		}
		for (auto& j : a)
			cout << j;
		cout << endl;
	}

	return 0;
}