#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include "sqlite3.h"
#include "sungtk_interface.h"

GtkWidget * window;
GtkWidget * window2;
GtkWidget * window3;
GtkWidget * window4;
GtkWidget * window5;
GtkWidget * window6;
GtkWidget * window7;
GtkWidget * window8;
GtkWidget * window10;
GtkWidget * entry_0;
GtkWidget * entry_1;
GtkWidget * entry4_0;
GtkWidget * entry4_1;
GtkWidget * entry5_0;
GtkWidget * entry6_0;
GtkWidget * entry6_1;
GtkWidget * entry6_2;
GtkWidget * entry7_0;
GtkWidget * entry8_1;
GtkWidget * entry8_2;
GtkWidget * label_3;
GtkWidget * label4_3;
GtkWidget * label5_2;
GtkWidget * label6_4;
GtkWidget * label7_4;
GtkWidget * label10_1;
GtkWidget * label10_2;
GtkWidget * label10_3;
GtkWidget * label10_4;
GtkWidget * label10_5;
const gchar * text0;

char * errmsg = NULL;
sqlite3 * db = NULL;


void guanli(GtkButton * button,gpointer user_data)
{
	const gchar * text1 = gtk_entry_get_text(GTK_ENTRY(entry_0));
	const gchar * text2 = gtk_entry_get_text(GTK_ENTRY(entry_1));

	char ** table = NULL;
	int r,c;
	int ret = sqlite3_open("lingshi.db",&db);
	if(ret != SQLITE_OK)
	{		
		perror("sqlite3_open");
	}

	char cmd[100]="";
	sprintf(cmd,"select * from users where username =\'%s\' and password=\'%s\'; ",text1,text2);	
	sqlite3_get_table(db,cmd,&table,&r,&c,&errmsg);
	if(r == 0)
	{
		gtk_label_set_text(GTK_LABEL(label_3),"用户名或密码输入错误！！！");
		gtk_entry_set_text(GTK_ENTRY(entry_0),"");
		gtk_entry_set_text(GTK_ENTRY(entry_1),"");

	}
	else
	{
		gtk_widget_hide_all(window2);
		gtk_widget_show_all(window3);
	}
	

}
void guanlidl(GtkButton * button,gpointer user_data)
{

	gtk_widget_hide_all(window);
	gtk_widget_show_all(window2);

}
void zhuce(GtkButton * button,gpointer user_data)
{
	
	gtk_widget_hide_all(window2);
	gtk_widget_show_all(window4);

}
void zhucecg(GtkButton * button,gpointer user_data)
{
	const gchar * text1 = gtk_entry_get_text(GTK_ENTRY(entry4_0));
	const gchar * text2 = gtk_entry_get_text(GTK_ENTRY(entry4_1));

	char ** table = NULL;
	int r,c;
	int ret = sqlite3_open("lingshi.db",&db);
	if(ret != SQLITE_OK)
	{
		perror("sqlite3_open");
	}

	char cmd1[100]="";
	sprintf(cmd1,"insert into users values(\'%s\',\'%s\');",text1,text2);	
	sqlite3_exec(db,cmd1,NULL,NULL,&errmsg);

	gtk_label_set_text(GTK_LABEL(label4_3),"恭喜你注册成功啦！");
	gtk_entry_set_text(GTK_ENTRY(entry4_0),"");
	gtk_entry_set_text(GTK_ENTRY(entry4_1),"");

}

void qxzhuce(GtkButton * button,gpointer user_data)
{
	gtk_widget_hide_all(window4);
	gtk_widget_show_all(window2);

}
void xiaofeiym(GtkButton * button,gpointer user_data)
{
	gtk_entry_set_text(GTK_ENTRY(entry5_0),"");
	gtk_label_set_text(GTK_LABEL(label5_2),"");
	gtk_widget_hide_all(window);
	gtk_widget_show_all(window5);

}

void xszjjm(GtkButton * button,gpointer user_data)
{
	gtk_label_set_text(GTK_LABEL(label6_4),"");
	gtk_widget_hide_all(window3);
	gtk_widget_show_all(window6);

}

void zjqxjm(GtkButton * button,gpointer user_data)
{
	gtk_widget_hide_all(window6);
	gtk_widget_show_all(window3);

}


void xgjm(GtkButton * button,gpointer user_data)
{
	gtk_label_set_text(GTK_LABEL(label7_4),"");
	gtk_widget_hide_all(window3);
	gtk_widget_show_all(window7);

}

