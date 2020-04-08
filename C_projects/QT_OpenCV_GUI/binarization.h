#pragma once
// 使用OpenCV完成圖片前處理

#ifndef  BINARIZATION_H
#define BINARIZATION_H

#include <QtWidgets/QMainWindow>
#include "image_processing_qmain.h"
#include "ui_binarization.h"

#include <qdialog.h>
// 用來使圖片還原
#include "image.h"

#include <map>
#include <qcombobox.h>
#include <qpushbutton.h>
// OpenCV庫
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
namespace Ui {
	class binarizationClass;
}

//宣告二值化 的Dialog子視窗功能
class binarization : public QDialog
{
	Q_OBJECT
public:
	explicit binarization(QWidget *parent = 0);
	~binarization();
private:
	Ui::binarizationClass *ui;
	QComboBox *comboBox;
	QLineEdit *lineEdit;
	QLineEdit *lineEdit_2;
	QPushButton *pushButton;
	QPushButton *pushBotton_2;
	QPushButton *pushBotton_3;
	QLabel *label;

private slots:
	void on_lowThresh_clicked();
	void on_highThresh_clicked();
	void on_comboBox_clicked();
	Mat on_enter_clicked();
	void on_restore_clicked();
	void on_send_clicked();
	int receiveData_int(QString);
	int receiveData_bin_type(QString);
signals:
	void sendData(QString);//用來傳遞QString數據
	void sendData(string);
	//void sendData(QLabel); //用來傳遞QImage數據
};

#endif //BINARIZATION_H
