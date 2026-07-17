#pragma once

class Market{
private:
    double S;
    double r;
    double sigma;

public:
    Market(double S_,double r_,double sigma_):S(S_),r(r_),sigma(sigma_){}

    double getSpot() const{ return S;}
    double getRate() const{ return r;}
    double getVol() const{ return sigma;}
};
