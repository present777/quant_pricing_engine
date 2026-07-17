#pragma once

#include<algorithm>

enum class OptionType{Call,Put};

class Payoff{
public:
    virtual ~Payoff()=default;

    virtual double operator()(double spot) const = 0;
    virtual OptionType getType() const = 0;
    virtual double getStrike() const = 0;
};

class PayoffCall:public Payoff{
private:
    double strike;
public:
    PayoffCall(double strike_):strike(strike_){}

    double operator()(double spot) const override{
        return std::max(spot-strike,0.0);
    }

    OptionType getType() const override{
        return OptionType::Call;
    }

    double getStrike() const override{
        return strike;
    }
};

class PayoffPut:public Payoff{
private:
    double strike;
public:
    PayoffPut(double strike_):strike(strike_){}

    double operator()(double spot) const override{
        return std::max(strike-spot,0.0);
    }

    OptionType getType() const override{
        return OptionType::Put;
    }

    double getStrike() const override{
        return strike;
    }
};