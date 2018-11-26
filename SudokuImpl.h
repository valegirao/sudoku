//
// Created by martin on 11/14/18.
//

#ifndef SUDOKU_SUDOKUIMPL_H
#define SUDOKU_SUDOKUIMPL_H

#include <iostream>
#include <vector>
#include <algorithm>
class  SudokuImpl {
private:
    int ** matrix;
    int size;
    void fill_random_init(int num_hints);
public:
    SudokuImpl(int size, int num_hints);
    ~SudokuImpl();
    bool is_done();
    bool eval_insert(int row, int col, int eval_num);
    void insert_num(int row, int col, int num);
    void print();
};


#endif //SUDOKU_SUDOKUIMPL_H
