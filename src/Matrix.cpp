#include"Matrix.h"
#include"iostream"

Matrix::Matrix(int row, int col): _row(row), _col(col) {
    int elem_cnt = _row * _col;
    _pmat = new double[elem_cnt];
    fill_mat();
}

Matrix::Matrix(const Matrix& rhs): _row(rhs._row), _col(rhs._col){
int elem_cnt = _row * _col;
_pmat = new double[elem_cnt];
for(int ix = 0; ix<elem_cnt; ++ix){
    _pmat[ix] = rhs._pmat[ix];
}
}

Matrix::~Matrix()
{
}

void Matrix::display(){
    int elem_cnt = _row * _col;
    for(int i=0; i<_row; ++i){
        for(int j=0; j<_col; ++j){
        std::cout<<_pmat[i*_col + j]<<" ";
        }
        std::cout<<std::endl;
    }

}

void Matrix::fill_mat(int val){
    int elem_cnt = _row * _col;
    for(int ix = 0; ix<elem_cnt; ++ix){
        _pmat[ix] = val;
    }
}
