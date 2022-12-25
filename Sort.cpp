#include <cstdlib>
#include <functional>
#include <utility>
using std::function;
using std::swap;

template <typename T, typename Comparator>
T ChoosePivot(T first, T second, T last, Comparator comparator) {
  if (comparator(second, first) && comparator(last, second)) {
    return second;
  } else if (comparator(first, second) && comparator(last, first)) {
    return first;
  } else {
    return last;
  }
};

template <typename T, typename Comparator>
void QuickSort(T begin, T end, Comparator comparator) {
  size_t size;
  while ((size = end - begin) > 1) {
    int left = 0, right = size - 1;

    auto pivot = ChoosePivot(begin[0], begin[size / 2], end[-1], comparator);
    while (left < right) {
      while (comparator(begin[left], pivot)) {
        left++;
      }
      while (comparator(pivot, begin[right])) {
        right--;
      }
      if (left <= right) {
        swap(begin[left], begin[right]);
        left++;
        right--;
      }
    }
    if (right > (int)size - 1 - left) {
      if (left < (int)size - 1) {
        QuickSort(begin + left, end, comparator);
      }
      end = begin + right + 1;
    } else {
      if (right > 0) {
        QuickSort(begin, begin + right + 1, comparator);
      }
      begin = begin + left;
    }
  }
}

template <typename T, typename Comparator>
inline void InsertionSort(T begin, T end, Comparator comparator) {
  int size = end - begin;
  for (int current = 1; current < size; current++) {
    int move_start = current - 1;
    while (move_start > 0 && comparator(begin[current], begin[move_start])) {
      move_start--;
    }
    if (!comparator(begin[current], begin[move_start])) {
      move_start++;
    }

    auto tmp = std::move(begin[current]);
    for (int moving = current; move_start < moving; moving--) {
      begin[moving] = std::move(begin[moving - 1]);
    }
    begin[move_start] = std::move(tmp);
  }
}

template <typename T, typename Comparator>
void Sort(T begin, T end, Comparator comparator) {
  size_t size;
  while ((size = end - begin) > 1) {
    // magic number is 11
    if (size < 12) {
      InsertionSort(begin, end, comparator);
      return;
    }
    int left = 0, right = size - 1;

    auto pivot = ChoosePivot(begin[0], begin[size / 2], end[-1], comparator);
    while (left < right) {
      while (comparator(begin[left], pivot)) {
        left++;
      }
      while (comparator(pivot, begin[right])) {
        right--;
      }
      if (left <= right) {
        swap(begin[left], begin[right]);
        left++;
        right--;
      }
    }
    if (right > (int)size - 1 - left) {
      if (left < (int)size - 1) {
        QuickSort(begin + left, end, comparator);
      }
      end = begin + right + 1;
    } else {
      if (right > 0) {
        QuickSort(begin, begin + right + 1, comparator);
      }
      begin = begin + left;
    }
  }
}
