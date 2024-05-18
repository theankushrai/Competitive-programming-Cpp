
#include<iostream>
using namespace std;

int update_bit(int n, int i, int value)
{
    int mask = ~(1 << i);
    n = n & mask;
    return (n | (value << i));
}

int main()
{
    int n, i, value;
    cin >> n >> i >> value;
    cout << update_bit(n, i, value);
    return 0;
}