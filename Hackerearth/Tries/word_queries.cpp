/*
				C++
				encoding: UTF-8
				Modified: <12/Jul/2019 11:03:41 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

class Trie {
public:
	int val;
	Trie* child[26];
	Trie () {
		fr (i, 0, 26) this->child[i] = nullptr;
		this->val = 0;
	}
	void insert (string s) {
		Trie* node = this;
		for (auto x : s) {
			if (node->child[x - 'a'] == nullptr) node->child[x - 'a'] = new Trie ();
			node = node->child[x - 'a'];
			node->val++;
		}
	}
	int query (string s) {
		Trie* node = this;
		for (auto x : s) {
			if (node->child[x - 'a'] == nullptr) return 0;
			node = node->child[x - 'a'];
		}
		return node->val;
	}
};

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, q;
	cin >> n >> q;
	Trie* root = new Trie ();
	fr (i, 0, n) {
		string s;
		cin >> s;
		root->insert (s);
	}
	while (q--) {
		string s;
		cin >> s;
		pr1 (root->query (s));
	}
	return 0;
}
