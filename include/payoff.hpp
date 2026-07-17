#pragma once

#include<algorithm>

class Payoff{
public:
    virtual ~Payoff()=default;

    virtual double operator()(double spot) const = 0;
};

class PayoffCall:public Payoff{
private:
    double strike;
public:
    PayoffCall(double strike_):strike(strike_){}

    double operator()(double spot) const override{
        return std::max(spot-strike,0.0);
    }
};