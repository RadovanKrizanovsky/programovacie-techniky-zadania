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
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/


#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

void printQueue(queue<int> & data){

    while(!data.empty()){
        cout << " " << data.front();
        data.pop();
    }
    cout << endl;
}

void printList(list<string> & data){

    for (string i: data) {
        std::cout << i << " ";
    }
    cout << endl;
}

void printList(list<int> & data){

    for (int i: data) {
        std::cout << i << " ";
    }
    cout << endl;
}

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori frontu, ktora obsahuje rovnake prvky ako vstupny zoznam, ale v opacnom poradi.
    Obsah vstupneho zoznamu nemeni.

    Implementujte pomocou reverzneho iteratora!

    PARAMETER:
        [in] data - zoznam prvkov, ktore funkcia nakopiruje do vytvorenej fronty.

    NAVRATOVA HODNOTA:
        Nova fronta, obsahujuca kopie prvkov vstupneho zoznamu v opacnom poradi
*/

queue<int> reverse(const list<int> & data) noexcept {

    queue<int> qe;

    for (reverse_iterator<list<int>::const_iterator> it = data.rbegin(); it != data.rend(); it++){
        qe.push(*it);
    }

    return qe; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia preusporiada prvky vo fronte tak, ze budu v opacnom poradi.

    Implementujte pomocou zasobnika!
    Algoritmus ulozi prvky z fronty do zasobnika a potom zo zasobnika naspat do fronty.

    PARAMETER:
        [in, out] data - fronta, v ktorej funkcia zmeni poradie prvkov na opacne
*/

void reverse(queue<int> & data) noexcept {

    stack<int> st;

    while(!data.empty()){
        st.push(data.front());
        data.pop();
    }

    while(!st.empty()){
        data.push(st.top());
        st.pop();
    }

}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori vektor, ktoreho prvkami su vektory cisiel typu 'int'.

    PARAMETRE:
        [in] size1 - pocet prvkov hlavneho vektora (pocet vnorenych vektorov)
        [in] size2 - pocet prvkov kazdeho vektora, ktory je prvkom hlavneho vektora (vnorene vektory budu rovnako dlhe, ich dlzka bude 'size2')
        [in] value - hodnota kazdeho celeho cisla vo vektore vektorov

    NAVRATOVA HODNOTA:
        Vektor, ktoreho prvkami su vektory cisiel (pocet jeho prvkov je 'size1').
        Vnorene vektory su rovnako dlhe (pocty ich prvkov su 'size2').
        Vsetky cisla vo vektore vektorov maju hodnotu 'value'.

    PRIKLAD:
        vstup:
            size1 = 2, size2 = 5, value = 10
        vystup:
            { {10, 10, 10, 10, 10}, {10, 10, 10, 10, 10} }
*/

vector<vector<int>> create2dVector(const size_t size1, const size_t size2, const int value) noexcept {

    vector<vector<int>> vectorOfVectors;
    vector<int> genericVector;

    for (size_t i = 0; i < size2; i++) {
        genericVector.push_back(value);
    }

    for (size_t i = 0; i < size1; i++) {
        vectorOfVectors.push_back(genericVector);
    }

    return vectorOfVectors; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati textovy retacec, ktory vznikne zretazenim textu 'text', medzery  a cisla 'number'.

    PARAMETRE:
        [in] text - textovy retazec
        [in] number - cislo

    NAVRATOVA HODNOTA:
        Novy textovy retazec, ktory vznikne zretazenim 'text', jednej medzery a 'number'
        (cislo 'number' je skonvertovane na textovy retazec).

    PRIKLADY:
        1. priklad:
            text: "abc", number: 10, vystup: "abc 10"
        2. priklad:
            text: " abc ", number: 10, vystup: " abc  10"
        3. priklad:
            text: "", number: -10, vystup: " -10"
*/

string connectWithSpace(const string & text, const int number) noexcept {

    return text + " " + to_string(number); // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia precita cisla zo vstupneho textoveho prudu a vrati ich sucet.
    Ak sa vo vstupnom prude vyskytne text, ktory sa neda skonvertovat na cislo,
    tak citanie skonci a vrati sucet precitanych cisiel (funkcia neskusa hladat dalsie cisla).
    Pred, medzi a za cislami moze byt lubovolny pocet bielych znakov.

    PARAMETER:
        [in] text - vstupny textovy prud

    NAVRATOVA HODNOTA:
        Sucet precitanych cisiel (do konca, alebo po vyskyt chyby pri citani alebo konvertovani textu na cislo)

    PRIKLADY:
        text: "10 20 30 10", vystup: 70
        text: " 10   20 30 10 ", vystup: 70
        text: "10 a 20", vystup: 10 (pri konverzii "a" na cislo nastala chyba, funkcia vratila sucet cisiel po vyskyt prvej chyby citania/konverzie)
        text: "", vystup: 0
        text: " ", vystup: 0
*/

int sum(istringstream & text) noexcept {

    int totalSum = 0;
    string word;
    int tempInt;
    bool run = true;

    while (text >> word && run) {
        stringstream tempStream(word);
        if (tempStream >> tempInt) {
            totalSum += tempInt;
        } else {
            run = false;
        }
    }


    return totalSum; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prelozi zoznam slov 'sentence' z jedneho jazyka do druheho pomocou slovnika 'translator' a vrati prelozeny zoznam slov.
    Pri prekladani zachova vstupne poradie slov.
    Ak sa v slovniku 'translator' nenachadza preklad, tak do vystupneho zoznamu zapise namiesto prekladu otaznik.
    Pri preklade sa rozlisuju male a velke pismena, cize pri hladani prekladu netreba konvertovat velke pismena na male, alebo opacne.

    PARAMETERE:
        [in] translator - mapuje slova zo vstupneho jazyka do vystupneho jazyka
        [in] sentence   - zoznam slov vo vstupnom jazyku

    NAVRATOVA HODNOTA:
        Novy zoznam slov prelozenych do vystupneho jazyka, v poradi, v ktorom boli v 'sentence'.
        Ak slovnik 'translator' neobsahuje preklad slova, tak je vo vystupnom zozname namiesto prekladu otaznik.

    PRIKLADY:
        Vo vsetkych prikladoch predpokladajme obsah prekladoveho slovnika:
            translator: {
                "read" -> "citat",
                "write" -> "pisat",
                "book" -> "kniha",
                "I" -> "ja",
                "you" -> "ty",
                "he" -> "on",
                "she" -> "ona",
                "it" -> "ono"
                "a" -> "",
                "an" -> "",
                "the" -> ""
            }
        1. priklad:
            sentence: { "I", "read", "a", "book"}, vystup: { "ja", "citat", "", "kniha" }
        2. priklad:
            sentence: { "I", "am", "reading", "a", "book" }, vystup: { "ja", "?", "?", "", "kniha"}
        3. priklad:
            sentence: { "He", "reads", "a", "book" }, vystup: { "?", "?", "", "kniha"}, poznamka: neprelozil "He", pretoze v slovniku je len "he"
*/

list<string> translate(const map<string, string> & translator, const list<string> & sentence) noexcept {

    list<string> translated;
    _Rb_tree_const_iterator<pair<const basic_string<char>, basic_string<char>>> mapIt;

    for (_List_const_iterator<basic_string<char>> sentenceIt = sentence.begin(); sentenceIt != sentence.end(); sentenceIt++){
        if ((mapIt = translator.find(*sentenceIt)) != translator.end()){
            translated.push_back(mapIt->second);
        } else {
            translated.push_back("?");
        }
    }

    return translated; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci su vo vstupnom textovom retazci spravne sparovane zatvorky.
    Ak ano, vrati 'true', inak vrati 'false'.
    Testuje nasledujuce typy zatvoriek: ( ) { } [ ] < >1

    V implementacii pouzite na ukladanie otvaracich zatvoriek zasobnik.
    Porovnavajte zatvaracie zatvorky s poslednou otvaracou zatvorkou (na vrchole zasobnika).

    PARAMETER:
        [in] mathExpression - textovy retazec, v ktorom funkcia testuje spravnost sparovania zatvoriek

    NAVRATOVA HODNOTA:
        Ak su zatvorky spravne sparovane vrati 'true', inak vrati 'false'.

    PRIKLADY:
        vstup: "ab - (c< d > 1) + {[23 ( [ 45] ) 6] 7} 8 ", vystup: 'true'
        vstup: "(", vystup: 'false'
        vstup: "())", vystup: 'false'
        vstup: "{ >", vystup: 'false'
        vstup: "", vystup: 'true'
*/

bool areParenthesisPaired(const string & mathExpression) noexcept {
    
    stack<char> begining;
    int left = 0;
    int right = 0;

    for (size_t i = 0; i < mathExpression.size(); i++) {
        if (mathExpression[i] == '(' || mathExpression[i] == '[' || mathExpression[i] == '{' || mathExpression[i] == '<') {

            switch (mathExpression[i]) {
                case '(':
                    begining.push(')');
                    left++;
                    break;
                case '[':
                    begining.push(']');
                    left++;
                    break;
                case '{':
                    begining.push('}');
                    left++;
                    break;
                case '<':
                    begining.push('>');
                    left++;
                    break;
            }

        } else if (mathExpression[i] == ')' || mathExpression[i] == ']' || mathExpression[i] == '}' || mathExpression[i] == '>') {
            right++;

            if (begining.empty()) {
                return  false;
            }

            if (mathExpression[i] != begining.top()) {
                return false;
            } else {
                begining.pop();
            }
        }
    }
    if (left != right) {
        return false;
    }
    
    return true; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia 'execute' zavola funkciu 'function', s parametrami 'parameter1' a 'parameter2' a vrati jej vysledok.

    PARAMETRE:
        [in] function   - funkcia, ktoru funkcia 'execute' zavola
        [in] parameter1 - pri volani 'function' bude pouzity ako 1. parameter
        [in] parameter2 - pri volani 'function' bude pouzity ako 2. parameter

    NAVRATOVA HODNOTA:
        Vysledok volania 'function(parameter1, parameter2)'

    Funkcie 'multiply' a 'maxValue' su priklady funkcii, ktore mozu byt pouzite ako parameter funkcie 'execute'.

    PRIKLADY:
        1. priklad:
            volanie: execute(multiply, 20, 50) alebo execute(&multiply, 20, 50)
            vystup: 1000
        2. priklad:
            volanie: execute(maxValue, 20, 50) alebo execute(&maxValue, 20, 50)
            vystup: 50
        3. priklad:
            volanie: execute([](int a, int b)->int { return a - b; }, 20, 50)
            vystup: -30
*/

int multiply(int a, int b) noexcept {
    return a * b;
}

int maxValue(int a, int b) noexcept {
    if(a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int execute(int (*function)(int, int), int parameter1, int parameter2) {

    return function(parameter1, parameter2); // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia 'thrownException' zavola funkciu 'function', ktora je vstupnym parametrom.
    Vrati hodnotu podla toho, ci a aku vynimku funkcia 'function' pri volani vyhodi.

    PARAMETER:
        [in] function - funkcia, ktora bude zavolana a testovana (ci a aku vynimku vyhodi)

    NAVRATOVA HODNOTA:
        ExceptionType::NO_EXCEPTION - ak 'function' nevyhodi ziadnu vynimku
        ExceptionType::INVALID_ARGUMENT - ak 'function' vyhodi vynimku typu 'std::invalid_argument'
        ExceptionType::BAD_ALLOC - ak 'function' vyhodi vynimku typu 'std::bad_alloc'
        ExceptionType::UNKNOWN_EXCEPTION - ak 'function' vyhodi iny typ vynimky

    Funkcie: 'doNotThrow', 'throwInvalidArgument', 'throwBadAlloc', 'throwOutOfRange' mozete pouzit pre testovanie.
*/

void doNotThrow() noexcept {
}

void throwInvalidArgument() {
    throw std::invalid_argument("popis vynimky"); // konstruktor vynimky ma parameter
}

void throwBadAlloc() {
    throw std::bad_alloc(); // konstruktor vynimky nema parameter
}

void throwOutOfRange() {
    throw std::out_of_range("popis vynimky");
}

enum class ExceptionType {
    NO_EXCEPTION,
    INVALID_ARGUMENT,
    BAD_ALLOC,
    UNKNOWN_EXCEPTION
};

ExceptionType thrownException(void (*function)()) noexcept {

    try {
        function();
    } catch (std::invalid_argument & ia) {
        return ExceptionType::INVALID_ARGUMENT;

    } catch (std::bad_alloc & ba) {
        return ExceptionType::BAD_ALLOC;

    } catch (...) {
        return ExceptionType::UNKNOWN_EXCEPTION;
    }

    return ExceptionType::NO_EXCEPTION; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori zoznam, ktoreho jeden prvok bude mat hodnotu 1, ostatne prvky hodnotu 0.
    Zoznam bude mat 'length' prvkov.
    Prvok s indexom 'indexOfOne' bude mat hodnotu 1, ostatne prvky hodnotu 0.
    V pripade chybnych vstupnych parametrov, funkcia vyhodi vynimku.

    PARAMETRE:
        [in] length - pocet prvkov vytvoreneho zoznamu
        [in] indexOfOne - index prvku, ktory bude mat hodnotu 1

    NAVRATOVA HODNOTA:
        Zoznam, ktory obsahuje jednu 1 (prvok s indexom 'indexOfOne') a ostatne jeho prvky maju hodnotu 0.
        Prvy prvok ma index nula.
        Pocet prvkov zoznamu je 'length'

    VYNIMKA:
        Ak 'indexOfOne' >= 'length', tak funkcia vyhodi vynimku typu 'IndexOutOfRangeException',
        ktora nesie informacie o pozadovanej dlzke zoznamu a indexe kde mala byt hodnota 1.

    PRIKLADY:
        1. priklad
            vstup: length = 5, indexOfOne = 0
            vystup: {1, 0, 0, 0, 0}
        2. priklad
            vstup: length = 5, indexOfOne = 1
            vystup: {0, 1, 0, 0, 0}
        3. priklad
            vstup: length = 5, indexOfOne = 5
            vyhodi vynimku, ktorej metoda 'getLength' vrati 5 a 'getIndex' vrati 5
        4. priklad
            vstup: length = 5, indexOfOne = 10
            vyhodi vynimku, ktorej metoda 'getLength' vrati 5 a 'getIndex' vrati 10
        5. priklad
            vstup: count = 0, indexOfOne = 0
            vyhodi vynimku, ktorej metoda 'getLength' vrati 0 a 'getIndex' vrati 0
*/

class IndexOutOfRangeException {
private:
    const size_t length;
    const size_t index;
public:
    IndexOutOfRangeException(size_t length, size_t index) noexcept
            : length(length)
            , index(index) {
    }

    size_t getLength() const noexcept {
        return length;
    }

    size_t getIndex() const noexcept {
        return index;
    }

    string what() const noexcept {
        return "index out of range: " + to_string(index) + " >= " + to_string(length);
    }
};

list<int> createList(const list<int>::size_type length, const list<int>::size_type indexOfOne) {

    if (indexOfOne >= length) {
        throw IndexOutOfRangeException(length, indexOfOne);
    }

    list<int> finalList;
    for (list<int>::size_type i = 0; i < length; i++) {
        finalList.push_front(0);
    }

    list<int>::iterator i;
    list<int>::size_type index = 0;
    for (i = finalList.begin(); i != finalList.end(); i++){
        if (index == indexOfOne){
            *i = 1;
        }
        index++;
    }

    return finalList; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne testovacie funkcie a struktury

int main() {

    /*
    list<int> data = {0,1,2,3,4,5};

    queue<int> qe = reverse(data);

    while(!qe.empty()){
        cout<<" "<<qe.front();
        qe.pop();
    }
    */
    /*
    queue<int> data;

    for (int i = 0; i < 5; i++) {
        data.push(i);
    }

    while(!data.empty()){
        cout<<" "<<data.front();
        data.pop();
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        data.push(i);
    }

    reverse(data);

    while(!data.empty()){
        cout<<" "<<data.front();
        data.pop();
    }
    */

    /*
    string s = "pes";
    int n = 5;
    cout<<connectWithSpace(s, n);
    */

    /*
    istringstream text(" 10   20 30 10 ");

    int num = sum(text);
    cout << num;
    */

    /*
    map<string,string> translator;
    translator.insert(make_pair("read", "citat"));
    translator.insert(make_pair("write", "pisat"));
    translator.insert(make_pair("book", "kniha"));
    translator.insert(make_pair("I", "ja"));
    translator.insert(make_pair("you", "ty"));
    translator.insert(make_pair("he", "on"));
    translator.insert(make_pair("she", "ona"));
    translator.insert(make_pair("it", "ono"));
    translator.insert(make_pair("a", ""));
    translator.insert(make_pair("an", ""));
    translator.insert(make_pair("the", ""));

    const list<string> sentence = { "He", "reads", "a", "book" };

    list<string> translated = translate(translator, sentence);

    printList(translated);
    */

    /*
    const string mathExpression = "";
    cout << areParenthesisPaired(mathExpression);
    */

    /*
    cout<<execute(multiply, 20, 50);
    cout<< " | ";
    cout<<execute(&multiply, 20, 50);
    cout<<endl;

    cout<<execute(maxValue, 20, 50);
    cout<< " | ";
    cout<<execute(&maxValue, 20, 50);
    cout<<endl;

    cout<<execute([](int a, int b)->int { return a - b; }, 20, 50);
    */

    /*
    list<int> list = createList(10, 8);
    printList(list);
    */

    return 0;
}
