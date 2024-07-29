#pragma once
#define enemy_num 10
#include"enemy_tank_move.hpp"
void init_tank_pos() {
    Tank mytank;
    mytank.x = 8;
    mytank.y = 24;
    //初始化坦克位置以及坐标数据
    change_pos_data<int>(mytank.y, mytank.x, 200);

    bullet bullet_s;
    bullet_s.status = 0;

    bullet enemy_bullet[enemy_num];
    Tank enemy_Tank[enemy_num];

    /*Tank enemy_tank1, enemy_tank2, enemy_tank3;
    enemy_tank1.x = 0;
    enemy_tank1.y = 11;
    enemy_tank2.x = 12;
    enemy_tank2.y = 0;
    enemy_tank3.x = 24;
    enemy_tank3.y = 11;*/
    /*change_pos_data<int>(enemy_tank1.y, enemy_tank1.x, 200);
    change_pos_data<int>(enemy_tank2.y, enemy_tank2.x, 200);
    change_pos_data<int>(enemy_tank3.y, enemy_tank3.x, 200);*/

    //获取我方坦克图片
    IMAGE tank_dir_img[4];
    loadimage(&tank_dir_img[UP], _T("D:\\Tankfight_source\\resources\\image\\tank_up.jpg"), 50, 50);
    loadimage(&tank_dir_img[DOWN], _T("D:\\Tankfight_source\\resources\\image\\tank_down.jpg"), 50, 50);
    loadimage(&tank_dir_img[LEFT], _T("D:\\Tankfight_source\\resources\\image\\tank_left.jpg"), 50, 50);
    loadimage(&tank_dir_img[RIGHT], _T("D:\\Tankfight_source\\resources\\image\\tank_right.jpg"), 50, 50);
    //获取敌方坦克图片
    IMAGE enemy_tank_img[4];
    loadimage(&enemy_tank_img[UP], _T("D:\\Tankfight_source\\resources\\image\\it1_up.jpg"), 50, 50);
    loadimage(&enemy_tank_img[DOWN], _T("D:\\Tankfight_source\\resources\\image\\it1_down.jpg"), 50, 50);
    loadimage(&enemy_tank_img[LEFT], _T("D:\\Tankfight_source\\resources\\image\\it1_left.jpg"), 50, 50);
    loadimage(&enemy_tank_img[RIGHT], _T("D:\\Tankfight_source\\resources\\image\\it1_right.jpg"), 50, 50);

    //我方坦克图像放置
    for (int i = 0;i<enemy_num; i++) {
        int res = i % 3;
        switch (res) {
        case 0:
            enemy_Tank[i].x = 0;
            enemy_Tank[i].y = 11;
            enemy_Tank[i].tank_direction = RIGHT;
            break;
        case 1:
            enemy_Tank[i].x = 12;
            enemy_Tank[i].y = 0;
            enemy_Tank[i].tank_direction = DOWN;
            break;
        case 2:
            enemy_Tank[i].x = 24;
            enemy_Tank[i].y = 11;
            enemy_Tank[i].tank_direction = LEFT;
            break;
        
            enemy_Tank[i].live = 1;
            change_pos_data<int>(enemy_Tank[i].y, enemy_Tank[i].x, 200);
            enemy_bullet[i].status = 0;
        }
    }
    //放置敌方坦克图像
    /*Direction etank1 = RIGHT;
    Direction etank2 = DOWN;
    Direction etank3 = LEFT;*/
    putimage(enemy_Tank[0].x * 25, enemy_Tank[0].y * 25, &enemy_tank_img[enemy_Tank[0].tank_direction]);
    putimage(enemy_Tank[1].x * 25, enemy_Tank[1].y * 25, &enemy_tank_img[enemy_Tank[1].tank_direction]);
    putimage(enemy_Tank[2].x * 25, enemy_Tank[2].y * 25, &enemy_tank_img[enemy_Tank[2].tank_direction]);

    //坦克控制接管
    ExMessage key;
    int current_time = 0;
    int enemy_total = 3;

    mytank.tank_direction = UP;
    Direction& mytank_direction = mytank.tank_direction;

    putimage((mytank.x) * 25, (mytank.y) * 25, &tank_dir_img[mytank_direction]);

    while (1) {

        if (current_time % 50 == 0) {
            
            for (int count = 0; count < enemy_total; count++) {
                if (enemy_Tank[count].live == 1) {
                    enemy_tank_move(&enemy_Tank[count], enemy_Tank[count].tank_direction, &enemy_tank_img[enemy_Tank[count].tank_direction]);
                }
     
            }
        }
        
        //获取键盘按键
        while(peekmessage(&key, EX_KEY,true)) {
            //key = getmessage(EX_KEY);
           
            //自动开启caplock模式
            /*if (key.vkcode == VK_CAPITAL) {
                key.message = WM_KEYDOWN;
                key.vkcode = VK_CAPITAL;
            }*/
            if (key.message == WM_KEYDOWN)
            {
                switch (key.vkcode) {
                case 'P':
                    system("pause");
                case 'W':
                    //向上移动
                    if (mytank_direction == UP && mytank.y - 1 >= 0 && map[mytank.y - 1][mytank.x] == 0 && map[mytank.y - 1][mytank.x + 1] == 0)
                    {

                        tank_move(&mytank, UP, &tank_dir_img[mytank_direction], 1);
                    }
                    else if (mytank_direction != UP) {
                        mytank_direction = UP;
                        tank_move(&mytank, UP, &tank_dir_img[mytank_direction], 0);
                    }
                    
                    break;
                case 'A':
                    if (mytank_direction == LEFT && mytank.x - 1 >= 0 && map[mytank.y][mytank.x - 1] == 0 && map[mytank.y + 1][mytank.x - 1] == 0)
                    {

                        tank_move(&mytank, LEFT, &tank_dir_img[mytank_direction], 1);
                    }
                    else if (mytank_direction != LEFT) {
                        mytank_direction = LEFT;
                        tank_move(&mytank, LEFT, &tank_dir_img[mytank_direction], 0);
                    }
                    break;
                case 'S':
                    if (mytank_direction == DOWN && mytank.y + 2 <= 25 && map[mytank.y + 2][mytank.x] == 0 && map[mytank.y + 2][mytank.x + 1] == 0)
                    {

                        tank_move(&mytank, DOWN, &tank_dir_img[mytank_direction], 1);

                    }
                    else if (mytank_direction != DOWN) {
                        mytank_direction = DOWN;
                        tank_move(&mytank, DOWN, &tank_dir_img[mytank_direction], 0);
                    }
                    break;
                case 'D':
                    if (mytank_direction == RIGHT && mytank.x + 2 <= 25 && map[mytank.y][mytank.x + 2] == 0 && map[mytank.y + 1][mytank.x + 2] == 0)
                    {

                        tank_move(&mytank, RIGHT, &tank_dir_img[mytank_direction], 1);

                    }
                    else if (mytank_direction != RIGHT) {
                        mytank_direction = RIGHT;
                        tank_move(&mytank, RIGHT, &tank_dir_img[mytank_direction], 0);
                    }
                    break;
                case 'J':
                    //子弹不存在的时候，初始化坐标
                    if (bullet_s.status == 0) {
                        if (mytank_direction == UP) {
                            bullet_s.x = mytank.x * 25 + 23;
                            bullet_s.y = mytank.y * 25 - 3;
                        }
                        else if (mytank_direction == LEFT) {
                            bullet_s.x = mytank.x * 25 - 3;
                            bullet_s.y = mytank.y * 25 + 23;
                        }
                        else if (mytank_direction == DOWN) {
                            bullet_s.x = mytank.x * 25 + 23;
                            bullet_s.y = mytank.y * 25 + 56;
                        }
                        else if (mytank_direction == RIGHT) {
                            bullet_s.x = mytank.x * 25 + 56;
                            bullet_s.y = mytank.y * 25 + 23;
                        }
                        //调整方向
                        bullet_s.bullet_direction = mytank_direction;
                        bullet_s.status = 1;

                    }
                    break;
                }

                //break;
            }
            
        }
        if (bullet_s.status == 1) {
            bullet_act(&bullet_s);
        }
        Sleep(10);
        current_time++;
            
    }

}