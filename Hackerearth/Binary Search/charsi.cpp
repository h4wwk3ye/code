/*
				C++
				encoding:UTF-8
				Modified: <04/Mar/2019 07:18:32 PM>

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
#define		 fr(i, s, e)				for (int i = s; i < e; i ++)

ll powermod(ll _a,ll _b,ll _m)	{ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

const int N=45005;
int arr[N];

void precompute(){
    fr(i,1,N-1){
        arr[i]=(arr[i-1]+i);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    precompute();
    int n;
    cin>>n;
    fr(i,1,N-1){
        int x=arr[i];
        int low=i, high=N-1,mid;
        while(low<high){
            mid=(low+high+1)/2;
            if (arr[mid]+x==n){
                pr1("YES");
                return 0;
            }
            if (arr[mid]+x>n)
                high=mid-1;
            else
                low=mid+1;
        }
    }
    pr1("NO");
    return 0;
}
