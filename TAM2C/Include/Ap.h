#pragma once

// p3d
#include <p3d/Include/AffineTransformation.h>
#include <p3d/Include/VerticalRotationTrajectory.h>
#include <p3d/Include/LateralRotationTrajectory.h>

// TAM2C
#include <TAM2C/Include/IMember.h>

class Ap : public IMember
{
public:
	Ap(p3d::Resource* rTower, p3d::Resource* rCannon, p3d::Scene3D* scene);

	void rotate(double deriva, double alza) override;

private:
	friend class Cabin;

	p3d::Object3D* tower;
	p3d::Object3D* cannon;

	p3d::VerticalRotationTrajectory* trajTower;
	p3d::LateralRotationTrajectory* trajCannon;
};