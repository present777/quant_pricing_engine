#pragma once

#include "Payoff.hpp"

class VanillaOption{
private:
    double expiry;

    const Payoff& payoff;
public:
    VanillaOption(double expiry_,const Payoff& payoff_):expiry(expiry_),payoff(payoff_){}

    double getExpiry() const{ return expiry; }

    double optionPayoff(double spot) const{
        return payoff(spot);
    }
};