// Find gcd For Two Numbers
int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

// Find Lcm For Two Numbers
int lcm(int a, int b) {
    return a / (gcd(a, b))* b;
}
