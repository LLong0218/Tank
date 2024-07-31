#pragma once
auto result_show(int res) {
	//加载胜利失败界面图片
	IMAGE win, lose;
	loadimage(&win, _T("image\\score.jpg"),500,450);
	loadimage(&lose, _T("image\\over.gif"), 350, 300);

	//根据res为suc或者fail来决定加载什么
	if (res) {
		putimage(150, 170, &lose);
	}
	else putimage(75, 100, &win);
	

	peekmessage;
}