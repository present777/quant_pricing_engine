#include "../include/VanillaOption.hpp"

VanillaOption::VanillaOption(double expiry_, const Payoff& payoff_) 
    : expiry(expiry_), payoff(payoff_) {}

double VanillaOption::getExpiry() const { 
    return expiry; 
}

double VanillaOption::optionPayoff(double spot) const {
    return payoff(spot);
}

const Payoff& VanillaOption::getPayoff() const {
    return payoff;
}