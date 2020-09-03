#include "showData.h"

#include <QString>
#include <QByteArray>
#include "HCNetSDK.h"
#include <QDateTime>
#include <QMessageBox>
#pragma comment(lib,"./HKlib_64/HCNetSDK.lib")


void CALLBACK MSesGCallback(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void*
	pUser)
{

	showData* p = (showData*)pUser;

	int i = 0;
	FILE *fSnapPic = NULL;
	FILE *fSnapPicPlate = NULL;
	//���´�������ο���ʵ��Ӧ���в������ڸûص�������ֱ�Ӵ������ݱ����ļ���
	//�������ʹ����Ϣ�ķ�ʽ(PostMessage)����Ϣ��Ӧ��������д���

	char filename[100];  //
	switch (lCommand)
	{
	case COMM_UPLOAD_PLATE_RESULT:
	{
		NET_DVR_PLATE_RESULT struPlateResult = { 0 };
		memcpy(&struPlateResult, pAlarmInfo, sizeof(struPlateResult));
		printf("���ƺ�: %s\n", struPlateResult.struPlateInfo.sLicense);//���ƺ�
		switch (struPlateResult.struPlateInfo.byColor)//������ɫ
		{
		case VCA_BLUE_PLATE:
			printf("������ɫ: ��ɫ\n");
			break;
		case VCA_YELLOW_PLATE:
			printf("������ɫ: ��ɫ\n");
			break;
		case VCA_WHITE_PLATE:
			printf("������ɫ: ��ɫ\n");
			break;
		case VCA_BLACK_PLATE:
			printf("������ɫ: ��ɫ\n");
			break;
		default:
			break;
		}
		//����ͼ
		if (struPlateResult.dwPicLen != 0 && struPlateResult.byResultType == 1)
		{
			//sprintf(filename, "testpic_%d.jpg", iNum);
			fSnapPic = fopen(filename, "wb");
			fwrite(struPlateResult.pBuffer1, struPlateResult.dwPicLen, 1, fSnapPic);
			//iNum++;
			fclose(fSnapPic);
		}
		//����ͼ
			if (struPlateResult.dwPicPlateLen != 0 && struPlateResult.byResultType == 1)
			{
				//sprintf(filename, "testPicPlate_%d.jpg", iNum);
				fSnapPicPlate = fopen(filename, "wb");
				fwrite(struPlateResult.pBuffer1, struPlateResult.dwPicLen, 1, fSnapPicPlate);
				//iNum++;
				fclose(fSnapPicPlate);
			}
		//������Ϣ����......
		break;
	}
	case COMM_ITS_PLATE_RESULT:
	{
		NET_ITS_PLATE_RESULT struITSPlateResult = { 0 };
		memcpy(&struITSPlateResult, pAlarmInfo, sizeof(struITSPlateResult));
		for (i = 0; i < struITSPlateResult.dwPicNum; i++)
		{
			printf("���ƺ�: %s\n", struITSPlateResult.struPlateInfo.sLicense);//���ƺ�
			switch (struITSPlateResult.struPlateInfo.byColor)//������ɫ
			{
			case VCA_BLUE_PLATE:
				printf("������ɫ: ��ɫ\n");
				break;
			case VCA_YELLOW_PLATE:
				printf("������ɫ: ��ɫ\n");
				break;
			case VCA_WHITE_PLATE:
				printf("������ɫ: ��ɫ\n");
				break;
			case VCA_BLACK_PLATE:
				printf("������ɫ: ��ɫ\n");
				break;
			default:
				break;
			}
			//���泡��ͼ
			if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) && (struITSPlateResult.struPicInfo[i].byType ==
				1) || (struITSPlateResult.struPicInfo[i].byType == 2))
			{

				
				QDateTime current_date_time = QDateTime::currentDateTime();
				//QString current_date = current_date_time.currentDateTimeUtc()
			   /* sprintf(filename, "%04d%02d%02d%02d%02d%02d_ch%02d.bmp", current_date_time, current_date_time.month(), current_date_time.day(), \
					current_date_time.h, CurTime.GetMinute(), CurTime.GetSecond(), m_struDeviceInfo.struChanInfo[GetCurChanIndex()].iChanIndex);
				sprintf(filename, "%s.jpg", current_date.toStdString().c_str());*/
				sprintf(filename, "%d.jpg", current_date_time.toTime_t());
				//qDebug() << filename << endl;

				fSnapPic = fopen(filename, "wb");
				fwrite(struITSPlateResult.struPicInfo[i].pBuffer, struITSPlateResult.struPicInfo[i].dwDataLen, 1, fSnapPic);
				//iNum++;
				fclose(fSnapPic);
				

				p->signalSendPicName(QString(filename));

			}
			//����СͼƬ
			if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) && (struITSPlateResult.struPicInfo[i].byType == 0))
			{
				//sprintf(filename, "testPicPlate%d_%d.jpg", iNum, i);
				fSnapPicPlate = fopen(filename, "wb");
				fwrite(struITSPlateResult.struPicInfo[i].pBuffer, struITSPlateResult.struPicInfo[i].dwDataLen, 1, \
					fSnapPicPlate);
				//iNum++;
				fclose(fSnapPicPlate);
			}
			//������Ϣ����......
		}
		break;
	}
	default:
		break;
	}
	return;
}


