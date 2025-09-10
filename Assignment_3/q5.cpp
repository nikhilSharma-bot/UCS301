#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(const string &exp)
{
    stack<int> st;
    for (char ch : exp)
    {
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            switch (ch)
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}
