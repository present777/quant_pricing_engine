#include <iostream>

#include "../include/Payoff.hpp"
#include "../include/VanillaOption.hpp"
#include "../include/BlackScholes.hpp"
#include "../include/MonteCarlo.hpp"
#include "../include/BinomialTree.hpp"
#include "../include/Greeks.hpp"
#include "../include/Market.hpp"

int main(){
    double S=100.0;
    double K=100.0;
    double r=0.05;
    double sigma=0.2;
    double T=1.0;

    Market market(S,r,sigma);

    PayoffCall call_payoff(K);
    VanillaOption call_option(T,call_payoff);

    PayoffPut put_payoff(K);
    VanillaOption put_option(T,put_payoff);

    int num_paths=1000000;
    int steps=1000;

    double bs_call=blackscholesPrice(call_option,market);
    double mc_call=MonteCarloPrice(call_option,market,num_paths);
    double bt_call=BinomialTreePrice(call_option,market,steps);

    double bs_put=blackscholesPrice(put_option,market);
    double mc_put=MonteCarloPrice(put_option,market,num_paths);
    double bt_put=BinomialTreePrice(put_option,market,steps);

    double delta_call=calDelta(call_option,market);
    double gamma_call=calGamma(call_option,market);
    double vega_call=calVega(call_option,market);

    double delta_put=calDelta(put_option,market);
    double gamma_put=calGamma(put_option,market);
    double vega_put=calVega(put_option,market);

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