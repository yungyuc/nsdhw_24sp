# ifndef _MATRIX_HPP
# define _MATRIX_HPP

#include<iostream>
#include<vector>
#include<stdexcept>
#include<mkl/mkl.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <pybind11/numpy.h>

class Matrix {
    public:

        Matrix(size_t nrow, size_t ncol);
        Matrix(size_t nrow, size_t ncol, std::vector<double> const & vec);
        // Matrix & operator=(std::vector<double> const & vec);
        Matrix(Matrix const & other);
        // Matrix & operator=(Matrix const & other);
        // Matrix(Matrix && other);
        // Matrix & operator=(Matrix && other);

        ~Matrix();

        double   operator() (size_t row, size_t col) const;
        double & operator() (size_t row, size_t col);

        size_t nrow() const;
        size_t ncol() const;

        bool operator==(Matrix const & other) const;

        // size_t size() const { return m_nrow * m_ncol; }
        double * buffer() const;
        // std::vector<double> buffer_vector() const;
        pybind11::array_t<double> array() const;

    private:

        size_t index(size_t row, size_t col) const;
        // void reset_buffer(size_t nrow, size_t ncol);

        size_t n_row = 0;
        size_t n_col = 0;
        double * buf = nullptr;
};

Matrix multiply_naive(const Matrix &m1, const Matrix &m2);
Matrix multiply_tile(const Matrix &m1, const Matrix &m2, size_t tile_size);
Matrix multiply_mkl(const Matrix &m1, const Matrix &m2);

# endif