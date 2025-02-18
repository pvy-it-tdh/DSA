#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string, int> count_words(string s)
{
    istringstream iss(s);
    string word;
    unordered_map<string, int> word_count;
    while (iss >> word)
    {
        word_count[word]++;
    }
    return word_count;
}
int main()
{
    string s = "hello world hello";
    unordered_map<string, int> word_count = count_words(s);
    for (auto it = word_count.begin(); it != word_count.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    return 0;
}