void xgxqjm(GtkButton * button,gpointer user_data)
{

	gtk_widget_hide_all(window7);
	gtk_widget_show_all(window3);

}

void xgfanhui(GtkButton * button,gpointer user_data)
{

	gtk_entry_set_text(GTK_ENTRY(entry7_0),"");
	gtk_widget_hide_all(window8);
	gtk_widget_show_all(window7);

}
void zjlingshi(GtkButton * button,gpointer user_data)
{
	const gchar * text0 = gtk_entry_get_text(GTK_ENTRY(entry6_0));
	const gchar * text1 = gtk_entry_get_text(GTK_ENTRY(entry6_1));
	const gchar * text2 = gtk_entry_get_text(GTK_ENTRY(entry6_2));
	gtk_label_set_text(GTK_LABEL(label6_4),"");
	char ** table = NULL;
	int r,c;
	int ret = sqlite3_open("lingshi.db",&db);
	if(ret != SQLITE_OK)
	{
		perror("sqlite3_open");
	}

	char cmd[100]="";
	sprintf(cmd,"select * from shangpin where spname=\'%s\';",text0);
    sqlite3_get_table(db,cmd,&table,&r,&c,&errmsg);
      if (r==0)
        {
        	sprintf(cmd,"insert into shangpin values(\'%s\',\'%s\',\'%s\');",text0,text1,text2);
    		sqlite3_exec(db,cmd,NULL,NULL,&errmsg);
    		gtk_label_set_text(GTK_LABEL(label6_4),"恭喜你添加成功啦！");
			gtk_entry_set_text(GTK_ENTRY(entry6_0),"");
			gtk_entry_set_text(GTK_ENTRY(entry6_1),"");
			gtk_entry_set_text(GTK_ENTRY(entry6_2),"");             
        }
        else
        {
        	gtk_label_set_text(GTK_LABEL(label6_4),"已存在该商品，请重新输入!!!");
        	gtk_entry_set_text(GTK_ENTRY(entry6_0),"");
			gtk_entry_set_text(GTK_ENTRY(entry6_1),"");
			gtk_entry_set_text(GTK_ENTRY(entry6_2),""); 
        }  
	

}
void xgqdjm(GtkButton * button,gpointer user_data)
{
	text0 = gtk_entry_get_text(GTK_ENTRY(entry7_0));
	gtk_label_set_text(GTK_LABEL(label7_4),"");
	char ** table = NULL;
	int r,c;
	int ret = sqlite3_open("lingshi.db",&db);
	if(ret != SQLITE_OK)
	{
		perror("sqlite3_open");
	}

	char cmd[100]="";
	sprintf(cmd,"select * from shangpin where spname=\'%s\';",text0);
    sqlite3_get_table(db,cmd,&table,&r,&c,&errmsg);
    if(r ==0)
    {
    	gtk_label_set_text(GTK_LABEL(label7_4),"暂无此商品，请重新输入商品名称！！！");
    	gtk_entry_set_text(GTK_ENTRY(entry7_0),"");
    }
    else
    {
    	
    	gtk_widget_hide_all(window7);
		gtk_widget_show_all(window8);
    }

}

void xgcgjm(GtkButton * button,gpointer user_data)
{
	const gchar * text1 = gtk_entry_get_text(GTK_ENTRY(entry8_1));
	const gchar * text2 = gtk_entry_get_text(GTK_ENTRY(entry8_2));

	char ** table = NULL;
	int r,c;
	int ret = sqlite3_open("lingshi.db",&db);
	if(ret != SQLITE_OK)
	{
		perror("sqlite3_open");
	}

	char cmd1[100]="";
	sprintf(cmd1,"update shangpin set spprice=\'%s\' ,spcount=\'%s\' where spname=\'%s\';",text1,text2,text0);	
	sqlite3_exec(db,cmd1,NULL,NULL,&errmsg);

	gtk_widget_hide_all(window8);
	gtk_entry_set_text(GTK_ENTRY(entry7_0),"");
	gtk_widget_show_all(window7);

}


