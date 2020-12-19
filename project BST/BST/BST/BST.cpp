#include "BST.h"
#include <iostream>
using namespace std;
BST::BST()
{
    root = NULL;
}
void BST::insert(int item)
{
    TreeNode* locptr = root;
    TreeNode* parent = NULL;        // pointer to parent of current node
       bool found = false;     // indicates if item already in BST
    while (!found && locptr != 0)
    {
        parent = locptr;
        if (item < locptr->data)       // descend left
            locptr = locptr->Lchild;
        else if (locptr->data < item)  // descend right
            locptr = locptr->Rchild;
        else                           // item found
            found = true;
    }
    if (!found)
    {                                 // construct node containing item
        locptr = new TreeNode(item);
        if ( parent == 0)               // empty tree
            root = locptr;
        else if (item < parent->data)  // insert to left of parent
            parent->Lchild = locptr;
        else                           // insert to right of parent
            parent->Rchild = locptr;
    }
    else
        cout << "Item already in the tree\n";
}



void BST::deleteItem(int item)
{
    TreeNode* locptr = root;
    TreeNode* parent = 0;
    bool found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       // descend left
        {
            parent = locptr;
            locptr = locptr->Lchild;
        }
        else if (locptr->data < item)  // descend right
        {
            parent = locptr;
            locptr = locptr->Rchild;
        }
        else                           // item found
            found = true;
    }
    if (!found)
    {
        cout << "item isn't found"<<endl;
        return;
    }
    if (locptr->Lchild != 0 && locptr->Rchild != 0)
    {
        TreeNode* succ = locptr->Rchild;
        parent = locptr;
        while (succ->Lchild != 0)
        {
            parent = succ;
            succ = succ->Lchild;
        }
        locptr->data = succ->data;
        locptr = succ;
    }
    TreeNode* sub = locptr->Lchild;
    if (sub == 0)
        sub = locptr->Rchild;
    if (parent == 0)
        root = sub;
    else if (parent->Lchild == locptr)
        parent->Lchild = sub;
    else
        parent->Rchild = sub;
    delete locptr;

}

bool BST::search(int item)
{
    TreeNode* locptr = root;
    bool found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       
            locptr = locptr->Lchild;
        else if (locptr->data < item)  
            locptr = locptr->Rchild;
        else                           
            found = true;
    }
    return found;
}
void BST::preorder(ostream& out)
{
    preorderAux(out, root);
}
void BST::postorder(ostream& out)
{
    postorderAux(out, root);
}
void BST::inorder(ostream& out)
{
    inorderAux(out, root);
}
void BST::preorderAux(ostream& out, TreeNode* subtreeRoot)
{
    if (subtreeRoot != 0)
    {
        out << subtreeRoot->data << "  ";      // V operation
        preorderAux(out, subtreeRoot->Lchild);    // L operation
        preorderAux(out, subtreeRoot->Rchild);   // R operation
    }
}
void BST::postorderAux(ostream& out, TreeNode* subtreeRoot)
{
    if (subtreeRoot != 0)
    {  
        
        postorderAux(out, subtreeRoot->Lchild);    // L operation
       postorderAux(out, subtreeRoot->Rchild);   // R operation
       out << subtreeRoot->data << "  ";      // V operation 
        
    }
}
void BST::inorderAux(ostream& out,  TreeNode* subtreeRoot) 
{
    if (subtreeRoot != 0)
    {
        inorderAux(out, subtreeRoot->Lchild);    // L operation
        out << subtreeRoot->data << "  ";      // V operation
        inorderAux(out, subtreeRoot->Rchild);   // R operation
    }
}
void BST::graph(ostream& out)
{
    graphAux(out, 0, root);
}
#include <iomanip>

void BST::graphAux(ostream& out, int indent,TreeNode* subtreeRoot)
{
    if (subtreeRoot != 0)
    {
        graphAux(out, indent + 8, subtreeRoot->Rchild);
        out << setw(indent) << " " << subtreeRoot->data << endl;
        graphAux(out, indent + 8, subtreeRoot->Lchild);
    }
}
