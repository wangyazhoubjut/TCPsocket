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
//	//���´�������ο���ʵ��Ӧ���в������ڸûص�������ֱ�Ӵ������ݱ����ļ���
//	//�������ʹ����Ϣ�ķ�ʽ(PostMessage)����Ϣ��Ӧ��������д���
//	switch (lCommand)
//	{
//	case COMM_UPLOAD_PLATE_RESULT:
//	{
//		NET_DVR_PLATE_RESULT struPlateResult = { 0 };
//		memcpy(&struPlateResult, pAlarmInfo, sizeof(struPlateResult));
//		printf("���ƺ�: %s\n", struPlateResult.struPlateInfo.sLicense);//���ƺ�
//		switch (struPlateResult.struPlateInfo.byColor)//������ɫ
//		{
//		case VCA_BLUE_PLATE:
//			printf("������ɫ: ��ɫ\n");
//			break;
//		case VCA_YELLOW_PLATE:
//			printf("������ɫ: ��ɫ\n");
//			break;
//		case VCA_WHITE_PLATE:
//			printf("������ɫ: ��ɫ\n");
//			break;
//		case VCA_BLACK_PLATE:
//			printf("������ɫ: ��ɫ\n");
//			break;
//		default:
//			break;
//		}
//		//����ͼ
//		if (struPlateResult.dwPicLen != 0 && struPlateResult.byResultType == 1)
//		{
//			sprintf(filename, "testpic_%d.jpg", iNum);
//			fSnapPic = fopen(filename, "wb");
//			fwrite(struPlateResult.pBuffer1, struPlateResult.dwPicLen, 1, fSnapPic);
//			iNum++;
//			fclose(fSnapPic);
//		}
//		//����ͼ
//			if (struPlateResult.dwPicPlateLen != 0 && struPlateResult.byResultType == 1)
//			{
//				sprintf(filename, "testPicPlate_%d.jpg", iNum);
//				fSnapPicPlate = fopen(filename, "wb");
//				fwrite(struPlateResult.pBuffer1, struPlateResult.dwPicLen, 1, fSnapPicPlate);
//				iNum++;
//				fclose(fSnapPicPlate);
//			}
//		//������Ϣ����......
//		break;
//	}
//	case COMM_ITS_PLATE_RESULT:
//	{
//		NET_ITS_PLATE_RESULT struITSPlateResult = { 0 };
//		memcpy(&struITSPlateResult, pAlarmInfo, sizeof(struITSPlateResult));
//		for (i = 0; i < struITSPlateResult.dwPicNum; i++)
//		{
//			printf("���ƺ�: %s\n", struITSPlateResult.struPlateInfo.sLicense);//���ƺ�
//			switch (struITSPlateResult.struPlateInfo.byColor)//������ɫ
//			{
//			case VCA_BLUE_PLATE:
//				printf("������ɫ: ��ɫ\n");
//				break;
//			case VCA_YELLOW_PLATE:
//				printf("������ɫ: ��ɫ\n");
//				break;
//			case VCA_WHITE_PLATE:
//				printf("������ɫ: ��ɫ\n");
//				break;
//			case VCA_BLACK_PLATE:
//				printf("������ɫ: ��ɫ\n");
//				break;
//			default:
//				break;
//			}
//			//���泡��ͼ
//			if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) && (struITSPlateResult.struPicInfo[i].byType ==
//				1) || (struITSPlateResult.struPicInfo[i].byType == 2))
//			{
//				sprintf(filename, "testITSpic%d_%d.jpg", iNum, i);
//				fSnapPic = fopen(filename, "wb");
//				fwrite(struITSPlateResult.struPicInfo[i].pBuffer, struITSPlateResult.struPicInfo[i].dwDataLen, 1, fSnapPic);
//				iNum++;
//					fclose(fSnapPic);
//			}
//			//����СͼƬ
//			if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) && (struITSPlateResult.struPicInfo[i].byType == 0))
//			{
//				sprintf(filename, "testPicPlate%d_%d.jpg", iNum, i);
//				fSnapPicPlate = fopen(filename, "wb");
//				fwrite(struITSPlateResult.struPicInfo[i].pBuffer, struITSPlateResult.struPicInfo[i].dwDataLen, 1, \
//					fSnapPicPlate);
//				iNum++;
//				fclose(fSnapPicPlate);
//			}
//			//������Ϣ����......
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
//	//��ʼ��
//	NET_DVR_Init();
//	//��ȡ����̨���ھ��
//	//HMODULE hKernel32 = GetModuleHandle("kernel32");
//	//GetConsoleWindow = (PROCGETCONSOLEWINDOW)GetProcAddress(hKernel32, "GetConsoleWindow");
//	//��������ʱ��������ʱ��
//	NET_DVR_SetConnectTime(2000, 1);
//	NET_DVR_SetReconnect(10000, true);
//	//---------------------------------------
//	//ע���豸
//	LONG lUserID;
//	NET_DVR_DEVICEINFO_V30 struDeviceInfo;
//	lUserID = NET_DVR_Login_V30("192.168.1.50", 8000, "admin", "hskj12345", &struDeviceInfo);
//	if (lUserID < 0)
//	{
//		printf("Login error, %d\n", NET_DVR_GetLastError());
//		NET_DVR_Cleanup();
//			return;
//	}
//	//���ñ����ص�����
//	NET_DVR_SetDVRMessageCallBack_V30(MSesGCallback1, NULL);
//	//���ò���
//	NET_DVR_SETUPALARM_PARAM struSetupParam = { 0 };
//	struSetupParam.dwSize = sizeof(NET_DVR_SETUPALARM_PARAM);
//	//�ϴ�������Ϣ����: 0- �ϱ�����Ϣ(NET_DVR_PLATE_RESULT), 1- �±�����Ϣ(NET_ITS_PLATE_RESULT)
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
//	//����Ԥ��
//	LONG lRealPlayHandle;
//	HWND hWnd = GetConsoleWindow(); //��ȡ���ھ��
//	NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
//	struPlayInfo.hPlayWnd = hWnd; //��Ҫ SDK ����ʱ�����Ϊ��Чֵ����ȡ��������ʱ��Ϊ��(���ûص�����)
//	struPlayInfo.lChannel = 1; //Ԥ��ͨ����
//	struPlayInfo.dwStreamType = 0; //0-��������1-��������2-���� 3��3-���� 4���Դ�����
//	struPlayInfo.dwLinkMode = 0; //0- TCP ��ʽ��1- UDP ��ʽ��2- �ಥ��ʽ��3- RTP ��ʽ��4-RTP/RTSP��5-RSTP/HTTP
//	struPlayInfo.bBlocked = 1; //0- ������ȡ����1- ����ȡ��
//	lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, NULL, NULL);
//	if (lRealPlayHandle < 0) //Ԥ��ʧ��
//	{
//		printf("NET_DVR_RealPlay_V40 error, %d\n", NET_DVR_GetLastError());
//		NET_DVR_Logout(lUserID);
//		NET_DVR_Cleanup();
//		return;
//	}
//	Sleep(5000);
//	//�ر�Ԥ��
//	NET_DVR_StopRealPlay(lRealPlayHandle);
//	printf("\n");
//	printf("\n");
//	printf("\n");
//		////////////////////////////////////////////////////////////
//		//���紥��ץ��
//		NET_DVR_SNAPCFG struSnapCfg;
//	memset(&struSnapCfg, 0, sizeof(NET_DVR_SNAPCFG));
//	//�ṹ���С
//	struSnapCfg.dwSize = sizeof(NET_DVR_SNAPCFG);
//	//��Ȧץ�Ĵ�����0-��ץ�ģ��� 0-���Ĵ�����Ŀǰ��� 5 ��
//	struSnapCfg.bySnapTimes = 1;
//	//ץ�ĵȴ�ʱ�䣬��λ ms��ȡֵ��Χ[0,60000]
//	struSnapCfg.wSnapWaitTime = 1000;
//	//���ļ��ʱ�䣬��λ ms��ȡֵ��Χ[67,60000]
//	struSnapCfg.wIntervalTime[0] = 1000;
//	struSnapCfg.wIntervalTime[1] = 1000;
//	//���� IO �����ĳ����ţ�ȡֵ��Χ[0,9]
//	struSnapCfg.byRelatedDriveWay = 0;
//	//���紥������
//	if (!NET_DVR_ContinuousShoot(lUserID, &struSnapCfg))
//	{
//		printf("NET_DVR_ContinuousShoot error, %d\n", NET_DVR_GetLastError());
//		return;
//	}
//	//---------------------------------------
//	//�˳�
//	Sleep(20000);
//	//���������ϴ�ͨ��
//	if (!NET_DVR_CloseAlarmChan_V30(lHandle))
//	{
//		printf("NET_DVR_CloseAlarmChan_V30 error, %d\n", NET_DVR_GetLastError());
//		NET_DVR_Logout(lUserID);
//		NET_DVR_Cleanup();
//		return;
//	}//ע���û�
//	NET_DVR_Logout(lUserID);
//	//�ͷ� SDK ��Դ
//	NET_DVR_Cleanup();
//	return;
//}