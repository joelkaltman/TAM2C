#include <iostream>

#include <QtWidgets/QApplication>
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/JtanPanels.h>

#include <p3d/Include/P3D.h>
#include <resources/Include/Admin.h>

#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ApPanels w;
	w.show();

	JtanPanels w2;
	w2.show();

	p3d::P3D::initialize(p3d::P3D::NetworkingMode::ONLY_LOCAL, p3d::P3D::Platform::DIRECTX_11);

	return a.exec();
}