#include "GUIMonitor.h"

#define STR_ENABLED "Enabled"
#define STR_DISABLED "Disabled"
#define STR_USABLE "Usable"
#define STR_NOTUSABLE "Not usable"

std::string getStateStringByType(ELEM_TYPE type, int state)
{
	if (type == BUTTON)
		return Definitons::buttonStateToString((BUTTON_STATE)state);
	else if (type == SWITCH)
		return Definitons::switchStateToString((SWITCH_STATE)state);
	else if (type == LED)
		return Definitons::ledStateToString((LED_STATE)state);

	return "";
}

QStringList getStateItems(ELEM_TYPE type)
{
	QStringList items;
	if (type == BUTTON)
	{
		for (int i = 0; i < INVALID_BUTTON; i++)
			items.push_back(QString(Definitons::buttonStateToString((BUTTON_STATE)i).c_str()));
	}
	else if (type == SWITCH)
	{
		for (int i = 0; i < INVALID_SWITCH; i++)
			items.push_back(QString(Definitons::switchStateToString((SWITCH_STATE)i).c_str()));
	}
	else if (type == LED)
	{
		for (int i = 0; i < INVALID_LED; i++)
			items.push_back(QString(Definitons::ledStateToString((LED_STATE)i).c_str()));
	}
	return items;
}


GUIMonitor::GUIMonitor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// combobox elements

	QStringList elemAp;
	QStringList elemJtan;
	for (int i = 0; i < ELEM_ID::INVALID_ID; i++)
	{
		if (i <= GDSU_BUTTON_CIRCLE)
		{
			elemAp.push_back(QString(Definitons::idToString((ELEM_ID)i).c_str()));
			indexElemAp[elemAp.size() - 1] = (ELEM_ID)i;

			elemJtan.push_back(QString(Definitons::idToString((ELEM_ID)i).c_str()));
			indexElemJtan[elemJtan.size() - 1] = (ELEM_ID)i;
		}
		else if (i <= AP_P2_BUTTON_1)
		{
			elemAp.push_back(QString(Definitons::idToString((ELEM_ID)i).c_str()));
			indexElemAp[elemAp.size() - 1] = (ELEM_ID)i;
		}
		else if (i <= JTAN_P1_BUTTON_2)
		{
			elemJtan.push_back(QString(Definitons::idToString((ELEM_ID)i).c_str()));
			indexElemJtan[elemJtan.size() - 1] = (ELEM_ID)i;
		}
	}

	ui.cmb_ap_gui_elem->addItems(elemAp);
	ui.cmb_jtan_gui_elem->addItems(elemJtan);

	connect(ui.cmb_ap_gui_elem, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbApElementChanged(int)));
	connect(ui.cmb_jtan_gui_elem, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbJtanElementChanged(int)));

	// combobox enabled
	QStringList enableList = (QStringList() << STR_ENABLED << STR_DISABLED);
	ui.cmb_ap_enabled->addItems(enableList);
	ui.cmb_jtan_enabled->addItems(enableList);

	connect(ui.cmb_ap_enabled, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbApEnabledChanged(int)));
	connect(ui.cmb_jtan_enabled, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbJtanEnabledChanged(int)));

	// combobox usable
	QStringList usableList = (QStringList() << STR_USABLE << STR_NOTUSABLE);
	ui.cmb_ap_usable->addItems(usableList);
	ui.cmb_jtan_usable->addItems(usableList);

	connect(ui.cmb_ap_usable, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbApUsableChanged(int)));
	connect(ui.cmb_jtan_usable, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbJtanUsableChanged(int)));

	// add subscribers
	apSub = new MySubscriber(ui.lbl_ap_last_action);
	apSub->cbOnNotify = [&]() { updateCurrentAp(); };

	jtanSub = new MySubscriber(ui.lbl_jtan_last_action);
	jtanSub->cbOnNotify = [&]() { updateCurrentJtan(); };

	ui.cmb_ap_gui_elem->setCurrentIndex(0);
	ui.cmb_jtan_gui_elem->setCurrentIndex(0);
}

