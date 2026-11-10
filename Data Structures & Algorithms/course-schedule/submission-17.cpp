class Solution {
    unordered_map<int, vector<int>> prereq;
    unordered_set<int> visited;
public:

    bool helper(int node, unordered_set<int>& path) {
        if (path.find(node) != path.end()) return false;

        if (visited.find(node) != path.end()) return true;
        visited.insert(node);
        path.insert(node);
        for (int nei: prereq[node]) {
            if (!helper(nei, path)) return false;
        }
        path.erase(node);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int>& vec: prerequisites) {
            int from = vec[1], to = vec[0];
            prereq[to].push_back(from);
        }

        for (int course = 0; course < numCourses; course++) {
            unordered_set<int> path;
            if (!helper(course, path)) return false;
        }
        return true;
    }
};
