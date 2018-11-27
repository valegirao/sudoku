

#include "SudokuImpl.h"

using namespace std;

SudokuImpl::SudokuImpl(int size, int num_hints) {
    this->size = size;
    //Creamos nuestra matriz
    matrix = new int*[size*size];
    for(int x = 0;x < size*size;x++){
        matrix[x] = new int[size*size];
    }

    //Llenamos la matrix con 0s (esto va a equivaler al espacio vacio)
    for(int x = 0;x < size*size;x++){
        for(int y = 0;y < size*size;y++){
            matrix[x][y] = 0;
        }
    }

    //Llenamos la matriz al azar @num_hints de numeros iniciales
    fill_random_init(num_hints);
}

bool SudokuImpl::eval_insert(int row, int col, int eval_num) {
    if(eval_num == 0)
        return false;

    for(int x = 0;x < size*size;x++){
        if(matrix[x][col] == eval_num)
            return false;
    }

    for(int y = 0;y < size*size;y++){
        if(matrix[row][y] == eval_num)
            return false;
    }

    int pos_x = row % size;
    int pos_y = col % size;

    int x = row - (size - pos_x);
    x = x < 0 ? 0 : x;
    int y = col - (size - pos_y);
    y = y < 0 ? 0 : y;

    for(;x < row - (size - pos_x) + size;x++){
        for(;y < col - (size - pos_y) + size;y++){
            if(matrix[x][y] == eval_num)
                return false;
        }
    }

    return true;
}

void SudokuImpl::insert_num(int row, int col, int num) {
    matrix[row][col] = num;

}

bool SudokuImpl::is_done() {
    for(int x = 0;x < size*size;x++){
        for(int y = 0;y < size*size;y++){
            if(matrix[x][y] == 0)
                return false;
        }
    }
    return true;
}

SudokuImpl::~SudokuImpl() {
    delete [] matrix;
}

void SudokuImpl::print() {
    int bar_x = size + 1;
    int bar_y = size +1;
    bool update_bar_x = false;
    bool write = false;
    for(int x = 0, x_mat = 0;x < size*size + 2 + (size-1);x++) {
        for (int y = 0, y_mat = 0; y < size * size + 2 + (size - 1); y++) {

            //Imprime la barrera superior e inferior del tablero
            if (x == 0 || x == size * size + 2 - 1 + size) {
                cout << "**";
                continue;
            } else if (x == bar_x) {
                cout << "**";
                update_bar_x = true;
                continue;
            }

                //Imprime las barreras laterales del tablero
            else if (y == 0 || y == size * size + 2 + 1) {
                cout << "* ";
                continue;
            } else if (y == bar_y) {
                bar_y += size + 1;
                cout << "* ";
                continue;
            } else {

                if (matrix[x_mat][y_mat] == 0)
                    cout << " ";
                else
                    cout << matrix[x_mat][y_mat];
                cout << " ";
                y_mat++;
                write = true;
            }

        }
        if (write){
            x_mat++;
            write = false;
        }
        bar_y = size+1;

        if(update_bar_x) {
            bar_x += size+1;
            update_bar_x = false;
        }
        cout << endl;
    }
}

void SudokuImpl::fill_random_init(int num_hints) {
    for(int x = 0;x < num_hints;x++){
        int pos_x = rand() % (size*size -1);
        int pos_y = rand() % (size*size -1);

        int num = rand() % (size*size+1);

        while(!eval_insert(pos_x, pos_y, num)){
            pos_x = rand() % (size*size-1);
            pos_y = rand() % (size*size-1);
            num = rand() % (size*size+1);
        }
        insert_num(pos_x, pos_y, num);
    }
}
