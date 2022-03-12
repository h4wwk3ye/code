/*
				C++
				encoding: UTF-8
				Last Modified: 16/Jun/20 09:36:55 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

vector< pair< int, int > > arr;
vector< char > ans;
string s;
int m;
vector< int > b;
map< pair< int, vector< char > >, int > mp;

void init () {
	b.resize (m);
	arr.clear ();
	ans.clear ();
	mp.clear ();
}

bool solve (int j, vector< char > curr, set< pair< char, int >, greater< pair< char, int > > > barr) { // index of barr, upto m, current placement
	print (j, curr, barr);
	if (j == arr.size ()) {
		//  50 * 50
		for (int k = 0; k < curr.size (); ++k) {
			int c = 0;
			if (curr[k] == '.') return false;
			for (int l = 0; l < curr.size (); ++l) {
				if (curr[l] == '.') return false;
				if (k != l) {
					if (curr[l] > curr[k]) c += abs (k - l);
				}
			}
			if (c != b[k]) return false;
		}
		ans = curr;
		return true;
	}

	if (mp.find ({j, curr}) != mp.end ()) return mp[{j, curr}];
	int& x = mp[{j, curr}];
	// int x = 0;
	auto it = barr.begin ();
	while (it != barr.end ()) {
		char a = it->first;
		int b = it->second;
		print (a, b, j, "here", barr);
		curr[arr[j].second] = a;
		barr.erase (it);
		x = solve (j + 1, curr, barr);
		if (x)
			break;
		else {
			// print ("sdfafafda");
			barr.insert ({a, b});
		}
		it++;
	}
	return x;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		cin >> m;

		init ();
		set< pair< char, int >, greater< pair< char, int > > > barr;
		for (int i = 0; i < s.size (); ++i) {
			barr.insert ({s[i], i});
		}

		for (int i = 0; i < m; ++i) {
			cin >> b[i];
			arr.push_back ({b[i], i});
		}
		sort (arr.begin (), arr.end ());
		// print (barr, arr);
		vector< char > curr (m, '.');
		solve (0, curr, barr);
		print (ans);
	}
	return 0;
}