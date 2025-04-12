#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

const int N = 1e5+10;
int dp[N];

int calc(int ind,vector<int>& vc,int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int ans = INT_MAX;
    for(int i=1;i<=k;i++){
        if(ind-i>=0) ans = min(ans,calc(ind-i,vc,k)+abs(vc[ind] - vc[ind-i]));
    }
    return dp[ind] = ans;
}



void solve()
{
    memset(dp,-1,sizeof(dp));
    int n,k;cin>>n>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    cout<<calc(n-1,vc,k)<<endl;
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
