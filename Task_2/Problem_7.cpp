class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'c')
            {
                if (st.size() >= 2)
                {
                    auto prv = st.top(); // b
                    st.pop();
                    auto befPrv = st.top(); // a
                    st.pop();
                    if (prv != 'b' || befPrv != 'a') return false;
                }
                else return false;

            }
            else
            {
                st.push(s[i]);
            }
        }
        return (st.empty());
    }
};