#include "GUIMonitor.h"

#include <GUI/Include/Switch.h>

#define STR_ENABLED "Enabled"
#define STR_DISABLED "Disabled"
#define STR_USABLE "Usable"
#define STR_NOTUSABLE "Not usable"

bool changedStateListInternally = false;

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

QStringList getStateItems(IElement* elem)
{
	QStringList items;
	if (elem->getType() == BUTTON)
	{
		for (int i = 0; i < INVALID_BUTTON; i++)
			items.push_back(QString(Definitons::buttonStateToString((BUTTON_STATE)i).c_str()));
	}
	else if (elem->getType() == SWITCH)
	{
		int pos = dynamic_cast<Switch*>(elem)->getPositions();

		for (int i = 0; i < INVALID_SWITCH && i < pos; i++)
			items.push_back(QString(Definitons::switchStateToString((SWITCH_STATE)i).c_str()));
	}
	else if (elem->getType() == LED)
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

	// combobox state
	connect(ui.cmb_ap_state, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbApStateChanged(int)));
	connect(ui.cmb_jtan_state, SIGNAL(currentIndexChanged(int)), this, SLOT(cmbJtanStateChanged(int)));

	// add subscribers
	apSub = new ApSubscriber(&ui);
	apSub->cbOnUINotify = [&]() { cmbApElementChanged(); };

	jtanSub = new JtanSubscriber(&ui);
	jtanSub->cbOnUINotify = [&]() { cmbJtanElementChanged(); };
}

void GUIMonitor::setScene(Scene* scene)
{
	Cabin* cabin = scene->getMainCabin();

	ap = cabin->getMember(Cabin::MEMBER_ID::AP);
	ap->addUISubscriber(apSub);
	ap->addMemberSubscriber(apSub);

	jtan = cabin->getMember(Cabin::MEMBER_ID::JTAN);
	jtan->addUISubscriber(jtanSub);
	jtan->addMemberSubscriber(jtanSub);

	cmbApUsableChanged(0);
	cmbJtanUsableChanged(0);

	IMemberConfig initialConfig;
	apSub->notifyMemberConfigChanged(initialConfig);
	jtanSub->notifyMemberConfigChanged(initialConfig);
}

void ApSubscriber::notifyUIChanged(ELEM_ID elem, ELEM_TYPE type, int state)
{
	std::string strElem = Definitons::idToString(elem);
	std::string strState = getStateStringByType(type, state);

	ui->lbl_ap_last_action->setText(QString((strElem + " (" + strState + ")").c_str()));

	cbOnUINotify();
}

void JtanSubscriber::notifyUIChanged(ELEM_ID elem, ELEM_TYPE type, int state)
{
	std::string strElem = Definitons::idToString(elem);
	std::string strState = getStateStringByType(type, state);

	ui->lbl_jtan_last_action->setText(QString((strElem + " (" + strState + ")").c_str()));

	cbOnUINotify();
}

void ApSubscriber::notifyMemberConfigChanged(const IMemberConfig& config)
{
	ui->lbl_ap_info_general->setText(QString(MemberConfig::generalToString(config.general).c_str()));
	ui->lbl_ap_info_navegation->setText(QString(MemberConfig::navToString(config.nav).c_str()));
	ui->lbl_ap_info_gun->setText(QString(MemberConfig::gunToString(config.gun).c_str()));
	ui->lbl_ap_info_ammo->setText(QString(MemberConfig::ammoToString(config.ammo).c_str()));
	ui->lbl_ap_info_vision->setText(QString(MemberConfig::visionToString(config.vision).c_str()));
	ui->lbl_ap_info_zoom->setText(QString(MemberConfig::zoomToString(config.zoom).c_str()));
	ui->lbl_ap_info_screen->setText(QString(MemberConfig::screenToString(config.screen).c_str()));
}

void JtanSubscriber::notifyMemberConfigChanged(const IMemberConfig& config)
{
	ui->lbl_jtan_info_general->setText(QString(MemberConfig::generalToString(config.general).c_str()));
	ui->lbl_jtan_info_navegation->setText(QString(MemberConfig::navToString(config.nav).c_str()));
	ui->lbl_jtan_info_gun->setText(QString(MemberConfig::gunToString(config.gun).c_str()));
	ui->lbl_jtan_info_ammo->setText(QString(MemberConfig::ammoToString(config.ammo).c_str()));
	ui->lbl_jtan_info_vision->setText(QString(MemberConfig::visionToString(config.vision).c_str()));
	ui->lbl_jtan_info_zoom->setText(QString(MemberConfig::zoomToString(config.zoom).c_str()));
	ui->lbl_jtan_info_screen->setText(QString(MemberConfig::screenToString(config.screen).c_str()));
}

