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
	//以下代码仅供参考，实际应用中不建议在该回调函数中直接处理数据保存文件，
	//例如可以使用消息的方式(PostMessage)在消息响应函数里进行处理。

	char filename[100];  //
	switch (lCommand)
	{
	case COMM_UPLOAD_PLATE_RESULT:
	{
		NET_DVR_PLATE_RESULT struPlateResult = { 0 };
		memcpy(&struPlateResult, pAlarmInfo, sizeof(struPlateResult));
		printf("车牌号: %s\n", struPlateResult.struPlateInfo.sLicense);//车牌号
		switch (struPlateResult.struPlateInfo.byColor)//车牌颜色
		{
		case VCA_BLUE_PLATE:
			printf("车辆颜色: 蓝色\n");
			break;
		case VCA_YELLOW_PLATE:
			printf("车辆颜色: 黄色\n");
			break;
		case VCA_WHITE_PLATE:
			printf("车辆颜色: 白色\n");
			break;
		case VCA_BLACK_PLATE:
			printf("车辆颜色: 黑色\n");
			break;
		default:
			break;
		}
		//场景图
		if (struPlateResult.dwPicLen != 0 && struPlateResult.byResultType == 1)
		{
			//sprintf(filename, "testpic_%d.jpg", iNum);
			fSnapPic = fopen(filename, "wb");
			fwrite(struPlateResult.pBuffer1, struPlateResult.dwPicLen, 1, fSnapPic);
			//iNum++;
			fclose(fSnapPic);
		}
		//车牌图
			if (struPlateResult.dwPicPlateLen != 0 && struPlateResult.byResultType == 1)
			{
				//sprintf(filename, "testPicPlate_%d.jpg", iNum);
				fSnapPicPlate = fopen(filename, "wb");
				fwrite(struPlateResult.pBuffer1, struPlateResult.dwPicLen, 1, fSnapPicPlate);
				//iNum++;
				fclose(fSnapPicPlate);
			}
		//其他信息处理......
		break;
	}
	case COMM_ITS_PLATE_RESULT:
	{
		NET_ITS_PLATE_RESULT struITSPlateResult = { 0 };
		memcpy(&struITSPlateResult, pAlarmInfo, sizeof(struITSPlateResult));
		for (i = 0; i < struITSPlateResult.dwPicNum; i++)
		{
			printf("车牌号: %s\n", struITSPlateResult.struPlateInfo.sLicense);//车牌号
			switch (struITSPlateResult.struPlateInfo.byColor)//车牌颜色
			{
			case VCA_BLUE_PLATE:
				printf("车辆颜色: 蓝色\n");
				break;
			case VCA_YELLOW_PLATE:
				printf("车辆颜色: 黄色\n");
				break;
			case VCA_WHITE_PLATE:
				printf("车辆颜色: 白色\n");
				break;
			case VCA_BLACK_PLATE:
				printf("车辆颜色: 黑色\n");
				break;
			default:
				break;
			}
			//保存场景图
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
			//车牌小图片
			if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) && (struITSPlateResult.struPicInfo[i].byType == 0))
			{
				//sprintf(filename, "testPicPlate%d_%d.jpg", iNum, i);
				fSnapPicPlate = fopen(filename, "wb");
				fwrite(struITSPlateResult.struPicInfo[i].pBuffer, struITSPlateResult.struPicInfo[i].dwDataLen, 1, \
					fSnapPicPlate);
				//iNum++;
				fclose(fSnapPicPlate);
			}
			//其他信息处理......
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


	//海康威视摄像头初始化及登录操作
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
	//结构体大小
	struSnapCfg.dwSize = sizeof(NET_DVR_SNAPCFG);
	//线圈抓拍次数，0-不抓拍，非 0-连拍次数，目前最大 5 次
	struSnapCfg.bySnapTimes = 1;
	//抓拍等待时间，单位 ms，取值范围[0,60000]
	struSnapCfg.wSnapWaitTime = 10;
	//连拍间隔时间，单位 ms，取值范围[67,60000]
	struSnapCfg.wIntervalTime[0] = 1000;
	struSnapCfg.wIntervalTime[1] = 1000;
	//触发 IO 关联的车道号，取值范围[0,9]
	struSnapCfg.byRelatedDriveWay = 1;
	struSnapCfg.dwSnapVehicleNum = 10;

	mServerM = new QTcpServer();
	connect(mServerM, SIGNAL(newConnection()), this, SLOT(slotTCPConnectincoming())); //连接客户端
	mServerM->listen(QHostAddress::Any, 2000);

}


