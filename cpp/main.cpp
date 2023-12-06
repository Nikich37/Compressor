// main function
#include <iostream>
#include "../headers/mtfUtil.h"
#include "../headers/bwtUtil.h"

int main() {
    std::string str = "BANANA";
    std::pair<size_t, std::string> BWT = getBWTransofrmedData(str);
    std::cout << BWT.first << " " << BWT.second << "\n";
    std::list<char> alphabet = getAlphabet(BWT.second);
    std::vector<unsigned char> mftTransofrmed = getMftTransofrm(BWT.second, alphabet);
    alphabet.sort();
    for (int num : mftTransofrmed) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    std::string restoredMtf = restoreMtfData(mftTransofrmed, alphabet);
    std::cout << getBWTRestoredData(restoredMtf, BWT.first) << "\n";
}
