#include <bits/stdc++.h>
#define ll long long int
#define li long int
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
		for(li i=0;i<length_c-set_bits_b;i++)
			arr[i]=0;
		for(li i=length_c-set_bits_b;i<length_c;i++)
			arr[i]=1;

        cpy=arr;
		//int cnt=0;
		ll cnt=0;
		do
		{
			//cnt+=1;
			ll no=0;
			for(li i = 0 ; i < length_c ; i++)
              no = (no << 1) + arr[i] ;

              if(__builtin_popcountll(c-no)==set_bits_a)
              	cnt++;

              next_permutation(arr.begin(),arr.end());
            //https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
		}
		while(arr!=cpy);
		cout<<cnt<<endl;

	}


	return 0;
}
