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

vector<char> expd(1, '\0');
vector<int> history(1, 0);
vector<vector<int>> Trie(1);

int getLen(int c) {
    int len = 0;
    while (c != 0) {
        len += 1 << Trie[c].size() - 1;
        c = Trie[c][Trie[c].size() - 1];
    }

    return len;
}

int queryUp(int c, int q) {
    int i = 0;
    while (q > 0) {
        if (i >= Trie[c].size())
            return -INF64;

        if (q & 1)
            c = Trie[c][i];
        
        i++;
        q >>= 1;
    }

    return c;
}

void debug() {
    cout << endl;
    cout << "Trie: " << endl;
    for (int i = 0; i < Trie.size(); i++) {
        cout << expd[i] << ": ";
        for (int x : Trie[i])
            cout << expd[x] << ' ';
        cout << endl;
    }
    cout << endl;
    cout << "history: " << endl;
    for (int x : history)
        cout << x << ' ';
    cout << endl;
    cout << endl;

    return;
}

void Init() {
    
    return;
}

void TypeLetter(char l) {
    int prv = history.back(), cur = expd.size();
    expd.push_back(l);
    history.push_back(cur);
    Trie.push_back({prv});
    for (int i = 0; i < 19; i++) {
        if (i >= Trie[prv].size())
            break;
            
        prv = Trie[prv][i];
        Trie[cur].push_back(prv);
    }

    return;
}

void UndoCommands(int u) {
    history.push_back(history[history.size() - u - 1]);

    return;
}

char GetLetter(int p) {
    int len = getLen(history.back());

    return expd[queryUp(history.back(), len - p - 1)];
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
            // debug();
        }
    }

    

    return 0;
}
//*/