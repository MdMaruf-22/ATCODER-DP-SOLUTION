#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

double dp[3000][3000];


double calc(int n,vector<double>& vc, int ind , int headCnt){
    if(ind == n){
        return (headCnt>n-headCnt)?1.0:0.0;
    }
    if(dp[ind][headCnt]!=-1) return dp[ind][headCnt];
    double head = vc[ind] * calc(n,vc,ind+1,headCnt+1);
    double tail = (1.0-vc[ind]) * calc(n,vc,ind+1,headCnt);
    return dp[ind][headCnt] = head + tail;
}



void solve()
{
    int n;cin>>n;
    vector<double> vc(n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1.0;
        }
    }
    for(int i=0;i<n;i++) cin>>vc[i];
    cout<<setprecision(10)<<calc(n,vc,0,0)<<endl;
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
