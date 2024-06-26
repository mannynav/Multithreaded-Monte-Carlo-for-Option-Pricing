#pragma once

#include "OptionBase.h"
#include <Eigen/Dense>
#include <map>


#ifndef EUROCALLOPTION_H
#define EUROCALLOPTION_H

class PseudoFactory;
class GreekBase;

class EuroCallOption : public OptionBase
{
public:

	EuroCallOption(double strike, double expiry) : strike_(strike), expiry_(expiry) {}
	EuroCallOption(PseudoFactory& factory);
	~EuroCallOption() = default;

	double ComputePayoff(double final_price) const override;
	Eigen::VectorXd ComputePayoffs(Eigen::MatrixXd& stock_prices) const override;
	std::map<std::string, double> ComputeGreeks(Eigen::MatrixXd& stock_prices,const ModelBase& model) const override;

private:

	double strike_{};
	double expiry_{};
};
#endif // EUROCALLOPTION_H
