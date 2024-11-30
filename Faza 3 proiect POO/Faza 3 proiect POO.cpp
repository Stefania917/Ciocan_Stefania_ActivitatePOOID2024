#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
    const int id;
    static int nrSmartphone;
    string marca;
    float* preturi;
    int nrPreturi;

public:
    Smartphone() : id(++nrSmartphone) {
        this->marca = "Samsung";
        this->nrPreturi = 0;
        this->preturi = nullptr;
    }

    Smartphone(string marca, int nrPreturi, float* preturi) : id(++nrSmartphone) {
        this->marca = marca;
        this->nrPreturi = nrPreturi;
        this->preturi = new float[nrPreturi];
        for (int i = 0; i < nrPreturi; i++) {
            this->preturi[i] = preturi[i];
        }
    }

    Smartphone(const Smartphone& s) : id(++nrSmartphone) {
        this->marca = s.marca;
        this->nrPreturi = s.nrPreturi;
        this->preturi = new float[s.nrPreturi];
        for (int i = 0; i < s.nrPreturi; i++) {
            this->preturi[i] = s.preturi[i];
        }
    }

    Smartphone& operator=(const Smartphone& s) {
        if (this == &s) return *this;
        this->marca = s.marca;
        this->nrPreturi = s.nrPreturi;
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }
        this->preturi = new float[s.nrPreturi];
        for (int i = 0; i < s.nrPreturi; i++) {
            this->preturi[i] = s.preturi[i];
        }
        return *this;
    }

    
    bool operator==(const Smartphone& s) const {
        return this->marca == s.marca && this->nrPreturi == s.nrPreturi;
    }

    bool operator<(const Smartphone& s) const {
        return this->nrPreturi < s.nrPreturi;
    }

    Smartphone operator+(float pretNou) const {
        Smartphone aux = *this;
        aux.nrPreturi++;
        float* noilePreturi = new float[aux.nrPreturi];
        for (int i = 0; i < aux.nrPreturi - 1; i++) {
            noilePreturi[i] = aux.preturi[i];
        }
        noilePreturi[aux.nrPreturi - 1] = pretNou;
        delete[] aux.preturi;
        aux.preturi = noilePreturi;
        return aux;
    }

    Smartphone& operator++() {
        this->nrPreturi++;
        float* noilePreturi = new float[this->nrPreturi];
        for (int i = 0; i < this->nrPreturi - 1; i++) {
            noilePreturi[i] = this->preturi[i];
        }
        noilePreturi[this->nrPreturi - 1] = this->preturi[this->nrPreturi - 2] + 100;
        delete[] this->preturi;
        this->preturi = noilePreturi;
        return *this;
    }

    void afisare() const {
        cout << "Smartphone " << this->id << ": " << this->marca << endl;
        cout << "Preturi: ";
        for (int i = 0; i < this->nrPreturi; i++) {
            cout << preturi[i] << " ";
        }
        cout << endl;
    }

    static int getNrSmartphone() { return nrSmartphone; }

    
    friend void schimbareMarca(Smartphone& s, const string& marcaNoua) {
        s.marca = marcaNoua;
    }

    ~Smartphone() {
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }
    }
};

int Smartphone::nrSmartphone = 0;

class Calculator {
private:
    const int id;
    static int nrCalculatoare;
    string model;
    int* specificatii;
    int nrSpecificatii;

public:
    Calculator() : id(++nrCalculatoare) {
        this->model = "Macbook";
        this->nrSpecificatii = 0;
        this->specificatii = nullptr;
    }

    Calculator(string model, int nrSpecificatii, int* specificatii) : id(++nrCalculatoare) {
        this->model = model;
        this->nrSpecificatii = nrSpecificatii;
        this->specificatii = new int[nrSpecificatii];
        for (int i = 0; i < nrSpecificatii; i++) {
            this->specificatii[i] = specificatii[i];
        }
    }

    Calculator(const Calculator& c) : id(++nrCalculatoare) {
        this->model = c.model;
        this->nrSpecificatii = c.nrSpecificatii;
        this->specificatii = new int[c.nrSpecificatii];
        for (int i = 0; i < c.nrSpecificatii; i++) {
            this->specificatii[i] = c.specificatii[i];
        }
    }

    Calculator& operator=(const Calculator& c) {
        if (this == &c) return *this;
        this->model = c.model;
        this->nrSpecificatii = c.nrSpecificatii;
        if (this->specificatii != nullptr) {
            delete[] this->specificatii;
        }
        this->specificatii = new int[c.nrSpecificatii];
        for (int i = 0; i < c.nrSpecificatii; i++) {
            this->specificatii[i] = c.specificatii[i];
        }
        return *this;
    }

    bool operator==(const Calculator& c) const {
        return this->model == c.model && this->nrSpecificatii == c.nrSpecificatii;
    }

    bool operator<(const Calculator& c) const {
        return this->nrSpecificatii < c.nrSpecificatii;
    }

    Calculator operator+(int specificatieNoua) const {
        Calculator aux = *this;
        aux.nrSpecificatii++;
        int* noileSpecificatii = new int[aux.nrSpecificatii];
        for (int i = 0; i < aux.nrSpecificatii - 1; i++) {
            noileSpecificatii[i] = aux.specificatii[i];
        }
        noileSpecificatii[aux.nrSpecificatii - 1] = specificatieNoua;
        delete[] aux.specificatii;
        aux.specificatii = noileSpecificatii;
        return aux;
    }

    void afisare() const {
        cout << "Calculator " << this->id << ": " << this->model << endl;
        cout << "Specificatii: ";
        for (int i = 0; i < this->nrSpecificatii; i++) {
            cout << specificatii[i] << " ";
        }
        cout << endl;
    }

