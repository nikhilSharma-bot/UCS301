#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &s)
{
    stack<char> parenthesesStack;
    for (char ch : s)
    {
        if (ch == '(')
        {
            parenthesesStack.push(ch);
        }
        else if (ch == ')')
        {
            if (parenthesesStack.empty())
                return false;
            parenthesesStack.pop();
        }
    }
    return parenthesesStack.empty();
}

int main()
{
    string s;
    cout << "Enter expression: ";
    cin >> s;
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
