/*
				C++
				encoding: UTF-8
				Modified: <30/Jul/2019 01:10:20 PM>

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
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

string s;
const int N = 1e6 + 5;
ve< int > counter[N];

struct Trie {
	Trie* children[26];
	int val;
	Trie () {
		fr (i, 0, 26) this->children[i] = nullptr;
		this->val = 0;
	}
};

void insert (Trie* node) {
	for (auto i : s) {
		if (node->children[i - 'a'] == nullptr) {
			node->children[i - 'a'] = new Trie ();
		}
		node = node->children[i - 'a'];
		node->val++;
	}
}

void dfs (Trie* node, int height) {
	fr (i, 0, 26) {
		if (node->children[i] != nullptr) {
			counter[height].pb (node->children[i]->val);
			dfs (node->children[i], height + 1);
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int mx = 0;
	Trie* root = new Trie ();
	fr (i, 0, n) {
		cin >> s;
		mx = max (mx, len (s));
		insert (root);
	}
	dfs (root, 0);
	fr (i, 0, mx + 1) pr (counter[i]);
	return 0;
}
