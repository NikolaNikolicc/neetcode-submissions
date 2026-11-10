class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> pr(numCourses);

        for (vector<int> prereq: prerequisites) {
            int to = prereq[0], from = prereq[1];
            indegree[to]++;
            pr[from].push_back(to);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int number = 0;
        while (q.size()) {
            int node = q.front(); q.pop();
            number++;

            for (int nei: pr[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }
        return number == numCourses;
    }
};
