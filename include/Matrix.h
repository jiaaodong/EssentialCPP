#ifndef Matrix_H
#define Matrix_H
class Matrix
{
private:
    /* data */
    int _row, _col;
    double* _pmat;
public:
    Matrix(int row, int col);
    Matrix(const Matrix& rhs);
    void display();
    void fill_mat(int val = 0);
    ~Matrix();
};

#endif