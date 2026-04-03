class Solution {
public:
    stack<string> st;

    string emptyStack() {
        string tmp = "";
        while (st.size() > 0 && st.top() != "[") {
            tmp = st.top() + tmp;
            st.pop();
        }
        if (st.size() > 0 && st.top() == "[") {
            st.pop();
        }
        return tmp;
    }

    void printStack() {
        stack<string> temp = st;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    string decodeString(string s) {
        int i = 0;
        while (i < s.size()) 
        {
            if (s[i] == ']') 
            {
                string tmp = this->emptyStack();
                int multiplier = stoi(st.top());
                st.pop();
                string helper = "";
                while (multiplier--) 
                {
                    helper += tmp;
                }
                st.push(helper);
            } 
            else 
            {
                if (isdigit(s[i])) 
                {
                    string num = "";
                    while (i < s.size() && isdigit(s[i])) 
                    {
                        num += s[i];
                        i++;
                    }
                    i--;
                    st.push(num);
                } 
                else 
                {
                st.push(string(1, s[i]));
                }
            }
            i++;
        }
        string tmp = this->emptyStack();
        return tmp;
    }
};