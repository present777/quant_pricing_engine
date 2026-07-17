#pragma once

#include <cmath>
#include "VanillaOption.hpp"
#include "Market.hpp"

inline double normCDF(double x){
    return 0.5*std::erfc(-x/std::sqrt(2));
}

inline double blackscholesCallPrice(double S,double K,double r,double T,double sigma){
    double d1=(std::log(S/K)+(r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    
    double d2=d1-sigma*std::sqrt(T);
    
    return S*normCDF(d1)-K*std::exp(-r*T)*normCDF(d2);
}

inline double blackscholesPrice(const VanillaOption& option,const Market& market){
    double K=option.getPayoff().getStrike();
    double T=option.getExpiry();
    double S=market.getSpot();
    double r=market.getRate();
    double sigma=market.getVol();
    OptionType type=option.getPayoff().getType();

    double call_price=blackscholesCallPrice(S,K,r,T,sigma);

    if(type==OptionType::Call){
        return call_price;
    }
    else{
        return call_price+K*std::exp(-r*T)-S;
    }
}
