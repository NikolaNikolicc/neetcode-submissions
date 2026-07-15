class Solution {
public:

    bool addElem(stack<char>& s, char p) {
        if (p == '(' || p == '{' || p == '[') {
            s.push(p);
            return true;
        }
        
        if (s.size() == 0) return false;
        char lastItem = s.top();
        if (
            (p == ')' && lastItem == '(') ||
            (p == '}' && lastItem == '{') ||
            (p == ']' && lastItem == '['))
            {
                s.pop();
                return true;
            }
        return false;
    }

    bool isValid(string s) {
        stack<char> parenthesis;
        for (auto& p: s) {
            if (!addElem(parenthesis, p)) return false;    
        }
        return parenthesis.size() == 0;
    }
};
