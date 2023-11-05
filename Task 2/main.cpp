// File: Task 2
// Purpose: perform operations on two big real numbers

// Author: Omar Mahfouz Mohammed
// Section: S3/4
// ID: 20220229
// TA: Belal Tarek
// Date: Nov 4 2023

// Author: Medhat Ahmed Abdelkarim
// Section: S3/4
// ID: 20220456
// TA: Belal Tarek
// Date: Nov 4 2023

//--------------------------------------------------------------------//
#include <bits./stdc++.h>
#include "BigReal.h"

using namespace std;

int main() {
    BigReal a("0.1243546000");
    BigReal b;
    b.setNum("-999999999999999999999999999999.99999999999");
    BigReal c = b;
    BigReal d = c + a;
    BigReal e = a - d;
    e += BigReal("-503429.7832");
    d -= BigReal("-91213.00000003");
    cout << --e << " " << ++d << "\n";
    cout << (e > d) << " " << (a == b) << " " << (c != c) << "\n";
}
