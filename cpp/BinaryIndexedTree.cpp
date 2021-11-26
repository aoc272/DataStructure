class BIT {
  vector<int> tree;
public:
  BIT(int n) : tree(n + 1, 0) {}

  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum += tree[i];
      i -= i & -i; // i &= i - 1
    }
    return sum;
  }

  void update(int i, int d) {
    while (i < tree.size()) {
      tree[i] += d;
      i += i & -i;
    }
  }
};