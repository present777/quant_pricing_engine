#pragma once

#include <cmath>

inline double normCDF(double x){
    return 0.5*std::erfc(-x/std::sqrt(2));
}

inline double blackscholesCallPrice(double S,double K,double r,double T,double sigma){
    double d1=(std::log(S/K)+(r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    
    double d2=d1-sigma*std::sqrt(T);
    
    return S*normCDF(d1)-K*std::exp(-r*T)*normCDF(d2);
}