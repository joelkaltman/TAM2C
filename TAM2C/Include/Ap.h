#pragma once

// p3d
#include <p3d/Include/AffineTransformation.h>
#include <p3d/Include/VerticalRotationTrajectory.h>
#include <p3d/Include/LateralRotationTrajectory.h>

// GUI
#include <GUI/Include/ApPanels.h>

// TAM2C
#include <TAM2C/Include/IMember.h>

class Ap : public IMember
{
public:
	Ap(p3d::Scene3D* scene, p3d::Scene2D* sceneGDSU);
	~Ap();

	void rotate(double deriva, double alza) override;

	UIElement* getUIElement(ELEM_ID elemId) override;

private:
	friend class Cabin;

	void setUIOperations();

	void opPWRpressed();
	void opSTABpressed();

	void createCameraGDSU() override;

	ApPanels uiAp;

	p3d::Object3D* turret = nullptr;
	p3d::Object3D* cannon = nullptr;

	p3d::VerticalRotationTrajectory* trajTower = nullptr;
	p3d::LateralRotationTrajectory* trajCannon = nullptr;

	p3d::Scene3D* scene = nullptr;
};