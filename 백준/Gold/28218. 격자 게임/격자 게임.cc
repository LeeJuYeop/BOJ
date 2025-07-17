#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

using ll = long long;
using matrix = vector<vector<ll>>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vb = vector<bool>;

// 풀이 2. 첫번째 순서가 이기 못하면 무조건 두번째 순서가 이기는 경우다.
int n, m, k, q;
vector<string> tmap;
vvi dp;

int go(int x, int y) {
    if(dp[x][y] != -1) return dp[x][y];
    int &ans = dp[x][y];
    // 한가지 경우라도 해당되면 더 볼 필요없음
    if(x+1 < n && tmap[x+1][y] != '#' && !go(x+1, y)) return ans = 1;
    if(y+1 < m && tmap[x][y+1] != '#' && !go(x, y+1)) return ans = 1;
    for(int i=1; i<=k; ++i) {
        if(x+i < n && y+i < m && tmap[x+i][y+i] != '#' && !go(x+i, y+i)) return ans=1;
    }
    return 0; // 아무리 해도 첫번 째가 이길 수 없다면 두번째가 이기는 것이다. 
}

void solve() {
    cin >> n >> m >>k;
    tmap = vector<string>(n);
    // (x, y)를 시작위치로 할 때 먼저 시작하는 사람이 이기는지 여부
    dp = vvi(n, vi(m, -1));
    dp[n-1][m-1] = 0; // (n-1, m-1)에서 시작하면 두번 째가 이긴다는 이야기
    for(int i=0; i<n; ++i) cin >> tmap[i];
    cin >> q;
    for(int i=0; i<q;++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int ans = go(x, y);
        if(ans) cout << "First\n";
        else cout << "Second\n";
    }
}

int main() {
    fastio;
    solve();
    return 0;
}