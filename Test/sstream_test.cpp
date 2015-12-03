#include <iostream>
#include <sstream>
using namespace std;

int main() {
    stringstream ss;
    ss << 12 ;
    string s;
    s = (ss.str());
    cout << s << endl;
    return 0;
}
