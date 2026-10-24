#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Fortareata {
private:
    const int ID;
    string denumire;

public:
    static int nrFortarete;

    Fortareata() : ID(++nrFortarete) {
        this->denumire = "Fortareata Generica";
    }

    Fortareata(int id_custom, string denumire) : ID(++nrFortarete) {
        this->denumire = denumire;
    }

    void afisare_fortareata() {
        cout << "=== Fortareata [" << this->ID << "]: " << this->denumire << " ===" << endl;
    }

};

int Fortareata::nrFortarete = 0;

class Camere {
private:
    int nr_camere;
    float* vector_ocupati;

public:
    Camere() {
        this->nr_camere = 0;
        this->vector_ocupati = nullptr;
    }

    Camere(int nr_camere, float* ocupatie) {
        if (nr_camere > 0 && ocupatie != nullptr) {
            this->nr_camere = nr_camere;
            this->vector_ocupati = new float[nr_camere];
            for (int i = 0; i < nr_camere; i++) {
                this->vector_ocupati[i] = ocupatie[i];
            }
        }
        else {
            this->nr_camere = 0;
            this->vector_ocupati = nullptr;
        }
    }

    void afisare_camere() {
        cout << "Numar total de camere: " << this->nr_camere << endl;
        if (this->nr_camere > 0 && this->vector_ocupati != nullptr) {
            for (int i = 0; i < this->nr_camere; i++) {
                cout << "  - Camera " << (i + 1) << " are ocupatia: " << this->vector_ocupati[i] << endl;
            }
        }
        else {
            cout << "  Nu exista camere inregistrate." << endl;
        }
        cout << endl;
    }

    int getNr_camere()
    {
        return this->nr_camere;
    }

    void setNr_camere(int nr_camere_nou)
    {
        if (nr_camere_nou >= 0)
        {
            this->nr_camere = nr_camere_nou;
        }
        else
        {
            throw "Valoare negativa";
        }
    }

    float* getVector_ocupati()
    {
        float* vector_ocupati_nou = new float[this->nr_camere];
        for (int i = 0; i < this->nr_camere; i++)
        {
            vector_ocupati_nou[i] = this->vector_ocupati[i];
        }
        return vector_ocupati_nou;
    }

    void setVector_ocupati(float* vector, int nrC)
    {
        setNr_camere(nrC);
        if (this->vector_ocupati != nullptr)
        {
            delete[] this->vector_ocupati;
        }
        this->vector_ocupati = new float[this->nr_camere];
        for (int i = 0; i < this->nr_camere; i++)
        {
            this->vector_ocupati[i] = vector[i];
        }
        delete[] vector;
    }

    ~Camere() {
        if (this->vector_ocupati != nullptr) {
            delete[] this->vector_ocupati;
        }
    }

};

class Locuitori {
private:
    string Nume_Locuitor;
    string Rol;
    int Varsta;

public:
    Locuitori() {
        this->Rol = "Fara rol";
        this->Varsta = 0;
        this->Nume_Locuitor = "Anonim";
    }

    Locuitori(string rol, int varsta, string nume) {
        this->Rol = rol;
        this->Varsta = varsta;
        this->Nume_Locuitor = nume;
    }

    void afisare_locuitor() {
        cout << "Rol: " << this->Rol << endl;
        cout << "Varsta: " << this->Varsta << endl;
        cout << "Nume: " << this->Nume_Locuitor << endl;
        cout << "------------------------" << endl;
    }
};


int main() {
    Fortareata Hunedoara;
    Hunedoara.afisare_fortareata();

    Fortareata* pMinimal = new Fortareata(2, "Minimal");
    pMinimal->afisare_fortareata();

    delete pMinimal;

    if (Fortareata::nrFortarete == 1) {
        cout << endl << "Am creat o complexitate Medievala numita Fortareata!" << endl << endl;
    }
    else {
        cout << endl << "Am creat " << Fortareata::nrFortarete << " Fortarete de putere exorbitanta!" << endl << endl;
    }

    cout << "=== EVIDENTA LOCUITORI ===" << endl;
    Locuitori locuitor1("Arcas", 28, "Vlad");
    Locuitori locuitor2("Fierar", 45, "Grigore");
    Locuitori locuitor3("Strajer", 22, "Matei");

    locuitor1.afisare_locuitor();
    locuitor2.afisare_locuitor();
    locuitor3.afisare_locuitor();

    Camere cCamere;
    cCamere.afisare_camere();

    try
    {
        cCamere.setNr_camere(2);
    }
    catch (int cod)
    {
        cout << endl << cod;
    }
    catch (const char* mesaj)
    {
        cout << endl << mesaj;
    }
    catch (...)
    {
        cout << endl << "Numar de locuri negativ!" << endl;
    }

    cout << endl << "Noul numar de camere este: " << cCamere.getNr_camere() << endl;

    cCamere.setVector_ocupati(new float[3] {16.0f, 10.0f, 12.0f}, 3);
    float* vector = cCamere.getVector_ocupati();

    cout << endl << "Noul numar de ocupanti sunt: " << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i != 2)
        {
            cout << vector[i] << " persoane, " << endl;
        }
        else cout << vector[i] << " persoane." << endl;
    }
    cCamere.afisare_camere();
    delete[] vector;

}
