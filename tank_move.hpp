#pragma once
//坦克移动实现

//#include"init_tank_pos.hpp"
//坦克方向枚举

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT

};

class bullet {
public:
    int x, y;
    Direction bullet_direction;
    int status = 0;

};
//坦克类
class Tank {
public:
    int x;
    int y;
    Direction tank_direction;
    int live = 1;
    int tank_current_num = 3;

    static void bullet_fire_init(Tank* tank, bullet* bullet) {
        if (bullet->status == 0) {
            if (tank->tank_direction == UP) {
                bullet->x = tank->x * 25 + 23;
                bullet->y = tank->y * 25 - 3;
            }
            else if (tank->tank_direction == LEFT) {
                bullet->x = tank->x * 25 - 3;
                bullet->y = tank->y * 25 + 23;
            }
            else if (tank->tank_direction == DOWN) {
                bullet->x = tank->x * 25 + 23;
                bullet->y = tank->y * 25 + 56;
            }
            else if (tank->tank_direction == RIGHT) {
                bullet->x = tank->x * 25 + 56;
                bullet->y = tank->y * 25 + 23;
            }
            //调整方向
            bullet->bullet_direction = tank->tank_direction;
            bullet->status = 1;

        }
    }

    Direction enemytank_auto_move(Tank* etank, int x, int y) {
        auto res = rand() % 100;
        for (int i = 0; i < etank->tank_current_num; i++) {
            if (etank->x < x) {
                if (etank->y < y) {
                    if (res <= 50) {
                        return RIGHT;
                    }
                    else {
                        return DOWN;
                    }
                }
                else {
                    if (res <= 50) {
                        return RIGHT;
                    }
                    else return UP;
                }
            }
            else {
                if (etank->y < y) {
                    if (res <= 50) {
                        return LEFT;
                    }
                    else return DOWN;
                }
                else {
                    if (res <= 50) {
                        return LEFT;
                    }
                    else return UP;
                }
            }
        }
    }

};


int tank_move(Tank* tank_s, Direction direction, IMAGE* img, int step) {
    int new_x = tank_s->x;
    int new_y = tank_s->y;

    if (step == 1) {
        if (direction == UP) {
            new_y -= 1;
        }
        else if (direction == DOWN) {
            new_y += 1;
        }
        else if (direction == LEFT) {
            new_x -= 1;
        }
        else if (direction == RIGHT) {
            new_x += 1;
        }
        else {
            return 0;
        }

    }

    change_pos_data(tank_s->y, tank_s->x, 0);


    setfillcolor(BLACK);
    solidrectangle(tank_s->x * 25, tank_s->y * 25, tank_s->x * 25 + 50, tank_s->y * 25 + 50);


    if (step == 1) {
        change_pos_data(new_y, new_x, 200);
        tank_s->x = new_x;
        tank_s->y = new_y;

    }

    putimage(tank_s->x * 25, tank_s->y * 25, img);
    return 1;

}