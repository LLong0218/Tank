// Tank.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include"menu.hpp"
#include"change_pos_data.hpp"
#include"initmap.hpp"
#include"tank_move.hpp"
#include"bullet_act.hpp"
#include"bullet_hit_wall.hpp"
#include"init_tank_pos.hpp"
#include"control_tank_move.hpp"

//void getimage(IMAGE img, const char[] path, int width, int length) {
//    loadimage(&img, _T("path"), width, length);
//}

//void bullet_hit_wall(int x,int y,bullet* bullet);

int main()
{
    //初始化绘图窗口
    initgraph(650,650);
    
    menu();

    initmap();

    init_tank_pos();
 
    system("pause");
    
}
