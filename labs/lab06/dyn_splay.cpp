// Operacje leftRotate, rightRotate i splay wzorowane na:
// https://www.geeksforgeeks.org/splay-tree-set-1-insert/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    const int element, weight;
    int count;
    struct Node *left, *right;

    Node(int _element, int _weight) : element(_element), weight(_weight),
                                      count(_weight), left(nullptr),
                                      right(nullptr) {}
};

int countValue(Node *v) {
    return (v != nullptr) ? v->count : 0;
}

void updateCountValue(Node *v) {
    assert(v != nullptr);
    v->count = v->weight + countValue(v->left) + countValue(v->right);
}

Node *leftRotate(Node *currentRoot) {
    Node *rightSon = currentRoot->right;
    currentRoot->right = rightSon->left;
    rightSon->left = currentRoot;
    updateCountValue(currentRoot);
    updateCountValue(rightSon);
    return rightSon;
}

Node *rightRotate(Node *currentRoot) {
    Node *leftSon = currentRoot->left;
    currentRoot->left = leftSon->right;
    leftSon->right = currentRoot;
    updateCountValue(currentRoot);
    updateCountValue(leftSon);
    return leftSon;
}

Node *splay(Node *root, int seqIndex) {
    if (root == nullptr) {
        return root;
    }
    if (seqIndex >= countValue(root->left) &&
        seqIndex <= countValue(root->left) + root->weight - 1) {
        return root;
    } else if (seqIndex < countValue(root->left)) {
        if (root->left == nullptr) {
            return root;
        }
        if (seqIndex < countValue(root->left->left)) {
            root->left->left = splay(root->left->left, seqIndex);
            root = rightRotate(root);
        } else if (seqIndex >= countValue(root->left->left) + root->left->weight) {
            root->left->right = splay(root->left->right, seqIndex -
            countValue(root->left->left) - root->left->weight);
            if (root->left->right != nullptr) {
                root->left = leftRotate(root->left);
            }
        }
        return (root->left == nullptr) ? root : rightRotate(root);
    } else {
        if (root->right == nullptr) {
            return root;
        }
        if (seqIndex - countValue(root->left) - root->weight <
            countValue(root->right->left)) {
            root->right->left = splay(root->right->left,
            seqIndex - countValue(root->left) - root->weight);
            if (root->right->left != nullptr) {
                root->right = rightRotate(root->right);
            }
        } else if (seqIndex - countValue(root->left) - root->weight >=
                    countValue(root->right->left) + root->right->weight) {
            root->right->right = splay(root->right->right,
            seqIndex - countValue(root->left) - root->weight
            - countValue(root->right->left) - root->right->weight);
            root = leftRotate(root);
        }
        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

int get(Node **root, int j) {
    *root = splay(*root, j);
    return (*root)->element;
}

void insert(Node **root, int j, int x, int k) {
    Node *newSeg = new Node(x, k);
    if (*root == nullptr) {
        *root = newSeg;
        return;
    }
    Node *v = splay(*root, j);
    if (j == countValue(v->left)) {
        newSeg->left = v->left;
        v->left = newSeg;
        updateCountValue(newSeg);
        updateCountValue(v);
        *root = v;
    } else if (j == countValue(v->left) + v->weight) {
        newSeg->right = v->right;
        v->right = newSeg;
        updateCountValue(newSeg);
        updateCountValue(v);
        *root = v;
    } else {
        Node *v1 = new Node(v->element, j - countValue(v->left));
        Node *v2 = new Node(v->element, v->weight - j + countValue(v->left));
        v1->left = v->left;
        v2->right = v->right;
        newSeg->left = v1;
        newSeg->right = v2;
        updateCountValue(v1);
        updateCountValue(v2);
        updateCountValue(newSeg);
        delete v;
        *root = newSeg;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *root = nullptr;
    int m; cin >> m;
    int w = 0;
    for (int i = 0; i < m; i++) {
        char op;
        int j, x, k;
        cin >> op;
        if (op == 'i') {
            cin >> j >> x >> k;
            j = (j + w) % (countValue(root) + 1);
            insert(&root, j, x, k);
        } else if (op == 'g') {
            cin >> j;
            j = (j + w) % countValue(root);
            w = get(&root, j);
            cout << w << "\n";
        }
    }
    return 0;
}
