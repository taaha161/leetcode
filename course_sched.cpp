class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> recursionStack(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && !dfs(visited, recursionStack, i, graph)) {
                return false;
            }
        }
       

       return true;

    }

    bool dfs(vector<bool>& visited, vector<bool>& recursionStack, int curr, vector<vector<int>>& graph  ){
        visited[curr] = true;
        recursionStack[curr] = true;

        for(int i=0; i<graph[curr].size(); i++){
            int neighbour = graph[curr][i];

            if(recursionStack[neighbour]){
                return false;
            }
            else if(!visited[neighbour]){
                if(!dfs(visited, recursionStack, neighbour, graph)){
                    return false;
                }
            }
        }
        recursionStack[curr] = false;

        return true;
    }
    
    vector<vector<int>> buildGraph(int vertices, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(vertices);

          for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        return graph;
    }

    
};