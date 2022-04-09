class Solution {
public:
    void flatten(TreeNode* root) {
        //base case
        if(root == NULL) return;
        stack<TreeNode*> s; // using stack type TreeNode
        s.push(root); // insert root node to stack 
        
    
        while(!s.empty()) 
        {
            //set current node to the top stack and remove it
            TreeNode* curr = s.top();
            s.pop();
            
            // update stacks data with children nodes 
            if(curr->right != NULL) s.push(curr->right);
            if(curr->left != NULL) s.push(curr->left);
            
            //set the right child of current to the value at the top of the stack for post-order 
            if(!s.empty()) curr->right = s.top();
            curr->left = NULL; // set the left children of the node to null
        }
        
    }
};