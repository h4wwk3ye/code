#include <bits/stdc++.h>
using namespace std;

bool solve (string& s, vector< string >& arr, set< int > mp, int curr) {
	if (curr > (int)s.size ()) return false;
	if (curr == (int)s.size ()) return true;
	for (int i = 0; i < arr.size (); ++i) {
		if (mp.find (i) == mp.end ()) {
			// this string hasn't been used
			// check if this string can be appended to curr to form s
			if (s.size () - curr < (int)arr[i].size ()) {
				// can't use as remaining length is smaller
				continue;
			}
			vector< int > a (26, 0), b (26, 0);
			for (int j = 0; j < arr[i].size (); ++j) {
				a[arr[i][j] - 'a']++;
				b[s[j + curr] - 'a']++;
			}
			bool flag = true;
			for (int j = 0; j < 26; ++j) {
				if (a[j] != b[j]) {
					// cant use this string
					flag = false;
					break;
				}
			}

			if (flag) {
				// we can use this string
				mp.insert (i);
				return solve (s, arr, mp, curr + (int)arr[i].size ());
			}
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector< string > arr (n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	set< int > mp; // that have already been selected
	cout << solve (s, arr, mp, 0);
	return 0;
}