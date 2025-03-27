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

vector<string> history(1);

void Init() {
    
    return;
}

void TypeLetter(char l) {
    string res = history.back();
    res += l;
    history.push_back(res);

    return;
}

void UndoCommands(int u) {
    history.push_back(history[history.size() - u - 1]);

    return;
}

char GetLetter(int p) {
    return history.back()[p];
}

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Init();

    int t = 1;
    cin >> t;
    while (t--) {
        char c;
        cin >> c;
        if (c == 'T') {
            char l;
            cin >> l;
            TypeLetter(l);
        } else if (c == 'U') {
            int u;
            cin >> u;
            UndoCommands(u);
        } else if (c == 'P') {
            int p;
            cin >> p;
            cout << GetLetter(p) << endl;
        }
    }

    return 0;
}
//*/