class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // base case
        if(inorder.size() != postorder.size()) return NULL;
        
        // hashmap to keep track of where the index of number in postorder exists in inorder vector
        map<int, int> m;
        for(int i = 0; i < inorder.size(); i++) 
        {
            m[inorder[i]] = i;  
        }
        
        // call a function which builds the binary tree using inorder and postorder
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, m);
        
        
    }
    
    // function that builds the tree using the parameters of vector index, starting points and ending points 
    TreeNode* buildTreePostIn(vector<int> &inorder, int iStartPoint, int iEndPoint, vector<int> &postorder, int pStartPoint, int pEndPoint, map<int, int> &m)
    {
        // return null if the size of the vectors are zero
        if(pStartPoint>pEndPoint || iStartPoint>iEndPoint) return NULL;
        
        // set the root equal to the last index in postorder 
        TreeNode* root = new TreeNode(postorder[pEndPoint]);
        int inOrderRoot = m[postorder[pEndPoint]]; // set the root of inorder to the last number in the posorder
        // get the number of elements of the left side by subtracting the root                                                   // index with the starting point of inorder
        int leftNums = inOrderRoot - iStartPoint; 
        
        //recursively divide the left and the right side of the tree into subproblems, where each side will contain its own root and place the left and right childs accordingly
        root->left  = buildTreePostIn(inorder, iStartPoint, inOrderRoot-1, postorder, pStartPoint, pStartPoint+leftNums-1, m);
        root->right = buildTreePostIn(inorder, inOrderRoot + 1, iEndPoint, postorder, pStartPoint+leftNums, pEndPoint-1, m);
        return root; // return the root
    }
};                                         
