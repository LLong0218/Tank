#pragma once
int bullet_hit_wall(int x, int y, bullet* bullet) {
    if (map[y][x] == 1) {
        map[y][x] = 0;
        bullet->status = 0;
        setfillcolor(BLACK);
        solidrectangle(x * 25, y * 25, x * 25 + 25, y * 25 + 25);
    }
    else if (map[y][x] == 2) {
        bullet->status = 0;
    }
    return 0;
}