//#include "main.h"
#include "Library.h"

using namespace std;

int main() {
    while (true) {
        switch (menu()) {
            case 1:
                includeBook();
                break;
            case 2:
                checkOutBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                status();
                break;
            case 5:
                return 0;
            default:
                cout << "Wrong option, try again!";
        }

    }
}

