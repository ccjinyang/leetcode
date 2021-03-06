// Source : https://oj.leetcode.com/problems/valid-parentheses/
// Author : Hao Chen
// Date   : 2014-06-30

#include <iostream>
#include <string>
using namespace std;

bool isValid(string s) {

    string stack;

    while(s.size()>0){

        char lch = s.back();

        if (lch == '[' || lch=='{' || lch=='(') {
            if (s.size()<=0) return false;
            char rch = stack.back();
            if ((lch=='[' && rch ==']') ||
                    (lch=='{' && rch =='}') ||
                    (lch=='(' && rch ==')') ) {
                s.pop_back();
                stack.pop_back();
            }else{
                return false;
            }
        }

        if (lch== ']' || lch=='}' || lch==')' ) {
            s.pop_back();
            stack.push_back(lch);
        }
    }
    return (s.size()==0 && stack.size()==0 );
}

int main(int argc, char**argv)
{
    string s = "{{}{[]()}}";
    if (argc>1){
        s = argv[1];
    }
    cout << "str = \"" << (s) << "\"" << endl;
    cout << isValid(s) << endl;
}
