#include <iostream>
#include "SudokuImpl.h"



using namespace std;
int main() {
    srand(time(NULL));
    while(true) {
        int opcion, size, hints = 10;
        cout << "[___Sudoku__]" << endl;
        cout << "1. 4x4 " << endl;
        cout << "2. 3x3 " << endl;
        cout << "3. 2x2 " << endl;
        cout << "-1. Salir" << endl;

        cout << "Escoge: ";
        cin >> opcion;
        size = opcion == 1 ? 4 : opcion == 2 ? 3 : opcion == 3 ? 2 : -1;
        cout << endl;
        if(opcion == -1)
            return 0;

        bool end_hints = true;
        while (end_hints) {
            cout << "Cantidad de hints para rellenar(-1 para default): ";
            cin >> hints;
            cout << endl;
            if (hints < size * size * size * size && hints != 0 && hints > -2)
                end_hints = false;
        }
        SudokuImpl sudoku(size, hints);
        while(!sudoku.is_done()){
            sudoku.print();
            cout << endl;

            int x, y, num;
            cout << "Pos x: ";
            cin >> x;
            cout << endl;

            cout << "Pos y: ";
            cin >> y;
            cout << endl;

            cout << "Numero: ";
            cin >> num;
            cout << endl;

            if(x >= size*size || y >= size*size || x < 0 || y < 0 || !sudoku.eval_insert(x, y, num)) {
                cout << "Movimiento invalido" << endl;
                continue;
            }
            sudoku.insert_num(x, y, num);

        }
        cout << "Ganaste!" << endl;
    }
    return 0;
}
