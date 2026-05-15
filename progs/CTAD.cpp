import std;
using namespace std;

template<typename T>
struct Box {
    T value;
};

template<typename T>
class Buffer {
public:
    explicit Buffer(size_t capacity) {
        items.reserve(capacity);
    }
    void add(const T& item) {
        items.push_back(item);
    }
    const vector<T>& get_items() const {
        return items;
    }
private:
    vector<T> items;
};

int main() {
    array a {1, 2, 3}; // is gelijk aan std::array<int, 3> {1, 2, 3}
    println("a = {}", a);

    vector v {1, 2, 3}; // is gelijk aan std::vector<int> {1, 2, 3}
    println("v = {}", v);

    vector w1 {"Hallo", "wereld"}; // is gelijk aan std::vector<const char*> {"Hallo", "wereld"}
    println("w1 = {}", w1);
    // w1[0].append(" iedereen op de "); // error: request for member 'append' in 'w1.std::vector<const char*, std::allocator<const char*> >::operator[](0)', which is of non-class type '__gnu_cxx::__alloc_traits<std::allocator<const char*>, const char*>::value_type' {aka 'const char*'}
    println("w1 = {}", w1);

    vector<string> w2 {"Hallo", "wereld"}; // is gelijk aan std::vector<std::string> {"Hallo", "wereld"}
    println("w2 = {}", w2);
    w2[0].append(" iedereen op de ");
    println("w2 = {}", w2);

    vector w3 {"Hallo"s, "wereld"s}; // is gelijk aan std::vector<std::string> {"Hallo", "wereld"}
    println("w3 = {}", w3);
    w3[0].append(" iedereen op de ");
    println("w3 = {}", w3);

    Box b {42}; // is gelijk aan Box<int>{42}
    println("b.value = {}", b.value);
//  Buffer buf {1024}; // error: class template argument deduction failed
    Buffer<string> buf {1024};
    buf.add("Hallo");
    buf.add("Wereld");
    println("Buffer items: {}", buf.get_items());
}