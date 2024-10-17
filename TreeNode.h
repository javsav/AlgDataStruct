
template<typename T>
class TreeNode {

 private:
  T data;
  bool isRed = true;
  TreeNode* parent;
  TreeNode* leftChild;
  TreeNode* rightChild;
  friend class RedBlackTree;

 public:
  TreeNode(T data, TreeNode* l, TreeNode* r, bool colour);
  TreeNode(T data, TreeNode* l, TreeNode* r);
  TreeNode(T data, bool colour);
  TreeNode(T data);
  TreeNode();
};