void ckspjm(GtkButton * button,gpointer user_data)
{
	gtk_widget_hide_all(window3);
	gtk_widget_show_all(window10);
	char ** table = NULL;
	int r,c;
	int ret = sqlite3_open("lingshi.db",&db);
	if(ret != SQLITE_OK)
	{
		perror("sqlite3_open");
	}
	char cmd1[500]="";
	sprintf(cmd1,"select * from shangpin;");
	sqlite3_get_table(db,cmd1,&table,&r,&c,&errmsg);
	if(r==0)
	{
		gtk_label_set_text(GTK_LABEL(label10_1),"目前没有商品！！！");
	}
	else
	{
		char shuju1[100]="";
		sprintf(shuju1,"spname:%-20s spprice:%-20s spcount:%-20s\n",table[3],table[4],table[5]);
		gtk_label_set_text(GTK_LABEL(label10_1),shuju1);
		char shuju2[100]="";
		sprintf(shuju2,"spname:%-20s spprice:%-20s spcount:%-20s\n",table[6],table[7],table[8]);
		gtk_label_set_text(GTK_LABEL(label10_2),shuju2);
		char shuju3[100]="";
		sprintf(shuju3,"spname:%-20s spprice:%-20s spcount:%-20s\n",table[9],table[10],table[11]);
		gtk_label_set_text(GTK_LABEL(label10_3),shuju3);
		char shuju4[100]="";
		sprintf(shuju4,"spname:%-20s spprice:%-20s spcount:%-20s\n",table[12],table[13],table[14]);
		gtk_label_set_text(GTK_LABEL(label10_4),shuju4);
		char shuju5[100]="";
		sprintf(shuju5,"spname:%-20s spprice:%-20s spcount:%-20s\n",table[15],table[16],table[17]);
		gtk_label_set_text(GTK_LABEL(label10_5),shuju5);
	}

}

void cxfanhui(GtkButton * button,gpointer user_data)
{


	gtk_widget_hide_all(window10);
	gtk_widget_show_all(window3);

}

void qdgoumai(GtkButton * button,gpointer user_data)
{
	const gchar * text5 = gtk_entry_get_text(GTK_ENTRY(entry5_0));

	gtk_label_set_text(GTK_LABEL(label5_2),"");
	char ** table = NULL;
	int r,c;
	int ret = sqlite3_open("lingshi.db",&db);
	if(ret != SQLITE_OK)
	{
		perror("sqlite3_open");
	}

	char cmd2[100]="";
	sprintf(cmd2,"select spcount from shangpin where spname=\'%s\';",text5);
   	sqlite3_get_table(db,cmd2,&table,&r,&c,&errmsg);
    if(r ==0)
    {
    	gtk_label_set_text(GTK_LABEL(label5_2),"暂无此商品，请重新输入商品名称！！！");
    	//gtk_label_set_text(GTK_LABEL(label5_1),"");
    	gtk_entry_set_text(GTK_ENTRY(entry5_0),"");
    }
    else
    {

    	//char cmd1[100]="";
		//sprintf(cmd1,"update shangpin set spcount=\'%s\' where spname=\'%s\';",count-'1',text1);	
		//sqlite3_exec(db,cmd1,NULL,NULL,&errmsg);
		gtk_label_set_text(GTK_LABEL(label5_2),"恭喜成功购买商品！");

    }



}

void qxgoumai(GtkButton * button,gpointer user_data)
{
	gtk_widget_hide_all(window5);
	gtk_widget_show_all(window);

}


void fhgoumai(GtkButton * button,gpointer user_data)
{
	gtk_widget_hide_all(window10);
	gtk_widget_show_all(window5);

}

//退出系统
void quit(GtkButton * button,gpointer user_data)
{
	gtk_widget_hide_all(window3);
	gtk_widget_show_all(window);

}


//设置图片
void load_image(GtkWidget *image, const char *file_path, const int w, const int h )
{
    gtk_image_clear( GTK_IMAGE(image) ); // 清除图像
    GdkPixbuf *src_pixbuf = gdk_pixbuf_new_from_file(file_path, NULL); // 创建图片资源
    GdkPixbuf *dest_pixbuf=gdk_pixbuf_scale_simple(src_pixbuf,w,h,GDK_INTERP_BILINEAR); // 指定大小
    gtk_image_set_from_pixbuf(GTK_IMAGE(image), dest_pixbuf); // 图片控件重新设置一张图片(pixbuf)
    g_object_unref(src_pixbuf); // 释放资源
    g_object_unref(dest_pixbuf); // 释放资源
}
//设置文字
void set_label_font_size(GtkWidget *label, int size)
{
    PangoFontDescription *font; // 字体指针
    font = pango_font_description_from_string("");//参数为字体名字，任意即可
    // #define PANGO_SCALE 1024
    pango_font_description_set_size(font, size*PANGO_SCALE);// 设置字体大小
    gtk_widget_modify_font(label, font); // 改变 label 的字体大小
    pango_font_description_free(font); // 释放字体指针分配的空间
}



