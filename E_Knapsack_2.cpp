#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int INF = 1e18;
int dp [110][100010];
int calc(int ind,int profit, vector<vector<int>>& vc){
    if(profit==0) return 0;
    if(ind<0) return INF;
    if (dp[ind][profit] != -1) return dp[ind][profit];
    int ans = INF;
    //Include
    if(profit >= vc[ind][1]) ans = calc(ind-1,profit-vc[ind][1],vc) + vc[ind][0];
    //Exclude
    int ans2 = calc(ind-1,profit,vc);
    return dp[ind][profit] = min(ans, ans2);;
}

void solve()
{
    memset(dp,-1,sizeof dp);
    int n,w;cin>>n>>w;
    vector<vector<int>> vc(n,vector<int>(2));
    int total_profit = 0;
    for(int i=0;i<n;i++){
        cin>>vc[i][0]>>vc[i][1];
        total_profit += vc[i][1];
    }
    int ans=0;
    for(int i=0;i<=total_profit;i++){
        if(calc(n-1,i,vc)<=w){
            ans = i;
        }
    }
    cout<<ans<<"\n";
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
