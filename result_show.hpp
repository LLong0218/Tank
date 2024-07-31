#pragma once
auto result_show(int res) {
	//加载胜利失败界面图片
	IMAGE win, lose;
	loadimage(&win, _T("..\\score.jpg"),500,450);
	loadimage(&lose, _T("..\\over.gif"), 200, 200);

	//根据res为suc或者fail来决定加载什么
	if (res) {
		putimage(75, 100, &win);
	}
	else putimage(200, 200, &lose);
	
	//peekmessage;
}