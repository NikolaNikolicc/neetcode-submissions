class Solution {
    vector<vector<int>> adj;
    unordered_map<int, unordered_set<int>> prereqMap;

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.assign(numCourses, vector<int>());
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        for (int crs = 0; crs < numCourses; crs++) {
            dfs(crs);
        }

        vector<bool> res;
        for (auto& query : queries) {
            res.push_back(prereqMap[query[1]].count(query[0]));
        }
        return res;
    }

private:
    unordered_set<int>& dfs(int crs) {
        if (prereqMap.count(crs)) {
            return prereqMap[crs];
        }
        prereqMap[crs] = unordered_set<int>();
        for (int pre : adj[crs]) {
            auto& cur = dfs(pre);
            prereqMap[crs].insert(cur.begin(), cur.end());
        }
        prereqMap[crs].insert(crs);
        return prereqMap[crs];
    }
};