#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

const int N = 1e5+10;
int dp[N][3];

int calc(vector<vector<int>>& vc,int ind,int pos){
    if(ind==0) return vc[ind][pos];
    if(dp[ind][pos]!=-1) return dp[ind][pos];
    int ans = INT_MIN;
    int i,j;
    if(pos==0) i=1,j=2;
    else if(pos==1) i=0,j=2;
    else i=0,j=1;
    ans = max(ans,calc(vc,ind-1,i) + vc[ind][pos]);
    ans = max(ans,calc(vc,ind-1,j) + vc[ind][pos]);
    return dp[ind][pos] = ans;
}
void solve()
{
    memset(dp,-1,sizeof dp);
    int n;cin>>n;
    vector<vector<int>> vc(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>vc[i][j];
        }
    }
    int ans = max({calc(vc, n - 1, 0), calc(vc, n - 1, 1), calc(vc, n - 1, 2)});
    cout << ans << endl;
    // for(auto x:vc){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
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
