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
	Ap(p3d::Scene3D* scene);

	void rotate(double deriva, double alza) override;

	void addGDSURotation(p3d::Scene2D* scene2d, p3d::Sprite* sprite) override;

private:
	friend class Cabin;

	p3d::Object3D* turret;
	p3d::Object3D* cannon;

	p3d::VerticalRotationTrajectory* trajTower;
	p3d::LateralRotationTrajectory* trajCannon;

	p3d::ROIRotationAnimation* spriteRot;
};