class Solution {
    unordered_map<int, vector<int>> adj;

public:
    bool dfs(int course, unordered_set<int>& visited) {
        if (visited.count(course) > 0) {
            return false;
        }
        
        if (adj[course].size() == 0) {
            return true;
        }
        visited.insert(course);
        for (int nei: adj[course]) {
            if (!dfs(nei, visited)) {
                return false;
            }
        }
        visited.erase(course);
        adj[course] = {};
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int> pre: prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        
        unordered_set<int> visited;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, visited)) return false;
        }
        return true;
    }
};
