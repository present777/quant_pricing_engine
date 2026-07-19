#pragma once

#include "VanillaOption.hpp"
#include "Market.hpp"

double calDelta(const VanillaOption& option, const Market& market, double dS_ratio = 1e-4);
double calGamma(const VanillaOption& option, const Market& market, double dS_ratio = 1e-4);
double calVega(const VanillaOption& option, const Market& market, double dsigma = 1e-4);