#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Funcion que genera un random del 1 al 100
int generarNum1al100() {
    return rand() % 100 + 1;
}

//Clase clima
class Clima {
private:
    int gradosC;
    string tiempo = "Soleado";
public:
    void setTiempo() {
        int probabilidad = generarNum1al100();
        if (probabilidad <= 60) {
            tiempo = "Soleado";
        } else if (probabilidad > 60 && probabilidad <= 95) {
            tiempo = "Nublado";
            int probabilidadLluvia = generarNum1al100();
            if (probabilidadLluvia <= 48) {
                tiempo = "Soleado";
            } else {
                tiempo = "Lluvioso";
            }
        } else if (probabilidad > 95) {
            tiempo = "Lluvioso";
        }
    }
    string getTiempo(){
        return tiempo;}
};

class TransporteAereo {
protected:
    string matricula;
    string nombreAerolinea;
    string tipoTransporte;
public:
    TransporteAereo(string mat, string aerolinea, string tipo) : matricula(mat), nombreAerolinea(aerolinea), tipoTransporte(tipo) {}
    virtual ~TransporteAereo() = default;
    string getTipo() { return tipoTransporte; }
};

class OVNI : public TransporteAereo {
public:
    OVNI(string mat, string aerolinea) : TransporteAereo(mat, aerolinea, "OVNI") {}
    string getMatriculaOVNI() { return matricula; }
    string getAerolineaOVNI() { return nombreAerolinea; }
};

class Avion : public TransporteAereo {
public:
    Avion(string mat, string aerolinea) : TransporteAereo(mat, aerolinea, "Avion") {}
    string getMatriculaAvion() { return matricula; }
    string getAerolineaAvion() { return nombreAerolinea; }
};

class Aeropuerto {
private:
    string nombre = "John F. Kennedy International Airport";
    TransporteAereo* EspacioAereo[5];
    Clima climaActual;

public:
    Aeropuerto() {
        for (int i = 0; i < 5; ++i) {
            EspacioAereo[i] = nullptr;
        }
    }

    Clima getClimaActual(){
    return climaActual;}
    
    void reporteClima(){
    cout<<"El tiempo actual es "<<climaActual.getTiempo();}
    





    void añadir(TransporteAereo* transporteCreado) {
    bool espacioEncontrado = false;  // Variable para indicar si encontramos un espacio vacío.
    
    for (int i = 0; i < 5; ++i) {
        if (EspacioAereo[i] == nullptr) {
            cout << "Espacio Disponible en la posición " << i << endl;
            EspacioAereo[i] = transporteCreado;  // Añadir el nuevo transporte.
            espacioEncontrado = true;
            return;
        }
    }

    // Si no se encontró espacio vacío, reemplaza el transporte más antiguo
    cout << "Espacio aéreo lleno. Reemplazando el transporte más antiguo..." << endl;
    delete EspacioAereo[0];  // Libera la memoria del primer elemento.
    for (int i = 1; i < 5; ++i) {
        EspacioAereo[i - 1] = EspacioAereo[i];  // Mueve los elementos hacia adelante.
    }
    EspacioAereo[4] = transporteCreado;  // Añade el nuevo transporte al final.
}



    string getAeropuerto() { return nombre; }

