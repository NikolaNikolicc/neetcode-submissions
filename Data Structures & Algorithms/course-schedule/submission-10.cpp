class Solution {
private:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> path;
    bool dfs(int pos){
        if (path.count(pos)){
            return false;
        }

        path.insert(pos);
        for (int pre: adj[pos]){
            if (!dfs(pre)){
                return false;
            }
        }
        path.erase(pos);
        adj[pos].clear();

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int> pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++){
            if (!dfs(i)){
                return false;
            }
        }
        return true;
    }
};
