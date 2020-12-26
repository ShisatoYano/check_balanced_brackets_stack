#include <bits/stdc++.h>
using namespace std;

// check if brackets are balanced
bool are_brackets_balanced(string input) {
    stack<char> s;
    char x;

    // traversing
    for (char & i : input) {
        if ((i == '(') ||
            (i == '[') ||
            (i == '{')) {
            s.push(i);
            continue;
        }

        // current char is not opening bracket,
        // it must be closing. stack cannot be empty
        if (s.empty()) {
            return false;
        }

        switch (i) {
            case ')':
                x = s.top();
                s.pop();
                if (x == '{' || x == '[') {
                    return false;
                }
                break;
            case '}':
                x = s.top();
                s.pop();
                if (x == '(' || x == '[') {
                    return false;
                }
                break;
            case ']':
                x = s.top();
                s.pop();
                if (x == '(' || x == '{') {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    return s.empty();
}

int main() {
    string input_balanced = "{()}[]";

    cout << input_balanced << " is ";
    if (are_brackets_balanced(input_balanced)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    string input_unbalanced = "[(])";

    cout << input_unbalanced << " is ";
    if (are_brackets_balanced(input_unbalanced)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
