#include <stdio.h>
#include <iostream>
#include <vector>
#include <complex>
#include "omp.h"
#include "qregister.hpp"

#define NUM_THREADS 4

using namespace std;

int main() {
  omp_set_num_threads(NUM_THREADS);
  QRegister qreg({{0,1}, {1,0}, {1/sqrt(2), 1/sqrt(2)}, {1/sqrt(2), -1/sqrt(2)}, {1/sqrt(2), {0,1/sqrt(2)}}});
  vector <complex<double> > result;
  result = qreg.getStateVector();
  qreg.applyQFT();

  result = qreg.getStateVector();
  cout<<"n_qbits: "<< qreg.getNumberQubits() <<endl;
  for (int i = 0; i < result.size(); i++)
    cout<<"result["<<i<<"] = "<<result[i]<<endl;
  
  return 0;
}