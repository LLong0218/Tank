#pragma once


//�˵���ʼ��
void menu() {
    //logo��ʾ

    IMAGE logo_img;
    //getimage(&logo_img, _T("D:\\Tankfight_source\\resources\\image\\logo.bmp"), 433, 147);
    loadimage(&logo_img, _T("..\\logo.bmp"), 433, 147);
    putimage(110, 20, &logo_img);

    //������ťʵ��
    setlinecolor(WHITE);
    setfillcolor(BLACK);

    fillrectangle(230, 200, 310, 240);
    settextstyle(25, 0, _T("����"));
    outtextxy(240, 210, _T("˵��"));

    fillrectangle(350, 200, 430, 240);
    outtextxy(360, 210, _T("��ʼ"));


    //�淨����ͼƬ����
    IMAGE illustrate_img;
    loadimage(&illustrate_img, _T("..\\illustrate.jpg"), 300, 300);

    //��������ѭ������
    //int finished = 1;
    //���ý�������ж�����
    while (true) {
        MOUSEMSG mouse;
        mouse = GetMouseMsg();
        switch (mouse.uMsg) {

        case WM_MOUSEMOVE:
            if ((mouse.x > 230 && mouse.x < 310) && (mouse.y > 200 && mouse.y < 240)) {
                putimage(150, 250, &illustrate_img);
            }
            else {
                solidrectangle(150, 250, 450, 550);
            }
            break;
        case WM_LBUTTONDOWN:
            if ((mouse.x > 350 && mouse.x < 430) && (mouse.y > 200 && mouse.y < 240)) {
                cleardevice();
                /*finished = 0;
                break;*/
                return;
            }

        }

    }

}