#pragma once
auto result_show(int res) {
	//����ʤ��ʧ�ܽ���ͼƬ
	IMAGE win, lose;
	loadimage(&win, _T("image\\score.jpg"),500,450);
	loadimage(&lose, _T("image\\over.gif"), 350, 300);

	//����resΪsuc����fail����������ʲô
	if (res) {
		putimage(150, 170, &lose);
	}
	else putimage(75, 100, &win);
	

	peekmessage;
}