#include<bits/stdc++.h>
using namespace std;

#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<n;i++)

// 1 123 2   
// 2 1001 2
// Thu 1 : Nhap loai chuyen co so 1 la chuyen tu 10 sang he co so k, 2 la so n he co so k ve 10
// Thu 2, 3 : So n , So k

int main(){
	long long n;
	int k,t;
	cin >> t;
	if(t==1){
		cin>>n>>k;
		vector <int> ans;
		while(n){
			ans.push_back(n%k);
			n/=k;
		}
		reverse(ans.begin(), ans.end());
		for(int x: ans) cout<<x;
		
	}
	
	else{
		string s;
		cin>>s>>k;
		long long ans =0;
		f0 (i, s.size() ){
			ans = ans *k +s[i] ;
		}
		cout<< ans;
	}
	
	return 0;	
}
