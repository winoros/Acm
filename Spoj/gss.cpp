#include <bits/stdc++.h>

inline int getIdx(int l, int r) {
    return l + r | l != r;
}

struct node {
    int sum, internalMax, lMax, rMax;
};

node fuck[50010 << 1];

node upd(node lFuck, node rFuck) {
    node ret;
    ret.sum = lFuck.sum + rFuck.sum;
    ret.lMax = std::max(lFuck.lMax, lFuck.sum + rFuck.lMax);
    ret.rMax = std::max(rFuck.rMax, lFuck.rMax + rFuck.sum);
    ret.internalMax = std::max(lFuck.rMax + rFuck.lMax, std::max(lFuck.internalMax, rFuck.internalMax));
    return ret;
}

void build(int l, int r) {
    int idx = getIdx(l, r);
    if(l == r) {
        scanf("%d", &fuck[idx].sum);
        fuck[idx].internalMax = fuck[idx].lMax = fuck[idx].rMax = fuck[idx].sum;
    } else {
        int m = (l + r) >> 1;
        build(l, m);
        build(m + 1, r);
        fuck[idx] = upd(fuck[getIdx(l, m)], fuck[getIdx(m + 1, r)]);
    }
}

node query(int _l, int _r, int l, int r) {
    int idx = getIdx(l, r);
    if(_l <= l && r <= _r) {
        return fuck[idx];
    }
    int m = (l + r) >> 1;
    if(_r <= m)
        return query(_l, _r, l, m);
    if(m < _l)
        return query(_l, _r, m + 1, r);
    return upd(query(_l, _r, l, m), query(_l, _r, m + 1, r));
}

void MAIN() {
    int n;
    scanf("%d", &n);
    build(1, n);
    int m;
    scanf("%d", &m);
    for(int i = 0, x, y; i < m; ++ i) {
        scanf("%d%d", &x, &y);
        printf("%d\n", query(x, y, 1, n).internalMax);
    }
}

int main() {
    MAIN();
    return 0;
}
