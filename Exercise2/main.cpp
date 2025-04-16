#include <iostream>
#include <vector>
#include <chrono>
#include <numeric> // per std::iota
#include <string>
#include <cstdlib>
#include <ctime>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace std::chrono;
using namespace SortLibrary;

// Funzione per misurare il tempo medio di HeapSort
namespace SortLibrary {

double tempi_heap(const std::vector<int>& input_data)
{
    vector<unsigned int> tempi_heap;
    unsigned int numIterazioni = 10;

    for (unsigned int i = 0; i < numIterazioni; ++i) 
    {
        vector<int> data = input_data; // Copia del vettore per ogni iterazione
        // Misurazione del tempo per l'algoritmo HeapSort
        auto start_heap = steady_clock::now();
        HeapSort(data, 0, data.size() - 1);
        auto stop_heap = steady_clock::now();
        auto duration_heap = duration_cast<milliseconds>(stop_heap - start_heap);
        tempi_heap.push_back(duration_heap.count());
    }

    double sum_heap = 0;
    for (auto value : tempi_heap) {
        sum_heap += value;
    }
    return sum_heap / tempi_heap.size();
}

double tempi_bubble(const std::vector<int>& input_data)
{
    vector<unsigned int> tempi_bubble;
    unsigned int numIterazioni = 10;

    for (unsigned int i = 0; i < numIterazioni; ++i) // CORRETTO: unsigned int invece di int
    {
        vector<int> data = input_data; // Copia del vettore per ogni iterazione
        // Misurazione del tempo per l'algoritmo Bubble Sort
        auto start_bubble = steady_clock::now();
        BubbleSort(data);
        auto stop_bubble = steady_clock::now();
        auto duration_bubble = duration_cast<milliseconds>(stop_bubble - start_bubble);
        tempi_bubble.push_back(duration_bubble.count());
    }

    double sum_bubble = 0;
    for (auto value : tempi_bubble) {
        sum_bubble += value;
    }
    return sum_bubble / tempi_bubble.size();
}

} // namespace SortLibrary

int main(int argc, char **argv) {

    // Controllo se è stato fornito un argomento dalla riga di comando
    if (argc != 2) {
        cerr << "Non è statto fornito un input dalla linea di comando." << endl;
        return 1;
    }

    // Converto l'argomento in un numero intero
    int size = stoi(argv[1]); // string to int

    // Controllo se la conversione ha avuto successo
    if (size <= 0) {
        cerr << "Input sbagliato. Per favore inserisci un intero positivo." << endl;
        return 1;
    }

    // Altrimenti, la dimensione è valida, procedo con il programma
    cout << "Dimensione dell'array: " << size << endl;

    // Creazione di un vettore ordinato
    vector<int> data1(size);
    iota(data1.begin(), data1.end(), 0); // Riempie il vettore con valori crescenti

    // Calcolo delle medie dei tempi di esecuzione per HeapSort e BubbleSort
    double average1_heap = tempi_heap(data1);
    double average1_bubble = tempi_bubble(data1);

    // Stampa delle medie dei tempi di esecuzione
    cout << "La media dei tempi per l'algoritmo heap di un vettore completamente ordinato è di: " << average1_heap << " millisecondi" << endl;
    cout << "La media dei tempi per l'algoritmo bubble di un vettore completamente ordinato è di: " << average1_bubble << " millisecondi" << endl;

    // Creazione di un vettore di numeri casuali
    vector<int> data2(size);
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        data2[i] = rand() % 1000; // Numeri casuali nell'intervallo [0, 999]
    }

    // Calcolo delle medie dei tempi di esecuzione
    double average2_heap = tempi_heap(data2);
    double average2_bubble = tempi_bubble(data2);

    // Stampa delle medie dei tempi di esecuzione
    cout << "La media dei tempi per l'algoritmo heap per un vettore randomico è di: " << average2_heap << " millisecondi" << endl;
    cout << "La media dei tempi per l'algoritmo bubble per un vettore randomico è di: " << average2_bubble << " millisecondi" << endl;

    // Creazione di un vettore ordinato da perturbare
    vector<int> data3(size);
    iota(data3.begin(), data3.end(), 0);
    // Perturbazione leggera del vettore ordinato
    for (int i = 0; i < size; i++)
    {
        data3[i] += int(rand()) % 10; // somma un numero intero casuale tra 0 e 9
    }

    // Calcolo delle medie dei tempi di esecuzione
    double average3_heap = tempi_heap(data3);
    double average3_bubble = tempi_bubble(data3);

    // Stampa delle medie dei tempi di esecuzione
    cout << "La media dei tempi per l'algoritmo heap per un vettore leggermente randomico è di: " << average3_heap << " millisecondi" << endl;
    cout << "La media dei tempi per l'algoritmo bubble per un vettore leggermente randomico è di: " << average3_bubble << " millisecondi" << endl;

    return 0;
}