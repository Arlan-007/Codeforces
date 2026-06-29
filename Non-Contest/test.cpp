#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> myMap;

    myMap["apple"] = 10;
    myMap["banana"] = 5;
    myMap["orange"] = 8;
    myMap["apple"] = 12; // This will update the value for "apple", not add a new entry

    // Check the count of "apple"
    std::cout << "Count of 'apple': " << myMap["apple"] << std::endl;

    // Check the count of "grape" (which is not in the map)
    std::cout << "Count of 'grape': " << myMap.count("grape") << std::endl;

    return 0;
}
