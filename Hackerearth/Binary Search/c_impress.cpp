/*
				C++
				encoding:UTF-8
				Modified: <04/Mar/2019 01:29:43 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll					long long
#define		 mod					1000000007
#define		 ve					vector
#define		 pb					push_back
#define		 umap					unordered_map
#define		 pq					priority_queue
#define		 endl					"\n";
#define		 ff					first
#define		 ss					second
#define		 len(v)					int(v.size())
#define		 all(v)					v.begin(), v.end()
#define		 reset(a, b)				memset(a, b, sizeof(a));
#define		 sum(v)					accumulate(v.begin(), v.end(), (ll)0);
#define		 pr(x)					cout<<x<<"\n"
#define		 pr2(x, y)				cout<<x<<" "<<y<<"\n"
#define		 prv(v)					for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, s, e)				for (int i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    ve<ll> arr(n+1,0);
    ll x;
    fr(i,1,n+1){
        cin>>arr[i];
    }
    for(ll i=n-1;i>=0;i--){
        arr[i]+=arr[i+1];
    }
    reverse(all(arr));
    arr.pop_back();
    //prv(arr);
    int q;
    cin>>q;
    while(q--){
        cin>>x;
        int u=lower_bound(all(arr),x)-arr.begin();
        if (n%2==1){
            if (u%2==0)
                pr("A");
            else
                pr("B");
        }
        else{
            if (u%2==0)
                pr("B");
            else
                pr("A");
        }

    }

    return 0;
}
