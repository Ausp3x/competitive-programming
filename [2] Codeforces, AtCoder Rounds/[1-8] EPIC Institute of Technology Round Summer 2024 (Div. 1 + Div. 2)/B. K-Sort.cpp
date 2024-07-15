// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve(int t) {
    int n;
    cin >> n;
    vector<int> as(n);
    for (int &a : as)
        cin >> a;
    
    vector<int> pas(n);
    pas[0] = as[0];
    for (int i = 1; i < n; i++)
        pas[i] = max(as[i], pas[i - 1]);
    
    // for (int pa : pas)
    //     cout << pa << ' ';
    // cout << endl;

    // d, cnt
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        if (pas[i] == as[i])
            continue;
        
        m[pas[i] - as[i]]++;
    }

    vector<pair<int, int>> m_vec;
    for (auto [x, y] : m)
        m_vec.push_back({x, y});

    reverse(m_vec.begin(), m_vec.end());

    // cout << m_vec.size() << endl;
    // for (auto [x, y] : m_vec)
    //     cout << x << ' ' << y << endl;
    // cout << endl;

    if (m_vec.empty()) {
        cout << 0 << endl;
        return;
    }

    int cnt = 0;
    lng ans = 0;
    for (int i = 0; i < m_vec.size() - 1; i++) {
        ans += 1ll * (m_vec[i].first - m_vec[i + 1].first) * (m_vec[i].second + cnt + 1);
        cnt += m_vec[i].second;
    }
    ans += 1ll * m_vec.back().first * (m_vec.back().second + cnt + 1);
    
    cout << ans << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}