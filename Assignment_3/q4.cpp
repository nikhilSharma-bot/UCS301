#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string &exp)
{
    stack<char> st;
    string result = "";

    for (char ch : exp)
    {
        if (isalnum(ch))
        {
            result += ch;
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string exp;
    cout << "enter infix expression(only use * + - / and char ABC etc)";
    cin >> exp;
    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}