int main(int argc, char *argv[])
{
	//window
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"6-4小铺子页面");
	gtk_widget_set_size_request(window,950,540);
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	GtkWidget * fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window),fixed);

	GtkWidget * image = gtk_image_new_from_pixbuf(NULL);
	load_image(image,"bj.png",950,540);
	gtk_fixed_put(GTK_FIXED(fixed),image,0,0);

	GtkWidget * label = gtk_label_new("欢迎来到6-4小铺子！！！");
	set_label_font_size(label,40);
	sungtk_widget_set_font_color(label,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed),label,250,25);

	GtkWidget * button01 = gtk_button_new();
	GtkWidget * image_btn =gtk_image_new_from_pixbuf(NULL);
	load_image(image_btn,"22.jpg",155,70);
	gtk_button_set_image(GTK_BUTTON(button01),image_btn);
	gtk_button_set_relief(GTK_BUTTON(button01),GTK_RELIEF_NONE);
	gtk_fixed_put(GTK_FIXED(fixed),button01,500,300);
	g_signal_connect(button01,"pressed",G_CALLBACK(xiaofeiym),NULL);


	GtkWidget * button02 = gtk_button_new();
	GtkWidget * image_btn02 =gtk_image_new_from_pixbuf(NULL);
	load_image(image_btn02,"gl.png",100,50);
	gtk_button_set_image(GTK_BUTTON(button02),image_btn02);
	gtk_button_set_relief(GTK_BUTTON(button02),GTK_RELIEF_NONE);
	gtk_fixed_put(GTK_FIXED(fixed),button02,805,125);
	g_signal_connect(button02,"pressed",G_CALLBACK(guanlidl),NULL);


	//window2
	//====================================================
	window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window2,500,400);
	g_signal_connect(window2,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	GtkWidget * fixed2 = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window2),fixed2);

	GtkWidget * label_0 = gtk_label_new("账号");
	set_label_font_size(label_0,20);
	sungtk_widget_set_font_color(label_0,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed2),label_0,100,150);
	

	GtkWidget * label_1 = gtk_label_new("密码");
	set_label_font_size(label_1,20);
	sungtk_widget_set_font_color(label_1,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed2),label_1,100,250);
	
	GtkWidget * label_2 = gtk_label_new("用户管理登录界面");
	set_label_font_size(label_2,20);
	sungtk_widget_set_font_color(label_2,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed2),label_2,150,80);
	
	label_3 = gtk_label_new("");
	set_label_font_size(label_3,20);
	sungtk_widget_set_font_color(label_3,"red",0);
	gtk_fixed_put(GTK_FIXED(fixed2),label_3,100,50);
	

	entry_0 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed2),entry_0,200,150);
	entry_1 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed2),entry_1,200,250);
		

	
	GtkWidget *button_0 = gtk_button_new_with_label("登录");
	set_label_font_size(button_0,10);
	gtk_widget_set_size_request(button_0,50,50);
	g_signal_connect(button_0,"pressed",G_CALLBACK(guanli),NULL);
	gtk_fixed_put(GTK_FIXED(fixed2),button_0,200,300);
	
	GtkWidget *button_1 = gtk_button_new_with_label("注册");
	set_label_font_size(button_1,10);
	gtk_widget_set_size_request(button_1,50,50);
	gtk_fixed_put(GTK_FIXED(fixed2),button_1,300,300);
	g_signal_connect(button_1,"pressed",G_CALLBACK(zhuce),NULL);

//==============================================================

