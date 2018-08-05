//============================================================================
// Problem  : 916D - Jamie and To-do List
// Category : Persistent Segment Tree
//============================================================================
#include <bits/stdc++.h>
using namespace std;

template <typename T> struct Node {
    T x;
    Node<T> *l, *r;
    Node() { l = nullptr; r = nullptr; x = T(); }
    Node(T px) { Node(); x = px; }
    T get() { return x; }
    void set(T px) { x = px; }
    void add(T px) { x = x+px; }
    void update() {
        x = T();
        if(l) x += l->get();
        if(r) x += r->get();
    }
};

template <typename T, int L = 0, int R = 100100>
struct seg_tree {
    using node = Node<T>;
    virtual node* get(node* before) {
        return before? before : new node();
    }
    node* root;
    seg_tree() { clear(); }
    void clear() { root = nullptr; }

    node* set(node* cur, int l, int r, int pos, T x) {
        cur = get(cur);
        if(l == r) cur->set(x);
        else {
            int mid = (l+r) >> 1;
            if(pos <= mid) 
                cur->l = set(cur->l, l, mid, pos, x);
            else 
                cur->r = set(cur->r, mid+1, r, pos, x);
            cur->update();
        }
        return cur;
    }
    node* set(int pos, T x) { return root = set(root, L, R, pos, x); }
    node* set(node *r, int pos, T x) { return set(r, L, R, pos, x); }

    node* add(node* cur, int l, int r, int pos, T x) {
        cur = get(cur);
        if(l == r) cur->add(x);
        else {
            int mid = (l+r) >> 1;
            if(pos <= mid) 
                cur->l = add(cur->l, l, mid, pos, x);
            else 
                cur->r = add(cur->r, mid+1, r, pos, x);
            cur->update();
        }
        return cur;
    }
    node* add(int pos, T x) { return root = add(root, L, R, pos, x); }
    node* add(node *r, int pos, T x) { return add(r, L, R, pos, x); }

    T query(node* cur, int l, int r, int x, int y) {
        if(cur == nullptr || l > y || r < x) return T();
        if(x <= l && r <= y) return cur->get();
        int mid = (l+r) >> 1;
        if(y <= mid) 
            return query(cur->l, l, mid, x, y);
        if(x > mid) 
            return query(cur->r, mid+1, r, x, y);
        return query(cur->l, l, mid, x, y) + query(cur->r, mid+1, r, x, y);
    }
    T query(int x, int y) { return query(root, L, R, x, y); }
    T query(node *r, int x, int y) { return query(r, L, R, x, y); }
};

template<typename T, int L = 0, int R = 100100>
struct persistent_tree : seg_tree<T, L, R>{
    using node = Node<T>;
    node* get(node* before) override {
        node* new_node = new node();
        if(before) {
            new_node->l = before->l;
            new_node->r = before->r;
            new_node->x = before->x;
        }
        return new_node;
    }
};

const int MAXP = 1000000005; // Max priority value
const int MAXN = 100005; // Max number of assignments
using node = Node<int>;
map<string,int> mp;
int cnt = 0;

int get(string &s) {
    if(mp.find(s) == mp.end())
        mp[s] = cnt++;
    return mp[s];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    persistent_tree<int,0,MAXP> fr; // count priorities
    persistent_tree<int,0,MAXN> pr; // asignment_id to priority
    node* root = nullptr;
    node* root_pr = nullptr;
    vector<node*> roots,roots_pr;
    roots.push_back(root);
    roots_pr.push_back(root_pr);
    int q,x;
    string op,s;
    cin >> q;
    while(q--) {
        cin >> op;
        if(op == "set") {
            cin >> s >> x;
            int id = get(s);
            int val = pr.query(root_pr, id, id);
            if(val) {
                root = fr.add(root, val, -1);
            }
            root_pr = pr.set(root_pr, id, x);
            root = fr.add(root, x, 1);
        } 
        else if(op == "remove") {
            cin >> s;
            int id = get(s);
            int val = pr.query(root_pr, id, id);
            if(val) {
                root_pr = pr.set(root_pr, id, 0);
                root = fr.add(root, val, -1);
            }
        } 
        else if(op == "query") {
            cin >> s;
            int id = get(s);
            int val = pr.query(root_pr, id, id);
            cout << (val? fr.query(root, 0, val-1) : -1) << '\n';
        } 
        else if(op == "undo") {
            cin >> x;
            root = roots[roots.size() - 1 - x];
            root_pr = roots_pr[roots.size() - 1 - x];
        }
        roots.push_back(root);
        roots_pr.push_back(root_pr);
        cout.flush();
    }
    return 0; 
}