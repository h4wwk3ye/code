/*
				C++
				encoding: UTF-8
				Last Modified: 24/Sep/20 11:30:51 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << ' ';
	print (u, args...);
}

struct Trie {
	Trie* child[2];
	int cnt;
	Trie () {
		child[0] = child[1] = nullptr;
		cnt = 0;
	}
};

void insert (Trie* node, int val) {
	for (int i = 34; i >= 0; --i) {
		int c = (val >> i) & 1;
		if (!node->child[c]) node->child[c] = new Trie ();
		node = node->child[c];
		if (c) {
			node->cnt++;
			return; // dont need to go any further
		}
	}
}

int query (Trie* node, int val) {
	int ans = 0;
	unordered_set< int > s;
	for (int i = 34; i >= 0; --i) {
		int c = (val >> i) & 1;
		if (!node->child[c]) return ans;
		node = node->child[c];
		if (c) {
			ans += node->cnt;
			return ans;
		}
	}
	return ans;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector< int > arr (n);
		for (auto& i : arr)
			cin >> i;
		int ans = 0;
		Trie* root = new Trie ();
		for (size_t i = 0; i < n; i++) {
			ans += query (root, arr[i]);
			insert (root, arr[i]);
		}
		print (ans);
	}
	return 0;
}