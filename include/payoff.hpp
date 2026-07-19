#pragma once

enum class OptionType { Call, Put };

class Payoff {
public:
    virtual ~Payoff() = default;
    virtual double operator()(double spot) const = 0;
    virtual OptionType getType() const = 0;
    virtual double getStrike() const = 0;
};

class PayoffCall : public Payoff {
private:
    double strike;
public:
    explicit PayoffCall(double strike_);
    
    double operator()(double spot) const override;
    OptionType getType() const override;
    double getStrike() const override;
};

class PayoffPut : public Payoff {
private:
    double strike;
public:
    explicit PayoffPut(double strike_);
    
    double operator()(double spot) const override;
    OptionType getType() const override;
    double getStrike() const override;
};