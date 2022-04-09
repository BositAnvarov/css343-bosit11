class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) 
        {
            
            Node* curr = q.front();
            if(curr->left != NULL) 
            {
                curr->left->next = curr->right;
                if (curr->next != NULL) 
                {
                    curr->right->next = curr->next->left;
                }
                q.push(curr->left);
                q.push(curr->right);
            }
            q.pop();
        }
        return root;
    }
};