#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 3010;
int dp[N][N];

int calc(string& s,string& t,int n,int m){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    int ans;
    if(s[n-1]==t[m-1]) ans = calc(s,t,n-1,m-1) + 1;
    else ans = max(calc(s,t,n-1,m),calc(s,t,n,m-1));
    return dp[n][m] = ans;
}
string getLcs(string& s,string& t,int n,int m){
    int i=n,j=m;
    string ans = "";
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans.push_back(s[i-1]);
            i--;j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void solve()
{
    memset(dp,-1,sizeof dp);
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();
    calc(a,b,n,m);
    cout<<getLcs(a,b,n,m)<<endl;
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
