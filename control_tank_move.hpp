#pragma once

int control_tank_move(Tank* enemy_tank, Direction direction, IMAGE* enemy_img) {
    switch (direction) {
   
    case UP:
        //ÏòÉÏÒÆ¶¯
        if (direction == UP && enemy_tank->y - 1 >= 0 && map[enemy_tank->y - 1][enemy_tank->x] == 0 && map[enemy_tank->y - 1][enemy_tank->x + 1] == 0)
        {

            tank_move(enemy_tank, UP, enemy_img, 1);
        }
        else if (direction != UP) {
            direction = UP;
            tank_move(enemy_tank, UP, enemy_img, 0);
        }

        break;
    case LEFT:
        if (direction == LEFT && enemy_tank->x - 1 >= 0 && map[enemy_tank->y][enemy_tank->x - 1] == 0 && map[enemy_tank->y + 1][enemy_tank->x - 1] == 0)
        {

            tank_move(enemy_tank, LEFT, enemy_img, 1);
        }
        else if (direction != LEFT) {
            direction = LEFT;
            tank_move(enemy_tank, LEFT, enemy_img, 0);
        }
        break;
    case DOWN:
        if (direction == DOWN && enemy_tank->y + 2 <= 25 && map[enemy_tank->y + 2][enemy_tank->x] == 0 && map[enemy_tank->y + 2][enemy_tank->x + 1] == 0)
        {

            tank_move(enemy_tank, DOWN, enemy_img, 1);

        }
        else if (direction != DOWN) {
            direction = DOWN;
            tank_move(enemy_tank, DOWN, enemy_img, 0);
        }
        break;
    case RIGHT:
        if (direction == RIGHT && enemy_tank->x + 2 <= 25 && map[enemy_tank->y][enemy_tank->x + 2] == 0 && map[enemy_tank->y + 1][enemy_tank->x + 2] == 0)
        {

            tank_move(enemy_tank, RIGHT, enemy_img, 1);

        }
        else if (direction != RIGHT) {
            direction = RIGHT;
            tank_move(enemy_tank, RIGHT, enemy_img, 0);
        }
        break;
        return 1;
    }
}