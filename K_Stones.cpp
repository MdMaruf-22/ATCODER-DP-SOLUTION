#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int dp[100010];

bool calc(vector<int>& vc,int k){
    if(k==0) return false;
    if(dp[k]!=-1) return dp[k];
    for(int x:vc){
        if(k-x>=0){
            //Jodi ei move tate ami hari taile next move a ami jitbo
            if(calc(vc,k-x)==false){
                return dp[k] = 1;
            }
        }
    }
    dp[k] = 0;
    return false;
}


void solve()
{
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    if(calc(vc,k)) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
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
