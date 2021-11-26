class Heap {
  vector<int> data;
public:
  Heap() : data{} {}

  void push(int x) {
    data.push_back(x);
    int i = data.size() - 1;
    while (i > 0 && data[(i - 1) / 2] < data[i]) {
      swap(data[(i - 1) / 2], data[i]);
      i = (i - 1) / 2;
    }
  }

  void pop() {
    swap(data.front(), data.back());
    data.pop_back();
    int cur = 0, l, r, next;
    while (true) {
      l = 2 * cur + 1;
      r = l + 1;
      next = cur;
      
      if (l >= data.size())
        break;

      if (data[next] < data[l])
        next = l;

      if (r < data.size() && data[next] < data[r])
        next = r;

      if (next == cur)
        break;

      swap(data[cur], data[next]);
      cur = next;
    }
  }

  int top() {
    return data.front();
  }
};