#pragma once
#include <vector>
#include <map>
#include <iostream>
#include "SubsetToSum.h"

using namespace std;

template <class T>
class SubsetSumSolver {

public:

    vector<T> solve(vector<T> inputSet, T sum) {

        SubsetToSum<T>** table = new SubsetToSum<T>*[inputSet.size()];

        for (int i = 0; i < (int)inputSet.size(); i++) {
            table[i] = new SubsetToSum[sum + 1];
        }

        for (int i = 0; i < inputSet.size(); i++) {
            cout << i << ", ";
            for (T j = 0; j < sum; j++) {
                cout << j << ", ";
                if (j == 0) {
                    SubsetToSum<T> subsetToSum(0, nullptr);
                    table[i][j] = subsetToSum;
                }
                else if (i == 0) {
                    addTopRowElementToTable(table, inputSet[i], j);
                }
                else if (inputSet[i] > j) {
                    copyValueFromPreviousRow(table, i, j);
                }
                else {
                    determineElementValue();
                }
            }
            cout << endl;
        }


        delete[] table;

        return nullptr;
    }

    void addTopRowElementToTable(int** table, T element, T sum) {
        if (element == sum) {
            std::vector<T> subset();
            subset.add(element);
            SubsetToSum<T> subsetToSum(sum, subset);
            table[element][sum] = subsetToSum;
        }
        else {
            table[element][sum] = nullptr;
        }
    }

    void copyValueFromPreviousRow(int** table, int rowIndex, T sum) {
        table[rowIndex][sum] = table[rowIndex - 1][sum];
    }

    void determineElementValue(int** table, int rowIndex, T element, T sum) {
        if (table[rowIndex - 1][sum - element] != nullptr) {
            // get subset from subsetToSum object 
            // add it to new SubsetToSum object subset with current element
            // insert object in table
        }
    }
};