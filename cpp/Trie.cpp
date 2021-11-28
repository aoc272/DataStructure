constexpr int no_alphabets = 26;

class TrieNode {
  array<TrieNode*, no_alphabets> children;
  bool end;
public:
  TrieNode() : children{nullptr}, end{false} {}

  void insert(const string& key) {
    auto p = this;
    for (char c : key) {
      if (p->children[c - 'a'] == nullptr)
        p->children[c - 'a'] = new TrieNode;
      p = p->children[c - 'a'];
    }
    p->end = true;
  }

  bool find(const string& key) {
    auto p = this;
    for (char c : key) {
      if (p->children[c - 'a'] == nullptr)
        return false;
      p = p->children[c - 'a'];
    }
    return p->end;
  }
};