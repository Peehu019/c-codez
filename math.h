int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int product(int a, int b) {
    return a * b;
}

float division(int a, int b) {
    if (b != 0)
        return (float)a / b;
    else
        return 0.0; // Handle division by zero
}