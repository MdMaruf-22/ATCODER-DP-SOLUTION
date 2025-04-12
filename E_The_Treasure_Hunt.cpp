#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

int binarySearch(vector<int>& vc, int to_find) {
    int low = 0, high = vc.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (vc[mid] <= to_find) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vc1(n), vc2(m);
    for (int i = 0; i < n; i++) cin >> vc1[i];
    for (int i = 0; i < m; i++) cin >> vc2[i];
    
    // Sort array vc1 to apply binary search
    sort(vc1.begin(), vc1.end());
    
    for (int i = 0; i < m; i++) {
        int ans = binarySearch(vc1, vc2[i]);
        cout << ans << " ";
    }
    cout << endl;
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
