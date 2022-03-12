#include <bits/stdc++.h>
using namespace std;

unordered_map< char, int > mp;

bool cmp (char x, char y) {
	return mp[x] < mp[y];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < 26; ++i) {
		mp[a[i]] = 2 * i + 1;
		mp[a[i] - 32] = 2 * i;
	}
	sort (b.begin (), b.end (), cmp);
	cout << b << '\n';
	return 0;
}