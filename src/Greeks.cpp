#include "../include/Greeks.hpp"
#include "../include/BlackScholes.hpp"

double calDelta(const VanillaOption& option, const Market& market, double dS_ratio) {
    double S = market.getSpot();
    double r = market.getRate();
    double sigma = market.getVol();

    double actual_dS = S*dS_ratio;

    Market env_up(S + actual_dS, r, sigma);
    Market env_down(S - actual_dS, r, sigma);
    
    double price_up = blackscholesPrice(option, env_up);
    double price_down = blackscholesPrice(option, env_down);

    return (price_up - price_down) / (2.0 * actual_dS);
}

double calGamma(const VanillaOption& option, const Market& market, double dS_ratio) {
    double S = market.getSpot();
    double r = market.getRate();
    double sigma = market.getVol();

    double actual_dS = S*dS_ratio;

    Market env_up(S + actual_dS, r, sigma);
    Market env_down(S - actual_dS, r, sigma);
    
    double price_up = blackscholesPrice(option, env_up);
    double price_mid = blackscholesPrice(option, market);
    double price_down = blackscholesPrice(option, env_down);

    return (price_up - 2.0 * price_mid + price_down) / (actual_dS * actual_dS);
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