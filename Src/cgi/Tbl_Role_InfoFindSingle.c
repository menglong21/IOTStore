﻿// =================================================================== 
// 项目说明
//====================================================================
// 张家铭。@Copy Right 2016
// 文件： Tbl_Role_InfoFindSingle.c
// 作用：CGI文件源码
// 项目名称：物联仓储项目
// 创建时间：2016-10-18
// 负责人：张家铭
// ===================================================================
#include <stdio.h>
#include "../../Res/cgic.h"
#include "../../Res/SQLite3/Tbl_Role_InfoDAL.h"

int cgiMain(){
    char sCon[128];
	cgiFormString("sCon",sCon,128);
	Tbl_Role_Info _Tbl_Role_Info=Tbl_Role_InfoFindSingle(sCon);
	char strJson[1024];
	if (_Tbl_Role_Info.RoleID!=0)
	{
		sprintf(strJson,"{\"jsn\":[{\"RoleID\":\"%d\",\"RoleName\":\"%s\"}]}",_Tbl_Role_Info.RoleID,_Tbl_Role_Info.RoleName);
	}
	else
	{
		sprintf(strJson,"{\"jsn\":[]}");
	}
	printf("Content-Type:text/html;charset=UTF-8\n\n");
	printf("%s",strJson);

}

