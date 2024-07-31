#pragma once
#include"bullet_hit_wall.hpp"
//此处的enemy_tank是相对来说的，对敌方来说我方是敌对，需要做碰撞优化
int bullet_act(bullet* bullet_s,Tank* enemy_tank,Tank* friend_tank) {
    int x, y, bullet_new_x, bullet_new_y;
    
    x = bullet_s->x / 25;
    y = bullet_s->y / 25;

    setfillcolor(BLACK);
    solidrectangle(bullet_s->x, bullet_s->y, bullet_s->x + 3, bullet_s->y + 3);

    if (bullet_s->bullet_direction == UP) {
        bullet_s->y -= 2;
        bullet_new_x = x + 1;
        bullet_new_y = y;
    }
    else if (bullet_s->bullet_direction == DOWN) {
        bullet_s->y += 2;
        bullet_new_x = x + 1;
        bullet_new_y = y;
    }
    else if (bullet_s->bullet_direction == LEFT) {
        bullet_s->x -= 2;
        bullet_new_x = x;
        bullet_new_y = y + 1;
    }
    else if (bullet_s->bullet_direction == RIGHT) {
        bullet_s->x += 2;
        bullet_new_x = x;
        bullet_new_y = y + 1;
    }
    else {
        return 0;
    }

    if (bullet_s->x < 0 || bullet_s->y < 0 || bullet_s->x>650 || bullet_s->y>650) {
        bullet_s->status = 0;
        return 0;
    }

    //是否击中家的碰撞测试
    if (map[y][x] == 4 || map[bullet_new_y][bullet_new_x] == 4) {
        return 1;
        //后续补全game over
    }
    bullet_hit_wall(x, y, bullet_s);
    bullet_hit_wall(bullet_new_x, bullet_new_y, bullet_s);


    if (map[friend_tank->y][friend_tank->x] >= 100 && map[friend_tank->y][friend_tank->x] <= 109) {
        if (map[y][x] >= 100 && map[y][x] <= 109 || map[bullet_new_y][bullet_new_x] >= 100 && map[bullet_new_y][bullet_new_x] <= 109) {
            bullet_s->status = 0;
            return 0;
        }
    }

    if(!(map[friend_tank->y][friend_tank->x]>=100&&map[friend_tank->y][friend_tank->x]<=109)){
        if (map[y][x] >= 100 && map[y][x] <= 109 || map[bullet_new_y][bullet_new_x] >= 100 && map[bullet_new_y][bullet_new_x] <= 109) {
            Tank* tank = NULL;
            bullet_s->status = 0;
            if (map[y][x] >= 100 && map[y][x] <= 109) {
                tank = enemy_tank + (map[y][x] - 100);
            }
            else tank = enemy_tank + (map[bullet_new_y][bullet_new_x] - 100);

            tank->live = 0;

            change_pos_data<int>(tank->y, tank->x, 0);
            setfillcolor(BLACK);
            solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);
            return 0;
        }
    }
    
    if (map[friend_tank->y][friend_tank->x] == 200) {
        if (map[y][x] == 200 || map[bullet_new_y][bullet_new_x] == 200) {
            bullet_s->status = 0;
            return 0;
        }
    }
    if (!(map[friend_tank->y][friend_tank->x] == 200)) {
        if (map[y][x] == 200 || map[bullet_new_y][bullet_new_x] == 200) {
            bullet_s->status = 0;
            enemy_tank->live = 0;
            return 1;
        }
    }
    

    //IMAGE bullet_img;
    if (bullet_s->status == 1) {
        //loadimage(&bullet_img, _T("D:\\Tankfight_source\\resources\\image\\bullet.png"), 10,10);
        //putimage(bullet_s->x,bullet_s->y, &bullet_img);
        setfillcolor(WHITE);
        solidrectangle(bullet_s->x, bullet_s->y, bullet_s->x + 3, bullet_s->y + 3);
        return 0;
    }
}