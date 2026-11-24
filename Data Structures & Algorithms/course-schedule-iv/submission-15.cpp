#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<int, unordered_set<int>> prereq; // key: course, val: prerequisites for that course
    unordered_set<int> visited;
    vector<int> path;

    void addPath(int course) {
        for (int p: path) {
            prereq[course].insert(p);
        }
    }

    void printPrereq(int numCourses){
        for (int i = 0; i < numCourses; i++) {
            cout << "course: " << i << " prerequisites: [";

            bool first = true;
            for (int nei: prereq[i]) {
                if (!first) cout << ", ";
                cout << nei;
                first = false;
            }
            cout << "]" << endl; 
        }
    }

    bool topo(vector<vector<int>>& prerequisites, int course) {
        if (visited.find(course) != visited.end()) return false;

        addPath(course);
        
        path.push_back(course);
        visited.insert(course);

        for (int nei: prerequisites[course]) topo(prerequisites, nei);
        path.pop_back();
        return true;

    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj;
        adj.assign(numCourses, vector<int>());

        for (int i = 0; i < numCourses; i++) {
            prereq[i] = unordered_set<int>();
            adj[i] = vector<int>();
        }


        for (vector<int>& pre: prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            visited.clear();
            topo(adj, i);
        }
        // printPrereq(numCourses);

        vector<bool> res;

        for (vector<int>& query: queries) {
            int from = query[0], to = query[1];
            res.push_back(prereq[to].find(from) != prereq[to].end());
        }
        
        return res;
    }
};