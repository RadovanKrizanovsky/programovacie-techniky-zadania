/*
Meno a priezvisko: Radovan Krizanovsky

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (dopleny o riesenia).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};
//-------------------------------------------------------------------------------------------------
// POMOCNE FUNKCIE
//-------------------------------------------------------------------------------------------------

Node* nodeAtIndex (List* list, size_t index) {

    Node* nodeToReturn = list->first;

    for (size_t i = 1; i < index; i++) {
        nodeToReturn = nodeToReturn->next;
    }
    return nodeToReturn;

}

bool isFirstBiger (const char* str1, const char* str2) {

    int index = 0;

    while (str1[index] == str2[index]){
        if (str1[index] == '\0' && str2[index] == '\0') {
            return false;
        }
        index++;
    }

    if (str1[index] > str2[index]){
        return true;
    } else {
        return false;
    }
}



//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data' od najvacsieho prvku po najmensi prvok.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        {1, 3, 2} -> {3, 2, 1}
        {1, 2, 2, 1} -> {2, 2, 1, 1}
        {1} -> {1}
        {} -> {}
*/
void insertionSort(int *data, const size_t length) {

    for (size_t index2 = 1; index2 < length; ++index2) {

        int sortingRN = data[index2];
        size_t index1 = index2;

        while (index1 > 0 && sortingRN > data[index1-1]){
            data[index1] = data[index1-1];
            --index1;
        }
        data[index1] = sortingRN;
    }

}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada textove retazce v poli 'data' od najvacsieho prvku po najmensi (lexikograficky).
    Preusporiadajte smerniky v poli.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada.
                Pole obsahuje smerniky na textove retazce.
                Kazdy textovy retazec je ukonceny '\0'.
                Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).

    VSTUPNE PODMIENKY:
        'data' obsahuje minimalne jeden smernik.
        Posledny smernik ma hodnotu 'nullptr'.

    PRIKLADY:
        {"Juraj", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", nullptr}
        {"Juraj", "Anabela", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", "Anabela", nullptr}
        {"Andrej", "Juraj", "Andrej", nullptr} -> {"Juraj", "Andrej", "Andrej", nullptr}
        {"Andrej", nullptr} -> {"Andrej", nullptr}
        {nullptr} -> {nullptr}

    POZNAMKY:
        Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
        const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

        Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/
void insertionSort(const char *data[]) {

    size_t length = 0;

    while(data[length] != nullptr) {
        length++;
    }

    for (size_t index2 = 1; index2 < length; ++index2) {

        const char* sortingRN = data[index2];
        size_t index1 = index2;

        while (index1 > 0 && isFirstBiger(sortingRN, data[index1-1])){
            data[index1] = data[index1-1];
            --index1;
        }
        data[index1] = sortingRN;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada zretazeny zoznam 'list' od najvacsieho prvku po najmensi.
    Preusporiadajte uzly v zozname (nekopirujte hodnoty v uzloch).
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] list - zretazeny zoznam, ktory funkcia usporiada

    VSTUPNE PODMIENKY:
        'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
        'list' nie je 'nullptr'

    PRIKLADY:
        vstup: 2->1->3,        vystup: 3->2->1
        vstup: 1->2->2->1,     vystup: 2->2->1->1
        vstup: prazdny zoznam, vystup: prazdny zoznam
*/
void insertionSort(List * list) {


    if (list->first != nullptr) {

        size_t shiftLeft = 1;
        size_t globalShiftLeft = 1;

        Node* left;
        Node* middle;
        Node* right;

        Node* counterNode = list->first;
        size_t length = 1;

        while (counterNode->next != nullptr) {
            counterNode = counterNode->next;
            length++;
        }

        for (size_t i = 0; i < length-1; i++) {

            left = nodeAtIndex(list, length - shiftLeft - 1);
            middle = nodeAtIndex(list, length - shiftLeft);
            right = nodeAtIndex(list, length - shiftLeft + 1);

            while (right != nullptr && middle->data < right->data) {

                if (middle == list->first) {

                    list->first = right;
                    middle->next = right->next;
                    right->next = middle;

                } else {

                    left->next = right;
                    middle->next = right->next;
                    right->next = middle;

                }
                shiftLeft--;

                left = nodeAtIndex(list, length - shiftLeft - 1);
                middle = nodeAtIndex(list, length - shiftLeft);
                right = nodeAtIndex(list, length - shiftLeft + 1);

            }

            globalShiftLeft++;
            shiftLeft = globalShiftLeft;

        }
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vykona algoritmus merge (cast algoritmu merge sort), ktory ma linearnu vypoctovu zlozitost.
    Kombinuje dve susedne, usporiadane casti v poli 'input', do jednej usporiadanej casti v poli 'output'.
    Usporiadanie je od najvacsieho prvku po najmensi prvok!

    PARAMETRE:
        [out] output - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
        [in]  input  - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
                         musia byt pri volani funkcie usporiadane od najvacsieho prvku po najmensi
        [in]  low    - index 1. prvku lavej usporiadanej casti pola 'input'
        [in]  middle - index 1. prvku pravej usporiadanej casti pola 'input'
        [in]  high   - index za poslednym prvkom pravej usporiadanej casti pola 'input'

    VYSTUPNE PODMIENKY:
        Obsah 'input' je nezmeneny.
        output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1], zvysne prvky v 'output' funkcia nemeni.
        Prvky s indexami mensimi ako 'low' sa nemenia (ani v jednom poli).
        Prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (ani v jednom poli).

    PRIKLAD:
        low: 4
        middle: 8
        hight: 12
        input:                         {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10}
        output pred vykonanim funkcie: {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20}
        output po vykonani funkcie:    {20, 20, 20, 20,  8,  7,  5,  4,  2,  2,  1,  0, 20, 20, 20, 20}
*/
void merge(int* output, const int* input, const size_t low, const size_t middle, const size_t high) {
    size_t leftIndex = low;
    size_t rightIndex = middle;
    size_t index = low;

    while (index < high && leftIndex < middle && rightIndex < high) {

        if (input[leftIndex] >= input[rightIndex]) {
            output[index] = input[leftIndex];

            leftIndex++;
            index++;

        } else if (input[leftIndex] < input[rightIndex]) {
            output[index] = input[rightIndex];

            rightIndex++;
            index++;
        }
    }

    if (leftIndex < middle) {
        for (; leftIndex < middle; leftIndex++) {
            output[index] = input[leftIndex];
            index++;
        }
    }

    if (rightIndex < high) {
        for (; rightIndex < high; rightIndex++) {
            output[index] = input[rightIndex];
            index++;
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada prvky v poli 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus merge sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole

    PRIKLADY:
        {1, 3, 2} -> {3, 2, 1}
        {1, 2, 2, 1} -> {2, 2, 1, 1}
        {1} -> {1}
        {} -> {}

    POZNAMKA:
        Ak pouzijete pristup top-down, tak
        - v tejto funkcii zabezpecte vytvorenie a kopirovanie dat do pomocneho pola,
        - vytvorte a zavolajte rekurzivnu funkciu, v ktorej implementujete hlavnu cast algoritmu merge sort.
*/
void mergeSort(int *data, const size_t length) {

    /*  {1, 3, 2} -> {3, 2, 1}
    {1, 2, 2, 1} -> {2, 2, 1, 1}
    {1} -> {1}
    {} -> {}*/

    size_t H;
    size_t M;
    size_t L;

    bool switchCpy;
    int *PtrInp = data;
    int *temp = new int[length];
    int *PtrOut = temp;
    size_t index1 = 1;

    switchCpy = false;
    while (index1 < length) {

        size_t index2 = 0;
        while (index2 < length) {
            if ((index2+2*index1) < length) {
                H = (index2 + 2 * index1);
            } else {
                H = length;
            }
                if ((index2+index1) < length) {
                    M = (index2 + index1);
                } else {
                    M = length;
                }
            L = index2;
            index2 = ((index1*2)+index2);
            merge(PtrOut,PtrInp,L,M,H);

        }
        switchCpy = !switchCpy;
        index1 = 2*index1; // v Maine ukazuje zly index, oprav
        int *tmpPtr = PtrInp;
        PtrInp = PtrOut;
        PtrOut = tmpPtr;
    }
    if (switchCpy) {
        std::memcpy(data,temp,length*sizeof(data[0]));
    }
    delete[] temp;

}
//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {
    // tu mozete doplnit testovaci kod

    //void insertionSort(int *data, const size_t length)


    int numbers[] = {0, 1, 2, -333, -66, 6, 5, 0, 667};

    insertionSort(numbers, 9);

    for (int i = 0; i < 9; ++i) {
        std::cout << numbers[i] << ", ";
    }



    const char *names[] = {"Andrej", "Juraj", "Andrej", "Anabela", "Peter", nullptr};

    insertionSort(names);

    for (int i = 0; i < 6; ++i) {
        if (names[i] != nullptr) {
            std::cout << names[i] << ", ";
        } else {
            std::cout << "null";
        }

    }


    /*  {"Juraj", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", nullptr}
        {"Juraj", "Anabela", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", "Anabela", nullptr}
        {"Andrej", "Juraj", "Andrej", nullptr} -> {"Juraj", "Andrej", "Andrej", nullptr}
        {"Andrej", nullptr} -> {"Andrej", nullptr}
        {nullptr} -> {nullptr}*/

    List* list = new List;

    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;
    Node* node4 = new Node;
    Node* node5 = new Node;

    list->first = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;

    Node* nodeToPrint1 = node1;

    for (int i = 0; i < 6; i++) {

        if (nodeToPrint1 == nullptr) {
            std::cout << "null";
        } else {
            std::cout << nodeToPrint1->data << ", ";
            nodeToPrint1 = nodeToPrint1->next;
        }
    }
    std::cout << std::endl;

    insertionSort(list);

    Node* nodeToPrint2 = list->first;

    for (int i = 0; i < 6; i++) {

        if (nodeToPrint2 == nullptr) {
            std::cout << "null";
        } else {
            std::cout << nodeToPrint2->data << ", ";
            nodeToPrint2 = nodeToPrint2->next;
        }
    }



    int input[] = {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10};
    int output[] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

    for (int i = 0; i < 16; i++) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;

    merge(output,input,4,8,12);

    for (int i = 0; i < 16; i++) {
        std::cout << output[i] << " ";
    }


    /*  {1, 3, 2} -> {3, 2, 1}
    {1, 2, 2, 1} -> {2, 2, 1, 1}
    {1} -> {1}
    {} -> {}*/

    std::cout << std::endl;

    int array[] = {0, 1, 2, 3, 4, 5};

    for (int i = 0; i < 6; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;

    mergeSort(array, 6);

    for (int i = 0; i < 6; i++) {
        std::cout << array[i] << ", ";
    }

    return 0;
}
