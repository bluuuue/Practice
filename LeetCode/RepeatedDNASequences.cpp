#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int nSize = s.size();
        vector<string> repeatedStrs;
        if (nSize == 0)
            return repeatedStrs;

        //store all the appeared sequence
        set<int> allSequences;
        set<int> onlyRepeatedOnce;

        //define a hashTable
        int hash[26];
        hash['A' - 'A'] = 0;
        hash['C' - 'A'] = 1;
        hash['G' - 'A'] = 2;
        hash['T' - 'A'] = 3;

        for (int i = 0; i < nSize - 10 + 1; ++i)
        {
            int sequence = 0;
            for (int j = i; j < i + 10; ++j)
            {
                sequence = sequence << 2;
                sequence = sequence | hash[s[j] - 'A'];
            }
            if (allSequences.find(sequence) == allSequences.end())
            {
                allSequences.insert(sequence);
            }
            else if (onlyRepeatedOnce.find(sequence) == onlyRepeatedOnce.end())
            {
                repeatedStrs.push_back(string(s.begin() + i, s.begin() + i + 10));
                onlyRepeatedOnce.insert(sequence);
            }
        }
        return repeatedStrs;
    }
};

int main()
{
    Solution test;
    string ss = "AAAAAAAAAAAA";
    vector<string> repeated = test.findRepeatedDnaSequences(ss);
    for (int i = 0; i < repeated.size(); ++i)
    {
        cout << repeated[i] << endl;
    }
    return 0;
}
