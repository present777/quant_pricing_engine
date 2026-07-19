#pragma once

#include "VanillaOption.hpp"
#include "Market.hpp"

double MonteCarloPrice(const VanillaOption& option, const Market& market, int num_paths);