    void creadorTransporteAereo() {
        string matriculasAvion[75] = {"SEJEI4", "FQ3S4K", "G1B3H4", "GWCTHV", "E655U6", "74O928", "MTECJK", "ENV0MN", "WKS6UR", "3QDDT7", 
                                      "PRWFZH", "UII9SL", "7VH01S", "P2TFGY", "Y2ZU3I", "EJE6NL", "G708VM", "K7W197", "6V900U", "4CI3QN", 
                                      "JWDZW5", "SZ0TEM", "T123NO", "OT4JOA", "IDQDPP", "OE7SWJ", "FCKNAX", "7H8LSA", "64J8NW", "6PAV8A", 
                                      "DH35WR", "1PPS0R", "ZMNDE6", "K5Y0B5", "0PZ8LO", "5923C3", "9XME7P", "45QDWW", "C2CYC0", "V1XDAN", 
                                      "J9NM06", "NHCZLI", "IJ4AXD", "BRJCZ8", "VCAR5F", "STGK1F", "E1QYZC", "P2E52N", "RMWPCD", "B6DTL7", 
                                      "SKVCPE", "91TJ26", "8EF6ZU", "M5NNRB", "S7Z6YW", "QII55L", "FAQS3S", "BMU0KY", "KVPCN3", "UV7RYT", 
                                      "HF8NEE", "0GY3KW", "JCK36Q", "OUYV94", "X6NP6G", "7MAD53", "KN4XML", "9JUIAY", "O9QZPK", "SDOXLB", 
                                      "R9ED9R", "ID0XNQ", "8YQVB0", "L1IRYJ", "C5SEB2"};

        string aerolineasAvion[75] = {"Air China", "Air France", "Air New Zealand", "Air Serbia", "Air Senegal", "Asiana Airlines", "Austrian Airlines", 
                                      "Azores Airlines", "Brussels Airlines", "Cayman Airways", "China Eastern Airlines", "Eastern Airlines", 
                                      "EgyptAir", "EVA Air", "Flair Airlines", "ITA Airways", "Korean Air", "Lufthansa", "Neos", "Philippine Airlines", 
                                      "Royal Air Maroc", "Saudia", "Scandinavian Airlines", "Swiss International Air Lines", "TAP Air Portugal", "Turkish Airlines", 
                                      "VivaAerobus", "Volaris", "Aeroméxico", "Air Europa", "Air India", "Avianca", "Caribbean Airlines", "China Airlines", 
                                      "Copa Airlines", "Delta Air Lines", "El Al", "Emirates", "Etihad Airways", "Hawaiian Airlines", "Kenya Airways", "KLM", 
                                      "LATAM", "Singapore Airlines", "Uzbekistan Airways", "Virgin Atlantic", "WestJet", "XiamenAir", "Cape Air", "JetBlue", 
                                      "Aer Lingus", "Air Canada", "Alaska Airlines", "All Nippon Airways", "Condor", "Ethiopian Airlines", "Frontier Airlines", 
                                      "HiSky Europe", "Icelandair", "Kuwait Airways", "LOT Polish Airlines", "Norse Atlantic Airways", "Sun Country Airlines", 
                                      "Ukraine International Airlines", "American Airlines", "British Airways", "Cathay Pacific", "China Southern", "Finnair", 
                                      "Iberia", "Japan Airlines", "Level", "Qantas", "Qatar Airways", "Royal Jordanian"};
        string matriculasOVNI[3] = {"ElonMusk", "JeffBezos", "RichardBranson"};
        string aerolineasOVNI[3] = {"SpaceX", "Blue Origin", "Virgin Galactic"};
        
        int generaAvion = generarNum1al100();
        if (generaAvion <= 15) {
            
        int probabilidad = generarNum1al100();
        if (probabilidad <= 5) {
            int setter = rand() % 3;
            OVNI* ufo = new OVNI(matriculasOVNI[setter], aerolineasOVNI[setter]);
            añadir(ufo);
        } else {
            int setter = rand() % 75;
            Avion* avion = new Avion(matriculasAvion[setter], aerolineasAvion[setter]);
            añadir(avion);
        }
        }
    }

    void print() {
        for (int i = 0; i < 5; ++i) {
            if (EspacioAereo[i] == nullptr)
            continue;
            if (EspacioAereo[i]->getTipo() == "Avion") {
                Avion* avion = static_cast<Avion*>(EspacioAereo[i]);
                cout << "Avión: " << avion->getMatriculaAvion() << " de: " << avion->getAerolineaAvion() << endl;
            } else if (EspacioAereo[i]->getTipo() == "OVNI") {
                OVNI* ovni = static_cast<OVNI*>(EspacioAereo[i]);
                cout << "OVNI: " << ovni->getMatriculaOVNI() << " de: " << ovni->getAerolineaOVNI() << endl;
            }
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    Aeropuerto aeropuerto;
    cout << "Inicia operaciones el " << aeropuerto.getAeropuerto() << endl;
    string input;
    while (true) {
        aeropuerto.getClimaActual().setTiempo();
        aeropuerto.reporteClima();
        aeropuerto.creadorTransporteAereo();
        aeropuerto.print();
        cin >> input;
        if (input == "fin") {
            cout << "Cierra operaciones el " << aeropuerto.getAeropuerto() << endl;
            break;
        }
    }
    return 0;
}
