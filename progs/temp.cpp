import std;
using namespace std;

template<typename T> 
struct std::formatter<std::complex<T>>: public formatter<T> {
    auto format(const std::complex<T>& z, auto& context) const {
        context.advance_to(formatter<T>::format(z.real(), context));
        if (z.imag() >= 0)
            context.advance_to(format_to(context.out(), "+"));
        context.advance_to(formatter<T>::format(z.imag(), context));
        context.advance_to(format_to(context.out(), "j"));
        return context.out();
    }
};

int main() {
    complex<double> z {1.2, -2.9};
    cout << "z = " << z << '\n';
    println("z = {:.3f}", z);
}