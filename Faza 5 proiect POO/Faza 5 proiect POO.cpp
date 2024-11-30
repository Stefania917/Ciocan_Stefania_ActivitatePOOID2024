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

class Laptop {
private:
    string model;
    float pret;
    float dimensiuneEcran;
    Smartphone* smartphone;

public:
    Laptop() : model("Dell"), pret(3000.0), dimensiuneEcran(15.6), smartphone(nullptr) {}

    Laptop(string model, float pret, float dimensiuneEcran, Smartphone* smartphone)
        : model(model), pret(pret), dimensiuneEcran(dimensiuneEcran), smartphone(smartphone) {}

    string getModel() const { return model; }
    float getPret() const { return pret; }
    float getDimensiuneEcran() const { return dimensiuneEcran; }
    Smartphone* getSmartphone() const { return smartphone; }

    void setModel(string model) { this->model = model; }
    void setPret(float pret) { this->pret = pret; }
    void setDimensiuneEcran(float dimensiuneEcran) { this->dimensiuneEcran = dimensiuneEcran; }
    void setSmartphone(Smartphone* smartphone) { this->smartphone = smartphone; }

    Laptop& operator=(const Laptop& l) {
        if (this == &l) return *this;
        this->model = l.model;
        this->pret = l.pret;
        this->dimensiuneEcran = l.dimensiuneEcran;
        this->smartphone = l.smartphone;
        return *this;
    }

    Laptop operator+(Smartphone* s) {
        Laptop aux = *this;
        aux.smartphone = s;
        return aux;
    }

    bool operator==(const Laptop& l) const {
        return this->model == l.model && this->pret == l.pret && this->dimensiuneEcran == l.dimensiuneEcran;
    }

    void afisare() const {
        cout << "Laptop: " << this->model << ", Pret: " << this->pret << ", Ecran: "
            << this->dimensiuneEcran << " inch" << endl;
        if (this->smartphone != nullptr) {
            cout << "Smartphone asociat: ";
            this->smartphone->afisare();
        }
        else {
            cout << "Nu exista un smartphone asociat." << endl;
        }
    }
};

int main() {
    float preturi1[] = { 2999.99, 3499.99, 3999.99 };
    Smartphone smartphone1("Samsung", 3, preturi1);
    Smartphone smartphone2("Apple", 2, new float[2] {4499.99, 4999.99});

    Laptop laptop1("Lenovo", 2500.0, 14.0, nullptr);
    Laptop laptop2("HP", 3000.0, 15.6, &smartphone1);

    laptop1.afisare();
    laptop2.afisare();

    laptop1 = laptop1 + &smartphone2;
    cout << "\nDupã adãugarea unui smartphone:\n";
    laptop1.afisare();

    if (laptop1 == laptop2) {
        cout << "\nLaptopurile sunt identice.\n";
    }
    else {
        cout << "\nLaptopurile sunt diferite.\n";
    }

    return 0;
}