#pragma once
#include <Eigen/Dense>
#include "OptionBase.h"

#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H

class PseudoFactory;

class AsianCallOption : public OptionBase
{
public:

	explicit AsianCallOption() = default;
	AsianCallOption(double strike, double expiry);
	AsianCallOption(const PseudoFactory& factory);

	double ComputePayoff(double final_price) const override;
	Eigen::VectorXd ComputePayoffs(Eigen::MatrixXd& stock_prices) const override;

private:

	double strike_{};
	double expiry_{};

};
#endif // ASIANCALLOPTION_H