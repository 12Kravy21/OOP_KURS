#include "AVL.h"
#include "tree.h"
#include <iostream>
#include <limits>
#define ESC "\033"

int main()
{
    std::string ru, eng;
    AVL wood;
    int choose = -1;
    while (true) {
        printf(ESC "c");
        std::cout << "1. Add element\n";
        std::cout << "2. Find word\n";
        std::cout << "3. Delete element\n";
        std::cout << "4. Write info\n";
        std::cout << "For exit write \"-1\"\n";
        std::cout << "Choose: ";
        std::cin >> choose;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choose) {
        case 1: {
            printf(ESC "c");
            std::cout << "Add english word: ";
            std::getline(std::cin, eng);
            std::cout << "Translation (russian word): ";
            std::getline(std::cin, ru);
            wood.AddToAVL(eng, ru);
            break;
        }
        case 2: {
            printf(ESC "c");
            std::cout << "Find english word: ";
            std::getline(std::cin, eng);
            if (wood.FindKey(wood.ReturnRoot(), eng)) {
                std::cout << "This word been found\n";
            } else {
                std::cout << "Word not found\n";
            }
            break;
        }
        case 3: {
            printf(ESC "c");
            std::cout << "Delete english word: ";
            std::getline(std::cin, eng);
            wood.DeleteInAVL(eng);
            break;
        }
        case 4: {
            printf(ESC "c");
            std::cout << "height: " << wood.HeightTree(wood.ReturnRoot())
                      << std::endl;
            std::cout << "left to right: ";
            wood.LeftToRight(wood.ReturnRoot());
            std::cout << std::endl << "up to down: ";
            wood.UpToDown(wood.ReturnRoot());
            std::cout << std::endl;
            break;
        }
        }
        if (choose == -1) {
            break;
        }
        std::cout << "Press key to continue...\n";
        getchar();
    }

    return 0;
}
