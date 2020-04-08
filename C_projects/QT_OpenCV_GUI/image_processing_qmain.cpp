//XXX.cpp 定義函式、class內容
#include "image_processing_qmain.h"

using namespace cv;
using namespace std;
//標頭檔在class中有宣告

image_processing_qmain::image_processing_qmain(QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::image_processing_qmainClass)
{
	ui->setupUi(this);
	//訊號槽方式下傅子窗體傳值的測試
	image_processing_qmain::binarization_dialog = new binarization; //建立新視窗Dialog
	image_processing_qmain::smoothing_dialog = new smoothing;
	//SINGAL和SLOT的連接
	connect(binarization_dialog, SIGNAL(sendData(string)), this, SLOT(receiveData(string)), Qt::UniqueConnection);
	connect(smoothing_dialog, SIGNAL(sendData(string)), this, SLOT(receiveData(string)), Qt::UniqueConnection);
	/*點選pushButtom開啟子視窗
	connect(const QObject * sender, const QMetaMethod & signal, const QObject * receiver, const QMetaMethod & method, Qt::ConnectionType type = Qt::AutoConnection)
	第一個參數 ： 傳送者物件指標，此物件必須繼承QObject。
	第二個參數 ： 傳送者的signal。
	第二個參數 ： 接收者物件指標，此物件必須繼承QObject。
	第四個參數 ： 接收者的slot。
	第五個參數 ： 連結類型，預設為Qt::AutoConnection。
	*/
	//QObject::connect(ui->pushButton_2, SIGNAL(),this, SLOT(on_Barization_clicked()));
}

image_processing_qmain::~image_processing_qmain()
{
	delete ui;//解構子
}

void image_processing_qmain::on_OpenFig_clicked()
{
	QString filename;
	//括號裏的參數分別是：指定父類、標題、默認打開後顯示的目錄、右下角的文件過濾器
	//QFileDialog::getOpenFileName(NULL,"標題",".","*.txt");
	filename = QFileDialog::getOpenFileName(this,
		tr("Select image"),
		"",
		tr("Image (*.png *.bmp *.jpg *.tif *.GIF)"));
	if (filename.isEmpty())
	{
		return;
	}
	else
	{
		/*
		QLabel *imagelabel = new QLabel;
		QImage image(filename);
		imagelabel->setPixmap(QPixmap::fromImage(image));
		//scrollArea = new QScrollArea;
		ui.scrollArea->setBackgroundRole(QPalette::Dark);
		ui.scrollArea->setWidget(imagelabel);
		*/
		// 更新全域變數image
		String str = filename.toStdString();
		Mat image_gro = imread(str);
		cv::cvtColor(image_gro, image_gro, COLOR_BGR2RGB);
		image_grobal::image = image_gro;
		// 顯示原圖
		QLabel *imagelabel = new QLabel;
		QImage image(filename);
		imagelabel->setPixmap(QPixmap::fromImage(image));
		ui->scrollArea->setBackgroundRole(QPalette::Dark);
		ui->scrollArea->setWidget(imagelabel);
	
	}
	textBrowser = new QTextBrowser();
	ui->textBrowser->insertPlainText("Image path: " + filename +"\n");
}

void image_processing_qmain::on_refresh_clicked()//點refresh可以刷新圖片
{
	// 刷新
	Mat img = image_grobal::image;
	QImage imgIn = QImage((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);

	QLabel *imagelabel = new QLabel;
	imagelabel->setPixmap(QPixmap::fromImage(imgIn));
	ui->scrollArea_2->setBackgroundRole(QPalette::Dark);
	ui->scrollArea_2->setWidget(imagelabel);

	QCoreApplication::processEvents();//沒用，想說可以持續刷新
	QApplication::processEvents();//沒用，想說可以持續刷新
}

void image_processing_qmain::receiveData(string data)
{	
	QString str = QString::fromStdString(data);//string to QString
	ui->textBrowser->insertPlainText(str+"\n");
}


void image_processing_qmain::on_Barization_clicked() //開啟binarization子視窗
{
	binarization_dialog->show();
}

void image_processing_qmain::on_somoothing_clicked()
{
	smoothing_dialog->show();
}
/*	cv::flip(image, image, 1);// <0:沿y軸翻轉 =0:沿x軸翻轉 >0:x,y軸同時翻轉
	QImage img1 = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(img1));
	label_2->resize(QSize(img1.width(), img1.height()));
	ui.scrollArea_2->setWidget(label_2);
*/