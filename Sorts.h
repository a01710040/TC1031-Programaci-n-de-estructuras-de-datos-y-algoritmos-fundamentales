#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

template <class T>
class Sorts {
private:
    void mergeArray(std::vector<T>& A, std::vector<T>& B, int low, int mid, int high);
    void mergeSplit(std::vector<T>& A, std::vector<T>& B, int low, int high);

public:
    // Mejor caso: O(n log n)
    // Caso promedio: O(n log n)
    // Peor caso: O(n log n)
    std::vector<T> mergeSort(const std::vector<T>& source);
};

/* Mejor caso: O(n)
 * Caso promedio: O(n)
 * Peor caso: O(n)
 */
template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        for (; j <= high; j++) {
            B[k] = A[j];
            k++;
        }
    } else {
        for (; i <= mid; i++) {
            B[k] = A[i];
            k++;
        }
    }

    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}
/* Mejor caso: O(n log n)
 * Caso promedio: O(n log n)
 * Peor caso: O(n log n)
 */
template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
    if ((high - low) < 1) {
        return;
    }
    int mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
}
/* Mejor caso: O(n log n)
 * Caso promedio: O(n log n)
 * Peor caso: O(n log n)
 */
template <class T>
std::vector<T> Sorts<T>::mergeSort(const std::vector<T> &source) {
    std::vector<T> v(source);
    std::vector<T> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
    return v;
}

#endif
