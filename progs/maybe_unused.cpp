int f(int i) { // warning: unused parameter 'i'
    return 42;
}

int g([[maybe_unused]] int i) {
    return 666;
}

int main() {
    int r1 = f(0);  // warning: unused variable 'r1'
    [[maybe_unused]] int r2 = g(0);
    return 0;
}