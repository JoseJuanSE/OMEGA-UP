#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull get(ull x){return x?get(x/2)+1:0;}
ull po(ull a,ull p){
    ull res=1;
    while(p){
      if(p&1)res*=a;
      a*=a;
      p>>=1;
   }
   return res;
}
ull s(ull x){
	ull n=get(x),s=0,t=1,m=po(2,n);
	vector<ull>c(n+1);
	for(ull i=n;i>0;i--){
		c[i]=x/m;
		c[i]-=s;
		s+=c[i];
		m/=2;
	}
	c[0]=x-s;
	s=0;
	for(ull i=0;i<=n;i++,t*=2)
		s+=c[i]*t;
	return s;
}
int main(){
	ull n,a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		cout<<s(b)-s(a-1)<<endl;
	}
	return 0;
}
