#include <iostream>

#include <p3d/Include/P3D.h>

#include <QtWidgets/QApplication>

#include <TAM2C/Include/Scene.h>

FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }

#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Config("../config.json");

	p3d::P3D::initialize(p3d::P3D::NetworkingMode::ONLY_LOCAL, p3d::P3D::Platform::DIRECTX_11); 

	Scene scene;
	scene.init();

	return a.exec();
}