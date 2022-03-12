#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	int t;
	cin>>t;
	for (int k=0;k<t;k++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ll set_bits_a=__builtin_popcountll(a);
		ll set_bits_b=__builtin_popcountll(b);
		ll length_c=(ll)log2(c)+1;
		vector<ll> arr(length_c),cpy(length_c);
		for(long i=0;i<set_bits_a;i++)
			arr[i]=1;
		for(long i=set_bits_a;i<length_c;i++)
			arr[i]=0;

        cpy=arr;
		//int cnt=0;
		ll cnt=0;
		do
		{
			//cnt+=1;
			ll no=0;
			for(int i = 0 ; i < length_c ; i++)
              no = (no << 1) + arr[i] ;

              if(__builtin_popcountll(c-no)==set_bits_b)
              	cnt++;

              next_permutation(arr.begin(),arr.end());
		}
		while(arr!=cpy);
		cout<<cnt<<endl;

	}


	return 0;
}
