#pragma once

#include <QtWidgets/QWidget>
#include <qlabel.h>
#include <GUIMonitor/Debug/uic/ui_GUIMonitor.h>

#include <TAM2C/Include/Scene.h>

class MySubscriber : public ISubscriber, public IMemberSubscriber
{
public:
	MySubscriber(Ui::GUIMonitorClass* ui) : ui(ui) {}

	std::function<void()> cbOnUINotify;

	Ui::GUIMonitorClass* ui;
};

class ApSubscriber : public MySubscriber
{
 public:
	ApSubscriber(Ui::GUIMonitorClass* ui) : MySubscriber(ui) {}

	void notifyUIChanged(ELEM_ID elem, ELEM_TYPE type, int state) override;

	void notifyMemberConfigChanged(const IMemberConfig& config) override;
};

class JtanSubscriber : public MySubscriber
{
 public:
	JtanSubscriber(Ui::GUIMonitorClass* ui) : MySubscriber(ui) {}

	void notifyUIChanged(ELEM_ID elem, ELEM_TYPE type, int state) override;

	void notifyMemberConfigChanged(const IMemberConfig& config) override;
};

class GUIMonitor : public QWidget
{
	Q_OBJECT

public:
	GUIMonitor(QWidget *parent = Q_NULLPTR);

	void setScene(Scene* scene);

private slots:
	void cmbApElementChanged(int index = -1); // on -1 update with current index
	void cmbJtanElementChanged(int index = -1);

	void cmbApEnabledChanged(int index);
	void cmbJtanEnabledChanged(int index);

	void cmbApUsableChanged(int index);
	void cmbJtanUsableChanged(int index);

	void cmbApStateChanged(int index);
	void cmbJtanStateChanged(int index);

private:
	Ui::GUIMonitorClass ui;

	IMember* ap;
	IMember* jtan;

	MySubscriber* apSub;
	MySubscriber* jtanSub;

	std::map<int, ELEM_ID> indexElemAp;
	std::map<int, ELEM_ID> indexElemJtan;
};
