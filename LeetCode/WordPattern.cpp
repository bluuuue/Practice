#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty()) return false;
        unordered_map<char, vector<int> > hash1;
        for (int i = 0; i < pattern.size(); ++i) {
            hash1[pattern[i]].push_back(i);
        }
        
        int count = 0;
        unordered_map<string, vector<int> > hash2;
        for (int i = 0; i < str.size(); ) {
            hash2[getWord(str, i)].push_back(count);
            ++count;
        }
        
        //compare the two hash
        unordered_map<char, vector<int> >::iterator it1 = hash1.begin();
        unordered_map<string, vector<int> >::iterator it2 = hash2.begin();
        for (; it1 != hash1.end() && it2 != hash2.end(); ++it1, ++it2) {
            int i = 0;
            for (; i < it1->second.size() && i < it2->second.size(); ++i) {
                if (it1->second[i] != it2->second[i])
                    return false;
                cout << it1->second[i] << " " << it2->second[i] << endl;
            }
            if (i != it1->second.size() || i != it2->second.size())
                return false;
            cout << endl;
        }
        return true;
    }
    
    string getWord(string str, int &i) {
        while (str[i] == ' ') {
            ++i;
        }
        int begin = i;
        int count = 0;
        while (i < str.size() && str[i] != ' ') {
            ++i;
            ++count;
        }
        return string(str, begin, count);
    }
};

int main() {
    string pattern("deadbeef");
    string str("d e a d b e e f");

    Solution t;

    cout << t.wordPattern(pattern, str) << endl;

    return 0;
}