//window3	

	window3 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window3),"6-4小铺子管理系统");
	gtk_widget_set_size_request(window3,800,600);

	g_signal_connect(window3,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	GtkWidget * fixed3 = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window3),fixed3);

	GtkWidget * image5 = gtk_image_new_from_pixbuf(NULL);
	load_image(image5,"5.jpg",800,600);
	gtk_fixed_put(GTK_FIXED(fixed3),image5,0,0);



	GtkWidget * label3_0 = gtk_label_new("6-4小铺子管理界面");
	set_label_font_size(label3_0,30);
	sungtk_widget_set_font_color(label3_0,"yellowblue",0);
	gtk_fixed_put(GTK_FIXED(fixed3),label3_0,250,100);

	

	GtkWidget * button3_0 = gtk_button_new_with_label(" - - - - - - -增加商品- - - - - - -");
	g_signal_connect(button3_0,"pressed",G_CALLBACK(xszjjm),NULL);
	set_label_font_size(button3_0,15);

	gtk_widget_set_size_request(button3_0,200,50);
	gtk_fixed_put(GTK_FIXED(fixed3),button3_0,350,200);

	GtkWidget * button3_1 = gtk_button_new_with_label("- - - - - - -查看商品- - - - - - -");
	g_signal_connect(button3_1,"pressed",G_CALLBACK(ckspjm),NULL);
	set_label_font_size(button3_1,15);

	gtk_widget_set_size_request(button3_1,200,50);
	gtk_fixed_put(GTK_FIXED(fixed3),button3_1,350,300);

	GtkWidget * button3_3 = gtk_button_new_with_label("- - - - - - -修改商品- - - - - - -");
	g_signal_connect(button3_3,"pressed",G_CALLBACK(xgjm),NULL);
	set_label_font_size(button3_3,15);

	gtk_widget_set_size_request(button3_3,200,50);
	gtk_fixed_put(GTK_FIXED(fixed3),button3_3,350,400);

	GtkWidget * button3_2 = gtk_button_new_with_label("- - - - - - -退出系统- - - - - - -");
	g_signal_connect(button3_2,"pressed",G_CALLBACK(quit),NULL);
	set_label_font_size(button3_2,15);

	gtk_widget_set_size_request(button3_2,200,50);
	gtk_fixed_put(GTK_FIXED(fixed3),button3_2,350,500);
	


//window4
//=================================================================
	window4 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window4,500,400);
	g_signal_connect(window4,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	GtkWidget * fixed4 = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window4),fixed4);

	GtkWidget * label4_0 = gtk_label_new("账号");
	set_label_font_size(label4_0,20);
	sungtk_widget_set_font_color(label4_0,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed4),label4_0,100,150);
	
	GtkWidget * label4_1 = gtk_label_new("密码");
	set_label_font_size(label4_1,20);
	sungtk_widget_set_font_color(label4_1,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed4),label4_1,100,250);
	
	
	GtkWidget * label4_2 = gtk_label_new("欢迎来到注册界面");
	set_label_font_size(label4_2,20);
	sungtk_widget_set_font_color(label4_2,"green",0);
	gtk_fixed_put(GTK_FIXED(fixed4),label4_2,150,80);


	label4_3 = gtk_label_new("");
	set_label_font_size(label4_3,20);
	sungtk_widget_set_font_color(label4_3,"black",0);
	gtk_fixed_put(GTK_FIXED(fixed4),label4_3,100,50);


	entry4_0 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed4),entry4_0,200,150);
	
	entry4_1 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed4),entry4_1,200,250);

	GtkWidget * button4_0 = gtk_button_new_with_label("确定");
	set_label_font_size(button4_0,10);
	g_signal_connect(button4_0,"pressed",G_CALLBACK(zhucecg),NULL);


	GtkWidget * button4_1 = gtk_button_new_with_label("取消");
	set_label_font_size(button4_1,10);
	g_signal_connect(button4_1,"pressed",G_CALLBACK(qxzhuce),NULL);
	
	gtk_widget_set_size_request(button4_0,50,50);

	gtk_fixed_put(GTK_FIXED(fixed4),button4_0,200,300);

	gtk_widget_set_size_request(button4_1,50,50);

	gtk_fixed_put(GTK_FIXED(fixed4),button4_1,300,300);


