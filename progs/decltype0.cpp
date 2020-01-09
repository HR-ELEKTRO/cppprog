#include <iostream>
using namespace std;

// Je wilt ri2 hetzelfde type maken dan ri1

int main() {
    {   
        auto i {42};
        auto& ri1 {i};
        [[maybe_unused]]
        // Dit werkt niet:
        auto ri2 {ri1};
        cout << "i = " << i << '\n';
        ri1 = 43;
        cout << "i = " << i << '\n';
        ri2 = 44;
        cout << "i = " << i << '\n';
    }
    {   
        auto i {42};
        auto& ri1 {i};
        // Dit werkt wel, maar is  niet zo elegant:
        auto& ri2 {ri1};
        cout << "i = " << i << '\n';
        ri1 = 43;
        cout << "i = " << i << '\n';
        ri2 = 44;
        cout << "i = " << i << '\n';
    }
    {   
        auto i {42};
        auto& ri1 {i};
        // Dit werkt ook en is al iets eleganter, alleen moeten we ri1 twee keer intypen:
        decltype(ri1) ri2 {ri1};
        cout << "i = " << i << '\n';
        ri1 = 43;
        cout << "i = " << i << '\n';
        ri2 = 44;
        cout << "i = " << i << '\n';
    }
    {   
        auto i {42};
        auto& ri1 {i};
        // Dit werkt en is elegant:
        decltype(auto) ri2 {ri1};
        cout << "i = " << i << '\n';
        ri1 = 43;
        cout << "i = " << i << '\n';
        ri2 = 44;
        cout << "i = " << i << '\n';
    }
}
