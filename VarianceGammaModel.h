#pragma once

#include "ModelBase.h"
#include "PseudoFactory.h"
#include "RandomBase.h"

#ifndef VARIANCEGAMMAMODEL_H
#define VARIANCEGAMMAMODEL_H

class PseudoFactory;

class VarianceGammaModel : public ModelBase

{
public:
	VarianceGammaModel(double S0, double r, double sigma);
	VarianceGammaModel(PseudoFactory& factory);
	~VarianceGammaModel();
	void simulate_paths(int start_idx, int end_idx, Eigen::MatrixXd& paths) const override;

private:

	double s0_{};
	double r_{};


	double mu_Vg_{};
	double theta_{};
	double omega_{};
	double beta_{};
	double sigmaVg_{};

	double dt_{};
	double N_{};
	double T_{};

	RandomBase* generator_{};
};
#endif // GBMMODEL_H