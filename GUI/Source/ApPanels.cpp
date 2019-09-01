#include <GUI/Include/ApPanels.h>

#include <TAM2C/Include/Definitions.h>

ApPanels::ApPanels(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	loadImages();
}

void ApPanels::loadImages()
{
	QPixmap image = QPixmap(Definitions::getGUIPath("ApPanels.png").c_str());

	ui.AP_Background->setPixmap(image);
}