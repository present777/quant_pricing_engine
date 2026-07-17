#pragma once

#include "VanillaOption.hpp"
#include <vector>
#include <cmath>

inline double BinomialTreePrice(const VanillaOption& option,double S,double r,double sigma,int steps){
    double T=option.getExpiry();
    double dt=T/steps;

    double u=std::exp(sigma*std::sqrt(dt));
    double d=1.0/u;
    double p=(std::exp(r*dt)-d)/(u-d);
    double discount=std::exp(-r*dt);

    std::vector<double> values(steps+1);

    for(int i=0;i<=steps;++i){
        double S_T=S*std::pow(u,steps-i)*std::pow(d,i);
        values[i]=option.optionPayoff(S_T);
    }

    for(int step=steps-1;step>=0;--step){
        for(int i=0;i<=step;++i){
            values[i]=discount*(p*values[i]+(1.0-p)*values[i+1]);
        }
    }

    return values[0];

}