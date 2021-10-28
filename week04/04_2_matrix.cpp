// A dynamically-allocated matrix (bidimensional array)
#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "How many rows and columns? ";
    cin >> rows;
    cin >> cols;

    // Allocate an array of pointers to 'double' values (one pointer per row)
    // we need to manuallly allocate and deallocate using pointers to pointer:
    // we allocate one array for each row and the we keep pointers to each one of the arrays

    double **a = new double*[rows]; // we create an array whose elements pointer to double --> the result is a pointer to pointer to double
    for (int i = 0; i < rows; i++) {
        // Now each row pointer points to an array of 'double' values
        a[i] = new double[cols];
    }

    // Initialise the matrix with value 0 in each cell
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = 0.0; // a is an array which contains an address; so a[i] points to the i-th element of the array, which is again an address:
            // then a[i][j] points to the j-th element which is a double
        }
    }

    // Display the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the matrix: delete each row, and then the array of pointers
    // We *cannot* begin by deleting the array of pointers!
    for (int i = 0; i < rows; i++) {
        delete[] a[i]; // delete each row
    }
    delete[] a; // finally, delete main array

    return 0;
}