void GUIMonitor::cmbApElementChanged(int index)
{
	int i = index;
	if (index == -1)
		i = ui.cmb_ap_gui_elem->currentIndex();

	ELEM_ID id = indexElemAp[i];
	IElement* elem = ap->getGUIElement(id);

	QStringList items = getStateItems(elem);

	if (index != -1 || ui.cmb_ap_state->count() == 0)
	{
		changedStateListInternally = true;
		ui.cmb_ap_state->clear();
		ui.cmb_ap_state->addItems(items);
		changedStateListInternally = false;
	}

	ui.lbl_ap_current_state->setText(QString(getStateStringByType(elem->getType(), elem->getState()).c_str()));
	(elem->getEnabled()) ? ui.lbl_ap_current_enabled->setText(STR_ENABLED) : ui.lbl_ap_current_enabled->setText(STR_DISABLED);
	(elem->getUsable()) ? ui.lbl_ap_current_usable->setText(STR_USABLE) : ui.lbl_ap_current_usable->setText(STR_NOTUSABLE);
}

void GUIMonitor::cmbJtanElementChanged(int index)
{
	int i = index;
	if (index == -1)
		i = ui.cmb_ap_gui_elem->currentIndex();

	ELEM_ID id = indexElemJtan[index];
	IElement* elem = jtan->getGUIElement(id);

	QStringList items = getStateItems(elem);

	if (index != -1 || ui.cmb_jtan_state->count() == 0)
	{
		changedStateListInternally = true;
		ui.cmb_jtan_state->clear();
		ui.cmb_jtan_state->addItems(items);
		changedStateListInternally = false;
	}

	ui.lbl_jtan_current_state->setText(QString(getStateStringByType(elem->getType(), elem->getState()).c_str()));
	(elem->getEnabled()) ? ui.lbl_jtan_current_enabled->setText(STR_ENABLED) : ui.lbl_jtan_current_enabled->setText(STR_DISABLED);
	(elem->getUsable()) ? ui.lbl_jtan_current_usable->setText(STR_USABLE) : ui.lbl_jtan_current_usable->setText(STR_NOTUSABLE);
}

void GUIMonitor::cmbApEnabledChanged(int index)
{
	if (ui.cmb_ap_gui_elem->count() == 0)
		return;

	ELEM_ID id = indexElemAp[ui.cmb_ap_gui_elem->currentIndex()];
	IElement* elem = ap->getGUIElement(id);

	(index == 0) ? elem->setEnabled(true) : elem->setEnabled(false);

	cmbApElementChanged();
}

void GUIMonitor::cmbJtanEnabledChanged(int index)
{
	if (ui.cmb_jtan_gui_elem->count() == 0)
		return;

	ELEM_ID id = indexElemJtan[ui.cmb_jtan_gui_elem->currentIndex()];
	IElement* elem = jtan->getGUIElement(id);

	(index == 0) ? elem->setEnabled(true) : elem->setEnabled(false);

	cmbJtanElementChanged();
}

void GUIMonitor::cmbApUsableChanged(int index)
{
	if (ui.cmb_ap_gui_elem->count() == 0)
		return;

	ELEM_ID id = indexElemAp[ui.cmb_ap_gui_elem->currentIndex()];
	IElement* elem = ap->getGUIElement(id);

	(index == 0) ? elem->setUsable(true) : elem->setUsable(false);

	cmbApElementChanged();
}

void GUIMonitor::cmbJtanUsableChanged(int index)
{
	if (ui.cmb_jtan_gui_elem->count() == 0)
		return;

	ELEM_ID id = indexElemJtan[ui.cmb_jtan_gui_elem->currentIndex()];
	IElement* elem = jtan->getGUIElement(id);

	(index == 0) ? elem->setUsable(true) : elem->setUsable(false);

	cmbJtanElementChanged();
}

void GUIMonitor::cmbApStateChanged(int index)
{
	if (ui.cmb_ap_gui_elem->count() == 0 || changedStateListInternally)
		return;

	ELEM_ID id = indexElemAp[ui.cmb_ap_gui_elem->currentIndex()];
	IElement* elem = ap->getGUIElement(id);

	elem->setState(index);
}

void GUIMonitor::cmbJtanStateChanged(int index)
{
	if (ui.cmb_jtan_gui_elem->count() == 0 || changedStateListInternally)
		return;

	ELEM_ID id = indexElemJtan[ui.cmb_jtan_gui_elem->currentIndex()];
	IElement* elem = jtan->getGUIElement(id);

	elem->setState(index);
}