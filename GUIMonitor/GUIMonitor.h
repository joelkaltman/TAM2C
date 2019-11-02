#pragma once

#include <QtWidgets/QWidget>
#include <qlabel.h>
#include <GUIMonitor/Debug/uic/ui_GUIMonitor.h>

#include <TAM2C/Include/Scene.h>

class MySubscriber : public ISubscriber
{
public:
	MySubscriber(QLabel* label) : myLabel(label) {}

	void notify(ELEM_ID elem, ELEM_TYPE type, int state) override;

	std::function<void()> cbOnNotify;

	QLabel* myLabel;
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
