#pragma once

#include "VanillaOption.hpp"
#include "Market.hpp"

double normCDF(double x);

double blackscholesCallPrice(double S, double K, double r, double T, double sigma);

double blackscholesPrice(const VanillaOption& option, const Market& market);