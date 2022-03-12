/*
				C++
				encoding:UTF-8
				Modified: <17/Mar/2019 10:18:42 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 prv(v)                 for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    umap<char, int> mp;
    for(char i:s)
        mp[i]++;

    if (len(mp)>n){
        pr1(-1);
        return 0;
    }

    int low=1, high=1e3+5, mid;
    while (low<high){
        mid = (low+high)/2;
        ll ans=0;
        for(auto& [k,v]: mp)
            ans+=(v-1)/mid+1;

        if (ans<=n)
            high=mid;
        else
            low=mid+1;
    }

    pr1(high);
    int tot=0;
    for (auto& [k,v]: mp){
        int x=(v-1)/low+1;
        fr(j,0,x){
            cout<<k;
            tot++;
        }
    }
    fr(i,tot,n)
        cout<<"a";
    cout<<endl;

    return 0;
}
