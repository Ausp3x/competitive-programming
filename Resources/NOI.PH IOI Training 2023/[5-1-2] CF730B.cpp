#include <iostream>
#include <vector>
using namespace std;
char ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    char ans; cin >> ans;
    return ans;
}
pair<int, int> min_then_max(int i, int j) {
    char comp = ask(i, j);
    if (comp == '<') {
        return {i, j};
    } else { // if comp == '=', then either is fine; arbitrarily choose this ordering
        return {j, i}; 
    }
}
int get_min(int i, int j) {
    return min_then_max(i, j).first;
}
int get_max(int i, int j) {
    return min_then_max(i, j).second;
}
void solve() {
    int n; cin >> n;
    vector<int> minis, maxis;
    minis.reserve(n/2), maxis.reserve(n/2);
    for (int i = 1; i <= n/2; i++) {
        auto[mini, maxi] = min_then_max(i, n/2 + i);
        minis.push_back(mini);
        maxis.push_back(maxi);
    }

    int miniest;
    if (n & 1) {
        miniest = n;
    } else {
        miniest = minis.back();
        minis.pop_back();
    }
    for (int& mini: minis) {
        miniest = get_min(miniest, mini);
    }

    int maxiest;
    if (n & 1) {
        maxiest = n;
    } else {
        maxiest = maxis.back();
        maxis.pop_back();
    }
    for (int& maxi: maxis) {
        maxiest = get_max(maxiest, maxi);
    }

    cout << "! " << miniest << " " << maxiest << endl;
}
int main() {
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}