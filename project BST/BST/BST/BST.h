#include "TreeNode.h"
#ifndef BINARY SEARCH TREE
#define BINARY SEARCH TREE

#include <iostream>
using namespace std;


class BST {
public:
	BST();
	void insert(int item);
	void deleteItem(int item);
	void graph(ostream& out);
	bool search( int item);
	void preorder(ostream & out );
	void postorder(ostream & out);
	void inorder(ostream & out);


private:
	TreeNode* root;
	void inorderAux(ostream& out,TreeNode* subtreePtr) ;
	void preorderAux(ostream& out,TreeNode* subtreePtr);
	void postorderAux(ostream& out,TreeNode* subtreePtr);
	void graphAux(ostream& out, int indent, TreeNode* subtreeRoot);
};

#endif
