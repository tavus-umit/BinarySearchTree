
#include "analysis.h"


int main() {

    // Functions to use Binary Search Tree
    int keys[] = {10,7,20,5,9,15,21,2,12,18,24,3,19};
    int size = 13;
    BST bst(keys, size);
    bst.findFullBTLevel();
    bst.lowestCommonAncestor(3,9);
    bst.lowestCommonAncestor(12,15);
    bst.maximumSumPath();
    bst.maximumWidth();
    bst.pathFromAtoB(2,21);
    bst.insertKey(8);
    bst.insertKey(7);
    bst.deleteKey(10);
    bst.deleteKey(11);
    bst.displayInorder();

    // Functions to measure the time taken for each 1000 insertions to the binary search tree
    analysis analysis;
    analysis.timeAnalysis();

    return 0;

}
