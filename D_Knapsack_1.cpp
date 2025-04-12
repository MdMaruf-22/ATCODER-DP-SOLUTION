#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int dp[110][100010];
int calc(int ind,vector<vector<int>>& vc,int wt){
    if(ind==0){
        if(wt-vc[ind][0]>=0) return vc[ind][1];
        else return 0;
    }
    if(wt==0) return 0;
    if(dp[ind][wt]!=-1) return dp[ind][wt];
    int ans = INT_MIN;
    //Include
    if(wt-vc[ind][0]>=0) ans = max(ans,calc(ind-1,vc,wt-vc[ind][0]) + vc[ind][1]);
    //Exclude
    ans = max(ans,calc(ind-1,vc,wt));
    return dp[ind][wt] = ans;
}

void solve()
{
    memset(dp,-1,sizeof dp);
    int n,w;cin>>n>>w;
    vector<vector<int>> vc(n,vector<int>(2));
    for(int i=0;i<n;i++) cin>>vc[i][0]>>vc[i][1];
    cout<<calc(n-1,vc,w)<<endl;
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
