/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
     
    map <Node*, Node*> checked; // hashmap to store nodes
    Node* cloneGraph(Node* node) {
        
        
        if(node == NULL) return NULL; // base case
        
        if(checked[node]) return checked[node]; // if the node is inside checked map return
        
        Node *cloneNode = new Node(node->val, node->neighbors); //clone a new node
        checked[node] = cloneNode; //add the cloned node to map
        
        
        // loop through the neighbors 
        int num;
        while(cloneNode->neighbors.size() > num) 
        {
            cloneNode->neighbors[num] = cloneGraph(cloneNode->neighbors[num]); // set the neighbor nodes
            num++; //increment equal to number of nodes in original graph
        }
        return cloneNode; //return the cloned graph
        
        
        
    }
};