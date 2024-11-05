#include <iostream>
#include <utility> // For std::pair
using namespace std;

// Recursive Fibonacci function with step count
int fib(int n, int &cnt) {
    if (n <= 1) {
        cnt++;
        return n;
    }

    cnt += 2; // Two recursive calls
    return fib(n - 1, cnt) + fib(n - 2, cnt);
}

// Iterative Fibonacci function returning a pair of (Fibonacci number, step count)
pair<int, int> iter_fib(int n) {
    int cnt = 1; // Initial count
    int a = 0, b = 1;

    for (int i = 2; i <= n; i++) {
        cnt++; // Increment step count
        int c = a + b;
        a = b;
        b = c;
    }

    return {b, cnt}; // Return Fibonacci number and total steps
}

int main() {
    int n = 4; // You can change this to any value you want
    int cnt = 0;

    // Recursive Fibonacci calculation
    cout << "Fibonacci (Recursive): " << fib(n, cnt) << endl;
    cout << "Step count (Recursive): " << cnt << endl;

    // Iterative Fibonacci calculation
    cout << "Fibonacci (Iterative): " << endl;
    auto val = iter_fib(n); 
    cout << "Fibonacci: " << val.first << endl;
    cout << "Step count (Iterative): " << val.second << endl;

    return 0;
}