//window5
//=================================================================
	window5 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window5),"6-4小铺子页面");
	gtk_widget_set_size_request(window5,1000,550);
	g_signal_connect(window5,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	GtkWidget * fixed5 = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window5),fixed5);

	GtkWidget * label5_0 = gtk_label_new("欢迎来到6-4小铺子！！！");
	set_label_font_size(label5_0,40);
	sungtk_widget_set_font_color(label5_0,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed5),label5_0,200,25);

	GtkWidget * label5_1 = gtk_label_new("输入需要购买的商品名称");
	set_label_font_size(label5_1,20);
	sungtk_widget_set_font_color(label5_1,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed5),label5_1,200,250);

	entry5_0 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed5),entry5_0,200,300);

	label5_2 = gtk_label_new("");
	set_label_font_size(label5_2,40);
	sungtk_widget_set_font_color(label5_2,"red",0);
	gtk_fixed_put(GTK_FIXED(fixed5),label5_2,200,150);

	GtkWidget * button5_0 = gtk_button_new_with_label("确定");
	set_label_font_size(button5_0,10);
	gtk_widget_set_size_request(button5_0,50,50);
	gtk_fixed_put(GTK_FIXED(fixed5),button5_0,200,400);
	g_signal_connect(button5_0,"pressed",G_CALLBACK(qdgoumai),NULL);

	GtkWidget * button5_2 = gtk_button_new_with_label("查看");
	set_label_font_size(button5_2,10);
	gtk_widget_set_size_request(button5_2,50,50);
	gtk_fixed_put(GTK_FIXED(fixed5),button5_2,250,400);	
	g_signal_connect(button5_2,"pressed",G_CALLBACK(ckspjm),NULL);

	GtkWidget * button5_1 = gtk_button_new_with_label("取消");
	set_label_font_size(button5_1,10);
	gtk_widget_set_size_request(button5_1,50,50);
	gtk_fixed_put(GTK_FIXED(fixed5),button5_1,300,400);	
	g_signal_connect(button5_1,"pressed",G_CALLBACK(qxgoumai),NULL);


//window6
//==============================================================
	window6 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window6,500,400);


	g_signal_connect(window6,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	
	GtkWidget * fixed6 = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window6),fixed6);
	

	GtkWidget * label6_0 = gtk_label_new("零食名称");
	set_label_font_size(label6_0,20);
	sungtk_widget_set_font_color(label6_0,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed6),label6_0,100,150);
	
	
	
	GtkWidget * label6_1 = gtk_label_new("零食数量");
	set_label_font_size(label6_1,20);
	sungtk_widget_set_font_color(label6_1,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed6),label6_1,100,200);
	
	
	GtkWidget * label6_2 = gtk_label_new("零食价格");
	set_label_font_size(label6_2,20);
	sungtk_widget_set_font_color(label6_2,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed6),label6_2,100,250);
	
	
	GtkWidget * label6_3 = gtk_label_new("零食增加页面");
	set_label_font_size(label6_3,20);
	sungtk_widget_set_font_color(label6_3,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed6),label6_3,150,80);

	label6_4 = gtk_label_new("");
	set_label_font_size(label6_4,20);
	sungtk_widget_set_font_color(label6_4,"red",0);
	gtk_fixed_put(GTK_FIXED(fixed6),label6_4,150,50);
		
	entry6_0 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed6),entry6_0,250,150);
	
	entry6_1 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed6),entry6_1,250,200);
	
	entry6_2 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed6),entry6_2,250,250);
		
	GtkWidget * button6_0 = gtk_button_new_with_label("确定");
	set_label_font_size(button6_0,10);
	gtk_widget_set_size_request(button6_0,50,50);
	gtk_fixed_put(GTK_FIXED(fixed6),button6_0,200,300);
	g_signal_connect(button6_0,"pressed",G_CALLBACK(zjlingshi),NULL);

	GtkWidget * button6_1 = gtk_button_new_with_label("取消");
	set_label_font_size(button6_1,10);
	gtk_widget_set_size_request(button6_1,50,50);
	gtk_fixed_put(GTK_FIXED(fixed6),button6_1,300,300);	
	g_signal_connect(button6_1,"pressed",G_CALLBACK(zjqxjm),NULL);



//window7
//==============================================================
	window7 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window7,500,400);


	g_signal_connect(window7,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	GtkWidget * fixed7 = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window7),fixed7);

	GtkWidget * label7_0 = gtk_label_new("想要修改的商品名称");
	set_label_font_size(label7_0,20);
	sungtk_widget_set_font_color(label7_0,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed7),label7_0,150,150);	
	
	GtkWidget * label7_3 = gtk_label_new("修改零食信息");
	set_label_font_size(label7_3,20);
	sungtk_widget_set_font_color(label7_3,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed7),label7_3,20,20);

	label7_4 = gtk_label_new("修改零食信息");
	set_label_font_size(label7_4,20);
	sungtk_widget_set_font_color(label7_4,"red",0);
	gtk_fixed_put(GTK_FIXED(fixed7),label7_4,30,50);

	entry7_0 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed7),entry7_0,150,180);

	
	GtkWidget * button7_0 = gtk_button_new_with_label("确定");
	set_label_font_size(button7_0,10);
	gtk_widget_set_size_request(button7_0,50,50);
	gtk_fixed_put(GTK_FIXED(fixed7),button7_0,200,300);
	g_signal_connect(button7_0,"pressed",G_CALLBACK(xgqdjm),NULL);

	GtkWidget * button7_1 = gtk_button_new_with_label("取消");
	set_label_font_size(button7_1,10);
	gtk_widget_set_size_request(button7_1,50,50);
	gtk_fixed_put(GTK_FIXED(fixed7),button7_1,300,300);
	g_signal_connect(button7_1,"pressed",G_CALLBACK(xgxqjm),NULL);




