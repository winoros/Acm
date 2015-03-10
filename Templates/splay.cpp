const int max_node;
const int inf;

struct node {
    int val, size, change, minn, maxx, sum;
    bool reverse;
    node *p, *ch[2];
    node (): size(0), change(0), minn(inf), maxx(-inf), sum(0), reverse(false) {}
    bool d() {
        return p->ch[1] == this;
    }
	//remember upd after setc
    void setc(node *c, int d) {
        c->p = this;
        ch[d] = c;
    }
	void add(int v) {
		change += v;
		val += v;
		minn += v;
		maxx += v;
		sum += size*v;
	}
    void rev() {
        reverse ^= 1;
    }
    void upd() {
        size = ch[0]->size + ch[1]->size + 1;
		minn = min(val, min(ch[0]->minn, ch[1]->minn));
		maxx = max(val, max(ch[0]->maxx, ch[1]->maxx));
		sum = val + ch[0]->sum + ch[1]->sum;
    }
    void relax();
} Tnull, *null = &Tnull;

void node::relax() {
	if(change != 0) {
		for(int i = 0; i < 2; ++i)
			if(ch[i] != null)
				ch[i]->add(change);
		change = 0;
	}
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

node *make(int val) { // add a new node into the tree
	tot->p = null;
	tot->val = tot->sum = tot->minn = tot->maxx = val;
	tot->change = 0;
	tot->reverse = false;
	tot->ch[0] = tot->ch[1] = null;
	tot->size = 1;
	return ++tot;
}

node *build(int l, int r) {
	if(l > r)
		return null;
	int m = (l+r)>>1;
	node *now = make(value(m)); //edit the value(m) according to the specific problem
	now->setc(build(l, m-1), 0);
	now->setc(build(m+1, r), 0);
	now->upd();
	return now;
}

void insert(int pos, int val) { //insert a new element after posth element
	node *pred = find(pos);
	node *succ = find(pos+1);
	splay(succ);
	splay(pred, succ);
	pred->setc(make(val), 1);
	pred->upd();
	succ->upd();
}

void del(int pos) { //delete posth element
	node *pred = find(pos-1);
	node *succ = find(pos+1);
	splay(pred);
	splay(succ, pred);
	succ->ch[0] = null;
	succ->upd();
	pred->upd();
}
