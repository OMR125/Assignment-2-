// File: task 2
// Purpose: perform operations on two big real numbers


// Author: omar mahfouz mohammed
// Section: s3/4
// ID: 20220229
// TA: belal tarek
// Date: nov 4 2023

// Author: medhat ahmed abdelkarim
// Section: s3/4
// ID: 20220456
// TA: belal tarek
// Date: nov 4 2023

//--------------------------------------------------------------------//
#include <bits./stdc++.h>
#include "BigReal.h"
using namespace std;
int main() {
    BigReal n1;
    BigReal n2("13.0000456");
    cin>>n1;
    n2+=n1;
    n1-=BigReal("139088.9008");
    BigReal n3 = n1 + n2;
    n3=n3-n1;
    cout << ++n1<<" "<<++n2<<" "<<--n3;
}
