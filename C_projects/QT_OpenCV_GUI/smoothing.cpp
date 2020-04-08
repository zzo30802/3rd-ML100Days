#include "smoothing.h"
using namespace cv;
using namespace std;
smoothing::smoothing(QWidget *parent)
	:QDialog(parent),
	ui(new Ui::smoothingClass)
{
	ui->setupUi(this);

	// 顯示Input
	
	Mat input;
	image_grobal::image.copyTo(input);
	QImage input_QImage = QImage((const unsigned char*)(input.data), input.cols, input.rows, QImage::Format_RGB888);
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(input_QImage));
	label->resize(QSize(input_QImage.width(), input_QImage.height()));
	ui->scrollArea->setWidget(label);
	
	// GaussianBlur( )
	int nMin = 1;
	int nMax = 99;
	int nSingleStep = 2;
	// 滑動條
	ui->horizontalSlider->setMinimum(nMin);//最小值
	ui->horizontalSlider->setMaximum(nMax);
	ui->horizontalSlider->setSingleStep(nSingleStep);
	ui->horizontalSlider_2->setMinimum(nMin);//最小值
	ui->horizontalSlider_2->setMaximum(nMax);
	ui->horizontalSlider_2->setSingleStep(nSingleStep);
	ui->horizontalSlider_3->setMinimum(nMin);//最小值
	ui->horizontalSlider_3->setMaximum(nMax);
	ui->horizontalSlider_3->setSingleStep(nSingleStep);
	ui->horizontalSlider->setValue(5);  //初始值
	ui->horizontalSlider_2->setValue(5);
	ui->horizontalSlider_3->setValue(5);
	//微調框
	ui->spinBox->setMinimum(nMin);
	ui->spinBox->setMaximum(nMax);
	ui->spinBox->setSingleStep(nSingleStep);
	ui->spinBox_2->setMinimum(nMin);
	ui->spinBox_2->setMaximum(nMax);
	ui->spinBox_2->setSingleStep(nSingleStep);
	ui->spinBox_3->setMinimum(nMin);
	ui->spinBox_3->setMaximum(nMax);
	ui->spinBox_3->setSingleStep(nSingleStep);
	ui->spinBox->setValue(5);   //初始值
	ui->spinBox_2->setValue(5);
	ui->spinBox_3->setValue(5);
	//連接信號槽
	connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
	connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_2, SLOT(setValue(int)));
	connect(ui->spinBox_3, SIGNAL(valueChanged(int)), ui->horizontalSlider_3, SLOT(setValue(int)));
	connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
	connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
	connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->spinBox_3, SLOT(setValue(int)));

	// medianBlur( )
	ui->spinBox_4->setMinimum(nMin);
	ui->spinBox_4->setMaximum(nMax);
	ui->spinBox_4->setValue(5);
	ui->horizontalSlider_4->setMinimum(nMin);
	ui->horizontalSlider_4->setMaximum(nMax);
	ui->horizontalSlider_4->setValue(5);
	connect(ui->spinBox_4, SIGNAL(valueChanged(int)), ui->horizontalSlider_4, SLOT(setValue(int)));
	connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int)), ui->spinBox_4, SLOT(setValue(int)));

	// averageBlur( )
	ui->spinBox_5->setMinimum(nMin);
	ui->spinBox_5->setMaximum(nMax);
	ui->spinBox_5->setValue(5);
	ui->horizontalSlider_5->setMinimum(nMin);
	ui->horizontalSlider_5->setMaximum(nMax);
	ui->horizontalSlider_5->setValue(5);
	connect(ui->spinBox_5, SIGNAL(valueChanged(int)), ui->horizontalSlider_5, SLOT(setValue(int)));
	connect(ui->horizontalSlider_5, SIGNAL(valueChanged(int)), ui->spinBox_5, SLOT(setValue(int)));

}
smoothing::~smoothing()
{
	delete ui;
}

// 共通=========================================================
int smoothing::receiveData_int(int data)
{
	return data;
}
double smoothing::receiveData_double(int data)
{
	double num = double(data);
	return num;
}
string smoothing::receiveData_Qstring2string(QString data)  //Qstring to string
{
	string str = data.toStdString();//string to QString
	return str;
}
int smoothing::receiveData_QString2int(QString data)
{
	int num = data.toInt();
	return num;
}
void smoothing::on_restore_clicked()
{
	QImage result_QImage = QImage((const unsigned char*)(image_grobal::image.data), image_grobal::image.cols, image_grobal::image.rows, QImage::Format_RGB888);
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(result_QImage));
	label->resize(QSize(result_QImage.width(), result_QImage.height()));
	ui->scrollArea->setWidget(label);
	label_2 = new QLabel();
	label_2->setPixmap(QPixmap::fromImage(result_QImage));
	label_2->resize(QSize(result_QImage.width(), result_QImage.height()));
	ui->scrollArea_2->setWidget(label_2);
}

