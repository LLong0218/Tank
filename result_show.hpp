#pragma once
auto result_show(int res) {
	//����ʤ��ʧ�ܽ���ͼƬ
	IMAGE win, lose;
	loadimage(&win, _T("..\\score.jpg"),500,450);
	loadimage(&lose, _T("..\\over.gif"), 200, 200);

	//����resΪsuc����fail����������ʲô
	if (res) {
		putimage(75, 100, &win);
	}
	else putimage(200, 200, &lose);
	
	//peekmessage;
}