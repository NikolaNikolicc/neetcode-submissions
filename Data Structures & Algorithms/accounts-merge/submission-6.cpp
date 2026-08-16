class UnionFind {
    unordered_map<int, unordered_set<string>> accEmails;
    unordered_map<int, int> accParents;
    unordered_map<int, string> accName;
public:
    unordered_set<string> getEmails (int index) {
        return accEmails[index];
    }

    string getName(int index) {
        return accName[index];
    }

    int find(int node) {
        while (node != accParents[node]) {
            accParents[node] = accParents[accParents[node]];
            node = accParents[node];
        }
        return node;
    }

    void addAccount(int index, string name, vector<string> emails) {
        accParents[index] = index;
        accEmails[index] = unordered_set<string>(emails.begin(), emails.end());
        accName[index] = name;
        for (int i = 0; i < index; i++) {
            int parent = find(i);
            if (parent != i) continue;

            for (const auto &email: accEmails[i]) {
                if (accEmails[index].count(email)) {
                    accParents[i] = index;
                    for (const auto &e: accEmails[i]) accEmails[index].insert(e);
                    break;
                }
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind *uf = new UnionFind();
        
        for (int i = 0; i < accounts.size(); i++) {
            string name = accounts[i][0];
            vector<string> emails(accounts[i].begin() + 1, accounts[i].end());

            uf->addAccount(i, name, emails);
        }

        vector<vector<string>> res;
        for (int i = 0; i < accounts.size(); i++) {
            int parent = uf->find(i);
            if (parent == i) {
                vector<string> myVec(uf->getEmails(parent).begin(), uf->getEmails(parent).end());
                sort(myVec.begin(), myVec.end());
                myVec.insert(myVec.begin(), uf->getName(parent));
                res.push_back(myVec);
            }
        }
        return res;
    }
};