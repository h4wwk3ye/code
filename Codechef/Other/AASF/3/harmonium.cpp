//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Mar/20 09:52:29 PM
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
int n, q;
int arr[N];

struct Trie {
	Trie* child[2];
	Trie () {
		this->child[0] = nullptr;
		this->child[1] = nullptr;
	}
};

void insert (Trie* root, int val) {
	Trie* node = root;
	dfr (i, 20, -1) {
		int c = (val >> i) & 1;
		if (!node->child[c]) node->child[c] = new Trie ();
		node = node->child[c];
	}
}

bool query (Trie* root, int val, int bit) {
	if (!root) return false;
	if (bit == -1) return true;
	int c = (val >> bit) & 1;
	bool ans;
	if (!c) { // both can be tried;
		ans = query (root->child[0], val, bit - 1) or query (root->child[1], val, bit - 1);
	} else {
		ans = query (root->child[0], val, bit - 1);
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	Trie* root = new Trie ();
	fr (i, 1, n + 1) {
		cin >> arr[i];
		insert (root, arr[i]);
	}
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		bool ans = query (root, x, 20);
		pr (ans ? "Yes" : "No");
	}
	return 0;
}