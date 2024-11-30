#include<iostream>
#include<string>
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
        if (this == &s) {
            return *this;
        }
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

    void afisare() {
        cout << "Smartphone " << this->id << ": " << this->marca << endl;
        if (this->preturi != nullptr) {
            cout << "Preturi: ";
            for (int i = 0; i < this->nrPreturi; i++) {
                cout << preturi[i] << " ";
            }
            cout << endl;
        }
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
        this->model = "HP";
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
        if (this == &c) {
            return *this;
        }
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

    void afisare() {
        cout << "Calculator " << this->id << ": " << this->model << endl;
        if (this->specificatii != nullptr) {
            cout << "Specificatii: ";
            for (int i = 0; i < this->nrSpecificatii; i++) {
                cout << specificatii[i] << " ";
            }
            cout << endl;
        }
    }

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


    CeasInteligent(const CeasInteligent& ci) : id(++nrCeasuri) {
        this->brand = ci.brand;
        this->nrFunctii = ci.nrFunctii;
        this->functii = new bool[ci.nrFunctii];
        for (int i = 0; i < ci.nrFunctii; i++) {
            this->functii[i] = ci.functii[i];
        }
    }


    CeasInteligent& operator=(const CeasInteligent& ci) {
        if (this == &ci) {
            return *this;
        }
        this->brand = ci.brand;
        this->nrFunctii = ci.nrFunctii;
        if (this->functii != nullptr) {
            delete[] this->functii;
        }
        this->functii = new bool[ci.nrFunctii];
        for (int i = 0; i < ci.nrFunctii; i++) {
            this->functii[i] = ci.functii[i];
        }
        return *this;
    }

    void afisare() {
        cout << "Ceas Inteligent " << this->id << ": " << this->brand << endl;
        if (this->functii != nullptr) {
            cout << "Functii: ";
            for (int i = 0; i < this->nrFunctii; i++) {
                cout << (functii[i] ? "Activat" : "Dezactivat") << " ";
            }
            cout << endl;
        }
    }

    ~CeasInteligent() {
        if (this->functii != nullptr) {
            delete[] this->functii;
        }
    }
};

int CeasInteligent::nrCeasuri = 0;

int main() {
    // Crearea obiectelor pentru Smartphone
    float preturiSmartphone[] = { 999.99f, 1200.50f, 1099.99f };
    Smartphone s1("Samsung", 3, preturiSmartphone);
    Smartphone s2("Apple", 2, new float[2] {1099.99f, 1299.99f});
    Smartphone s3 = s1; // Copiere

    // Crearea obiectelor pentru Calculator
    int specificatiiCalculator[] = { 8, 16, 512 };
    Calculator c1("Dell", 3, specificatiiCalculator);
    Calculator c2("HP", 2, new int[2] {8, 256});
    Calculator c3 = c1; // Copiere

    // Crearea obiectelor pentru Ceas Inteligent
    bool functiiCeas[] = { true, false, true };
    CeasInteligent ci1("Apple", 3, functiiCeas);
    CeasInteligent ci2("Samsung", 2, new bool[2] {true, false});
    CeasInteligent ci3 = ci1; // Copiere

    // Afi?are obiecte
    s1.afisare();
    s2.afisare();
    s3.afisare();

    c1.afisare();
    c2.afisare();
    c3.afisare();

    ci1.afisare();
    ci2.afisare();
    ci3.afisare();

    return 0;
}
