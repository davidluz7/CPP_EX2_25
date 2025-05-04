#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace MatrixNS {
    class SquareMat {
        size_t size;
        std::vector<std::vector<double>> mat;

    public:
        // Constructors
        SquareMat(size_t n);
        SquareMat(const std::vector<std::vector<double>>& values);

        // Access
        std::vector<double>& operator[](size_t index);
        const std::vector<double>& operator[](size_t index) const;
        size_t get_size() const;

        // Arithmetic
        SquareMat operator+(const SquareMat& other) const;
        SquareMat operator-(const SquareMat& other) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat& other) const;
        SquareMat operator*(double scalar) const;
        SquareMat operator/(double scalar) const;
        SquareMat operator%(const SquareMat& other) const;
        SquareMat operator%(int scalar) const;
        SquareMat operator^(int power) const;

        // Compound assignment
        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(double scalar);
        SquareMat& operator/=(double scalar);
        SquareMat& operator%=(int scalar);

        // Comparison
        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;
        bool operator<(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;

        // Other operators
        SquareMat& operator++();    // pre-increment
        SquareMat operator++(int);  // post-increment
        SquareMat& operator--();    // pre-decrement
        SquareMat operator--(int);  // post-decrement
        SquareMat operator~() const;
        double operator!() const;

    private:
        double sum_elements() const;
        double determinant_recursive(const std::vector<std::vector<double>>& m) const;
        void validate_same_size(const SquareMat& other) const;
    };

    std::ostream& operator<<(std::ostream& os, const SquareMat& m);
}