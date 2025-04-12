#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

const int N = 1e5+10;
int dp[N];

int calc(int ind,vector<int>& vc){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int ans1 = INT_MAX,ans2=INT_MAX;
    if(ind-1>=0) ans1 = calc(ind-1,vc) + abs(vc[ind] - vc[ind-1]);
    if(ind-2>=0) ans2 = calc(ind-2,vc) + abs(vc[ind] - vc[ind-2]);
    return dp[ind] = min(ans1,ans2);
}



void solve()
{
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    cout<<calc(n-1,vc)<<endl;
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
