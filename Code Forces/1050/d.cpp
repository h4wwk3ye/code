/*
                C++
                encoding: UTF-8
                Last Modified: 2025/09/13 11:01:58
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include "../prettyprint.hpp"
#else
#	define debug(...)
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

int32_t main () {
    ios_base::sync_with_stdio (false), cin.tie (nullptr);
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        vector<int> even, odd;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x & 1) odd.push_back(x);
            else even.push_back(x);
        }
        sort(odd.begin(), odd.end(), greater<int>());
        if (odd.size() == 0) {
            print(0);
            continue;
        }
        int ans = 0;
        for (auto& i: even) ans += i;
        for (int i = 0; i < (odd.size() + 1) / 2; ++i) {
            ans += odd[i];
        }
        print(ans);
    }
    return 0;
}