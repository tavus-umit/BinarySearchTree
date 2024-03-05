# BinarySearchTree

The member functions of "BST" class are defined as follows:
__BST__: Constructor. Reads the integer keys of the array one by one, and inserts them into the binary search tree one by
one. You can assume that there are no identical keys in the array.


__insertKey__: Inserts a key to the BST, if it does not exist in the BST before.


__deleteKey__: Deletes a key from the BST, if it exists in the BST.


__displayInorder__: Displays an inorder traversal of the BST.


__findFullBTLevel__: Finds the maximum level at which the tree is a full binary tree, and displays the level number.
Assume that root is level 1 in all the level related questions.


__lowestCommonAncestor__: Finds the common Ancestor of keys A and B that has the highest level. Assume that a node
A is the ancestor of itself.


__maximumSumPath__: Finds the path from root to a leaf node which has the maximum sum of the keys included in the
path, and displays the keys of the path from its root to the leaf. You can assume that there is only one path with the
maximum Sum path in the tree.


__maximumWidth__: Finds the level of the tree which has the maximum number of nodes and displays its keys from left
to right. In case of multiple maximum widths select the lowest level.


__pathFromAtoB__: Finds the path from key A to key B, and displays the keys included in the path

The member functions of "analysis" class are defined as follows


__timeAnalysis__:generates a list of 10,000 random numbers and begins inserting them into an empty pointer-based Binary Search Tree (BST).
After every 1000 insertions, displays: a) the time taken for those insertions (using the clock function from the ctime
library to calculate elapsed time), and b) the height of the tree.
