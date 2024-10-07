// 2696. Minimum String Length After Removing Substrings

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            char cur_char = s[i];

            if (stack.empty()) {
                stack.push(cur_char);
                continue;
            }

            if (cur_char == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            else if (cur_char == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            else {
                stack.push(cur_char);
            }
        }

        return stack.size();
    }
};

int main() {
    Solution solution;
    string input = "ABACD"; // Example input
    cout << "Minimum length of string after operations: " << solution.minLength(input) << endl;

    return 0;
}
