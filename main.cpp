// lab-3-QuickSort.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//

#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

#include "Sort.cpp"

using std::cout, std::endl;
using std::swap;
using std::vector;

const int NUMBER_OF_SORT_CALLS = 1000;

int main() {
  auto comp = [](int lhs, int rhs) { return rhs < lhs; };
  std::ofstream fout("times.csv");
  fout << "n,qsort,insertion_sort,sort" << endl;
  for (int elements = 1; elements <= 100; elements++) {
    vector<int> data;
    for (int i = 0; i < elements; i++) {
      data.push_back(i);
    }
    for (int i = 0; i < elements; i++) {
      swap(data[i], data[rand() % elements]);
    }

    vector<vector<int>> quick_sort_data, insertion_sort_data, sort_data;
    for (int i = 0; i < NUMBER_OF_SORT_CALLS; i++) {
      quick_sort_data.push_back(data);
      insertion_sort_data.push_back(data);
      sort_data.push_back(data);
    }

    // insertion
    clock_t start = clock();
    for (int i = 0; i < NUMBER_OF_SORT_CALLS; i++) {
      InsertionSort(insertion_sort_data[i].begin(),
                    insertion_sort_data[i].end(), comp);
    }
    clock_t end = clock();
    int insertion_time = end - start;

    // quick
    start = clock();
    for (int i = 0; i < NUMBER_OF_SORT_CALLS; i++) {
      QuickSort(quick_sort_data[i].begin(), quick_sort_data[i].end(), comp);
    }
    end = clock();
    int quick_time = end - start;

    // sort
    start = clock();
    for (int i = 0; i < NUMBER_OF_SORT_CALLS; i++) {
      Sort(quick_sort_data[i].begin(), quick_sort_data[i].end(), comp);
    }
    end = clock();
    int sort_time = end - start;

    for (int i = 0; i < elements; i++) {
      if (quick_sort_data[0][i] != insertion_sort_data[0][i]) {
        cout << "elements do not match after sort!" << endl
             << "quick_sort_data(quick    ): ";
        for (int j = 0; j < elements; j++) {
          cout << quick_sort_data[0][j] << " ";
        }
        cout << endl << "insertion_sort_data(insertion): ";
        for (int j = 0; j < elements; j++) {
          cout << insertion_sort_data[0][j] << " ";
        }
        cout << endl << "data (default  ): ";
        for (int j = 0; j < elements; j++) {
          cout << data[j] << " ";
        }
        cout << endl;
        fout.close();
        return 1;
      }
    }

    fout << elements << "," << quick_time << "," << insertion_time << ","
         << sort_time << endl;
  }
  fout.close();
}
