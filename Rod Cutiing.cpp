#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 1e5+10;
int dp[N];
int calc(int len,int n,vector<int>& vc){
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len];
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(len-i>=0) ans = max(ans,calc(len-i,n,vc) + vc[i-1]);
    }
    return dp[len] = ans;
}




void solve()
{
    memset(dp,-1,sizeof dp);
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int ans = calc(n,n,vc);
    cout<<ans<<endl;
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
