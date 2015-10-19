#include<iostream>
#include<string>
#include<list>
#include<deque>
using namespace std;

int main() {
    list<string> t;
    t.push_back("abc");
    t.push_back("def");

    deque<int> aa;
    aa.push_back(0);
    aa.push_back(1);
    cout << aa[1] << endl;

    for (auto it = t.begin(); it != t.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}

