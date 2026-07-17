#include <iostream>

#include "../include/Payoff.hpp"
#include "../include/VanillaOption.hpp"
#include "../include/BlackScholes.hpp"
#include "../include/MonteCarlo.hpp"
#include "../include/BinomialTree.hpp"

int main(){
    double S=100.0;
    double K=100.0;
    double r=0.05;
    double sigma=0.2;
    double T=1.0;

    PayoffCall payoff(K);
    VanillaOption option(T,payoff);

    int num_paths=1000000;
    int steps=1000;

    double bs_price=blackscholesCallPrice(S,K,r,T,sigma);
    double mc_price=MonteCarloPrice(option,S,r,sigma,num_paths);
    double bt_price=BinomialTreePrice(option,S,r,sigma,steps);

    std::cout<<"Black-Scholes Call Price: "<< bs_price <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Monte Carlo Call Price: "<< mc_price <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Binomial Tree Call Price: "<< bt_price <<std::endl;

    return 0;
}