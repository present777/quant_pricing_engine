#include "../include/BinomialTree.hpp"

#include <vector> 
#include <cmath>
#include <stdexcept>

double BinomialTreePrice(const VanillaOption& option, const Market& market, int steps) {
    double T = option.getExpiry();
    double S = market.getSpot();
    double r = market.getRate();
    double sigma = market.getVol();

    if (T <= 0.0) throw std::invalid_argument("Time to maturity (T) must be positive");
    if (sigma <= 0.0) throw std::invalid_argument("Volatility (sigma) must be positive");
    if (S <= 0.0) throw std::invalid_argument("Spot must be positive");
    if (steps <= 0) throw std::invalid_argument("Number of steps must be positive");

    double dt = T / steps;
    
    double u = std::exp(sigma * std::sqrt(dt));
    double d = 1.0 / u;
    double p = (std::exp(r * dt) - d) / (u - d);
    double discount = std::exp(-r * dt);
    
    std::vector<double> values(steps + 1);

    for(int i = 0; i <= steps; ++i) {
        double S_T = S * std::pow(u, steps - i) * std::pow(d, i);
        values[i] = option.optionPayoff(S_T);
    }
    
    for(int step = steps - 1; step >= 0; --step) {
        for(int i = 0; i <= step; ++i) {
            values[i] = discount * (p * values[i] + (1.0 - p) * values[i + 1]);
        }
    }

    return values[0];
}