// GaussianBlur( )=========================================================
// 將資料傳送到演算法運算
void smoothing::on_gaussian_ksize_clicked()
{
	//emit sendData(ui->horizontalSlider->tickPosition());
	emit sendData(ui->horizontalSlider->value());
}
void smoothing::on_sigmaX_clicked()
{
	emit sendData(ui->horizontalSlider_2->value());
}
void smoothing::on_sigmaY_clicked()
{
	emit sendData(ui->horizontalSlider_3->value());
}
void smoothing::on_borderType_clicked()
{
	emit sendData(ui->lineEdit->text());
}
Mat smoothing::on_gaussianEnter_clicked() //Enter點擊後，計算高斯濾波
{
	extern Mat image;
	Mat src, dst;
	int ksize;
	double sigmaX, sigmaY;
	int borderType;
	src = image_grobal::image;
	dst = src.clone();
	ksize = receiveData_int(ui->horizontalSlider->value());
	sigmaX = receiveData_int(ui->horizontalSlider_2->value());
	sigmaY = receiveData_int(ui->horizontalSlider_3->value());
	borderType = receiveData_QString2int(ui->lineEdit->text());
	GaussianBlur(src, dst, Size(ksize, ksize), sigmaX, sigmaY);
	//GaussianBlur(src, dst, Size(ksize, ksize), sigmaX, sigmaY, 0);

	//用QLabel顯示圖片
	//Mat轉QImage
	QImage result_QImage = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_RGB888);
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(result_QImage));
	label->resize(QSize(result_QImage.width(), result_QImage.height()));
	ui->scrollArea_2->setWidget(label);
	return dst;
}
void smoothing::on_gaussianSend_clicked()
{
	// 將全域圖片取代為send出去計算好的Mat結果
	image_grobal::image = smoothing::on_gaussianEnter_clicked();
	/*
	int ksize = ui->horizontalSlider->value();
	double sigmaX = ui->horizontalSlider_2->value();
	double sigmaY = ui->horizontalSlider_3->value();
	int borderType = (ui->lineEdit->text()).toInt();
	*/
	string ksize = to_string(receiveData_int(ui->horizontalSlider->value()));
	string sigmaX = to_string(ui->horizontalSlider_2->value());
	string sigmaY = to_string(ui->horizontalSlider_3->value());
	string borderType = to_string((ui->lineEdit->text()).toInt());
	emit sendData("GaussianBlur, ksize: " + ksize + " ,sigmaX: " + sigmaX + " ,sigmaY: " + sigmaY + " ,borderType: " + borderType);
}

// medianBlur( )=========================================================
Mat smoothing::on_medianEnter_clicked()
{
	extern Mat image;
	Mat src, dst;
	int ksize;
	src = image_grobal::image;
	dst = src.clone();
	ksize = receiveData_int(ui->horizontalSlider_4->value());
	medianBlur(src, dst, ksize);
	//用QLabel顯示圖片
	//Mat轉QImage
	QImage result_QImage = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_RGB888);
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(result_QImage));
	label->resize(QSize(result_QImage.width(), result_QImage.height()));
	ui->scrollArea_2->setWidget(label);
	return dst;
}
void smoothing::on_medianSend_clicked()
{
	// 將全域圖片取代為send出去計算好的Mat結果
	image_grobal::image = smoothing::on_medianEnter_clicked();
	string ksize = to_string(receiveData_int(ui->horizontalSlider_4->value()));
	emit sendData("medianBlur, ksize: "+ksize);
}

// averageBlur( )
Mat smoothing::on_averageEnter_clicked()
{
	extern Mat image;
	Mat src, dst;
	int ksize, anchorX, anchorY, borderType;
	src = image_grobal::image;
	dst = src.clone();
	ksize = receiveData_int(ui->horizontalSlider_5->value());
	anchorX = receiveData_QString2int(ui->lineEdit_2->text());
	anchorY = receiveData_QString2int(ui->lineEdit_3->text());
	borderType = receiveData_QString2int(ui->lineEdit_4->text());
	blur(src, dst, Size(ksize, ksize), Point(-1, -1));
	//用QLabel顯示圖片
	//Mat轉QImage
	QImage result_QImage = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_RGB888);
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(result_QImage));
	label->resize(QSize(result_QImage.width(), result_QImage.height()));
	ui->scrollArea_2->setWidget(label);
	return dst;
}
void smoothing::on_averageSend_clicked()
{
	// 將全域圖片取代為send出去計算好的Mat結果
	image_grobal::image = smoothing::on_averageEnter_clicked();
	string ksize = to_string(receiveData_int(ui->horizontalSlider_4->value()));
	string anchorX = to_string((ui->lineEdit_2->text()).toInt());
	string anchorY = to_string((ui->lineEdit_3->text()).toInt());
	string borderType = to_string((ui->lineEdit_4->text()).toInt());
	emit sendData("averageBlur, ksize: " + ksize+" Point anchor=Point("+ anchorX +","+anchorY+"), borderType:"+ borderType);
}












