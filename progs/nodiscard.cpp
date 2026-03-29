[[nodiscard]] int f() {
    return 42;
}

int g() {
    return 666;
}

int main() {
    f(); // warning: ignoring return value of 'int f()', declared with attribute 'nodiscard'
    g();
}