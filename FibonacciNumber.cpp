#include <iostream>

int fibonacciIterative(int n) {
    if (n <= 1)
        return n;
    
    int fib1 = 0;
    int fib2 = 1;
    int fib = 0;
    int steps = 1; // Initialize step counter
    
    for (int i = 2; i <= n; i++) {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
        steps++; // Increment step counter
    }
    
    std::cout << "Number of steps (Iterative): " << steps << std::endl;
    
    return fib;
}

int fibonacciRecursive(int n, int& steps) {
    if (n <= 1) {
        steps++;
        return n;
    }
    steps++; // Increment step counter
    return fibonacciRecursive(n - 1, steps) + fibonacciRecursive(n - 2, steps);
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    
    int iterativeSteps = 0; // Initialize step counter for iterative method
    int recursiveSteps = 0; // Initialize step counter for recursive method
    
    // Calculate Fibonacci using iterative method
    int iterativeResult = fibonacciIterative(n);
    std::cout << "Fibonacci(" << n << ") [Iterative] = " << iterativeResult << std::endl;
    std::cout << "Total steps (Iterative): " << iterativeSteps << std::endl;
    
    // Calculate Fibonacci using recursive method
    int recursiveResult = fibonacciRecursive(n, recursiveSteps);
    std::cout << "Fibonacci(" << n << ") [Recursive] = " << recursiveResult << std::endl;
    std::cout << "Total steps (Recursive): " << recursiveSteps << std::endl;
    
    return 0;
}