void GUIMonitor::setScene(Scene* scene)
{
	Cabin* cabin = scene->getMainCabin();

	ap = cabin->getMember(Cabin::MEMBER_ID::AP);
	ap->addSubscriberToUI(apSub);

	jtan = cabin->getMember(Cabin::MEMBER_ID::JTAN);
	jtan->addSubscriberToUI(jtanSub);
}


void MySubscriber::notify(ELEM_ID elem, ELEM_TYPE type, int state)
{
	std::string strElem = Definitons::idToString(elem);
	std::string strState = getStateStringByType(type, state);

	myLabel->setText(QString((strElem + " (" + strState + ")").c_str()));

	cbOnNotify();
}

void GUIMonitor::updateCurrentAp()
{
	cmbApElementChanged(ui.cmb_ap_gui_elem->currentIndex());
}

void GUIMonitor::updateCurrentJtan()
{
	cmbJtanElementChanged(ui.cmb_jtan_gui_elem->currentIndex());
}

void GUIMonitor::cmbApElementChanged(int index)
{
	ELEM_ID id = indexElemAp[index];
	IElement* elem = ap->getGUIElement(id);

	QStringList items = getStateItems(elem->getType());

	ui.cmb_ap_state->clear();
	ui.cmb_ap_state->addItems(items);

	ui.lbl_ap_current_state->setText(QString(getStateStringByType(elem->getType(), elem->getState()).c_str()));
	(elem->getEnabled()) ? ui.lbl_ap_current_enabled->setText(STR_ENABLED) : ui.lbl_ap_current_enabled->setText(STR_DISABLED);
	(elem->getUsable()) ? ui.lbl_ap_current_usable->setText(STR_USABLE) : ui.lbl_ap_current_usable->setText(STR_NOTUSABLE);
}

void GUIMonitor::cmbJtanElementChanged(int index)
{
	ELEM_ID id = indexElemJtan[index];
	IElement* elem = jtan->getGUIElement(id);

	QStringList items = getStateItems(elem->getType());

	ui.cmb_jtan_state->clear();
	ui.cmb_jtan_state->addItems(items);

	ui.lbl_jtan_current_state->setText(QString(getStateStringByType(elem->getType(), elem->getState()).c_str()));
	(elem->getEnabled()) ? ui.lbl_jtan_current_enabled->setText(STR_ENABLED) : ui.lbl_jtan_current_enabled->setText(STR_DISABLED);
	(elem->getUsable()) ? ui.lbl_jtan_current_usable->setText(STR_USABLE) : ui.lbl_jtan_current_usable->setText(STR_NOTUSABLE);
}

void GUIMonitor::cmbApEnabledChanged(int index)
{
	ELEM_ID id = indexElemAp[index];
	IElement* elem = ap->getGUIElement(id);

	(index == 0) ? elem->setEnabled(true) : elem->setEnabled(false);

	updateCurrentAp();
}

void GUIMonitor::cmbJtanEnabledChanged(int index)
{
	ELEM_ID id = indexElemJtan[index];
	IElement* elem = jtan->getGUIElement(id);

	(index == 0) ? elem->setEnabled(true) : elem->setEnabled(false);

	updateCurrentJtan();
}

void GUIMonitor::cmbApUsableChanged(int index)
{
	ELEM_ID id = indexElemAp[index];
	IElement* elem = ap->getGUIElement(id);

	(index == 0) ? elem->setUsable(true) : elem->setUsable(false);

	updateCurrentAp();
}

void GUIMonitor::cmbJtanUsableChanged(int index)
{
	ELEM_ID id = indexElemJtan[index];
	IElement* elem = jtan->getGUIElement(id);

	(index == 0) ? elem->setUsable(true) : elem->setUsable(false);

	updateCurrentJtan();
}

void GUIMonitor::cmbApStateChanged(int index)
{
	ELEM_ID id = indexElemAp[index];
	IElement* elem = ap->getGUIElement(id);

	elem->setState(index);
}

void GUIMonitor::cmbJtanStateChanged(int index)
{
	ELEM_ID id = indexElemJtan[index];
	IElement* elem = jtan->getGUIElement(id);

	elem->setState(index);
}