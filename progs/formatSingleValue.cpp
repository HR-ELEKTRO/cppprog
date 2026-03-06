// formatSingleValue.cpp
// https://www.modernescpp.com/index.php/formatting-user-defined-types-in-c20/
// BroJZ aangepast aan C++26

import std;
using namespace std;

class SingleValue {
public: 
  SingleValue() = default;
  explicit SingleValue(int s): singleValue{s} {}
  int getValue() const {
    return singleValue;
  }
private:
  int singleValue{};
};

template<>
struct std::formatter<SingleValue> {
  constexpr auto parse(format_parse_context& context) {
    return context.begin();
  }
  auto format(const SingleValue& sVal, format_context& context) const {
    return std::format_to(context.out(), "{}", sVal.getValue());
  }
};

int main() {
  SingleValue sVal0;
  SingleValue sVal2020{2020};
  SingleValue sVal2023{2023};

  println("Single Value: {} {} {}", sVal0, sVal2020, sVal2023);
  println("Single Value: {1} {1} {1}", sVal0, sVal2020, sVal2023);
  println("Single Value: {2} {1} {0}", sVal0, sVal2020, sVal2023);
}