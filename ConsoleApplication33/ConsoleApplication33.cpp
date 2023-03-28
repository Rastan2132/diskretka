#include "Header.h"

int main() {
    string input;
    cout << "Podaj rownanie logiczne z trzema zmiennymi (q, r, p): ";
    getline(cin, input);

    bool found = false;

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                bool result = Bool_logics(static_cast<bool>(i), static_cast<bool>(j), static_cast<bool>(k), input);
                if (result) {
                    found = true;
                    cout << "Tautologia dla wartosci: q=" << j << ", r=" << k << ", p=" << i << endl;
                }
            }
        }
    }

    if (!found) {
        cout << "Rownanie nie jest tautologia." << endl;
    }

    return 0;
}
