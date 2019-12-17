// Voorbeeld van namespaces

#include <cmath>
#include <iostream>

namespace Broeders {
    double sin(double d) {
        // Broeders zondigt (sin) niet ;-)
        return 0;
    }
}

namespace Zondaar {
    double sin(double d) {
        // Zondaar zondigt (sin) wel ;-)
        return 1;
    }
    class Breuk {
    public:
        Breuk() {
            std::cout << "Er is een Zondaar::Breuk geboren." << std::endl;
        }
        //...
    };
}

namespace Broeders {
    class Breuk {
    public:
        Breuk() {
            std::cout << "Er is een Broeders::Breuk geboren." << std::endl;
        }
        //...
    };
}

int main() {
    std::cout << "std::sin(4.71238898) = " << std::sin(4.71238898) << std::endl;
    std::cout << "Broeders::sin(4.71238898) = " << Broeders::sin(4.71238898) << std::endl;
    std::cout << "Zondaar::sin(4.71238898) = " << Zondaar::sin(4.71238898) << std::endl;

    Broeders::Breuk b1;
    Zondaar::Breuk b2;

    {
        using Broeders::sin;
        std::cout << "sin(4.71238898) = " << sin(4.71238898) << std::endl;
        std::cout << "std::sin(4.71238898) = " << std::sin(4.71238898) << std::endl;
    }

    {
        using namespace std;
        cout << "sin(4.71238898) = " << sin(4.71238898) << endl;
        cout << "Broeders::sin(4.71238898) = " << Broeders::sin(4.71238898) << endl;
    }

    using std::cin;
    cin.get();
    return 0;
}

/*
Uitvoer:

std::sin(4.71238898) = -1
Broeders::sin(4.71238898) = 0
Zondaar::sin(4.71238898) = 1
Er is een Broeders::Breuk geboren.
Er is een Zondaar::Breuk geboren.
sin(4.71238898) = 0
std::sin(4.71238898) = -1
sin(4.71238898) = -1
Broeders::sin(4.71238898) = 0
*/