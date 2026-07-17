#pragma once

#include "BlackScholes.hpp"

inline double calDelta(double S,double K,double r,double T,double sigma,double dS=1e-4){
    double price_up=blackscholesCallPrice(S+dS,K,r,T,sigma);
    double price_down=blackscholesCallPrice(S-dS,K,r,T,sigma);

    return (price_up-price_down)/(2.0*dS);
}

inline double calGamma(double S,double K,double r,double T,double sigma,double dS=1e-4){
    double price_up=blackscholesCallPrice(S+dS,K,r,T,sigma);
    double price_mid=blackscholesCallPrice(S,K,r,T,sigma);
    double price_down=blackscholesCallPrice(S-dS,K,r,T,sigma);

    return (price_up-2.0*price_mid+price_down)/(dS*dS);
}

inline double calVega(double S,double K,double r,double T,double sigma,double dsigma=1e-4){
    double price_up=blackscholesCallPrice(S,K,r,T,sigma+dsigma);
    double price_down=blackscholesCallPrice(S,K,r,T,sigma-dsigma);

    return(price_up-price_down)/(2.0*dsigma);
}