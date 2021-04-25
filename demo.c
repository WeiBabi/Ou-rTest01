#include <stdio.h>
#include "sqlite3.h"
int main(int argc, char const *argv[])
{
	sqlite3 *db = NULL;
	int ret = sqlite3_open("qq.db",&db);
	if (ret!= SQLITE_OK)
	{
		perror("sqlite3_open");
		return 0;
	}

	char * errmsg = NULL;
	sqlite3_exec(db,"create table qq_haoyou(id int,name text,sex text);",NULL,NULL,&errmsg);

	int a = 0;

	while(1)
	{
		printf("1---添加好友\n");
		printf("2---查看全部好友\n");
		printf("3---查询好友\n");
		printf("4---删除好友\n");
		printf("5---修改好友信息\n");
		printf("6---退出\n");
		printf("*******************\n");
		printf("请输入想要执行的功能\n");

		scanf("%d",&a);
		if (a==1)
		{
			int id = 0;
			char name[16]="";
			char sex[16]="";
			printf("请输入好友id\n");
			scanf("%d",&id);
			printf("请输入好友姓名\n");
			scanf("%s",name);
			printf("请输入好友性别\n");
			scanf("%s",sex);

			char cmd[100]="";
			sprintf(cmd,"insert into qq_haoyou values(%d,\'%s\',\'%s\');",id,name,sex);
			sqlite3_exec(db,cmd,NULL,NULL,&errmsg);
			printf("好友添加成功！\n");
		}
		else if (a==2)
		{
			char ** table = NULL;
			int r,c,i,j;
			sqlite3_get_table(db,"select * from qq_haoyou;",&table,&r,&c,&errmsg);

			
			for ( i = 0; i < r+1; i++)
			{
				for ( j = 0; j < c; j++)
				{
					printf("%-6s",table[i*c+j] );
				}
				printf("\n");
			}
		}

		else if (a==3)
		{
			char ** table = NULL;
			int r,c,i,j;
			char cmd[100]="";
			printf("请输入要查询好友的id\n");
			int id;
			scanf("%d",&id);
			sprintf(cmd,"select * from qq_haoyou where id =%d;",id);
			sqlite3_get_table(db,cmd,&table,&r,&c,&errmsg);
			if (r==0)
			{
				printf("查无此人!\n");
			}
			else
			{
				for ( i = 0; i < r+1; i++)
				{
					for ( j = 0; j < c; j++)
					{
						printf("%-6s",table[i*c+j] );
					}
					printf("\n");
				}
			}
		}
		else if (a==4)
		{
			char **table = NULL;
			int r,c,i,j;
			char cmd[100]="";
			printf("请输入要删除好友的id\n");
			int id;
			scanf("%d",&id);
			sprintf(cmd,"select * from qq_haoyou where id =%d",id);
			sqlite3_get_table(db,cmd,&table,&r,&c,&errmsg);
			if (r==0)
			{
				printf("查无此人!\n");
			}
			else
			{
				char cmd1[100]="";
				sprintf(cmd1,"delete from qq_haoyou where id =%d",id);
				sqlite3_exec(db,cmd1,NULL,NULL,&errmsg);
				printf("删除成功！\n");
			}

		}
		else if (a==5)
		{
			char ** table = NULL;
			int r,c,i,j;
			char cmd[100]="";
			char cmd1[100]="";
			printf("请输入要修改的id\n");
			int id;
			char name[16]="";
			char sex[16]="";
			scanf("%d",&id);
			sprintf(cmd,"select * from qq_haoyou where id =%d;",id);
			sqlite3_get_table(db,cmd,&table,&r,&c,&errmsg);
			if (r==0)
			{
				printf("查无此人!\n");
			}
			else
			{
				for ( i = 0; i < r+1; i++)
				{
					for ( j = 0; j < c; j++)
					{
						printf("%-6s",table[i*c+j] );
					}
					printf("\n");
				}
				int gai;
				printf("选择你要修改的内容\n 按1修改姓名\n 按2修改性别\n");
				scanf("%d",&gai);
				if (gai==1)
				{
					printf("请输入新姓名\n");
					scanf("%s",name);
					sprintf(cmd1,"update qq_haoyou set name =\'%s\' where id=%d",name,id);
					sqlite3_exec(db,cmd1,NULL,NULL,&errmsg);
				}
				else if (gai==2)
				{
					printf("请输入新性别\n");
					scanf("%s",sex);
					sprintf(cmd1,"update qq_haoyou set sex =\'%s\' where id=%d",sex,id);
					sqlite3_exec(db,cmd1,NULL,NULL,&errmsg);
				}
				else
				{
					printf("请重新输入！\n");
				}

			}
		}
		else if (a==6)
		{
			sqlite3_close(db);
			break;
		}



	}


	

	return 0;
}