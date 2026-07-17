#include <iostream>

#include "../include/Payoff.hpp"
#include "../include/VanillaOption.hpp"
#include "../include/BlackScholes.hpp"

int main(){
    double S=100.0;
    double K=100.0;
    double r=0.05;
    double sigma=0.2;
    double T=1.0;

    double bs_price=blackscholesCallPrice(S,K,r,T,sigma);

    std::cout<<"Black-Scholes Call Price: "<< bs_price <<std::endl;

    return 0;
}