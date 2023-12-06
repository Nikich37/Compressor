#pragma once

#include <list>
#include <string>
#include <vector>
#include <set>
#include <iostream>

std::list<char> getAlphabet(const std::string &data);

std::vector<unsigned char> getMftTransofrm(const std::string &data,
                                           std::list<char> &alphabet);

std::string restoreMtfData(const std::vector<unsigned char> &mtfData, std::list<char> &alphabet);
