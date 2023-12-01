// main function
#include <iostream>
#include "../headers/bwtUtil.h"

int main() {
    std::string str = "banana";
    std::pair<size_t, std::string> BWT = getBWTransofrmedData(str);
    std::cout << BWT.first << " " << BWT.second << "\n";
    std::string restoredData = getBWTRestoredData(BWT.second, BWT.first);
    std::cout << restoredData << "\n"; 
}
