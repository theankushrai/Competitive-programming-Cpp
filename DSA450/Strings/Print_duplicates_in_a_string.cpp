// 1. brute force - take each element and check whether we have duplicate of that - n2 time complexity
//2. sort and check logn complexity;
//3. using unordered map to keep the value n complexity

void printduplicates(string s)
{
    unordered_map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    for (auto it : m)
    {
        if (it.second > 1)
            cout << it.first << endl;
    }
}