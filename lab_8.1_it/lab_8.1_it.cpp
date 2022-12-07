// lab_8.1_it.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <optional>

std::optional<std::string::size_type> nth_occurrence_index(const std::string& str, char to_find, int n)
{
    std::string::size_type position = 0;
    for (int i = 0; i < n; i++) {
        position = str.find(to_find, position);
        if (position == std::string::npos) {
            return std::nullopt;
        }
        ++position;
    }
    return position - 1;
}

void replace_all(std::string& str, const std::string& what, const std::string& with)
{
    for (
        std::string::size_type pos{};
        str.npos != (pos = str.find(what, pos));
        pos += with.length()
        ) {
        str.replace(pos, what.length(), with);
    }
}

int main()
{
    std::string str = "0123,567,901,345";

    const auto index = nth_occurrence_index(str, ',', 3);
    if (index) {
        std::cout << *index;
    }
    else {
        std::cout << "Not found";
    }
    std::cout << "\n";

    replace_all(str, ",", "**");
    std::cout << str << "\n";
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
