/*
				C++
				encoding: UTF-8
				Modified: <04/Jul/2019 11:33:36 AM>

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
	bool leaf;
	int value;
	Trie* child[26];

	Trie () {
		this->leaf = false;
		this->value = 0;
		for (int i = 0; i < 26; i++)
			this->child[i] = nullptr;
	}

	void insert (string, int);
	int search (string);
};

void Trie::insert (string key, int val) {
	Trie* curr = this;
	for (auto i : key) {
		if (curr->child[i - 'a'] == nullptr) {
			curr->child[i - 'a'] = new Trie ();
		}
		curr = curr->child[i - 'a'];
		curr->value = max (val, curr->value);
	}
	curr->leaf = true;
}

int Trie::search (string key) {
	if (this == nullptr) return -1;
	Trie* curr = this;
	int ans = -1;
	for (auto i : key) {
		curr = curr->child[i - 'a'];
		if (curr == nullptr) {
			ans = -1;
			break;
		}
		ans = curr->value;
	}
	return ans;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, q;
	cin >> n >> q;
	Trie* head = new Trie ();
	fr (i, 1, n + 1) {
		string s;
		int w;
		cin >> s >> w;
		head->insert (s, w);
	}
	while (q--) {
		string s;
		cin >> s;
		int ans = head->search (s);
		pr1 (ans);
	}
	return 0;
}