showData::showData(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	QObject::connect(this, SIGNAL(signalSendPicName(QString)),this, SLOT(slotReceivePicName(QString)));
	//signalSendPicName(QString str)


	//������������ͷ��ʼ������¼����
	config_.devIp = "192.168.6.184";
	config_.devPort = "8000";
	config_.devUser = "admin";
	config_.devPwd = "hskj12345";

	if (loginCarema())
	{
		QMessageBox::about(NULL, "About", "About this application");
	}
	





	/*NET_DVR_SNAPCFG struSnapCfg;
	CString csTemp;*/

	//memset(&struSnapCfg, 0, sizeof(NET_DVR_SNAPCFG));
	//struSnapCfg.dwSize = sizeof(NET_DVR_SNAPCFG);
	//struSnapCfg.byRelatedDriveWay = nDriveWay;
	//struSnapCfg.bySnapTimes = 1;
	//struSnapCfg.wSnapWaitTime = 10;
	//struSnapCfg.wIntervalTime[0] = 1000;
	//struSnapCfg.wIntervalTime[1] = 1000;
	//struSnapCfg.wIntervalTime[2] = 1000;
	//struSnapCfg.wIntervalTime[3] = 1000;
	////struSnapCfg.dwSnapVehicleNum = g_nSnapVehicleNum;//gCount;//58;



	memset(&struSnapCfg, 0, sizeof(NET_DVR_SNAPCFG));
	//�ṹ���С
	struSnapCfg.dwSize = sizeof(NET_DVR_SNAPCFG);
	//��Ȧץ�Ĵ�����0-��ץ�ģ��� 0-���Ĵ�����Ŀǰ��� 5 ��
	struSnapCfg.bySnapTimes = 1;
	//ץ�ĵȴ�ʱ�䣬��λ ms��ȡֵ��Χ[0,60000]
	struSnapCfg.wSnapWaitTime = 10;
	//���ļ��ʱ�䣬��λ ms��ȡֵ��Χ[67,60000]
	struSnapCfg.wIntervalTime[0] = 1000;
	struSnapCfg.wIntervalTime[1] = 1000;
	//���� IO �����ĳ����ţ�ȡֵ��Χ[0,9]
	struSnapCfg.byRelatedDriveWay = 1;
	struSnapCfg.dwSnapVehicleNum = 10;

	mServerM = new QTcpServer();
	connect(mServerM, SIGNAL(newConnection()), this, SLOT(slotTCPConnectincoming())); //���ӿͻ���
	mServerM->listen(QHostAddress::Any, 2000);

}


bool showData::loginCarema()
{
	// ��ʼ��
	NET_DVR_Init();
	//��������ʱ��������ʱ��
	NET_DVR_SetConnectTime(2000, 1);
	NET_DVR_SetReconnect(10000, true);

	//��¼�����������豸��ַ����¼�û��������
	NET_DVR_USER_LOGIN_INFO struLoginInfo = { 0 };
	struLoginInfo.bUseAsynLogin = 0; //ͬ����¼��ʽ
	strcpy(struLoginInfo.sDeviceAddress, config_.devIp.toStdString().c_str()); //�豸IP��ַ
	struLoginInfo.wPort = 8000; //�豸����˿�
	strcpy(struLoginInfo.sUserName, config_.devUser.toStdString().c_str()); //�豸��¼�û���
	strcpy(struLoginInfo.sPassword, config_.devPwd.toStdString().c_str()); //�豸��¼����

																		   //�豸��Ϣ, �������
	NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = { 0 };

	lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
	if (lUserID < 0)
	{
		qDebug() << "Login failed, error code:" << NET_DVR_GetLastError();
		NET_DVR_Cleanup();
		return false;
	}

	qDebug() << "NET_DVR_Login_V40 success!";

	//���ñ����ص�
	NET_DVR_SetDVRMessageCallBack_V30(MSesGCallback, this);
	
	//���ò���
	NET_DVR_SETUPALARM_PARAM struSetupParam = { 0 };
	struSetupParam.dwSize = sizeof(NET_DVR_SETUPALARM_PARAM);
	struSetupParam.byAlarmInfoType = 1;
	LONG lHandle = NET_DVR_SetupAlarmChan_V41(lUserID, &struSetupParam);
	if (lHandle < 0)
	{
		printf("NET_DVR_SetupAlarmChan_V41 error, %d\n", NET_DVR_GetLastError());
		NET_DVR_Logout(lUserID);
		NET_DVR_Cleanup();
		return false;
	}

	NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
	HWND g_hWnd1 = (HWND)ui.label->winId();
	struPlayInfo.hPlayWnd = g_hWnd1;         //��ҪSDK����ʱ�����Ϊ��Чֵ����ȡ��������ʱ����Ϊ��
	struPlayInfo.lChannel = 1;       //Ԥ��ͨ����
	struPlayInfo.dwStreamType = 0;       //0-��������1-��������2-����3��3-����4���Դ�����
	struPlayInfo.dwLinkMode = 0;       //0- TCP��ʽ��1- UDP��ʽ��2- �ಥ��ʽ��3- RTP��ʽ��4-RTP/RTSP��5-RSTP/HTTP
	struPlayInfo.bBlocked = 1;       //0- ������ȡ����1- ����ȡ��

	LONG lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, NULL, NULL);
	if (lRealPlayHandle < 0)
	{
		qDebug() << "NET_DVR_RealPlay_V40 error:" << NET_DVR_GetLastError();
		NET_DVR_Logout(lUserID);
		NET_DVR_Cleanup();
		return false;
	}
	qDebug() << "NET_DVR_RealPlay_V40 success!";


	return true;
}

