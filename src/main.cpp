#include <iostream>

#include "../include/Payoff.hpp"
#include "../include/VanillaOption.hpp"
#include "../include/BlackScholes.hpp"
#include "../include/MonteCarlo.hpp"
#include "../include/BinomialTree.hpp"
#include "../include/Greeks.hpp"

int main(){
    double S=100.0;
    double K=100.0;
    double r=0.05;
    double sigma=0.2;
    double T=1.0;

    PayoffCall call_payoff(K);
    VanillaOption call_option(T,call_payoff);

    PayoffPut put_payoff(K);
    VanillaOption put_option(T,put_payoff);

    int num_paths=1000000;
    int steps=1000;

    double bs_call=blackscholesPrice(call_option,S,r,sigma);
    double mc_call=MonteCarloPrice(call_option,S,r,sigma,num_paths);
    double bt_call=BinomialTreePrice(call_option,S,r,sigma,steps);

    double bs_put=blackscholesPrice(put_option,S,r,sigma);
    double mc_put=MonteCarloPrice(put_option,S,r,sigma,num_paths);
    double bt_put=BinomialTreePrice(put_option,S,r,sigma,steps);

    double delta_call=calDelta(call_option,S,r,sigma);
    double gamma_call=calGamma(call_option,S,r,sigma);
    double vega_call=calVega(call_option,S,r,sigma);

    double delta_put=calDelta(put_option,S,r,sigma);
    double gamma_put=calGamma(put_option,S,r,sigma);
    double vega_put=calVega(put_option,S,r,sigma);

    std::cout<<"Black-Scholes Call Price: "<< bs_call <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Monte Carlo Call Price: "<< mc_call <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Binomial Tree Call Price: "<< bt_call <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Call Delta: "<< delta_call <<std::endl;
    std::cout<<"Call Gamma: "<< gamma_call <<std::endl;
    std::cout<<"Call Vega: "<< vega_call <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Black-Scholes Put Price: "<< bs_put <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Monte Carlo Put Price: "<< mc_put <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Binomial Tree Put Price: "<< bt_put <<std::endl;
    std::cout << "========================================" << std::endl;
    std::cout<<"Put Delta: "<< delta_put <<std::endl;
    std::cout<<"Put Gamma: "<< gamma_put <<std::endl;
    std::cout<<"Put Vega: "<< vega_put <<std::endl;

    return 0;
}