//window8
//==============================================================
	window8 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window8,500,400);


	g_signal_connect(window8,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	
	GtkWidget * fixed8 = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window8),fixed8);
	
	
	GtkWidget * label8_1 = gtk_label_new("零食数量");
	set_label_font_size(label8_1,20);
	sungtk_widget_set_font_color(label8_1,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed8),label8_1,100,100);
	
	
	GtkWidget * label8_2 = gtk_label_new("零食价格");
	set_label_font_size(label8_2,20);
	sungtk_widget_set_font_color(label8_2,"#EEB2EE",0);
	gtk_fixed_put(GTK_FIXED(fixed8),label8_2,100,200);
	
	entry8_1 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed8),entry8_1,250,100);
	
	entry8_2 = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed8),entry8_2,250,200);
	
	
	GtkWidget * button8_0 = gtk_button_new_with_label("确定");
	set_label_font_size(button8_0,10);
	gtk_widget_set_size_request(button8_0,50,50);
	gtk_fixed_put(GTK_FIXED(fixed8),button8_0,200,300);
	g_signal_connect(button8_0,"pressed",G_CALLBACK(xgcgjm),NULL);
	
	GtkWidget * button8_1 = gtk_button_new_with_label("取消");
	set_label_font_size(button8_1,10);
	gtk_widget_set_size_request(button8_1,50,50);
	gtk_fixed_put(GTK_FIXED(fixed8),button8_1,300,300);
	g_signal_connect(button8_1,"pressed",G_CALLBACK(xgfanhui),NULL);


//==============================================================



//window10
//===============================================================
	window10 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window10),"6-4小铺子");
	gtk_widget_set_size_request(window10,1000,550);
	g_signal_connect(window10,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	GtkWidget * fixed10 = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window10),fixed10);

	GtkWidget * label10_0 = gtk_label_new("6-4小铺子商品查询");
	set_label_font_size(label10_0,40);
	sungtk_widget_set_font_color(label10_0,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed10),label10_0,250,25);


	label10_1 = gtk_label_new("");
	set_label_font_size(label10_1,20);
	sungtk_widget_set_font_color(label10_1,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed10),label10_1,125,125);

	label10_2 = gtk_label_new("");
	set_label_font_size(label10_2,20);
	sungtk_widget_set_font_color(label10_2,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed10),label10_2,125,160);

	label10_3 = gtk_label_new("");
	set_label_font_size(label10_3,20);
	sungtk_widget_set_font_color(label10_3,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed10),label10_3,125,195);

	label10_4 = gtk_label_new("");
	set_label_font_size(label10_4,20);
	sungtk_widget_set_font_color(label10_4,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed10),label10_4,125,230);

	label10_5 = gtk_label_new("");
	set_label_font_size(label10_5,20);
	sungtk_widget_set_font_color(label10_5,"153, 187, 64",0);
	gtk_fixed_put(GTK_FIXED(fixed10),label10_5,125,265);

	GtkWidget * button10_0 = gtk_button_new_with_label("返回管理界面");
	set_label_font_size(button10_0,20);
	gtk_widget_set_size_request(button10_0,100,50);
	gtk_fixed_put(GTK_FIXED(fixed10),button10_0,450,470);
	g_signal_connect(button10_0,"pressed",G_CALLBACK(cxfanhui),NULL);

	GtkWidget * button10_1 = gtk_button_new_with_label("返回购买界面");
	set_label_font_size(button10_1,20);
	gtk_widget_set_size_request(button10_1,100,50);
	gtk_fixed_put(GTK_FIXED(fixed10),button10_1,600,470);
	g_signal_connect(button10_1,"pressed",G_CALLBACK(fhgoumai),NULL);
//===============================================================


	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}