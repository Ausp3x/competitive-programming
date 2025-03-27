#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
typedef long long ll;

struct SegTree {
    SegTree *left, *right;
    ll orig_total_sum; // this was the original sum of the entire interval, before updates
    ll update;         // this is the lazily-stored updates to the entire interval
    int l, r;
    SegTree(vector<ll>& a, int l, int r) {
        this->l = l;
        this->r = r;
        this->update = 0;

        if (l == r) {
            this->left = this->right = nullptr;
            orig_total_sum = a[l];
        } else {
            int m = (l + r)/2;
            this->left = new SegTree(a, l, m);
            this->right = new SegTree(a, m+1, r);
            pull();
        }
    }
    /*
        If I know the orig_answer,
         and I know the collective update applied to the whole range (what was +k'ed to the entire interval)
         can I compute the new answer (i.e. how the update to the entire array change the answer) from that?

         Yes
    */
    ll total_sum() {
        return orig_total_sum + (r - l + 1)*update;
    }

    /*
        Push my updates down to my children,
          then "reset" my status
    */
    void push() {
        this->orig_total_sum = total_sum();
        if (left != nullptr && right != nullptr) {
            left->update += this->update;
            right->update += this->update;
        }
        this->update = 0;
    }

    /*
        Recompute my status using the states of my children
    */
    void pull() {
        assert(update == 0);
        if(left != nullptr && right != nullptr) {
            this->orig_total_sum = left->total_sum() + right->total_sum();
        }
    }

    ll range_sum_query(int L, int R) {
        if (r < L || R < l) {
            return 0;
        } else if (L <= l && r <= R) {
            return this->total_sum();  // the COMPUTED value
        } else {
            push(); // always remember to PUSH down the updates before recursing!!
            return left->range_sum_query(L, R) + right->range_sum_query(L, R);
        }
    }

    void range_add(int L, int R, ll k) {
        if (r < L || R < l) {
            return;
        } else if (L <= l && r <= R) {
            /*
                Also carries this implicit idea of:  How do I COLLAPSE a long sequence of operations into O(1) different values that represent the accumulated effect of that sequence of operations

                Easy for associative operations
                    sum(sum(sum(orig, 5), 6), 9) = sum(orig, sum(5, 6, 9)  = sum(orig, 20)
                    max(max(max(orig, 5), 6), 9) = sum(orig, max(5, 6, 9)) = max(orig, 9)

                You might have to think about it a bit more for "weirder" operations.
                In fact, "how do I accumulate these operations" might be the crux step!  
            */
            this->update += k;
        } else {
            push(); // always remember to PUSH down the updates before recursing!!
            left->range_add(L, R, k);
            right->range_add(L, R, k);
            pull(); // I need to recompute my original answer after messing with my children
        }
    }

    void print(int depth=0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has orig_sum " << orig_total_sum << " and current lazily accumulated updates " << update << endl;
        if (left != nullptr && right != nullptr) {
            left->print(depth+1);
            right->print(depth+1);
        }
    }
};

int main() {
    int n; 
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegTree *root = new SegTree(a, 0, n-1);
    root->print();

    return 0;
}