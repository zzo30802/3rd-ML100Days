#include "binarization.h"
using namespace cv;
using namespace std;

binarization::binarization(QWidget *parent)
	: QDialog(parent),
	ui(new Ui::binarizationClass)
{
	ui->setupUi(this); //ui->setupUi(this);
	connect(ui->pushButton_3, SIGNAL(), this, SLOT(on_send_clicked()));

	//combox內容選項設定
	ui->comboBox->addItem("CV_THRESH_BINARY");
	ui->comboBox->addItem("CV_THRESH_BINARY_INV");
	ui->comboBox->addItem("CV_THRESH_TRUNC");
	ui->comboBox->addItem("CV_THRESH_TOZERO");
	ui->comboBox->addItem("CV_THRESH_TOZERO_INV");
	ui->comboBox->addItem("CV_THRESH_OTSU");
	ui->comboBox->setCurrentText("CV_THRESH_BINARY");
}
binarization::~binarization()
{
	delete ui;//解構子
}

// 定義slot函數功能
void binarization::on_lowThresh_clicked()
{
	//獲取lineEdit的輸入並傳送出去
	emit sendData(ui->lineEdit->text());
}
void binarization::on_highThresh_clicked()
{
	emit sendData(ui->lineEdit_2->text());
}
void binarization::on_comboBox_clicked()
{
	emit sendData(ui->comboBox->currentText());
}
Mat binarization::on_enter_clicked()
{
	extern Mat image;
	//計算二值法
	Mat img, result;
	int lowThresh, highThresh;
	int bin_type;
	img = image_grobal::image;
	result = img.clone();
	lowThresh = receiveData_int(ui->lineEdit->text());
	highThresh = receiveData_int(ui->lineEdit_2->text());
	bin_type = receiveData_bin_type(ui->comboBox->currentText());
	threshold(img, result, lowThresh, highThresh, bin_type);
	//emit sendData(result);
	//用QLabel顯示圖片
	QImage result_QImage = QImage((const unsigned char*)(result.data), result.cols, result.rows, QImage::Format_RGB888);
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(result_QImage));
	label->resize(QSize(result_QImage.width(), result_QImage.height()));
	ui->scrollArea->setWidget(label);
	return result;
}

void binarization::on_restore_clicked()
{
	QImage result_QImage = QImage((const unsigned char*)(image_grobal::image.data), image_grobal::image.cols, image_grobal::image.rows, QImage::Format_RGB888);
	label = new QLabel();
	label->setPixmap(QPixmap::fromImage(result_QImage));
	label->resize(QSize(result_QImage.width(), result_QImage.height()));
	ui->scrollArea->setWidget(label);
}

void binarization::on_send_clicked()
{
	//emit sendData(ui.scrollArea->setWidget);
	//connect(this->ui.pushButton_3, SIGNAL(clicked()), image_processing_qmain::this->ui.scrollArea, SLOT());
	image_grobal::image = binarization::on_enter_clicked();
	string lowThresh = (ui->lineEdit->text()).toStdString();
	string highThresh = (ui->lineEdit_2->text()).toStdString();
	emit sendData("binarization,  lowThresh: " + lowThresh+", highThresh: "+ highThresh);
}

int binarization::receiveData_int(QString data)
{
	int num = data.toInt();
	return num;
}
int binarization::receiveData_bin_type(QString data)
{
	string str = data.toStdString();
	// map 用value找key，並回傳
	map<string, int>dict;
	dict["CV_THRESH_BINARY"] = 0;
	dict["CV_THRESH_BINARY_INV"] = 1;
	dict["CV_THRESH_TRUNC"] = 2;
	dict["CV_THRESH_TOZERO"] = 3;
	dict["CV_THRESH_TOZERO_INV"] = 4;
	dict["CV_THRESH_OTSU"] = 8;
	int num = dict.at(str);
	return num;
}

