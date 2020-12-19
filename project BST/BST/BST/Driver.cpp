#include <ostream>
#include "BST.h"
#include <iostream>
using namespace std;
int main()
{
    BST tree;
    tree.graph(cout); // create BST
    tree.deleteItem(5); //delete from empty node
    tree.insert(77); //insert numbers
    tree.insert(30);
    tree.insert(90);
    tree.insert(29);
    tree.insert(89);
    tree.insert(156);
    tree.insert(88);
    tree.insert(12);
    tree.insert(3);
    tree.graph(cout); // graph the BST to visualize 
    cout << "The number " << (tree.search(158) ? "is" : "is not") << " in the BST\n";  //search non-existing number
    cout << "The number " << (tree.search(12) ? "is" : "is not") << " in the BST\n"; // search existing number
    tree.inorder(cout); // inorder
    cout << "" << endl; 
    tree.preorder(cout); //reorder
    cout << "" << endl;
    tree.postorder(cout); //postorder
    cout << "" << endl;
    tree.deleteItem(1); // delete non-existing node
    tree.deleteItem(12); // delete existing node with 1 child and display the BST
    tree.graph(cout);
    tree.deleteItem(29); // delete node with 2 child and dispay
    tree.graph(cout);
    tree.deleteItem(88); // delete node with 0 child and display
    tree.graph(cout);
    
}

