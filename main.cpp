#include <iostream>
using namespace std;

const int MAX_PRODOTTI = 50;

// parte 1
void caricaMagazzino(int magazzino[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Quantità del prodotto " << i << ": ";
        cin >> magazzino[i];
    }
}

void visualizzaStato(int magazzino[], int n) {
    cout << "\n--- STATO MAGAZZINO ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Prodotto " << i << ": " << magazzino[i] << " pezzi\n";
    }
}

int calcolaTotale(int magazzino[], int n) {
    int totale = 0;
    for (int i = 0; i < n; i++) {
        totale += magazzino[i];
    }
    return totale;
}

// parte 2
int prodottoScarsita(int magazzino[], int n) {
    int indiceMin = 0;
    for (int i = 1; i < n; i++) {
        if (magazzino[i] < magazzino[indiceMin]) {
            indiceMin = i;
        }
    }
    return indiceMin;
}

void sottoScorta(int magazzino[], int n, int soglia) {
    cout << "\nProdotti sotto la soglia (" << soglia << "):\n";
    for (int i = 0; i < n; i++) {
        if (magazzino[i] < soglia) {
            cout << "Prodotto " << i << " (" << magazzino[i] << " pezzi)\n";
        }
    }
}

double mediaPezzi(int magazzino[], int n) {
    return static_cast<double>(calcolaTotale(magazzino, n)) / n;
}

// parte 3
void vendiProdotto(int magazzino[], int indice, int quantita) {
    if (indice < 0 || indice >= MAX_PRODOTTI) {
        cout << "Indice non valido!\n";
        return;
    }
    if (magazzino[indice] >= quantita) {
        magazzino[indice] -= quantita;
        cout << "Vendita effettuata.\n";
    } else {
        cout << "Errore: quantità non disponibile!\n";
    }
}

void rifornimento(int magazzino[], int indice, int quantita) {
    if (indice < 0 || indice >= MAX_PRODOTTI) {
        cout << "Indice non valido!\n";
        return;
    }
    magazzino[indice] += quantita;
    cout << "Rifornimento completato.\n";
}

int main() {
    int n;
    int magazzino[MAX_PRODOTTI];

    cout << "Quanti prodotti vuoi inserire? (max 50): ";
    cin >> n;

    if (n < 1 || n > MAX_PRODOTTI) {
        cout << "Numero non valido!";
        return 0;
    }

    caricaMagazzino(magazzino, n);

    int scelta;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Visualizza stato\n";
        cout << "2. Calcola totale\n";
        cout << "3. Prodotto con scarsità\n";
        cout << "4. Prodotti sotto scorta\n";
        cout << "5. Media pezzi\n";
        cout << "6. Vendi prodotto\n";
        cout << "7. Rifornimento\n";
        cout << "0. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1:
                visualizzaStato(magazzino, n);
                break;
            case 2:
                cout << "Totale pezzi: " << calcolaTotale(magazzino, n) << endl;
                break;
            case 3:
                cout << "Prodotto con meno pezzi: " << prodottoScarsita(magazzino, n) << endl;
                break;
            case 4: {
                int soglia;
                cout << "Inserisci soglia: ";
                cin >> soglia;
                sottoScorta(magazzino, n, soglia);
                break;
            }
            case 5:
                cout << "Media pezzi: " << mediaPezzi(magazzino, n) << endl;
                break;
            case 6: {
                int indice, q;
                cout << "Indice prodotto: ";
                cin >> indice;
                cout << "Quantità da vendere: ";
                cin >> q;
                vendiProdotto(magazzino, indice, q);
                break;
            }
            case 7: {
                int indice, q;
                cout << "Indice prodotto: ";
                cin >> indice;
                cout << "Quantità da aggiungere: ";
                cin >> q;
                rifornimento(magazzino, indice, q);
                break;
            }
            case 0:
                cout << "Uscita...\n";
                break;
            default:
                cout << "Scelta non valida!\n";
        }

    } while (scelta != 0);

}
