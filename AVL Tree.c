#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *left, *right;
};

int height(struct Node* n) { return n ? n->height : 0; }
int max(int a, int b) { return a > b ? a : b; }

struct Node* newNode(int key) {
    struct Node* n = malloc(sizeof(struct Node));
    n->key = key; n->left = n->right = NULL; n->height = 1;
    return n;
}

int getBalance(struct Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left; y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right; x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* insert(struct Node* n, int k) {
    if (!n) return newNode(k);
    if (k < n->key) n->left = insert(n->left, k);
    else if (k > n->key) n->right = insert(n->right, k);
    else return n;
    n->height = 1 + max(height(n->left), height(n->right));
    int b = getBalance(n);
    if (b > 1 && k < n->left->key) return rotateRight(n);
    if (b < -1 && k > n->right->key) return rotateLeft(n);
    if (b > 1 && k > n->left->key) { n->left = rotateLeft(n->left); return rotateRight(n); }
    if (b < -1 && k < n->right->key) { n->right = rotateRight(n->right); return rotateLeft(n); }
    return n;
}

struct Node* minValue(struct Node* n) {
    while (n->left) n = n->left;
    return n;
}

struct Node* delete(struct Node* r, int k) {
    if (!r) return r;
    if (k < r->key) r->left = delete(r->left, k);
    else if (k > r->key) r->right = delete(r->right, k);
    else {
        if (!r->left || !r->right) {
            struct Node* t = r->left ? r->left : r->right;
            if (!t) { free(r); return NULL; }
            *r = *t; free(t);
        } else {
            struct Node* t = minValue(r->right);
            r->key = t->key;
            r->right = delete(r->right, t->key);
        }
    }
    r->height = 1 + max(height(r->left), height(r->right));
    int b = getBalance(r);
    if (b > 1 && getBalance(r->left) >= 0) return rotateRight(r);
    if (b > 1 && getBalance(r->left) < 0) { r->left = rotateLeft(r->left); return rotateRight(r); }
    if (b < -1 && getBalance(r->right) <= 0) return rotateLeft(r);
    if (b < -1 && getBalance(r->right) > 0) { r->right = rotateRight(r->right); return rotateLeft(r); }
    return r;
}

struct Node* search(struct Node* r, int k) {
    if (!r || r->key == k) return r;
    return k < r->key ? search(r->left, k) : search(r->right, k);
}

void inorder(struct Node* r) {
    if (r) { inorder(r->left); printf("%d ", r->key); inorder(r->right); }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    inorder(root); printf("\n");

    root = delete(root, 20);
    inorder(root); printf("\n");

    printf("Search 30: %s\n", search(root, 30) ? "Found" : "Not found");
    return 0;
}
