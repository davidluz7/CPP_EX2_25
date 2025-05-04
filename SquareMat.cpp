#include "SquareMat.hpp"

using namespace MatrixNS;

// Constructors
SquareMat::SquareMat(size_t n) : size(n), mat(n, std::vector<double>(n, 0.0)) {}

SquareMat::SquareMat(const std::vector<std::vector<double>>& values) {
    if (values.empty()) throw std::invalid_argument("Matrix must not be empty.");
    size_t n = values.size();
    for (const auto& row : values)
        if (row.size() != n) throw std::invalid_argument("Matrix must be square (equal rows and columns).");
    size = n;
    mat = values;
}

// Access
std::vector<double>& SquareMat::operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range.");
    return mat[index];
}
const std::vector<double>& SquareMat::operator[](size_t index) const {
    if (index >= size) throw std::out_of_range("Index out of range.");
    return mat[index];
}
size_t SquareMat::get_size() const { return size; }
double SquareMat::sum_elements() const {
    double sum = 0;
    for (const auto& row : mat)
        for (double val : row)
            sum += val;
    return sum;
}
void SquareMat::validate_same_size(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Matrix size mismatch.");
}

// Arithmetic Operators
SquareMat SquareMat::operator+(const SquareMat& other) const {
    validate_same_size(other);
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = mat[i][j] + other[i][j];
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    validate_same_size(other);
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = mat[i][j] - other[i][j];
    return result;
}

SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = -mat[i][j];
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = mat[i][j] * scalar;
    return result;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0) throw std::invalid_argument("Division by zero.");
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = mat[i][j] / scalar;
    return result;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    validate_same_size(other);
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            for (size_t k = 0; k < size; ++k)
                result[i][j] += mat[i][k] * other[k][j];
    return result;
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    validate_same_size(other);
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = mat[i][j] * other[i][j];
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = static_cast<int>(mat[i][j]) % scalar;
    return result;
}

SquareMat& SquareMat::operator+=(const SquareMat& other) {
    validate_same_size(other);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            mat[i][j] += other[i][j];
    return *this;
}

SquareMat& SquareMat::operator-=(const SquareMat& other) {
    validate_same_size(other);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            mat[i][j] -= other[i][j];
    return *this;
}

SquareMat& SquareMat::operator*=(double scalar) {
    for (auto& row : mat)
        for (auto& val : row)
            val *= scalar;
    return *this;
}

SquareMat& SquareMat::operator/=(double scalar) {
    if (scalar == 0) throw std::invalid_argument("Division by zero.");
    for (auto& row : mat)
        for (auto& val : row)
            val /= scalar;
    return *this;
}

SquareMat& SquareMat::operator%=(int scalar) {
    for (auto& row : mat)
        for (auto& val : row)
            val = static_cast<int>(val) % scalar;
    return *this;
}

// Power
SquareMat SquareMat::operator^(int power) const {
    if (power < 0) throw std::invalid_argument("Negative powers not supported.");
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        result[i][i] = 1.0;
    SquareMat base = *this;
    while (power) {
        if (power % 2 == 1) result = result * base;
        base = base * base;
        power /= 2;
    }
    return result;
}

// Increment and Decrement
SquareMat& SquareMat::operator++() {
    for (auto& row : mat)
        for (auto& val : row)
            ++val;
    return *this;
}

SquareMat SquareMat::operator++(int) {
    SquareMat temp = *this;
    for (auto& row : mat)
        for (auto& val : row)
            val++;
    return temp;
}

SquareMat& SquareMat::operator--() {
    for (auto& row : mat)
        for (auto& val : row)
            --val;
    return *this;
}

SquareMat SquareMat::operator--(int) {
    SquareMat temp = *this;
    for (auto& row : mat)
        for (auto& val : row)
            --val;
    return temp;
}

// Comparison
bool SquareMat::operator==(const SquareMat& other) const {
    return mat == other.mat;
}

bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

bool SquareMat::operator>(const SquareMat& other) const {
    return sum_elements() > other.sum_elements();
}

bool SquareMat::operator<(const SquareMat& other) const {
    return sum_elements() < other.sum_elements();
}

bool SquareMat::operator>=(const SquareMat& other) const {
    return !(*this < other);
}

bool SquareMat::operator<=(const SquareMat& other) const {
    return !(*this > other);
}

// Determinant
double SquareMat::operator!() const {
    std::vector<std::vector<double>> m = mat;
    int n = m.size();
    double det = 1.0;
    int swap_count = 0;

    for (int i = 0; i < n; ++i) {
        // חפש את האיבר עם הערך המוחלט הגדול ביותר לעמודה i (pivot)
        int pivot = i;
        for (int j = i + 1; j < n; ++j)
            if (std::abs(m[j][i]) > std::abs(m[pivot][i]))
                pivot = j;

        // אם האיבר על האלכסון הוא אפס, הדטרמיננטה אפס
        if (std::abs(m[pivot][i]) < 1e-9) return 0.0;

        if (pivot != i) {
            std::swap(m[i], m[pivot]);
            swap_count++;
        }

        det *= m[i][i];
        for (int j = i + 1; j < n; ++j) {
            double factor = m[j][i] / m[i][i];
            for (int k = i; k < n; ++k)
                m[j][k] -= factor * m[i][k];
        }
    }

    return (swap_count % 2 == 0 ? det : -det);
}

// Transpose
SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[j][i] = mat[i][j];
    return result;
}

// Output operator
std::ostream& MatrixNS::operator<<(std::ostream& os, const SquareMat& m) {
    for (size_t i = 0; i < m.get_size(); ++i) {
        for (size_t j = 0; j < m.get_size(); ++j) {
            os << m[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

