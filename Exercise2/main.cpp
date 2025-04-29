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
    // Ogni volta creo una copia di input_data in 'data' per non modificare il vettore originale
    vector<int> data = input_data;

    // Avvio il timer per misurare il tempo di esecuzione di HeapSort
    auto start_heap = steady_clock::now();

    // Eseguo HeapSort sul vettore copiato
    HeapSort(data, 0, data.size() - 1);

    // Fermata del timer subito dopo il termine di HeapSort
    auto stop_heap = steady_clock::now();

    // Calcolo la durata dell'ordinamento come differenza tra stop e start
    auto duration_heap = duration_cast<milliseconds>(stop_heap - start_heap);

    // Salvo il tempo misurato (in millisecondi) nel vettore tempi_heap
    tempi_heap.push_back(duration_heap.count());
}

    double sum_heap = 0;
	
	// Sommo tutti i tempi salvati
    for (auto value : tempi_heap) {
        sum_heap += value;
    }
	
	// Ritorno la media dei tempi
    return sum_heap / tempi_heap.size();
}

// Funzione che calcola il tempo medio di esecuzione del BubbleSort su input_data
double tempi_bubble(const std::vector<int>& input_data)
{
    // Vettore per salvare i tempi di esecuzione di ogni iterazione
    vector<unsigned int> tempi_bubble;

    // Numero di volte che vogliamo ripetere la misurazione
    unsigned int numIterazioni = 10;

    // Ripeto la misurazione
    for (unsigned int i = 0; i < numIterazioni; ++i)
    {
        // Creo una copia di input_data, così BubbleSort non modifica il vettore originale
        vector<int> data = input_data;

        // Misuro il tempo di esecuzione del BubbleSort
        auto start_bubble = steady_clock::now(); // Inizio timer
        BubbleSort(data);                        // Eseguo l'ordinamento
        auto stop_bubble = steady_clock::now();   // Fine timer

        // Calcolo la durata in millisecondi
        auto duration_bubble = duration_cast<milliseconds>(stop_bubble - start_bubble);

        // Salvo la durata nell'array dei tempi
        tempi_bubble.push_back(duration_bubble.count());
    }

    double sum_bubble = 0;

    // Sommo tutti i tempi salvati
    for (auto value : tempi_bubble) {
        sum_bubble += value;
    }

    // Ritorno la media dei tempi
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
	// std::iota (dalla libreria <numeric>) riempie un intervallo di elementi con numeri consecutivi, partendo da un valore iniziale che decidi io
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

    // Creazione di un vettore ordinato da perturbare. 
	// std::iota (dalla libreria <numeric>) riempie un intervallo di elementi con numeri consecutivi, partendo da un valore iniziale che decidi io
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