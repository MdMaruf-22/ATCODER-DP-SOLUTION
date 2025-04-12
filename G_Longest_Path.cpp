#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

const int N = 1e5 + 10;
vector<int> graph[N];
vector<int> vis(N, false);
vector<int> dp(N,-1);
int dfs(int vertex)
{
    if(dp[vertex]!=-1) return dp[vertex];
    int cnt=0;
    for(auto child:graph[vertex]){
        cnt = max(cnt,dfs(child)+1);
    }
    return dp[vertex] = cnt;
}

void solve()
{
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= vertices; i++)
    {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
