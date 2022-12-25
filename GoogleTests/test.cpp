#include <utility>
#include <vector>
#include "pch.h"

#include "../Sort.cpp"


TEST(QuickSort, SortIntgersInc) {
  auto comp = [](int lhs, int rhs) { return lhs < rhs; };
  for (int elements = 1; elements <= 100; elements++) {
    std::vector<int> data;
    for (int i = 0; i < elements; i++) {
      data.push_back(i);
    }
    for (int i = 0; i < elements; i++) {
      swap(data[i], data[rand() % elements]);
    }

    std::vector<int> quick_sort_data(data);

    QuickSort(quick_sort_data.begin(), quick_sort_data.end(), comp);
    std::sort(data.begin(), data.end());

    for (int i = 0; i < elements; i++) {
      ASSERT_EQ(quick_sort_data[i], data[i]);
    }
  }
}

TEST(QuickSort, SortIntgersDesc) {
  auto comp = [](int lhs, int rhs) { return rhs < lhs; };
  for (int elements = 1; elements <= 100; elements++) {
    std::vector<int> data;
    for (int i = 0; i < elements; i++) {
      data.push_back(i);
    }
    for (int i = 0; i < elements; i++) {
      swap(data[i], data[rand() % elements]);
    }

    std::vector<int> quick_sort_data(data);

    QuickSort(quick_sort_data.begin(), quick_sort_data.end(), comp);
    std::sort(data.begin(), data.end(), comp);

    for (int i = 0; i < elements; i++) {
      ASSERT_EQ(quick_sort_data[i], data[i]);
    }
  }
}

TEST(InsertionSort, SortIntgersInc) {
  auto comp = [](int lhs, int rhs) { return lhs < rhs; };
  for (int elements = 1; elements <= 100; elements++) {
    std::vector<int> data;
    for (int i = 0; i < elements; i++) {
      data.push_back(i);
    }
    for (int i = 0; i < elements; i++) {
      swap(data[i], data[rand() % elements]);
    }

    std::vector<int> insertion_sort_data(data);

    InsertionSort(insertion_sort_data.begin(), insertion_sort_data.end(), comp);

    std::sort(data.begin(), data.end());

    for (int i = 0; i < elements; i++) {
      ASSERT_EQ(data[i], insertion_sort_data[i]);
    }
  }
}

TEST(InsertionSort, SortIntgersDesc) {
  auto comp = [](int lhs, int rhs) { return rhs < lhs; };
  for (int elements = 1; elements <= 100; elements++) {
    std::vector<int> data;
    for (int i = 0; i < elements; i++) {
      data.push_back(i);
    }
    for (int i = 0; i < elements; i++) {
      swap(data[i], data[rand() % elements]);
    }

    std::vector<int> insertion_sort_data(data);

    InsertionSort(insertion_sort_data.begin(), insertion_sort_data.end(), comp);

    std::sort(data.begin(), data.end(), comp);

    for (int i = 0; i < elements; i++) {
      ASSERT_EQ(data[i], insertion_sort_data[i]);
    }
  }
}