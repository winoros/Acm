const int max_node;

struct node {
    int val, size;
    bool reverse;
    node *p, *ch[2];
    node (): size(0), reverse(false) {}
    bool d() {
        return p->ch[1] == this;
    }
    void setc(node *c, int d) {
        c->p = this;
        ch[d] = c;
    }
    void rev() {
        reverse ^= 1;
    }
    void upd() {
        size = ch[0]->size + ch[1]->size + 1;
    }
    void relax();
} Tnull, *null = &Tnull;

void node::relax() {
    if(reverse) {
        swap(ch[0], ch[1]);
        for(int i = 0; i < 2; ++i)
            if(ch[i] != null)
                ch[i]->rev();
        reverse = false;
    }
}

node *root, mem[max_node], *tot;

void rot(node *now) {
    node *p = now->p;
    p->relax();
    now->relax();
    int d = now->d();
    p->setc(now->ch[!d], d);
    now->p = p->p;
    if(now->p != null)
        p->p->setc(now, p->d());
    now->setc(p, !d);
    p->upd();
    if(now->p == null)
        root = now;
}

void splay(node *now, node *goal = null) {
    while(now->p != goal) {
        if(now->p->p == goal)
            rot(now);
        else {
            now->d() == now->p->d() ? rot(now->p) : rot(now);
            rot(now);
        }
    }
    now->upd();
    if(now->p == null)
        root = now;
}

node *find(int rk) { //assume that the data could be found is from 1 not 0
					 //i.e. we are actually finding the (rk+1)th element
    for(node *now = root; ; ) {
        now->relax();
        int sz = now->ch[0]->size;
        if(sz == rk)
            return now;
        else if(rk > sz)
            rk -= sz+1, now = now->ch[1];
        else
            now = now->ch[0];
    }
}

node *&get(int l, int r) { //[l,r)
    node *_l = find(l-1);
    node *_r = find(r);
    splay(_l);
    splay(_r, _l);
    return _r->ch[0];
}
