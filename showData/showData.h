#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_showData.h"


#include <QBuffer>
#include <QTcpServer>  
#include <QTcpSocket>
#include "HCNetSDK.h"
#include <QFile>

struct configInfo {
	QString devIp;
	QString devUser;
	QString devPwd;
	QString devPort;
};

class showData : public QMainWindow
{
    Q_OBJECT

public:
    showData(QWidget *parent = Q_NULLPTR);

signals:
	void signalSendPicName(QString str);

public slots:
   void slotReceivePicName(QString str);

   void updataProgress(qint64 num_bytes);
protected:
	bool loginCarema();
public slots:

 void slotTCPConnectincoming();
 void slotConnect_suc();
 void slotClient_dis();

public:
 QTcpSocket*  mSocketM;
private:
    Ui::showDataClass ui;
	QTcpServer*  mServerM;
	//QTcpSocket*  mSocketM;

	configInfo config_;  // 登录inxi


	LONG lUserID; // 注册设备(播放)


	//抓拍结构体
	NET_DVR_SNAPCFG struSnapCfg;



	quint64 total_btyes,
		bytes_written,
		bytes_to_write,
		load_size;
	QString file_name;
	QFile *local_file;
	QByteArray out_block;

	
};
