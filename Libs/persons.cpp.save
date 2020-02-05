#include "TXLib.h"

void risovat_buratino(int x, int y, HDC buratino) {
    txTransparentBlt (txDC(), x, y, 140, 140, buratino, 0, 0, TX_WHITE);
}
void risovat_buratinoMini(int x, int y, HDC buratino) {
    txTransparentBlt (txDC(), x, y, 60, 55, buratino, 0, 0, TX_WHITE);
}

void risovat_moneta(int x, int y, HDC moneta){
    txTransparentBlt (txDC(), x, y, 156, 157, moneta,0, 0, TX_WHITE);
}

void risovat_panel(HDC panel, int monetok_s_soboi, int monetok_v_kopilke, int zhizhey) {
    txBitBlt (txDC(), 0, 0, 1000, 1000, panel,0, 0);

    char monetok_s_soboi_stroka[100];
    sprintf(monetok_s_soboi_stroka, "%d", monetok_s_soboi);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 60);
    txTextOut(190, 5, monetok_s_soboi_stroka);

    char monetok_v_kopilke_stroka[100];
    sprintf(monetok_v_kopilke_stroka, "%d", monetok_v_kopilke);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 60);
    txTextOut(550, 5, monetok_v_kopilke_stroka);

     char zhizhey_stroka[100];
    sprintf(zhizhey_stroka, "%d", zhizhey);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 60);
    txTextOut(750, 5, zhizhey_stroka);
}

void risovat_kopilka(HDC kopilka){
    txTransparentBlt (txDC(), 550, 550, 230, 158, kopilka, 0, 0, TX_WHITE);
}

void risovatMenu(HDC menu) {
    txBitBlt (txDC(), 0, 0, 1000, 1000, menu,0, 0);
}

void risovat_perehod(HDC perehod) {
    txBitBlt (txDC(),0,0,1000,1000,perehod,0,0);
}

void risovat_labirint(HDC labirint, int xl,int yl) {
    txBitBlt (txDC(),0,0,4650,3824,labirint,xl,yl);

}
void risovat_labirint2(HDC labirint2, int xl,int yl) {
    txBitBlt (txDC(),0,0,4650,3824,labirint2,xl,yl);

}


void risovat_vstuplenye(HDC vstuplenye) {
    txBitBlt (txDC(),0,0,1000,1000,vstuplenye,0,0);
}

