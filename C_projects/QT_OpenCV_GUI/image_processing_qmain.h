// .h標頭檔 宣告class、函式
#pragma once

//防止多重include
#ifndef IMAGE_PROCESSING_QMAIN_H
#define IMAGE_PROCESSING_QMAIN_H

#include "image.h" // Mat image全域變數

#include <QtWidgets/QMainWindow>
#include "ui_image_processing_qmain.h"
#include "binarization.h"//二值化
#include "smoothing.h"//平滑化
//Qt Graphics View架構: QGraphicsScene、QGraphicsView、QGraphicsItem
//Scene(場景) View(顯示區域) Item(場景內的物件)
//https://kheresy.wordpress.com/2011/07/11/qt-graphics-view-framework-%E7%B0%A1%E4%BB%8B/
#include <QGraphicsScene> //QGraphicsScene是QGraphicsView中的場景
#include <QGraphicsView>  
#include <qfiledialog.h>
#include <qlabel.h>
#include <qtextbrowser.h>

//OpenCV
#include <opencv2\imgproc\imgproc.hpp> //前處理
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp> //gui
using namespace cv;
using namespace std;

namespace Ui {
	class image_processing_qmainClass;
}

class image_processing_qmain : public QMainWindow  //此專案繼承QMainWindow
{
	Q_OBJECT

public:
	explicit image_processing_qmain(QWidget *parent = 0);
	~image_processing_qmain(); //解構子
	QDialog *binarization_dialog;
	QDialog *smoothing_dialog;
//添加槽函數  按鈕控制
private slots:
	//按格式on_控件名_clicked命名函數，QT會默認完成函數和按鈕動作的連接
	//，如果不這樣命名的話就去設置 信號槽函數
	// Basic
	void on_OpenFig_clicked();
	void on_refresh_clicked();
	//binarazation
	void on_Barization_clicked();
	void receiveData(string data); //接收string資料的槽
	//smoothing
	void on_somoothing_clicked();

//
private:
	Ui::image_processing_qmainClass *ui;
	Mat image;
	QLabel *label;
	QLabel *label_2;
	QPushButton *pushButton;
	QPushButton *pushButton_2;
	QPushButton *pushButton_3;
	QTextBrowser *textBrowser;
};
#endif  //IMAGE_PROCESSING_QMAIN_H

/*
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_image_processing_qmain.h"

class image_processing_qmain : public QMainWindow
{
	Q_OBJECT

public:
	image_processing_qmain(QWidget *parent = Q_NULLPTR);

private:
	Ui::image_processing_qmainClass ui;
};
*/
