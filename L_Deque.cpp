#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int dp[3010][3010];

int calc(vector<int>& vc,int l,int r){
    if(l==r) return vc[l];
    if(dp[l][r]!=-1) return dp[l][r];
    int right = vc[r] - calc(vc,l,r-1); // ei round a ami koto pacchi - porer round a oppo koto pay
    int left = vc[l] - calc(vc,l+1,r); // ei round a ami koto pacchi - porer round a oppo koto pay
    return dp[l][r] = max(left,right);
}


void solve()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    cout<<calc(vc,0,n-1)<<endl;
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
