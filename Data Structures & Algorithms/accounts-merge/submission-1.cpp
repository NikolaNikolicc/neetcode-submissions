class UnionFind {
    unordered_map<int, unordered_set<string>> accEmails;
    unordered_map<int, int> accParents;
    unordered_map<int, string> accName;
public:
    unordered_set<string> getEmails(int index) {
        return accEmails[index];
    }

    string getName(int index) {
        return accName[index];
    }

    int find(int node) {
        if (accParents.find(node) == accParents.end()) accParents[node] = node;
        while (node != accParents[node]) {
            accParents[node] = accParents[accParents[node]];
            node = accParents[node];
        }
        return node;
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        accParents[pa] = pb;
        for (const auto &e : accEmails[pa]) accEmails[pb].insert(e);
        accEmails[pa].clear();
    }

    void addAccount(int index, string name, vector<string>& emails) {
        accName[index] = name;
        accParents[index] = index;
        for (const auto &e : emails) accEmails[index].insert(e);

        for (int i = 0; i < index; i++) {
            for (const auto &email : emails) {
                if (accEmails[find(i)].count(email)) {
                    unite(index, i);
                    break;
                }
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf;

        for (int i = 0; i < (int)accounts.size(); i++) {
            string name = accounts[i][0];
            vector<string> emails(accounts[i].begin() + 1, accounts[i].end());
            uf.addAccount(i, name, emails);
        }

        vector<vector<string>> res;
        for (int i = 0; i < (int)accounts.size(); i++) {
            if (uf.find(i) == i) {
                unordered_set<string> emailSet = uf.getEmails(i);
                vector<string> myVec(emailSet.begin(), emailSet.end());
                sort(myVec.begin(), myVec.end());
                myVec.insert(myVec.begin(), uf.getName(i));
                res.push_back(myVec);
            }
        }
        return res;
    }
};