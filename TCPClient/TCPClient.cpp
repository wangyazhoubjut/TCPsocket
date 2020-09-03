#include "TCPClient.h"
#include <QMessageBox>
#include <QByteArray>
#include <QImageReader>
TCPClient::TCPClient(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	mp_clientSocket = NULL;
	
	total_bytes = received_bytes = file_name_size = 0;

	if (mp_clientSocket == NULL)
	{
		mp_clientSocket = new QTcpSocket();
	}

	mp_clientSocket->connectToHost("192.168.1.157", 2000);
	if (!mp_clientSocket->waitForConnected(30000))
	{

		QMessageBox::information(this, "QT����ͨ��", "���ӷ����ʧ�ܣ�");
		return;

	}
	connect(mp_clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onClicked()));

}
void TCPClient::onClicked()
{

	char sendMsgChar[1024] = { 0 };

	strcpy_s(sendMsgChar, "1");

	int sendRe = mp_clientSocket->write(sendMsgChar, strlen(sendMsgChar));

	if (sendRe == -1)

	{

		QMessageBox::information(this, "QT����ͨ��", "�����˷�������ʧ�ܣ�");

		return;

	}

}


void TCPClient::ClientRecvData()
{

	qDebug() << "bytesAvailable" << mp_clientSocket->bytesAvailable() << endl;

	QDataStream in(mp_clientSocket);
	in.setVersion(QDataStream::Qt_5_8);

	// �����û��д �ܳ��Ⱥ��ļ�������
	if (received_bytes <= sizeof(qint64) * 2)
	{
		//д �ܳ��� �� �ļ�������
		if ((mp_clientSocket->bytesAvailable() >= sizeof(qint64) * 2) && file_name_size == 0)
		{
			in >> total_bytes >> file_name_size;
			received_bytes += sizeof(qint64) * 2;
		}

		//received_bytes == sizeof(qint64)*2ʱ  д���ļ���
		if (mp_clientSocket->bytesAvailable() >= file_name_size && file_name_size != 0)
		{
			in >> file_name;
			received_bytes += file_name_size;
			local_file = new QFile("1.jpg");

			if (!local_file->open(QFile::WriteOnly))
			{
				QMessageBox::warning(this, tr("Ӧ�ó���"),
					tr("�޷���ȡ�ļ� %1:\n%2.")
					.arg(file_name)
					.arg(local_file->errorString()));
				return;
			}
		}
		else
			return;
	}

	//д���ļ�����
	if (received_bytes < total_bytes)
	{
		received_bytes += mp_clientSocket->bytesAvailable();
		in_block = mp_clientSocket->readAll();
		qDebug() << "in_block" << in_block << endl;
		local_file->write(in_block);
		in_block.resize(0);
	}

	//���½�����
	//ui.progressBar->setMaximum(total_bytes);
	//ui.progressBar->setValue(received_bytes);
	//ui.label->setText(tr("%1 %").arg(QString::number(received_bytes / total_bytes * 100)));

	//�����������
	if (received_bytes == total_bytes)
	{
		mp_clientSocket->close();
		//ui.ButtonRecive->setEnabled(true);
		QApplication::restoreOverrideCursor();
	}
}