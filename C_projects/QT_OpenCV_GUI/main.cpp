#include "image_processing_qmain.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
	//image_grobal::image;
	QApplication a(argc, argv);
	image_processing_qmain w;
	w.show();
	return a.exec();
}