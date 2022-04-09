class Solution {
public:
    Node* connect(Node* root) {
        // base case
        if (root == NULL) return root;
        queue<Node*> q; // create new queue type node
        q.push(root); // put the root first in queue

        // loop while queue is not empty 
        while (!q.empty())
        {

            // set current node to front of queue
            // if current has a child set the left childs next pointer to the right child and right childs pointer to                 // NULL 
            Node* curr = q.front();
            if (curr->left != NULL)
            {
                curr->left->next = curr->right;
                if (curr->next != NULL)
                {
                    curr->right->next = curr->next->left;
                }

                // update queue
                q.push(curr->left);
                q.push(curr->right);
            }
            q.pop();
        }
        return root; // return the root
    }
};