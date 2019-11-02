#pragma once

// p3d
#include <p3d/Include/AffineTransformation.h>
#include <p3d/Include/VerticalRotationTrajectory.h>
#include <p3d/Include/LateralRotationTrajectory.h>

// GUI
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/ISubscriber.h>

// TAM2C
#include <TAM2C/Include/IMember.h>
#include <TAM2C/Include/IMemberConfig.h>

class Ap : public IMember, public ISubscriber
{
public:
	Ap(p3d::Scene3D* scene, p3d::Scene2D* sceneGDSU);
	~Ap();

	void rotate(double drift, double rise) override;

	void notify(ELEM_ID elem, ELEM_TYPE type, int state) override;

	IElement* getGUIElement(ELEM_ID id) override;

	void addSubscriberToUI(ISubscriber* sub) override;

private:
	friend class Cabin;

	void createCameraGDSU() override;

	ApPanels uiAp;

	p3d::Object3D* turret = nullptr;
	p3d::Object3D* cannon = nullptr;

	p3d::VerticalRotationTrajectory* trajTower = nullptr;
	p3d::LateralRotationTrajectory* trajCannon = nullptr;

	p3d::Scene3D* scene = nullptr;
};