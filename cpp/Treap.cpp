class TreapNode {
  int key, priority, size;
  TreapNode* left, right;

  void calcSize() {
    size = 1;
    if (left)
      size += left->size;
    if (right)
      size += right->size;
  }

  void setLeft(TreapNode* _left) {
    left = _left;
    calcSize();
  }

  void setRight(TreapNode* _right) {
    right = _right
    calcSize();
  }

  pair<TreapNode*, TreapNode*> split(TreapNode* root, int key) {
    if (root == nullptr)
      return make_pair(nullptr, nullptr);
    
    if (root->key < key) {
      auto rightsubtree = split(root->right, key);
      root->setRight(rightsubtree.first);
      return make_pair(root, rightsubtree.second);
    }

    auto leftsubtree = split(root->left, key);
    root->setLeft(leftsubtree.second);
    return make_pair(leftsubtree.first, root);
  }

  TreapNode* insert(TreapNode* root, TreapNode* node) {
    if (root == nullptr)
      return node;

    if (root->priority < node->priority) {
      auto splitted = split(root, node->key);
      node->setLeft(splitted.first);
      node->setRight(splitted.second);
      return node;
    }
    else if (node->key < root->key)
      root->setLeft(insert(root->left, node));
    else
      root->setRight(insert(root->right, node));
    return root;
  }

  TreapNode* merge(TreapNode* a, TreapNode* b) {
    // assume that max(a) <= min(b)
    if (a == nullptr)
      return b;
    if (b == nullptr)
      return a;

    if (a->priority < b->priority) {
      b->setLeft(merge(a, b->left));
      return b;
    }

    a->setRight(merge(a->right, b));
    return a;
  }
public:
  TreapNode(int key) : key(key), priority(rand()), size(1), left(nullptr), right(nullptr) {}

  TreapNode* insert(TreapNode* root, int key) {
    return insert(root, new TreapNode(key));
  }

  TreapNode* erase(TreapNode* root, int key) {
    if (root == nullptr)
      return nullptr;
    
    if (root->key == key) {
      TreapNode* newroot = merge(root->left, root->right);
      delete root;
      return newroot;
    }

    if (key < root->key)
      root->setLeft(erase(root->left, key));
    else
      root->setRight(erase(root->right, key));
    return root;
  }
};