bool showData::loginCarema()
{
	// 初始化
	NET_DVR_Init();
	//设置连接时间与重连时间
	NET_DVR_SetConnectTime(2000, 1);
	NET_DVR_SetReconnect(10000, true);

	//登录参数，包括设备地址、登录用户、密码等
	NET_DVR_USER_LOGIN_INFO struLoginInfo = { 0 };
	struLoginInfo.bUseAsynLogin = 0; //同步登录方式
	strcpy(struLoginInfo.sDeviceAddress, config_.devIp.toStdString().c_str()); //设备IP地址
	struLoginInfo.wPort = 8000; //设备服务端口
	strcpy(struLoginInfo.sUserName, config_.devUser.toStdString().c_str()); //设备登录用户名
	strcpy(struLoginInfo.sPassword, config_.devPwd.toStdString().c_str()); //设备登录密码

																		   //设备信息, 输出参数
	NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = { 0 };

	lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
	if (lUserID < 0)
	{
		qDebug() << "Login failed, error code:" << NET_DVR_GetLastError();
		NET_DVR_Cleanup();
		return false;
	}

	qDebug() << "NET_DVR_Login_V40 success!";

	//设置报警回调
	NET_DVR_SetDVRMessageCallBack_V30(MSesGCallback, this);
	
	//启用不妨
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
	struPlayInfo.hPlayWnd = g_hWnd1;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
	struPlayInfo.lChannel = 1;       //预览通道号
	struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
	struPlayInfo.dwLinkMode = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
	struPlayInfo.bBlocked = 1;       //0- 非阻塞取流，1- 阻塞取流

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
  
	mSocketM = mServerM->nextPendingConnection();//与客户端通信的套接字
												 //关联接收客户端数据信号readyRead信号（客户端有数据就会发readyRead信号）
	connect(mSocketM, SIGNAL(readyRead()), this, SLOT(slotConnect_suc()));
	//检测掉线信号
	connect(mSocketM, SIGNAL(disconnected()), this, SLOT(slotClient_dis()));
	//ui->labelZt->setText(QString::fromLocal8Bit("状态：已连接"));
	connect(mSocketM, SIGNAL(bytesWritten(qint64)), this, SLOT(updataProgress(qint64)));

	total_btyes = bytes_written = bytes_to_write = 0;
	load_size = 4 * 1024; //设置每次发送4KB大小

}


void showData::slotConnect_suc()
{
	//可以实现同时读取多个客户端发送过来的消息
	QTcpSocket *obj = (QTcpSocket*)sender();

	//obj->ip
	QByteArray msg = obj->readAll();
	unsigned short size = msg.size();

	qDebug() << "MSG:" << msg << endl;

	if ("1" == msg)
	{
		qDebug() << "Receive the Command Capture Pic" << msg << endl;

		// start抓图  jpgbuffer

		if (lUserID == -1)
		{
			//MessageBox("请先选择一个通道播放");
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
	QTcpSocket *obj = (QTcpSocket*)sender();//掉线对象
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
		QMessageBox::warning(this, tr("应用程序"),
			tr("无法读取文件 %1:\n%2.")
			.arg(file_name)
			.arg(local_file->errorString()));
		return;
	}

	//将待发送文件的大小暂存于total_btyes中
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


	//重头开始操作写
	out.device()->seek(0);
	//写入总长度和文件名长度 (文件名已经在前面被写进去了）
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
		//尽量每次发送4kb（load_size)
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