void showData::slotTCPConnectincoming()
{
  
	mSocketM = mServerM->nextPendingConnection();//��ͻ���ͨ�ŵ��׽���
												 //�������տͻ��������ź�readyRead�źţ��ͻ��������ݾͻᷢreadyRead�źţ�
	connect(mSocketM, SIGNAL(readyRead()), this, SLOT(slotConnect_suc()));
	//�������ź�
	connect(mSocketM, SIGNAL(disconnected()), this, SLOT(slotClient_dis()));
	//ui->labelZt->setText(QString::fromLocal8Bit("״̬��������"));
	connect(mSocketM, SIGNAL(bytesWritten(qint64)), this, SLOT(updataProgress(qint64)));

	total_btyes = bytes_written = bytes_to_write = 0;
	load_size = 4 * 1024; //����ÿ�η���4KB��С

}


void showData::slotConnect_suc()
{
	//����ʵ��ͬʱ��ȡ����ͻ��˷��͹�������Ϣ
	QTcpSocket *obj = (QTcpSocket*)sender();

	//obj->ip
	QByteArray msg = obj->readAll();
	unsigned short size = msg.size();

	qDebug() << "MSG:" << msg << endl;

	if ("1" == msg)
	{
		qDebug() << "Receive the Command Capture Pic" << msg << endl;

		// startץͼ  jpgbuffer

		if (lUserID == -1)
		{
			//MessageBox("����ѡ��һ��ͨ������");
			return;
		}


		if (!NET_DVR_ContinuousShoot(lUserID, &struSnapCfg))
		{
			printf("NET_DVR_ContinuousShoot error, %d\n", NET_DVR_GetLastError());
			return;
		}


	}
}


void showData::slotClient_dis()
{
	QTcpSocket *obj = (QTcpSocket*)sender();//���߶���
	//ui->labelZt->setText(obj->peerAddress().toString());
}

void showData::slotReceivePicName(QString picName)
{

	if (picName.isEmpty())
	{
		return;
	}
	

	local_file = new QFile(picName);

	if (!local_file->open(QFile::ReadOnly))
	{
		QMessageBox::warning(this, tr("Ӧ�ó���"),
			tr("�޷���ȡ�ļ� %1:\n%2.")
			.arg(file_name)
			.arg(local_file->errorString()));
		return;
	}

	//���������ļ��Ĵ�С�ݴ���total_btyes��
	total_btyes = local_file->size();

	//qDebug() << "PicFilesize" << total_btyes << endl;

	QDataStream out(&out_block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_8);

//	qDebug() << "outBlockSize"<<out_block.size();

	QString currrent_file = picName.right(picName.size() - picName.lastIndexOf('/') - 1);
	out << qint64(0) << qint64(0) << currrent_file;
	//qDebug() << "qint64Size" << sizeof(qint64(0))<<endl;
	//qDebug() << "currrent_file" << currrent_file.size()<<endl;
	
	//qDebug() <<"out_block size"<< out_block.size() << endl;
	//qDebug() << "out_ " << out << endl;

//	qDebug() << out_block << endl;
	total_btyes += out_block.size();


	//��ͷ��ʼ����д
	out.device()->seek(0);
	//д���ܳ��Ⱥ��ļ������� (�ļ����Ѿ���ǰ�汻д��ȥ�ˣ�
	out << total_btyes << qint64((out_block.size() - sizeof(qint64) * 2));
	//QDataStream out(&out_block, QIODevice::WriteOnly);
	bytes_to_write = total_btyes - mSocketM->write(out_block);
	out_block.resize(0);


}

void showData::updataProgress(qint64 num_bytes)
{
	bytes_written += (int)num_bytes;

	if (bytes_to_write > 0)
	{
		//����ÿ�η���4kb��load_size)
		out_block = local_file->read(qMin(bytes_to_write, load_size));
		bytes_to_write -= (int)mSocketM->write(out_block);
		out_block.resize(0);
	}
	else
	{
		mSocketM->close();
		local_file->close();
		QApplication::restoreOverrideCursor();
	}

}