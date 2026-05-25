import std;
using namespace std;

int main() {
    {
    string s1 {"Hello, World!"}; 
    // s1 bevat "Hello, World!"
    string s2 {s1.substr(0, s1.find(","))}; 
    // s2 bevat "Hello"
    println("{:?}", s1); // "Hello, World!"
    println("{:?}", s2); // "Hello"
    }
    {
   	string_view sv1 {"Hello, World!"}; 
    // s1 verwijst naar de string literal "Hello, World!"
    string_view sv2 {sv1.substr(0, sv1.find(","))}; 
    // s2 verwijst naar "Hello" binnen de string literal "Hello, World!"
    println("{:?}", sv1); // "Hello, World!"
    println("{:?}", sv2); // "Hello"
    }
    {
	string s1 {"Hello, World!"}; 
    // s1 bevat "Hello, World!";
    string_view sv1 {s1}; 
    // sv1 verwijst naar "Hello, World!" in s1
	string_view sv2 {sv1.substr(0, sv1.find(","))}; 
    // sv2 verwijst naar "Hello" in s1
	s1.replace(0, 5, "Hi"); 
    // s1 bevat nu "Hi, World!"
	println("{:?}", s1); // "Hi, World!"
    println("{:?}", sv1); // "Hi, World!\u{0}d!"
	println("{:?}", sv2); // "Hi, W"
    }
    string author {"Harry Broeders"};
    string_view author_view {author};
    println("{}", author_view);
    auto space_pos = author_view.find(" ");
    println("{}", space_pos);
    string_view first_name {author_view.substr(0, space_pos)};
    println("{}", first_name);
    string_view last_name {author_view.substr(space_pos + 1)};
    println("{}", last_name);
    // author_view[0] = 'B'; 
    // error: assignment of read-only location 'author_view.std::basic_string_view<char>::operator[](0)'
    author[0] = 'B';
    println("author = {}", author);
    println("author_view = {}", author_view);
    {
        auto name = std::make_unique<std::string>("Alice Wonderland");
        author_view = *name;
        println("author_view = {}", author_view);
    }
    auto name = std::make_unique<std::string>("Piet Plezier");
    println("name = {}", *name);
    // OOPS view on a deleted string!
    println("author_view = {}", author_view);
}

/* output:
"Hello, World!"
"Hello"
"Hi, World!"
"Hi, World!\u{0}d!"
"Hi, W"
Harry Broeders
5
Harry
Broeders
author = Barry Broeders
author_view = Barry Broeders
author_view = Alice Wonderland
name = Piet Plezier
author_view = name = Piet Plez
*/