/*
                C++
                encoding: UTF-8
                Last Modified: 2025/09/13 10:48:48
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
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> arr(n);
        for (auto&[a, b]: arr) {
            cin>>a>>b;
        }
        int side = 0, pos = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            // odd turn, staying at 1 preferred, so if it's even, loose 1 point
            auto&[a, b] = arr[i - 1];
            int possible = a - pos;
            if (possible & 1) {
                // odd opposite side
                if (side == b) {
                    ans += possible - 1;
                } else {
                    ans += possible;
                }
            } else {
                if (side == b) {
                    ans += possible;
                } else {
                    ans += possible - 1;
                }
            }
            side = b;
            pos = a;
        }
        ans += (m - pos);
        print(ans);
    }
    return 0;
}