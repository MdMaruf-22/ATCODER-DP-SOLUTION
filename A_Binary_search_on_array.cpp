#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 1e7 + 10;
vector<int> isPrime(N, false);
void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i + i; j < N; j += i)
                isPrime[j] = true;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        int sq = sqrt(k);
        if (sq * sq == k and isPrime[sq])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
