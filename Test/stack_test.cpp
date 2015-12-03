#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(0);
    cout << s.pop() << endl;
    return 0;
}
