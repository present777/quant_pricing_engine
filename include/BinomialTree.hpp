#pragma once

#include "VanillaOption.hpp"
#include "Market.hpp"

double BinomialTreePrice(const VanillaOption& option, const Market& market, int steps);