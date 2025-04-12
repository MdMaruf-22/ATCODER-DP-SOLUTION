#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 1e3+10;
int dp[N][N];
bool flag = false;


int calc(int ind,int sum,vector<int>& vc){
    if(sum==0) return true;
    if(ind<0) return 0;
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    if (sum - vc[ind] >= 0 && calc(ind - 1, sum - vc[ind], vc)) {
        return dp[ind][sum] = true;
    }
    return dp[ind][sum] = calc(ind - 1, sum, vc);
}


void solve()
{
    int n,sum;cin>>n>>sum;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    memset(dp,-1,sizeof dp);
    cout<<calc(n-1,sum,vc)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
