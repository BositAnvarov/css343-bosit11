class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses); // create a adjacency list for the graph
        
        // iterate through the courses in prerequisite 
        for(vector<int>& c: prerequisites) 
        {
            adjacencyList[c[1]].push_back(c[0]); // push the second number in the first adjacency list
        }
        
         // for each nodes in the total courses do deep search and check for cycles
        vector<int> stack;
        vector<int> visited(numCourses, 0);
        int n = NULL;
        while(n < numCourses) 
        {   
            // if the cycle exists then stop the program because it is invalid
            if(visited[n] == 0 && topologicalSort(adjacencyList, visited, n, stack)) return vector<int>();
            n++;
        }
        // reverse the order of elements in the stack 
        reverse(stack.begin(), stack.end());
        return stack; 
    }
    
    // check for cycles and do deep search
    bool topologicalSort(vector<vector<int>>& adjacencyList, vector<int> & visited, int n, vector<int>& stack)
    {
        visited[n] = 1;
        // checking the neighbors
        for (int num : adjacencyList[n]) 
        {
            if(visited[num] == 1) return true; // cycle found
            // if not visited, recursively call the same function
            if(visited[num] == 0 && topologicalSort(adjacencyList, visited, num, stack)) return true;
        }
        visited[n] = 2;
        stack.push_back(n);
        return false; // no cycle has been found
        
    }
};