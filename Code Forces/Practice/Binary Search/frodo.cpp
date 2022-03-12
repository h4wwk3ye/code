/*
				C++
				encoding:UTF-8
				Modified: <16/Mar/2019 02:04:48 PM>

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
#define		 pr1(x)					cout<<x<<"\n"
#define		 pr2(x, y)				cout<<x<<" "<<y<<"\n"
#define		 prv(v)					for (auto& ijk : v)  cout<<ijk<<" ";cout<<"\n"
#define		 fr(i, s, n)				for (int i = k ; i < n ; i++)
#define		 dfr(i, s, n)				for (int i = s; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    ll low=1, high=m, mid;
    while (low<high){
        mid=(low+high+1)/2;
        int prev=1;
        ll curr=mid;

        int y=k-1;
        if (y>mid-1)
            curr+=(mid-1)*mid/2+(y)-(mid-1);
        else
            curr+=((mid-1+mid-y)*y)/2;

        y=n-k;
        if (y>mid-1)
            curr+=((mid-1)*mid/2)+y-(mid-1);
        else
            curr+=((mid-1+mid-y)*y)/2;

        //cout<<mid<<" "<<curr<<" \n";

        if (curr<=m)
            low=mid;
        else
            high=mid-1;
        //pr1(curr);

    }
    pr1(low);
    return 0;
}
