#include <iostream>
#include <unordered_map>
using namespace std;

int countAnagramicPairs(string s)
{
    int n = s.length();
    unordered_map<string, int> substringCount;

    for (int i = 0; i < n; i++)
    {
        string substr = "";
        for (int j = i; j < n; j++)
        {
            substr += s[j];
            string sortedSub = substr;
            sort(sortedSub.begin(), sortedSub.end());
            substringCount[sortedSub]++;
        }
    }

    int count = 0;
    for (const auto &entry : substringCount)
    {
        int freq = entry.second;
        count += (freq * (freq - 1)) / 2; // Combination nC2
    }

    return count;
}

int main()
{
    string s = "abba";
    cout << countAnagramicPairs(s) << endl;

    return 0;
}