#include <iostream>
#include <thread>
#include <vector>

//ordena 
void bubbleShort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {//para cambiar de mayor a menor cambie > por <
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main()
{
    //Ponemos los valores a ordenar
    std::vector<int> arr = { 37,41,63,30,82,90,91,84,64,59 };
    int numThreads = 4;
    
    std::cout << "Arreglo original "<<std::endl;
    for (int numSort : arr) {
        std::cout << numSort << " ";
    }
   
    std::vector<std::thread>threads;
    //Dividimos el trabajo entre los nucleos
    for (int i = 0; i < numThreads; i++) {
        threads.emplace_back(bubbleShort, std::ref(arr));
    }
    //Esperar a que terminen de ordenar
    for (auto& thread : threads) {
        thread.join();
    }
    //Mostrar arreglo ordenado
    std::cout << "\nArreglo ordenado " << std::endl;
    for (int numSort : arr) {
        std::cout << numSort << " ";
    }
    std::cout << "Hola mundito!\n";
}
