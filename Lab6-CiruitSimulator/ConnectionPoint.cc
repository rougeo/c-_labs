#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

#include "ConnectionPoint.h"

using namespace std;

ConnectionPoint::ConnectionPoint(){}

void ConnectionPoint::setPotential(double value) {
  potential = value;
}

double ConnectionPoint::getPotential() {
  return potential;
}
