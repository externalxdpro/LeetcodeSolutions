#include <iostream>
#include <map>

using namespace std;

int fibonacci(int n, map<int, int> &memo)
{
    if (memo.find(n) != memo.end()) return memo[n];
    
    if (n == 0) return 0;
    
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int fib(int n)
{
    map<int, int> memo;
    memo[0] = 0;
    memo[1] = 1;
    
    return fibonacci(n, memo);
}

int main()
{
    cout << fib(0) << endl;
    cout << fib(2) << endl;
    cout << fib(3) << endl;
    cout << fib(4) << endl;
    cout << fib(30) << endl;

    return 0;
}