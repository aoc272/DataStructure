#include <vector>

using namespace std;

int query(const vector<int>& seg, int n, int b, int e, int l, int r) {
    if (r < b || e < l)
        return 0;

    if (l <= b && e <= r)
        return seg[n];

    int c = 2 * n + 1, m = (b + e) / 2;
    return query(seg, c, b, m, l, r) + query(seg, c + 1, m + 1, e, l, r);
}

void update(vector<int>& seg, int n, int b, int e, int i, int d) {
    if (i < b || e < i)
      return;

    if (b == e) {
      seg[n] += d;
      return;
    }

    int c = 2 * n + 1, m = (b + e) / 2;
    update(seg, c, b, m, i, d);
    update(seg, c + 1, m + 1, e, i, d);
    seg[n] = seg[c] + seg[c + 1];
}

void build(vector<int>& seg, int n, int b, int e, const vector<int>& v) {
  if (b == e) {
    seg[n] = v[b];
    return;
  }
  
  int c = 2 * n + 1, m = (b + e) / 2;
  build(seg, c, b, m, v);
  build(seg, c + 1, m + 1, e, v);
  seg[n] = seg[c] + seg[c + 1];
}