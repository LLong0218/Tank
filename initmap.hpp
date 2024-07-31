#pragma once

//加载初始化地图
void initmap() {
    IMAGE wall_special, wall_normal, home;

    //载入地图图片
    loadimage(&wall_special, _T("image\\wall1.jpg"), 25, 25);
    loadimage(&wall_normal, _T("image\\wall2.jpg"), 25, 25);
    loadimage(&home, _T("image\\home1.jpg"), 50, 50);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (map[i][j] == 1) {
                putimage(25 * j, 25 * i, &wall_normal);
            }
            else if (map[i][j] == 2) {
                putimage(25 * j, 25 * i, &wall_special);
            }
            else if (map[i][j] == 3)
            {
                putimage(25 * j, 25 * i, &home);
                //若后续受到伤害，判定条件是碰到值为4的map
                change_pos_data<int>(i, j, 4);

            }
        }
    }
}