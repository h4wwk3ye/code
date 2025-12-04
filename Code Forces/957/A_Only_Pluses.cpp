/*
                C++
                encoding: UTF-8
                Last Modified: 2024/07/11 09:50:53
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
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
        vector<int> arr(3);
        for(auto& i: arr) cin >> i;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < 5; ++i) {
            arr[0]++;
            if (arr[0] > arr[1]) swap(arr[0], arr[1]);
        } 
        print(arr[0] * arr[1] * arr[2]);
    }
    return 0;
}