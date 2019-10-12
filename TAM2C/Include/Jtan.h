#pragma once

// p3d
#include <p3d/Include/AffineTransformation.h>
#include <p3d/Include/VerticalRotationTrajectory.h>
#include <p3d/Include/LateralRotationTrajectory.h>

// GUI
#include <GUI/Include/JtanPanels.h>

// TAM2C
#include <TAM2C/Include/IMember.h>

class JTan : public IMember
{
public:
	JTan(p3d::Scene3D* scene, p3d::Scene2D* sceneGDSU);
	~JTan();

	void rotate(double deriva, double alza) override;
private:
	friend class Cabin;

	void createCameraGDSU() override;

	JtanPanels uiJtan;

	p3d::AffineTransformation* transfTraslation = nullptr;
	p3d::AffineTransformation* transfRotDirection = nullptr;
	p3d::AffineTransformation* transfRotHeight = nullptr;

	p3d::VerticalRotationTrajectory* trajDirection = nullptr;
	p3d::LateralRotationTrajectory* trajHeight = nullptr;

	p3d::Scene3D* scene = nullptr;
};