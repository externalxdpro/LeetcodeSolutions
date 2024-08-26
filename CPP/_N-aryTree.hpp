#include <vector>

class Node {
  public:
    int                 val;
    std::vector<Node *> children;

    Node() = default;

    Node(int _val) { val = _val; }

    Node(int _val, std::vector<Node *> _children) {
        val      = _val;
        children = _children;
    }
};
