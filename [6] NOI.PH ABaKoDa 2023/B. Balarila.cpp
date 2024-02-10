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
    string s;
    cin >> s;
    int n = s.size();

    vector<string> combinations = {"bc", "bd", "bf", "bg", "bh", "bj", "bk", "bl", "bm", "bn", "bp", "bq", 
                                   "br", "bs", "bt", "bv", "bw", "bx", "by", "bz", "cb", "cd", "cf", "cg", 
                                   "ch", "cj", "ck", "cl", "cm", "cn", "cp", "cq", "cr", "cs", "ct", "cv", 
                                   "cw", "cx", "cy", "cz", "db", "dc", "df", "dg", "dh", "dj", "dk", "dl", 
                                   "dm", "dn", "dp", "dq", "dr", "ds", "dt", "dv", "dw", "dx", "dy", "dz", 
                                   "fb", "fc", "fd", "fg", "fh", "fj", "fk", "fl", "fm", "fn", "fp", "fq", 
                                   "fr", "fs", "ft", "fv", "fw", "fx", "fy", "fz", "gb", "gc", "gd", "gf", 
                                   "gh", "gj", "gk", "gl", "gm", "gn", "gp", "gq", "gr", "gs", "gt", "gv", 
                                   "gw", "gx", "gy", "gz", "hb", "hc", "hd", "hf", "hg", "hj", "hk", "hl", 
                                   "hm", "hn", "hp", "hq", "hr", "hs", "ht", "hv", "hw", "hx", "hy", "hz", 
                                   "jb", "jc", "jd", "jf", "jg", "jh", "jk", "jl", "jm", "jn", "jp", "jq", 
                                   "jr", "js", "jt", "jv", "jw", "jx", "jy", "jz", "kb", "kc", "kd", "kf", 
                                   "kg", "kh", "kj", "kl", "km", "kn", "kp", "kq", "kr", "ks", "kt", "kv", 
                                   "kw", "kx", "ky", "kz", "lb", "lc", "ld", "lf", "lg", "lh", "lj", "lk", 
                                   "lm", "ln", "lp", "lq", "lr", "ls", "lt", "lv", "lw", "lx", "ly", "lz", 
                                   "mb", "mc", "md", "mf", "mg", "mh", "mj", "mk", "ml", "mn", "mp", "mq", 
                                   "mr", "ms", "mt", "mv", "mw", "mx", "my", "mz", "nb", "nc", "nd", "nf", 
                                   "ng", "nh", "nj", "nk", "nl", "nm", "np", "nq", "nr", "ns", "nt", "nv", 
                                   "nw", "nx", "ny", "nz", "pb", "pc", "pd", "pf", "pg", "ph", "pj", "pk", 
                                   "pl", "pm", "pn", "pq", "pr", "ps", "pt", "pv", "pw", "px", "py", "pz", 
                                   "qb", "qc", "qd", "qf", "qg", "qh", "qj", "qk", "ql", "qm", "qn", "qp", 
                                   "qr", "qs", "qt", "qv", "qw", "qx", "qy", "qz", "rb", "rc", "rd", "rf", 
                                   "rg", "rh", "rj", "rk", "rl", "rm", "rn", "rp", "rq", "rs", "rt", "rv", 
                                   "rw", "rx", "ry", "rz", "sb", "sc", "sd", "sf", "sg", "sh", "sj", "sk", 
                                   "sl", "sm", "sn", "sp", "sq", "sr", "st", "sv", "sw", "sx", "sy", "sz", 
                                   "tb", "tc", "td", "tf", "tg", "th", "tj", "tk", "tl", "tm", "tn", "tp", 
                                   "tq", "tr", "ts", "tv", "tw", "tx", "ty", "tz", "vb", "vc", "vd", "vf", 
                                   "vg", "vh", "vj", "vk", "vl", "vm", "vn", "vp", "vq", "vr", "vs", "vt", 
                                   "vw", "vx", "vy", "vz", "wb", "wc", "wd", "wf", "wg", "wh", "wj", "wk", 
                                   "wl", "wm", "wn", "wp", "wq", "wr", "ws", "wt", "wv", "wx", "wy", "wz", 
                                   "xb", "xc", "xd", "xf", "xg", "xh", "xj", "xk", "xl", "xm", "xn", "xp", 
                                   "xq", "xr", "xs", "xt", "xv", "xw", "xy", "xz", "yb", "yc", "yd", "yf", 
                                   "yg", "yh", "yj", "yk", "yl", "ym", "yn", "yp", "yq", "yr", "ys", "yt", 
                                   "yv", "yw", "yx", "yz", "zb", "zc", "zd", "zf", "zg", "zh", "zj", "zk", 
                                   "zl", "zm", "zn", "zp", "zq", "zr", "zs", "zt", "zv", "zw", "zx", "zy"};
    map<int, string> cnt_comb;
    for (int i = 1; i <= n; i++) {
        cnt_comb[i] = "NO";
    }

    for (auto comb : combinations) {
        int cnt = n;
        for (int i = 0; i < n - 1; i++) {
            if (s.substr(i, 2) == comb) {
                cnt--;
            }
        }
        
        if (cnt_comb[cnt] == "NO") {
            cnt_comb[cnt] = comb;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt_comb[i] << ' ';
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}