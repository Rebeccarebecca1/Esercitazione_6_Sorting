#pragma once

#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp" 

using namespace std;

namespace SortLibrary {

// --- Test ordinamento interi casuali con BubbleSort ---
TEST(TestSorting, BubbleSortWithInt)
{
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    BubbleSort<int>(v);
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12, 13};
    EXPECT_EQ(v, sortedV);
}

// --- Verifica ordinamento numeri double (casuali) con BubbleSort ---
TEST(TestSorting, BubbleSortWithDouble)
{
    vector<double> v = {12.3, -14.0, 1.7e-5, 1.8e+12, 35.3555, 12.0, 0.0};
    BubbleSort<double>(v);
    vector<double> sortedV = {-14.0, 0.0, 1.7e-5, 12.0, 12.3, 35.3555, 1.8e+12};
    EXPECT_EQ(v, sortedV);
}

// --- Ordinamento di vettore di interi con HeapSort ---
TEST(TestSorting, HeapSortWithInt)
{
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    HeapSort<int>(v, 0, v.size() - 1);
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12, 13};
    EXPECT_EQ(v, sortedV);
}

// --- Ordinamento di numeri reali con HeapSort ---
TEST(TestSorting, HeapSortWithDouble)
{
    vector<double> v = {12.3, -14.0, 1.7e-5, 1.8e+12, 35.3555, 12.0, 0.0};
    HeapSort<double>(v, 0, v.size() - 1);
    vector<double> sortedV = {-14.0, 0.0, 1.7e-5, 12.0, 12.3, 35.3555, 1.8e+12};
    EXPECT_EQ(v, sortedV);
}

// --- Test efficienza BubbleSort su vettore già ordinato ---
TEST(TestSorting, BubbleSortBestCase)
{
    vector<double> v(100);
    for (int i = 0; i < 100; i++)
        v[i] = 3 * i + 4;

    vector<double> sortedV = v;
    BubbleSort<double>(v);
    EXPECT_EQ(v, sortedV);
}

// --- BubbleSort su input ordinato inversamente (caso pessimo) ---
TEST(TestSorting, BubbleSortWorstCase)
{
    vector<double> v(100);
    for (int i = 0; i < 100; i++)
        v[i] = -4 * i;

    vector<double> sortedV(100);
    for (int i = 0; i < 100; i++)
        sortedV[i] = v[100 - i - 1];
    BubbleSort<double>(v);
    EXPECT_EQ(v, sortedV);
}

// --- HeapSort su vettore già ordinato: conferma best case ---
TEST(TestSorting, HeapSortBestCase)
{
    vector<double> v(100);
    for (int i = 0; i < 100; i++)
        v[i] = 3 * i + 4;

    vector<double> sortedV = v;
    HeapSort<double>(v, 0, v.size() - 1);
    EXPECT_EQ(v, sortedV);
}

// --- HeapSort applicato su vettore inversamente ordinato ---
TEST(TestSorting, HeapSortWorstCase)
{
    vector<double> v(100);
    for (int i = 0; i < 100; i++)
        v[i] = -4 * i;

    vector<double> sortedV(100);
    for (int i = 0; i < 100; i++)
        sortedV[i] = v[100 - i - 1];
    HeapSort<double>(v, 0, v.size() - 1);
    EXPECT_EQ(v, sortedV);
}

// --- Confronto risultati tra HeapSort e BubbleSort su dati casuali ---
TEST(TestSorting, HeapSort_and_BubbleSort)
{
    vector<double> v(500);
    for (unsigned int i = 0; i < 500; i++)
        v[i] = rand();

    vector<double> w = v;
    BubbleSort<double>(v);
    HeapSort<double>(w, 0, w.size() - 1);
    EXPECT_EQ(v, w);
}

// --- HeapSort su vettore di dimensione 1 ---
TEST(TestSorting, HeapSortSizeOne)
{
    vector<double> v = {4.0};
    vector<double> sortedV = {4.0};
    HeapSort<double>(v, 0, v.size() - 1);
    EXPECT_EQ(v, sortedV);
}

// --- BubbleSort su vettore con un solo elemento ---
TEST(TestSorting, BubbleSortSizeOne)
{
    vector<double> v = {2.0};
    vector<double> sortedV = {2.0};
    BubbleSort<double>(v);
    EXPECT_EQ(v, sortedV);
}

// --- Ordinamento HeapSort su vettore completamente vuoto ---
TEST(TestSorting, HeapSortVoidVector)
{
    vector<double> v;
    vector<double> sortedV;
    HeapSort<double>(v, 0, v.size() - 1);
    EXPECT_EQ(v, sortedV);
}

// --- BubbleSort applicato a un vettore vuoto ---
TEST(TestSorting, BubbleSortVoidVector)
{
    vector<double> v;
    vector<double> sortedV;
    BubbleSort<double>(v);
    EXPECT_EQ(v, sortedV);
}

} // namespace SortLibrary