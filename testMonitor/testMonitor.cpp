// testMonitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// p3d
#include <p3d/Include/P3D.h>

 // qt
#include <QtWidgets/QApplication>

// TAM2C
#include <GUIMonitor/GUIMonitor.h>
#include <TAM2C/Include/Scene.h>

FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}

#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Scene* scene = new Scene();
	scene->init(p3d::P3D::Platform::DIRECTX_11);

	GUIMonitor monitor;
	monitor.show();

	monitor.setScene(scene);

	return a.exec();
}