/*
                C++
                encoding: UTF-8
                Last Modified: 2025/09/13 10:38:10
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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<int> a(n), b(m);
        for (auto& i: a) cin >> i;
        for (auto& i: b) cin >> i;
        print(n + m);
    }
    return 0;
}   