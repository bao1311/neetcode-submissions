class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i = 0;
        int ans = 0;
        stack<string> st;
        while (i < tokens.size())
        {
            if (tokens[i] != "+" && tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "/")
            {
                st.push(tokens[i]);
            }
            else
            {
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
                st.pop();
                if (tokens[i] == "+")
                    st.push(to_string(a + b));
                else if (tokens[i] == "-")
                    st.push(to_string(a-b));
                else if (tokens[i] == "*")
                    st.push(to_string(a*b));
                else
                    st.push(to_string(a/b));

            }
            ++i;
        }
        return stoi(st.top());
        
    }
};
