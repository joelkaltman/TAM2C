#pragma once

// p3d
#include <p3d/Include/AffineTransformation.h>
#include <p3d/Include/VerticalRotationTrajectory.h>
#include <p3d/Include/LateralRotationTrajectory.h>

// TAM2C
#include <TAM2C/Include/IMember.h>

class JTan : public IMember
{
public:
	JTan(p3d::Scene3D* scene);

	void rotate(double deriva, double alza) override;

	void addGDSURotation(p3d::Scene2D* scene2d, p3d::Sprite* sprite) override;

private:
	friend class Cabin;

	p3d::AffineTransformation* transfTraslation;
	p3d::AffineTransformation* transfRotDirection;
	p3d::AffineTransformation* transfRotHeight;

	p3d::VerticalRotationTrajectory* trajDirection;
	p3d::LateralRotationTrajectory* trajHeight;

	p3d::ROIRotationAnimation* spriteRot;
};