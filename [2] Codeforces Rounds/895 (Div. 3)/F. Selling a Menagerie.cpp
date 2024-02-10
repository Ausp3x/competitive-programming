// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> as(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> as[i];
    }
    vector<int> cs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cs[i];
    }

    vector<bool> vst(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vst[i]) {
            continue;
        }

        int ii = i;
        queue<int> q;
        while (!vst[ii]) {
            vst[ii] = true;
            q.push(ii);

            ii = as[ii];
        }

        while (q.front() != ii && !q.empty()) {
            q.pop();
        }

        if (q.empty()) {
            continue;
        }

        int cheapest_animal = -1, min_cst = INF32;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cs[cur] < min_cst) {
                cheapest_animal = cur;
                min_cst = cs[cur];
            }
        }

        as[cheapest_animal] = -1;
    }

    vst.clear();
    vst.resize(n + 1);
    deque<int> ans;
    for (int i = 1; i <= n; i++) {
        if (vst[i]) {
            continue;
        }

        int ii = i;
        vector<int> sub_ans;
        while (true) {
            if (ii == -1) {
                for (int x : sub_ans) {
                    ans.push_back(x);
                }
                break;
            }

            if (vst[ii]) {
                for (int x : sub_ans | views::reverse) {
                    ans.push_front(x);
                }
                break;
            }

            vst[ii] = true;
            sub_ans.push_back(ii);

            ii = as[ii];
        }
    }

    while (!ans.empty()) {
        cout << ans.front() << ' ';
        ans.pop_front();
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}