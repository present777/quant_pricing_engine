#pragma once

class Market{
private:
    double S;
    double r;
    double sigma;

public:
    Market(double S_,double r_,double sigma_);

    double getSpot() const;
    double getRate() const;
    double getVol() const;
};
