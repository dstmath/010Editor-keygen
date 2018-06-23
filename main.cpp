#include <iostream>
#include <ctime>
#include "_010EditorKeygen.hpp"

int main() {
    std::string name;
    std::cout << "Input your name(English Only): ";
    std::getline(std::cin, name);

    std::tm ZeroDate = { 0, 0, 0, 1, 1, 1970 - 1900 };

    int ExpireYear = 2020;
    int ExpireMonth = 6;
    int ExpireDay = 23;
    std::tm ExpireDate = { 0, 0, 0, ExpireDay, ExpireMonth, ExpireYear - 1900 };
    uint32_t ExpireDaystamp = static_cast<uint32_t>(std::difftime(std::mktime(&ExpireDate), std::mktime(&ZeroDate)) / 3600 / 24);

    std::vector<byte> name_bytes(name.begin(), name.end());
    _010Editor::Keygen<_010Editor::KeyType::TimeLicense> keygen;
    std::cout << keygen.GetKey(name_bytes, ExpireDaystamp, 1);
    return 0;
}