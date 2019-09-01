#include <GUI/Include/JtanPanels.h>

#include <TAM2C/Include/Definitions.h>

JtanPanels::JtanPanels(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	loadImages();
}

void JtanPanels::loadImages()
{
	QPixmap image = QPixmap(Definitions::getGUIPath("JtanPanels.png").c_str());

	ui.JTAN_Background->setPixmap(image);
}