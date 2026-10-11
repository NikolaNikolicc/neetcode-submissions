#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>      // for std::pair
#include <algorithm>    // for std::find_if
#include <iostream>     // if you print anything

using namespace std;

class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_set<string> visited;

    double canGet(string &from, string &to) {
        if (visited.count(from) || adj.find(from) == adj.end()) {
            return -1.;
        }
        
        if (from == to) {
            // print same node
            cout << "same node: " << from << endl;
            return 1.;
        }

        visited.insert(from);
        for (auto &[nei, dist]: adj[from]) {
            double res = canGet(nei, to);
            if (res != -1.) {
                return res * dist;
            }
        }
        visited.erase(from);
        return -1.;
    }
    
public:

    bool contains(vector<pair<string, double>>& vec, string &value) {
        auto it = find_if(vec.begin(), vec.end(), 
            [&](const pair<string, double>& p) { return p.first == value;}
        );
        return it != vec.end();
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for (int i = 0; i < values.size(); i++) {
            string from = equations[i][0];
            string to = equations[i][1];
            double distance = values[i];
            if (!this->contains(adj[from], from)) adj[from].push_back({from, 1.});
            if (!this->contains(adj[from], to)) adj[from].push_back({to, distance});
            if (!this->contains(adj[to], to)) adj[to].push_back({to, 1.});
            if (!this->contains(adj[to], from)) adj[to].push_back({from, 1./distance});
        }

        // print adj list
        for (auto &[key, vec]: adj) {
            cout << key << ": ";
            for (auto &[nei, dist]: vec) {
                cout << "(" << nei << ", " << dist << ") ";
            }
            cout << endl;
        }

        vector<double> result;

        for (vector<string> &query: queries) {
            visited.clear();
            // print query
            cout << "query: " << query[0] << ", " << query[1] << endl;
            double res = canGet(query[0], query[1]);
            result.push_back(res);
            cout << "result: " << res << endl;
        }
        return result;
    }
};