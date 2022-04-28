class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL) return new TreeNode(val); // base case, add the new value if the node is null 
        // if the value passed is less than the root, add the value on the left side of the node
        else if (val < root->val) 
        {
            
            root->left = insertIntoBST(root->left, val); //check left subtree using recursion 
            
        }
        
        // if the value passed is more than the root, add the value on the right side of the node
        else 
        {
            
            root->right = insertIntoBST(root->right, val); //check right subtree using recursion
            
        }
        
        return root; // return the root
        
    }
};