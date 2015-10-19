#include <iostream>
#include <vector>
#include <string>
using namespace std;

void LineEditor(vector<string> strings)
{
    if(strings.empty())
        return;
    for (int i = 0; i < strings.size(); ++i)
    {
        cout << strings[i] << endl;
    }

    for (int i = 0; i < strings.size(); ++i)
    {
        cout << strings[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> strings;
    while (n--)
    {
        string strTemp;
        cin >> strTemp;
        strings.push_back(strTemp);
    }
    LineEditor(strings);
    return 0;
}
