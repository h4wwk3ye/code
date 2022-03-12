/*
				C++
				encoding: UTF-8
				Modified: <29/Jul/2019 01:28:21 AM>

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

struct Trie {
	Trie* children[26];
	string ans;
	int val;
	Trie () {
		fr (i, 0, 26) this->children[i] = nullptr;
		this->ans = "";
		this->val = 0;
	}
};

string s;

void insert (Trie* node) {
	for (char i : s) {
		if (node->children[i - 'a'] == nullptr) node->children[i - 'a'] = new Trie ();
		node = node->children[i - 'a'];
	}
	node->ans = s;
	node->val = 1;
}

bool flag;

Trie* l_node (Trie* node) {
	for (auto i : s) {
		if (node->children[i - 'a'] == nullptr) {
			flag = false;
			return node;
		}
		node = node->children[i - 'a'];
	}
	return node;
}

void query (Trie* node) {
	if (node->val) {
		pr (node->ans);
	}
	fr (i, 0, 26) {
		if (node->children[i] != nullptr) {
			query (node->children[i]);
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	Trie* root = new Trie ();
	while (n--) {
		cin >> s;
		insert (root);
	}
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		flag = true;
		Trie* node = l_node (root);
		if (!flag) {
			pr ("No suggestions");
			insert (root);
		} else {
			query (node);
		}
	}
	return 0;
}
