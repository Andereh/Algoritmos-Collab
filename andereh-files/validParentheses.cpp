#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isValid(string s) {
    int indx = 0;
    stack<char> stack;

    while (indx < s.size()) {
        if (s[indx] == '(' || s[indx] == '[' || s[indx] == '{')
            stack.push(s[indx]);
        else if (s[indx] == ')' && !stack.empty() && stack.top() == '(' ||
                 s[indx] == ']' && !stack.empty() && stack.top() == '[' ||
                 s[indx] == '}' && !stack.empty() && stack.top() == '{')
            stack.pop();
        else
            return false;

        indx++;
    }

    return stack.empty();
}

int main(int argc, char *argv[]) {
    string str1 = "()";      // true
    string str2 = "()[]{}";  // true
    string str3 = "(}";      // false

    cout << isValid(str1) << '\n';
    cout << isValid(str2) << '\n';
    cout << isValid(str3) << '\n';
    return 0;
}

