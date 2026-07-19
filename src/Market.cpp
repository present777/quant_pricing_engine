#include "../include/Market.hpp"

Market::Market(double S_,double r_,double sigma_):S(S_),r(r_),sigma(sigma_){};

double Market::getSpot() const{ return S;};
double Market::getRate() const{ return r;};
double Market::getVol() const{ return sigma;};