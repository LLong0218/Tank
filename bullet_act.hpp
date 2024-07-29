#pragma once
#include"bullet_hit_wall.hpp"
void bullet_act(bullet* bullet_s) {
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
        return;
    }

    if (bullet_s->x < 0 || bullet_s->y < 0 || bullet_s->x>650 || bullet_s->y>650) {
        bullet_s->status = 0;
        return;
    }

    //是否击中家的碰撞测试
    if (map[y][x] == 4 || map[bullet_new_y][bullet_new_x] == 4) {
        return;
        //后续补全game over
    }
    bullet_hit_wall(x, y, bullet_s);
    bullet_hit_wall(bullet_new_x, bullet_new_y, bullet_s);

    //IMAGE bullet_img;
    if (bullet_s->status == 1) {
        //loadimage(&bullet_img, _T("D:\\Tankfight_source\\resources\\image\\bullet.png"), 10,10);
        //putimage(bullet_s->x,bullet_s->y, &bullet_img);
        setfillcolor(WHITE);
        solidrectangle(bullet_s->x, bullet_s->y, bullet_s->x + 3, bullet_s->y + 3);
    }
}