#pragma once

int control_tank_move(Tank* tank, Direction direction, IMAGE* img) {
    switch (tank->tank_direction) {
   
    case UP:
        //ÏòÉÏÒÆ¶¯
        if (tank->tank_direction == UP && tank->y - 1 >= 0 && map[tank->y - 1][tank->x] == 0 && map[tank->y - 1][tank->x + 1] == 0)
        {
            tank_move(tank, UP, img, 1);
        }
        else if (tank->tank_direction != UP) {
            tank->tank_direction = UP;
            tank_move(tank, UP, img, 0);
        }

        break;
    case LEFT:
        if (tank->tank_direction == LEFT && tank->x - 1 >= 0 && map[tank->y][tank->x - 1] == 0 && map[tank->y + 1][tank->x - 1] == 0)
        {

            tank_move(tank, LEFT, img, 1);
        }
        else if (tank->tank_direction != LEFT) {
            tank->tank_direction = LEFT;
            tank_move(tank, LEFT, img, 0);
        }
        break;
    case DOWN:
        if (tank->tank_direction == DOWN && tank->y + 2 <= 25 && map[tank->y + 2][tank->x] == 0 && map[tank->y + 2][tank->x + 1] == 0)
        {

            tank_move(tank, DOWN, img, 1);

        }
        else if (tank->tank_direction != DOWN) {
            tank->tank_direction = DOWN;
            tank_move(tank, DOWN, img, 0);
        }
        break;
    case RIGHT:
        if (tank->tank_direction == RIGHT && tank->x + 2 <= 25 && map[tank->y][tank->x + 2] == 0 && map[tank->y + 1][tank->x + 2] == 0)
        {

            tank_move(tank, RIGHT, img, 1);

        }
        else if (tank->tank_direction != RIGHT) {
            tank->tank_direction = RIGHT;
            tank_move(tank, RIGHT, img, 0);
        }
        break;
        return 1;
    }
}