#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key)
{
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void postOrder(Node* root)
{
    if (root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> keys;
    int key;

    while (cin >> key)
        keys.push_back(key);

    Node* root = nullptr;
    for (int k : keys)
        root = insert(root, k);

    postOrder(root);

    return 0;
}