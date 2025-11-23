class Solution
{
public:
    int parseBoolExpr(string expression)
    {
        stack<char> operation;
        stack<char> vals;
        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] == '!' || expression[i] == '|' || expression[i] == '&')
            {
                operation.push(expression[i]);
                vals.push(expression[i + 1]);
                i++;
            }
            else if (expression[i] == 't' || expression[i] == 'f')
                vals.push(expression[i]);

            else if (expression[i] == ')')
            {
                char currOp = operation.top();
                bool res = (vals.top() == 't' ? true : false);
                while (vals.top() != '(')
                {
                    bool currVal = (vals.top() == 't' ? true : false);
                    switch (currOp)
                    {
                    case '!':
                        res = !currVal;
                        break;
                    case '&':
                        res = res && currVal;
                        break;
                    case '|':
                        res = res || currVal;
                        break;
                    }
                    vals.pop();
                }
                operation.pop();
                vals.pop();
                vals.push((res == true ? 't' : 'f'));
            }
        }
        return vals.top() == 't';
    }
};