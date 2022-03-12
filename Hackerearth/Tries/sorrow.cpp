/*
				C++
				encoding: UTF-8
				Modified: <28/Jul/2019 05:44:06 PM>

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

void pr (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

struct Trie {
	Trie* children[26];
	int val;
	Trie () {
		fr (i, 0, 26) this->children[i] = nullptr;
		this->val = 0;
	}
};

void insert (Trie* root, string s) {
	Trie* node = root;
	for (auto i : s) {
		if (node->children[i - 'a'] == nullptr) node->children[i - 'a'] = new Trie ();
		node = node->children[i - 'a'];
		node->val++;
	}
}

int find (Trie* root, string s) {
	Trie* node = root;
	int ans;
	for (auto i : s) {
		if (node->children[i - 'a'] == nullptr) return 0;
		node = node->children[i - 'a'];
		ans = node->val;
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	Trie* root = new Trie ();
	while (tc--) {
		string a, b;
		cin >> a >> b;
		if (a == "add") {
			insert (root, b);
		} else {
			pr (find (root, b));
		}
	}
	return 0;
}
