#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200'000

struct minmax_count {
    int min_value, min_count, max_value, max_count;
};

minmax_count tree[4 * MAX_N];
int first_son[MAX_N + 1];
int next_brother[MAX_N + 1];
int number[MAX_N + 1];
int subtree_end[MAX_N + 1];
int colours[MAX_N];
int n, q;

minmax_count combine(minmax_count a, minmax_count b) {
    int new_min_value, new_min_count, new_max_value, new_max_count;
    if (a.min_value < b.min_value) {
        new_min_value = a.min_value;
        new_min_count = a.min_count;
    } else if (b.min_value < a.min_value) {
        new_min_value = b.min_value;
        new_min_count = b.min_count;
    } else {
        new_min_value = a.min_value;
        new_min_count = a.min_count + b.min_count;
    }

    if (a.max_value > b.max_value) {
        new_max_value = a.max_value;
        new_max_count = a.max_count;
    } else if (b.max_value > a.max_value) {
        new_max_value = b.max_value;
        new_max_count = b.max_count;
    } else {
        new_max_value = a.max_value;
        new_max_count = a.max_count + b.max_count;
    }

    return minmax_count{new_min_value, new_min_count, new_max_value, new_max_count};
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = minmax_count{colours[tl], 1, colours[tl], 1};
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

minmax_count query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return minmax_count{INT32_MAX, 0, INT32_MIN, 0};
    }
    if (tl == l and tr == r) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = minmax_count{new_val, 1, new_val, 1};
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}

void make_christmas_tree() {
    int father;
    for (int i = 1; i <= n - 1; i++) {
        cin >> father; // father of (i+1)-th vertex
        next_brother[i + 1] = first_son[father];
        first_son[father] = i + 1;
    }
}

int make_preorder(int vertex, int act_num) {
    int son = first_son[vertex];
    number[vertex] = act_num;
    act_num++;
    while (son != 0) {
        act_num = make_preorder(son, act_num);
        son = next_brother[son];
    }
    subtree_end[vertex] = act_num - 1;
    return act_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    make_christmas_tree();
    make_preorder(1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> colours[number[i]];
    }

    build(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        char type; cin >> type;
        int v, x;
        if (type == 'z') {
            cin >> v >> x;
            update(1, 0, n - 1, number[v], x);
        } else {
            cin >> v;
            minmax_count result = query(1, 0, n - 1, number[v], subtree_end[v]);
            if (result.min_value == result.max_value or
            result.max_count == subtree_end[v] - number[v] or
            result.min_count == subtree_end[v] - number[v]) {
                cout << "TAK\n";
            } else {
                cout << "NIE\n";
            }
        }
    }

    return 0;
}
