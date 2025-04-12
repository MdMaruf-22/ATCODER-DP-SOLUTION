#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int MOD = 1e9 + 7;
int dp[1010][1010];
vector<vector<char>> grid; 
int n, m;

int dfs(int i, int j) {
    if (i == n - 1 && j == m - 1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int cnt = 0;
    if (i + 1 < n && grid[i + 1][j] == '.') cnt = (cnt+dfs(i+1,j))%MOD;
    if (j + 1 < m && grid[i][j + 1] == '.') cnt = (cnt+dfs(i,j+1))%MOD;;
    return dp[i][j]=cnt;
}

void solve() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m)); 
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = dfs(0, 0);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    //cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
