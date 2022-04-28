class Solution {
public:
    
    TreeNode* deleteNode(TreeNode* root, int key) { 
        if(root == NULL) return root; // base case 
        if(root->val > key) root->left = deleteNode(root->left, key); // check if the key is on the left subtree
        if(root->val < key) root->right = deleteNode(root->right, key); // check if the key is on the right subtree
        
        // after finding the key delete the node
        if(root->val == key) 
        {
            // no child
            if(root->left == NULL && root->right == NULL)
            {
                root = NULL; // leaf node
                return root;
            }
            
            // left child
            else if(root->right == NULL)
            {
                root = root->left; 
                return root;
            }
            
            // right child
            else if(root->left == NULL)
            {
                root = root->right;
                return root;
            }
            
            //2 children 
            else 
            {
                // create a temporary variable to store the right child of node
                // find the min node on the right subtree
                TreeNode* tmp = findMin(root->right); 
                root->val = tmp->val; // set root's value to the temp variable
                root->right = deleteNode(root->right, tmp->val); 
            }
            
        }
        
        return root;
    }
    
    // function to find the min value of the right subtree
    TreeNode* findMin(TreeNode* root) 
    {
        TreeNode* curr = root;
        while(curr->left != NULL) 
        {
            curr = curr->left;
        }
        return curr;
    }
    
};