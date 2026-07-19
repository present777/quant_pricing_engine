#include "../include/Payoff.hpp"
#include <algorithm>

PayoffCall::PayoffCall(double strike_) : strike(strike_) {}

double PayoffCall::operator()(double spot) const {
    return std::max(spot - strike, 0.0);
}

OptionType PayoffCall::getType() const {
    return OptionType::Call;
}

double PayoffCall::getStrike() const {
    return strike;
}

PayoffPut::PayoffPut(double strike_) : strike(strike_) {}

double PayoffPut::operator()(double spot) const {
    return std::max(strike - spot, 0.0);
}

OptionType PayoffPut::getType() const {
    return OptionType::Put;
}

double PayoffPut::getStrike() const {
    return strike;
}