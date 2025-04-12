#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
double dp [305][305][305];

double calc(int one,int two,int three,int n){
    if(one==0 && two==0 && three==0) return 0.0;
    if(one<0 || two<0 || three<0) return 0.0;
    if(dp[one][two][three] > -0.5) return dp[one][two][three];
    double total = one + two + three;
    double currProb = double(n)/(one + two + three);
    if(one>0) currProb += (one/total) * calc(one-1,two,three,n);
    if(two>0) currProb += (two/total) * calc(one+1,two-1,three,n);
    if(three>0) currProb += (three/total) * calc(one,two+1,three-1,n);
    return dp[one][two][three]=currProb;
 }


void solve()
{
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    int one=0,two=0,three=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x==1) one++;
        else if(x==2) two++;
        else three++;
    }
    double ans = calc(one,two,three,n);
    cout<<fixed<<setprecision(15)<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
