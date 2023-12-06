#include "../headers/mtfUtil.h"

std::list<char> getAlphabet(const std::string &data) {
    std::list<char> alphabet;
    std::set<char> s;
    for (char c : data) {
        if (!s.count(c)) {
            alphabet.push_back(c);
            s.insert(c);
        }
    }
    alphabet.sort();
    return alphabet;
}

std::vector<unsigned char> getMftTransofrm(const std::string &data,
                                           std::list<char> &alphabet) {
    std::vector<unsigned char> transformedData;
    transformedData.reserve(data.size());
    for (char c : data) {
        unsigned char idx = 0;
        for (auto it = alphabet.begin(); it != alphabet.end();
             std::advance(it, 1), idx++) {
            if (*it == c) {
                auto itToDelete = it;
                std::advance(it, -1);
                alphabet.push_front(c);
                alphabet.erase(itToDelete);
                break;
            }
        }
        transformedData.push_back(idx);
    }
    return transformedData;
}

std::string restoreMtfData(const std::vector<unsigned char> &mtfData,
                           std::list<char> &alphabet) {
    std::string restoredData;
    for (unsigned char idx : mtfData) {
        auto itToDelete = alphabet.begin();
        std::advance(itToDelete, idx);
        restoredData += *itToDelete;
        alphabet.push_front(*itToDelete);
        alphabet.erase(itToDelete);
    }
    return restoredData;
}
