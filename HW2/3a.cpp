// 72/80 cases passed
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        int max = 2147483647; //max a nodes value can be
        int min = -2147483648; //min a nodes value can be
        return subValid(root, min, max); // call function subValid to determine the node interval 
        
    }    
    bool subValid(TreeNode* node, int &leftInterval, int &rightInterval) { 
        
        if(node == NULL) return true; // base case
        
        //if the node is less than left interval and more than right interval, then node is not valid so return false
        if(!(node->val > leftInterval && node->val < rightInterval)) return false; 
        
        // divide the children of the bst into subproblems using recursion and pass appropriate intervals for each side
        return (subValid(node->left, leftInterval, node->val) && subValid(node->right, node->val, rightInterval)); 
    }
};