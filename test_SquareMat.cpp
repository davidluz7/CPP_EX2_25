//doodluz7@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
using namespace MatrixNS;

TEST_CASE("Invalid matrix sizes throw") {
    CHECK_THROWS(SquareMat({{1, 2}, {3}}));
    CHECK_THROWS(SquareMat(std::vector<std::vector<double>>{}));
}

TEST_CASE("Addition and subtraction") {
    SquareMat m1({{1, 2}, {3, 4}});
    SquareMat m2({{5, 6}, {7, 8}});
    CHECK((m1 + m2)[0][0] == 6);
    CHECK((m2 - m1)[1][1] == 4);
}

TEST_CASE("Unary minus") {
    SquareMat m({{1, -2}, {3, -4}});
    SquareMat neg = -m;
    CHECK(neg[0][0] == -1);
    CHECK(neg[0][1] == 2);
}

TEST_CASE("Multiplication by scalar") {
    SquareMat m({{1, 2}, {3, 4}});
    SquareMat result = m * 2.0;
    CHECK(result[0][0] == 2);
    CHECK(result[1][1] == 8);
}

TEST_CASE("Matrix multiplication") {
    SquareMat m1({{1, 2}, {3, 4}});
    SquareMat m2({{2, 0}, {1, 2}});
    SquareMat result = m1 * m2;
    CHECK(result[0][0] == 4);
    CHECK(result[0][1] == 4);
    CHECK(result[1][0] == 10);
    CHECK(result[1][1] == 8);
}

TEST_CASE("Transpose") {
    SquareMat m({{1, 2}, {3, 4}});
    SquareMat t = ~m;
    CHECK(t[0][1] == 3);
    CHECK(t[1][0] == 2);
}

TEST_CASE("Comparison operators") {
    SquareMat m1({{1, 2}, {3, 4}});
    SquareMat m2({{1, 2}, {3, 4}});
    SquareMat m3({{5, 6}, {7, 8}});
    CHECK(m1 == m2);
    CHECK(m1 != m3);
    CHECK(m3 > m1);
    CHECK(m1 <= m2);
}

TEST_CASE("Increment and decrement") {
    SquareMat m({{1, 2}, {3, 4}});
    ++m;
    CHECK(m[0][0] == 2);
    m--;
    CHECK(m[0][0] == 1);
}

TEST_CASE("Power and determinant") {
    SquareMat m({{1, 2}, {3, 4}});
    SquareMat m_squared = m ^ 2;
    CHECK(m_squared[0][0] == 7);
    CHECK(m_squared[0][1] == 10);
    CHECK(m_squared[1][0] == 15);
    CHECK(m_squared[1][1] == 22);
    CHECK((!m) == doctest::Approx(-2.0));
}

TEST_CASE("Element-wise multiplication") {
    SquareMat m1({{1, 2}, {3, 4}});
    SquareMat m2({{5, 6}, {7, 8}});
    SquareMat result = m1 % m2;
    CHECK(result[0][0] == 5);
    CHECK(result[1][1] == 32);
}

TEST_CASE("Modulo with scalar") {
    SquareMat m({{5, 6}, {7, 8}});
    SquareMat result = m % 5;
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 1);
    CHECK(result[1][0] == 2);
}

TEST_CASE("Division by scalar") {
    SquareMat m({{2, 4}, {6, 8}});
    SquareMat result = m / 2;
    CHECK(result[0][0] == 1);
    CHECK(result[1][1] == 4);
    CHECK_THROWS(m / 0);
}

TEST_CASE("Compound assignment operators") {
    SquareMat m({{1, 2}, {3, 4}});
    SquareMat a({{1, 1}, {1, 1}});
    m += a;
    CHECK(m[0][0] == 2);
    m -= a;
    CHECK(m[0][0] == 1);
    m *= 2;
    CHECK(m[0][0] == 2);
    m /= 2;
    CHECK(m[0][0] == 1);
    m %= 2;
    CHECK(m[0][0] == 1);
}

TEST_CASE("Index access") {
    SquareMat m(2);
    m[0][0] = 7;
    m[1][1] = 9;
    CHECK(m[0][0] == 7);
    CHECK(m[1][1] == 9);
    CHECK_THROWS(m[2][0]);
}
