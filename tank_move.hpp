#pragma once
//坦克移动实现


//坦克方向枚举
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT

};
//坦克类
class Tank {
public:
    int x;
    int y;
    Direction tank_direction;
    int live = 1;

};
class bullet {
public:
    int x, y;
    Direction bullet_direction;
    int status = 0;

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