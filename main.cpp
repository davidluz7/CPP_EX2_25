#include "SquareMat.hpp"
#include <iostream>

using namespace MatrixNS;
using namespace std;

int main() {
    try {
        cout << "Creating 2x2 matrices A and B...\n";
        SquareMat A({{1, 2}, {3, 4}});
        SquareMat B({{5, 6}, {7, 8}});

        cout << "Matrix A:\n" << A;
        cout << "Matrix B:\n" << B;

        cout << "A + B:\n" << (A + B);
        cout << "A - B:\n" << (A - B);
        cout << "-A:\n" << (-A);

        cout << "A * B:\n" << (A * B);
        cout << "A * 2:\n" << (A * 2);
        cout << "A % B (element-wise):\n" << (A % B);
        cout << "A % 3 (modulo scalar):\n" << (A % 3);

        cout << "A / 2:\n" << (A / 2);

        cout << "Transpose of A:\n" << (~A);
        cout << "Determinant of A: " << !A << "\n";

        cout << "Power: A^2:\n" << (A ^ 2);

        cout << "Incrementing A...\n";
        ++A;
        cout << A;

        cout << "Decrementing A...\n";
        A--;
        cout << A;

        cout << "Comparison: A == B? " << (A == B) << "\n";
        cout << "Comparison: A != B? " << (A != B) << "\n";
        cout << "Comparison: A > B? " << (A > B) << "\n";

        cout << "Accessing A[0][1]: " << A[0][1] << "\n";
        A[0][1] = 10;
        cout << "Updated A:\n" << A;

        cout << "Using compound assignment operators...\n";
        A += B;
        A -= B;
        A *= 2;
        A /= 2;
        A %= 5;
        cout << "Final A:\n" << A;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
