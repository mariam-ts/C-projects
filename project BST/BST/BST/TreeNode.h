
#include <iostream>
using namespace std;
#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {

public:
    friend class BST;
    TreeNode();  //default constructor
    TreeNode(int i, TreeNode* L = 0, TreeNode* R = 0); //explicit value constructor
    int getItem() const; // accessor function
    void setItem(int i);
private:
    int data;
    TreeNode* Lchild;
    TreeNode* Rchild;

};
     inline TreeNode::TreeNode()
        :data(NULL), Lchild(0), Rchild(0)
    {}

      inline TreeNode::TreeNode(int i, TreeNode* L , TreeNode* R )
        : data(i), Lchild(L), Rchild(R)
       {};

      inline int TreeNode::getItem() const
      {
        return data;
       }
      inline void TreeNode::setItem(int i)
      {
          data = i;
      }
#endif
