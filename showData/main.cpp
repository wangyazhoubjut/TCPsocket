#include "showData.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	showData w;
	w.show();
	return a.exec();
}

//#include <stdio.h>
//#include <iostream>
//#include "Windows.h"
//#include "HCNetSDK.h"
//using namespace std;
////typedef HWND(WINAPI *PROCGETCONSOLEWINDOW)();
////PROCGETCONSOLEWINDOW GetConsoleWindow;
//int iNum = 0;
//void CALLBACK MSesGCallback1(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void*
//	pUser)
//{
//	int i = 0;
//	char filename[100];
//	FILE *fSnapPic = NULL;
//	FILE *fSnapPicPlate = NULL;
//	//以下代码仅供参考，实际应用中不建议在该回调函数中直接处理数据保存文件，
//	//例如可以使用消息的方式(PostMessage)在消息响应函数里进行处理。
//	switch (lCommand)
//	{
//	case COMM_UPLOAD_PLATE_RESULT:
//	{
//		NET_DVR_PLATE_RESULT struPlateResult = { 0 };
//		memcpy(&struPlateResult, pAlarmInfo, sizeof(struPlateResult));
//		printf("车牌号: %s\n", struPlateResult.struPlateInfo.sLicense);//车牌号
//		switch (struPlateResult.struPlateInfo.byColor)//车牌颜色
//		{
//		case VCA_BLUE_PLATE:
//			printf("车辆颜色: 蓝色\n");
//			break;
//		case VCA_YELLOW_PLATE:
//			printf("车辆颜色: 黄色\n");
//			break;
//		case VCA_WHITE_PLATE:
//			printf("车辆颜色: 白色\n");
//			break;
//		case VCA_BLACK_PLATE:
//			printf("车辆颜色: 黑色\n");
//			break;
//		default:
//			break;
//		}
//		//场景图
//		if (struPlateResult.dwPicLen != 0 && struPlateResult.byResultType == 1)
//		{
//			sprintf(filename, "testpic_%d.jpg", iNum);
//			fSnapPic = fopen(filename, "wb");
//			fwrite(struPlateResult.pBuffer1, struPlateResult.dwPicLen, 1, fSnapPic);
//			iNum++;
//			fclose(fSnapPic);
//		}
//		//车牌图
//			if (struPlateResult.dwPicPlateLen != 0 && struPlateResult.byResultType == 1)
//			{
//				sprintf(filename, "testPicPlate_%d.jpg", iNum);
//				fSnapPicPlate = fopen(filename, "wb");
//				fwrite(struPlateResult.pBuffer1, struPlateResult.dwPicLen, 1, fSnapPicPlate);
//				iNum++;
//				fclose(fSnapPicPlate);
//			}
//		//其他信息处理......
//		break;
//	}
//	case COMM_ITS_PLATE_RESULT:
//	{
//		NET_ITS_PLATE_RESULT struITSPlateResult = { 0 };
//		memcpy(&struITSPlateResult, pAlarmInfo, sizeof(struITSPlateResult));
//		for (i = 0; i < struITSPlateResult.dwPicNum; i++)
//		{
//			printf("车牌号: %s\n", struITSPlateResult.struPlateInfo.sLicense);//车牌号
//			switch (struITSPlateResult.struPlateInfo.byColor)//车牌颜色
//			{
//			case VCA_BLUE_PLATE:
//				printf("车辆颜色: 蓝色\n");
//				break;
//			case VCA_YELLOW_PLATE:
//				printf("车辆颜色: 黄色\n");
//				break;
//			case VCA_WHITE_PLATE:
//				printf("车辆颜色: 白色\n");
//				break;
//			case VCA_BLACK_PLATE:
//				printf("车辆颜色: 黑色\n");
//				break;
//			default:
//				break;
//			}
//			//保存场景图
//			if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) && (struITSPlateResult.struPicInfo[i].byType ==
//				1) || (struITSPlateResult.struPicInfo[i].byType == 2))
//			{
//				sprintf(filename, "testITSpic%d_%d.jpg", iNum, i);
//				fSnapPic = fopen(filename, "wb");
//				fwrite(struITSPlateResult.struPicInfo[i].pBuffer, struITSPlateResult.struPicInfo[i].dwDataLen, 1, fSnapPic);
//				iNum++;
//					fclose(fSnapPic);
//			}
//			//车牌小图片
//			if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) && (struITSPlateResult.struPicInfo[i].byType == 0))
//			{
//				sprintf(filename, "testPicPlate%d_%d.jpg", iNum, i);
//				fSnapPicPlate = fopen(filename, "wb");
//				fwrite(struITSPlateResult.struPicInfo[i].pBuffer, struITSPlateResult.struPicInfo[i].dwDataLen, 1, \
//					fSnapPicPlate);
//				iNum++;
//				fclose(fSnapPicPlate);
//			}
//			//其他信息处理......
//		}
//		break;
//	}
//	default:
//		break;
//	}
//	return;
//}
//void main()
//{
//	//---------------------------------------
//	//初始化
//	NET_DVR_Init();
//	//获取控制台窗口句柄
//	//HMODULE hKernel32 = GetModuleHandle("kernel32");
//	//GetConsoleWindow = (PROCGETCONSOLEWINDOW)GetProcAddress(hKernel32, "GetConsoleWindow");
//	//设置连接时间与重连时间
//	NET_DVR_SetConnectTime(2000, 1);
//	NET_DVR_SetReconnect(10000, true);
//	//---------------------------------------
//	//注册设备
//	LONG lUserID;
//	NET_DVR_DEVICEINFO_V30 struDeviceInfo;
//	lUserID = NET_DVR_Login_V30("192.168.1.50", 8000, "admin", "hskj12345", &struDeviceInfo);
//	if (lUserID < 0)
//	{
//		printf("Login error, %d\n", NET_DVR_GetLastError());
//		NET_DVR_Cleanup();
//			return;
//	}
//	//设置报警回调函数
//	NET_DVR_SetDVRMessageCallBack_V30(MSesGCallback1, NULL);
//	//启用布防
//	NET_DVR_SETUPALARM_PARAM struSetupParam = { 0 };
//	struSetupParam.dwSize = sizeof(NET_DVR_SETUPALARM_PARAM);
//	//上传报警信息类型: 0- 老报警信息(NET_DVR_PLATE_RESULT), 1- 新报警信息(NET_ITS_PLATE_RESULT)
//	struSetupParam.byAlarmInfoType = 0;
//	LONG lHandle = NET_DVR_SetupAlarmChan_V41(lUserID, &struSetupParam);
//	if (lHandle < 0)
//	{
//		printf("NET_DVR_SetupAlarmChan_V41 error, %d\n", NET_DVR_GetLastError());
//		NET_DVR_Logout(lUserID);
//		NET_DVR_Cleanup();
//		return;
//	}
//	//---------------------------------------
//	//启动预览
//	LONG lRealPlayHandle;
//	HWND hWnd = GetConsoleWindow(); //获取窗口句柄
//	NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
//	struPlayInfo.hPlayWnd = hWnd; //需要 SDK 解码时句柄设为有效值，仅取流不解码时可为空(设置回调函数)
//	struPlayInfo.lChannel = 1; //预览通道号
//	struPlayInfo.dwStreamType = 0; //0-主码流，1-子码流，2-码流 3，3-码流 4，以此类推
//	struPlayInfo.dwLinkMode = 0; //0- TCP 方式，1- UDP 方式，2- 多播方式，3- RTP 方式，4-RTP/RTSP，5-RSTP/HTTP
//	struPlayInfo.bBlocked = 1; //0- 非阻塞取流，1- 阻塞取流
//	lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, NULL, NULL);
//	if (lRealPlayHandle < 0) //预览失败
//	{
//		printf("NET_DVR_RealPlay_V40 error, %d\n", NET_DVR_GetLastError());
//		NET_DVR_Logout(lUserID);
//		NET_DVR_Cleanup();
//		return;
//	}
//	Sleep(5000);
//	//关闭预览
//	NET_DVR_StopRealPlay(lRealPlayHandle);
//	printf("\n");
//	printf("\n");
//	printf("\n");
//		////////////////////////////////////////////////////////////
//		//网络触发抓拍
//		NET_DVR_SNAPCFG struSnapCfg;
//	memset(&struSnapCfg, 0, sizeof(NET_DVR_SNAPCFG));
//	//结构体大小
//	struSnapCfg.dwSize = sizeof(NET_DVR_SNAPCFG);
//	//线圈抓拍次数，0-不抓拍，非 0-连拍次数，目前最大 5 次
//	struSnapCfg.bySnapTimes = 1;
//	//抓拍等待时间，单位 ms，取值范围[0,60000]
//	struSnapCfg.wSnapWaitTime = 1000;
//	//连拍间隔时间，单位 ms，取值范围[67,60000]
//	struSnapCfg.wIntervalTime[0] = 1000;
//	struSnapCfg.wIntervalTime[1] = 1000;
//	//触发 IO 关联的车道号，取值范围[0,9]
//	struSnapCfg.byRelatedDriveWay = 0;
//	//网络触发连拍
//	if (!NET_DVR_ContinuousShoot(lUserID, &struSnapCfg))
//	{
//		printf("NET_DVR_ContinuousShoot error, %d\n", NET_DVR_GetLastError());
//		return;
//	}
//	//---------------------------------------
//	//退出
//	Sleep(20000);
//	//撤销布防上传通道
//	if (!NET_DVR_CloseAlarmChan_V30(lHandle))
//	{
//		printf("NET_DVR_CloseAlarmChan_V30 error, %d\n", NET_DVR_GetLastError());
//		NET_DVR_Logout(lUserID);
//		NET_DVR_Cleanup();
//		return;
//	}//注销用户
//	NET_DVR_Logout(lUserID);
//	//释放 SDK 资源
//	NET_DVR_Cleanup();
//	return;
//}