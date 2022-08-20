#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> parantheses;
        
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                parantheses.push(c);
            }
            else
            {
                if (parantheses.empty())
                    return false;
                char top_p = parantheses.top();
                if (c == ')' && top_p != '(')
                    return false;
                if (c == ']' && top_p != '[')
                    return false;
                if (c == '}' && top_p != '{')
                    return false;
                parantheses.pop();
            }
        }
        
        if (parantheses.empty())
            return true;
        else
            return false;
    }
};

