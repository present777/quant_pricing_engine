#pragma once

#include "Payoff.hpp"

class VanillaOption {
private:
    double expiry;
    const Payoff& payoff;
public:
    VanillaOption(double expiry_, const Payoff& payoff_);
    
    double getExpiry() const;
    
    double optionPayoff(double spot) const;
    
    const Payoff& getPayoff() const;
};