    static int getNrCalculatoare() { return nrCalculatoare; }

    ~Calculator() {
        if (this->specificatii != nullptr) {
            delete[] this->specificatii;
        }
    }
};

int Calculator::nrCalculatoare = 0;

class CeasInteligent {
private:
    const int id;
    static int nrCeasuri;
    string brand;
    bool* functii;
    int nrFunctii;

public:
    CeasInteligent() : id(++nrCeasuri) {
        this->brand = "Apple";
        this->nrFunctii = 0;
        this->functii = nullptr;
    }

    CeasInteligent(string brand, int nrFunctii, bool* functii) : id(++nrCeasuri) {
        this->brand = brand;
        this->nrFunctii = nrFunctii;
        this->functii = new bool[nrFunctii];
        for (int i = 0; i < nrFunctii; i++) {
            this->functii[i] = functii[i];
        }
    }

    CeasInteligent(const CeasInteligent& c) : id(++nrCeasuri) {
        this->brand = c.brand;
        this->nrFunctii = c.nrFunctii;
        this->functii = new bool[c.nrFunctii];
        for (int i = 0; i < c.nrFunctii; i++) {
            this->functii[i] = c.functii[i];
        }
    }

    CeasInteligent& operator=(const CeasInteligent& c) {
        if (this == &c) return *this;
        this->brand = c.brand;
        this->nrFunctii = c.nrFunctii;
        if (this->functii != nullptr) {
            delete[] this->functii;
        }
        this->functii = new bool[c.nrFunctii];
        for (int i = 0; i < c.nrFunctii; i++) {
            this->functii[i] = c.functii[i];
        }
        return *this;
    }

    bool operator==(const CeasInteligent& c) const {
        return this->brand == c.brand && this->nrFunctii == c.nrFunctii;
    }

    bool operator<(const CeasInteligent& c) const {
        return this->nrFunctii < c.nrFunctii;
    }

    CeasInteligent operator+(bool functieNoua) const {
        CeasInteligent aux = *this;
        aux.nrFunctii++;
        bool* noileFunctii = new bool[aux.nrFunctii];
        for (int i = 0; i < aux.nrFunctii - 1; i++) {
            noileFunctii[i] = aux.functii[i];
        }
        noileFunctii[aux.nrFunctii - 1] = functieNoua;
        delete[] aux.functii;
        aux.functii = noileFunctii;
        return aux;
    }

    void afisare() const {
        cout << "Ceas Inteligent " << this->id << ": " << this->brand << endl;
        cout << "Functii: ";
        for (int i = 0; i < this->nrFunctii; i++) {
            cout << functii[i] << " ";
        }
        cout << endl;
    }

    static int getNrCeasuri() { return nrCeasuri; }

    ~CeasInteligent() {
        if (this->functii != nullptr) {
            delete[] this->functii;
        }
    }
};

int CeasInteligent::nrCeasuri = 0;

int main() {
    Smartphone smartphone1("Samsung", 3, new float[3] { 300, 400, 500 });
    smartphone1.afisare();

    Smartphone smartphone2("Huawei", 2, new float[2] { 200, 300 });
    smartphone2.afisare();

    Calculator calc1("Macbook", 2, new int[2] { 8, 16 });
    calc1.afisare();

    Calculator calc2("Dell", 3, new int[3] { 4, 8, 16 });
    calc2.afisare();

    CeasInteligent ceas1("Apple", 3, new bool[3] { true, false, true });
    ceas1.afisare();

    CeasInteligent ceas2("Garmin", 2, new bool[2] { false, true });
    ceas2.afisare();

    schimbareMarca(smartphone1, "Xiaomi");
    cout << "Dupa schimbarea marcii pentru smartphone1:" << endl;
    smartphone1.afisare();

    smartphone1 = smartphone1 + 600;
    cout << "Dupa adaugarea unui pret la smartphone1:" << endl;
    smartphone1.afisare();

   

    if (smartphone1 == smartphone2) {
        cout << "Smartphone1 si Smartphone2 sunt egale." << endl;
    }
    else {
        cout << "Smartphone1 si Smartphone2 NU sunt egale." << endl;
    }

    if (smartphone1 < smartphone2) {
        cout << "Smartphone1 are pretul mai mic decat Smartphone2." << endl;
    }
    else {
        cout << "Smartphone1 are pretul mai mare sau egal decat Smartphone2." << endl;
    }

    calc1 = calc1 + 32;
    cout << "Dupa adaugarea unei noi specificatii la calc1:" << endl;
    calc1.afisare();

    

    if (calc1 == calc2) {
        cout << "Calc1 si Calc2 sunt egale." << endl;
    }
    else {
        cout << "Calc1 si Calc2 NU sunt egale." << endl;
    }

    if (calc1 < calc2) {
        cout << "Calc1 are mai putine specificatii decat Calc2." << endl;
    }
    else {
        cout << "Calc1 are mai multe specificatii fata de Calc2." << endl;
    }

    ceas1 = ceas1 + false;
    cout << "Dupa adaugarea unei noi functii la ceas1:" << endl;
    ceas1.afisare();

    

    if (ceas1 == ceas2) {
        cout << "Ceas1 si Ceas2 sunt egale." << endl;
    }
    else {
        cout << "Ceas1 si Ceas2 NU sunt egale." << endl;
    }

    if (ceas1 < ceas2) {
        cout << "Ceas1 are mai putine functii decat Ceas2." << endl;
    }
    else {
        cout << "Ceas1 are mai multe functii fata de Ceas2." << endl;
    }

    return 0;
}
