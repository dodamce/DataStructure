#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class ValueType>
void DisPlay(const vector<ValueType> &vet)
{
    for (auto &val : vet)
    {
        cout << val << " ";
    }
    cout << "\n";
}