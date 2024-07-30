#pragma once
#define enemy_num 10
#include"control_tank_move.hpp"

void init_tank_pos() {
    Tank mytank;
    mytank.x = 8;
    mytank.y = 24;
    //��ʼ��̹��λ���Լ���������
    change_pos_data<int>(mytank.y, mytank.x, 200);

    bullet bullet_s;
    bullet_s.status = 0;

    bullet enemy_bullet[enemy_num];
    Tank enemy_Tank[enemy_num];

    //��ȡ�ҷ�̹��ͼƬ
    IMAGE tank_dir_img[4];
    loadimage(&tank_dir_img[UP], _T("..\\tank_up.jpg"), 50, 50);
    loadimage(&tank_dir_img[DOWN], _T("..\\tank_down.jpg"), 50, 50);
    loadimage(&tank_dir_img[LEFT], _T("..\\tank_left.jpg"), 50, 50);
    loadimage(&tank_dir_img[RIGHT], _T("..\\tank_right.jpg"), 50, 50);
    //��ȡ�з�̹��ͼƬ
    IMAGE enemy_tank_img[4];
    loadimage(&enemy_tank_img[UP], _T("..\\it1_up.jpg"), 50, 50);
    loadimage(&enemy_tank_img[DOWN], _T("..\\it1_down.jpg"), 50, 50);
    loadimage(&enemy_tank_img[LEFT], _T("..\\it1_left.jpg"), 50, 50);
    loadimage(&enemy_tank_img[RIGHT], _T("..\\it1_right.jpg"), 50, 50);

    //�з�̹�˳�ʼ��
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
            //change_pos_data<int>(enemy_Tank[i].y, enemy_Tank[i].x, 100+i);
            enemy_bullet[i].status = 0;
        }
    }
    //���õз�̹��ͼ��
    /*Direction etank1 = RIGHT;
    Direction etank2 = DOWN;
    Direction etank3 = LEFT;*/
    tank_move(&enemy_Tank[0],RIGHT,&enemy_tank_img[enemy_Tank[0].tank_direction],0);
    //putimage(enemy_Tank[0].x * 25, enemy_Tank[0].y * 25, &enemy_tank_img[enemy_Tank[0].tank_direction]);
    change_pos_data<int>(enemy_Tank[0].y, enemy_Tank[0].x, 100);
    tank_move(&enemy_Tank[1], DOWN, &enemy_tank_img[enemy_Tank[1].tank_direction], 0);
    //putimage(enemy_Tank[1].x * 25, enemy_Tank[1].y * 25, &enemy_tank_img[enemy_Tank[1].tank_direction]);
    change_pos_data<int>(enemy_Tank[1].y, enemy_Tank[1].x, 101);
    tank_move(&enemy_Tank[2], LEFT, &enemy_tank_img[enemy_Tank[2].tank_direction], 0);
    //putimage(enemy_Tank[2].x * 25, enemy_Tank[2].y * 25, &enemy_tank_img[enemy_Tank[2].tank_direction]);
    change_pos_data<int>(enemy_Tank[2].y, enemy_Tank[2].x, 102);

    //̹�˿��ƽӹ�
    ExMessage key;
    int current_time = 0;
 

    mytank.tank_direction = UP;
    Direction& mytank_direction = mytank.tank_direction;
    
    srand(time(NULL));

    putimage((mytank.x) * 25, (mytank.y) * 25, &tank_dir_img[mytank_direction]);

    while (1) {
        //ÿ����ת��һ�ι���Ŀ��
        if (current_time % 200 == 0) {
            for (int count = 0; count < enemy_Tank->tank_current_num; count++) {
                //��ʧ̹�˲��ٴ���
                if (enemy_Tank[count].live == 0) continue;
                //ż�������ϳ�
                if (current_time % 2 == 0) {
                    Direction d = enemy_Tank[count].enemytank_auto_move(&enemy_Tank[count], 12, 24);
                    control_tank_move(&enemy_Tank[count], d, &enemy_tank_img[d]);
                }
                else {
                    Direction d = enemy_Tank[count].enemytank_auto_move(&enemy_Tank[count], mytank.x, mytank.y);
                    control_tank_move(&enemy_Tank[count], d, &enemy_tank_img[d]);
                }
                //��ʼ�������ӵ�
                Tank::bullet_fire_init(&enemy_Tank[count], &enemy_bullet[count]);
            }
            
        }
        //ÿ0.5s��һ��
        else if (current_time % 50 == 0) {
            
            for (int count = 0; count < enemy_Tank->tank_current_num; count++) {
                if (enemy_Tank[count].live == 1) {
                    control_tank_move(&enemy_Tank[count], enemy_Tank[count].tank_direction, &enemy_tank_img[enemy_Tank[count].tank_direction]);
                }
     
            }
        }
        
        //��ȡ���̰���
        if(peekmessage(&key, EX_KEY,true)) {
            //key = getmessage(EX_KEY);
           
            //�Զ�����caplockģʽ
            /*if (key.vkcode == VK_CAPITAL) {
                key.message = WM_KEYDOWN;
                key.vkcode = VK_CAPITAL;
            }*/
            if (key.message == WM_KEYDOWN)
            {
                switch (key.vkcode) {
                case 'P':
                    system("pause");
                    break;
                case 'W':
                    //�����ƶ�
                    control_tank_move(&mytank, UP, &tank_dir_img[UP]);
                    break;
                case 'A':
                    control_tank_move(&mytank, LEFT, &tank_dir_img[LEFT]);
                    break;
                case 'S':
                    control_tank_move(&mytank, DOWN, &tank_dir_img[DOWN]);
                    break;
                case 'D':
                    control_tank_move(&mytank, RIGHT, &tank_dir_img[RIGHT]);                
                    break;
                case 'J':
                    Tank::bullet_fire_init(&mytank, &bullet_s);
                    break;
                }

                //break;
            }
            
        }
        if (bullet_s.status == 1) {
            if(bullet_act(&bullet_s,enemy_Tank));
        }
        //�з��ӵ��Լ���
        for (int count = 0; count < enemy_Tank->tank_current_num; count++) {
            if(enemy_bullet[count].status == 1) {
                bullet_act(&enemy_bullet[count],&mytank);
                
            }
        }
        Sleep(10);
        current_time++;
            
    }

}