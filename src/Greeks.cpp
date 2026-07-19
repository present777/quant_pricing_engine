#include "../include/Greeks.hpp"
#include "../include/BlackScholes.hpp"

double calDelta(const VanillaOption& option, const Market& market, double dS) {
    double S = market.getSpot();
    double r = market.getRate();
    double sigma = market.getVol();

    Market env_up(S + dS, r, sigma);
    Market env_down(S - dS, r, sigma);
    
    double price_up = blackscholesPrice(option, env_up);
    double price_down = blackscholesPrice(option, env_down);

    return (price_up - price_down) / (2.0 * dS);
}

double calGamma(const VanillaOption& option, const Market& market, double dS) {
    double S = market.getSpot();
    double r = market.getRate();
    double sigma = market.getVol();

    Market env_up(S + dS, r, sigma);
    Market env_down(S - dS, r, sigma);
    
    double price_up = blackscholesPrice(option, env_up);
    double price_mid = blackscholesPrice(option, market);
    double price_down = blackscholesPrice(option, env_down);

    return (price_up - 2.0 * price_mid + price_down) / (dS * dS);
}

double calVega(const VanillaOption& option, const Market& market, double dsigma) {
    double S = market.getSpot();
    double r = market.getRate();
    double sigma = market.getVol();

    Market env_up(S, r, sigma + dsigma);
    Market env_down(S, r, sigma - dsigma);
    
    double price_up = blackscholesPrice(option, env_up);
    double price_down = blackscholesPrice(option, env_down);
    
    return (price_up - price_down) / (2.0 * dsigma);
}