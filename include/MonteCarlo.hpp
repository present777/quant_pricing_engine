#pragma once

#include "VanillaOption.hpp"
#include <random>
#include <cmath>
#include "Market.hpp"

inline double MonteCarloPrice(const VanillaOption& option,const Market& market,int num_paths){
    double T=option.getExpiry();
    double S=market.getSpot();
    double r=market.getRate();
    double sigma=market.getVol();

    double payoffs_sum=0.0;

    std::mt19937 generator(42);
    std::normal_distribution<double> distribution(0.0,1.0);

    const double drift=(r-0.5*sigma*sigma)*T;
    const double vol_sqrt_T=sigma*std::sqrt(T); 

    for(int i=0;i<num_paths;++i){
        double Z=distribution(generator);

        double S_T=S*std::exp(drift+vol_sqrt_T*Z);

        double payoff=option.optionPayoff(S_T);

        payoffs_sum+=payoff;
    }

    double average_payoff=payoffs_sum/num_paths;
    return std::exp(-r*T)*average_payoff;
}