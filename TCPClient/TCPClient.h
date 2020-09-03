#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TCPClient.h"
#include <QBuffer>
#include <QTcpServer>  
#include <QTcpSocket>
#include <QMessageBox>
#include <QFile>
class TCPClient : public QMainWindow
{
    Q_OBJECT

public:
    TCPClient(QWidget *parent = Q_NULLPTR);

private:
    Ui::TCPClientClass ui;
	QTcpSocket* mp_clientSocket;
public slots:

	void onClicked();
	void ClientRecvData();

private:
	qint64 total_bytes;
	qint64 received_bytes;
	qint64 file_name_size;
	QString file_name;
	QFile *local_file;
	QByteArray in_block;

};
