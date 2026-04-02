export module stack;

export template <typename T> class Stack {
public:
    Stack() = default;
    Stack(const Stack&) = delete;
    virtual ~Stack() = default;
    void operator=(const Stack&) = delete;
    virtual void push(const T& t) = 0;
    virtual void pop() = 0;
    virtual const T& top() const = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
};
