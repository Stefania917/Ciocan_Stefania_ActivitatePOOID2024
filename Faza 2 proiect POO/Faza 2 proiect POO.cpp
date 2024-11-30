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

    
    int getId() const { return this->id; }
    string getMarca() const { return this->marca; }
    void setMarca(string marca) { this->marca = marca; }
    int getNrPreturi() const { return this->nrPreturi; }
    void setNrPreturi(int nrPreturi) { this->nrPreturi = nrPreturi; }

    float* getPreturi() const {
        float* VectorPreturi = new float[this->nrPreturi];
        for (int i = 0; i < this->nrPreturi; i++) {
            VectorPreturi[i] = this->preturi[i];
        }
        return VectorPreturi;
    }

    void setPreturi(float* noulVectorPreturi, int nrnoulVectorPreturi) {
        this->nrPreturi = nrnoulVectorPreturi;
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }
        this->preturi = new float[nrnoulVectorPreturi];
        for (int i = 0; i < nrnoulVectorPreturi; i++) {
            this->preturi[i] = noulVectorPreturi[i];
        }
    }

    
    ~Smartphone() {
        if (this->preturi != nullptr) {
            delete[] this->preturi;  
        }
    }

    
    void afisare() const {
        cout << "Smartphone " << this->id << ": " << this->marca << endl;
        if (this->preturi != nullptr) {
            cout << "Preturi: ";
            for (int i = 0; i < this->nrPreturi; i++) {
                cout << preturi[i] << " ";
            }
            cout << endl;
        }
    }

    static int getNrSmartphone() { return nrSmartphone; }
    static void setNrSmartphone(int _nrSmartphone) { nrSmartphone = _nrSmartphone; }
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

    
    int getId() const { return this->id; }
    string getModel() const { return this->model; }
    void setModel(string model) { this->model = model; }
    int getNrSpecificatii() const { return this->nrSpecificatii; }
    void setNrSpecificatii(int nrSpecificatii) { this->nrSpecificatii = nrSpecificatii; }

    int* getSpecificatii() const {
        int* noileSpec = new int[this->nrSpecificatii];
        for (int i = 0; i < this->nrSpecificatii; i++) {
            noileSpec[i] = this->specificatii[i];
        }
        return noileSpec;
    }

    void setSpecificatii(int* noileSpecificatii, int nrSpecNou) {
        this->nrSpecificatii = nrSpecNou;
        if (this->specificatii != nullptr) {
            delete[] this->specificatii;
        }
        this->specificatii = new int[nrSpecNou];
        for (int i = 0; i < nrSpecNou; i++) {
            this->specificatii[i] = noileSpecificatii[i];
        }
    }

    
    ~Calculator() {
        if (this->specificatii != nullptr) {
            delete[] this->specificatii;  
        }
    }

    
    void afisare() const {
        cout << "Calculator " << this->id << ": " << this->model << endl;
        if (this->specificatii != nullptr) {
            cout << "Specificatii: ";
            for (int i = 0; i < this->nrSpecificatii; i++) {
                cout << specificatii[i] << " ";
            }
            cout << endl;
        }
    }

    static int getNrCalculatoare() { return nrCalculatoare; }
    static void setNrCalculatoare(int _nrCalculatoare) { nrCalculatoare = _nrCalculatoare; }
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
        if (this == &c) {
            return *this;
        }
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

    
    int getId() const { return this->id; }
    string getBrand() const { return this->brand; }
    void setBrand(string brand) { this->brand = brand; }
    int getNrFunctii() const { return this->nrFunctii; }
    void setNrFunctii(int nrFunctii) { this->nrFunctii = nrFunctii; }

    bool* getFunctii() const {
        bool* noileFunctii = new bool[this->nrFunctii];
        for (int i = 0; i < this->nrFunctii; i++) {
            noileFunctii[i] = this->functii[i];
        }
        return noileFunctii;
    }

    void setFunctii(bool* noileFunctii, int nrnoileFunctii) {
        this->nrFunctii = nrnoileFunctii;
        if (this->functii != nullptr) {
            delete[] this->functii;
        }
        this->functii = new bool[nrnoileFunctii];
        for (int i = 0; i < nrnoileFunctii; i++) {
            this->functii[i] = noileFunctii[i];
        }
    }

    
    ~CeasInteligent() {
        if (this->functii != nullptr) {
            delete[] this->functii;  
        }
    }

    
    void afisare() const {
        cout << "Ceas inteligent " << this->id << ": " << this->brand << endl;
        if (this->functii != nullptr) {
            cout << "Functii: ";
            for (int i = 0; i < this->nrFunctii; i++) {
                cout << functii[i] << " ";
            }
            cout << endl;
        }
    }

    static int getNrCeasuri() { return nrCeasuri; }
    static void setNrCeasuri(int _nrCeasuri) { nrCeasuri = _nrCeasuri; }
};

int CeasInteligent::nrCeasuri = 0;

int main() {
    float preturiSmartphone[] = { 2000.5, 2500.0, 1500.75 };
    Smartphone s1("Samsung", 3, preturiSmartphone);

    int specificatiiCalculator[] = { 16, 512, 3000 };
    Calculator c1("Asus", 3, specificatiiCalculator);

    bool functiiCeas[] = { true, false, true };
    CeasInteligent ceas1("Apple", 3, functiiCeas);

    s1.afisare();
    c1.afisare();
    ceas1.afisare();

   
    cout << "Numar smartphone-uri: " << Smartphone::getNrSmartphone() << endl;
    cout << "Numar calculatoare: " << Calculator::getNrCalculatoare() << endl;
    cout << "Numar ceasuri inteligente: " << CeasInteligent::getNrCeasuri() << endl;

    return 0;
}
