#pragma once

#include "BlackScholes.hpp"

inline double calDelta(const VanillaOption& option,double S,double r,double sigma,double dS=1e-4){
    double price_up=blackscholesPrice(option,S+dS,r,sigma);
    double price_down=blackscholesPrice(option,S-dS,r,sigma);

    return (price_up-price_down)/(2.0*dS);
}

inline double calGamma(const VanillaOption& option,double S,double r,double sigma,double dS=1e-4){
    double price_up=blackscholesPrice(option,S+dS,r,sigma);
    double price_mid=blackscholesPrice(option,S,r,sigma);
    double price_down=blackscholesPrice(option,S-dS,r,sigma);

    return (price_up-2.0*price_mid+price_down)/(dS*dS);
}

inline double calVega(const VanillaOption& option,double S,double r,double sigma,double dsigma=1e-4){
    double price_up=blackscholesPrice(option,S,r,sigma+dsigma);
    double price_down=blackscholesPrice(option,S,r,sigma-dsigma);

    return(price_up-price_down)/(2.0*dsigma);
}