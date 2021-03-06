#include "Libs\\TXLib.h"
#include "Libs\\persons.cpp"
#include <string>

struct Vrag
{
    int x;
    int y;
    int shir;
    int vys;
    int speed;
    HDC pic;
};

void proverka_v_labirinte(int x, int y, int xl, int yl, bool* popal) {
    *popal = false;
    for (int x_get = x - xl+10; x_get < x - xl + 130; x_get += 10)
    {
        for (int y_get = y - yl + 10; y_get < y - yl + 130; y_get += 10)
        {
            if (*popal == false and txGetPixel(x_get, y_get) == TX_BLACK)
            {
                *popal = true;
            }
        }
    }
}

void dvigenie_buratino(HDC*   kartinka , HDC buratino2 ,HDC  buratino , HDC buratino_verh,
        HDC buratino_niz, int* x , int* y , int speed) {

    if (GetAsyncKeyState(VK_LEFT) &&  *y < 800)
    {
        *kartinka = buratino2;
        *x -= speed;

    }
    else if (GetAsyncKeyState(VK_RIGHT) && *x< 800-156 )
    {
        *kartinka = buratino;
        *x += speed;

    }
    else
    {
        *kartinka = buratino;
    }

    if (GetAsyncKeyState(VK_UP)&& *y > 70)
    {
        *kartinka = buratino_verh;
        *y -= speed;

    }
    else if (GetAsyncKeyState(VK_DOWN) && *y < 700)
    {
        *kartinka = buratino_niz;
        *y += speed;

    }
}
void dvigenie_buratino_lab(HDC*   kartinka , HDC buratino2 ,HDC  buratino , HDC buratino_verh,
        HDC buratino_niz, int* x , int* y , int speed,int* xl, int* yl) {

    if (GetAsyncKeyState(VK_LEFT) )
    {
        *kartinka = buratino2;
        *x -= speed;
        *xl -= speed;
    }
    else if (GetAsyncKeyState(VK_RIGHT) )
    {
        *kartinka = buratino;
        *x += speed;
        *xl += speed;
    }
    else
    {
        *kartinka = buratino;
    }

    if (GetAsyncKeyState(VK_UP) )
    {
        *kartinka = buratino_verh;
        *y -= speed;
        *yl -= speed;
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        *kartinka = buratino_niz;
        *y += speed;
        *yl += speed;
    }
}

void sobral_monetu (int* monetok_s_soboi, int* monetok_v_kopilke, int* x , int* y , int* moneta_x,int* moneta_y){

    if (abs (*x - *moneta_x) + abs (*y - *moneta_y) < 100 &&
        *monetok_s_soboi < 1 &&
        *monetok_v_kopilke <=9) {

        if (*monetok_s_soboi <=0) {

            *moneta_x = random(500);
            *moneta_y = random(700);
            *monetok_s_soboi = *monetok_s_soboi + 1;
        }
    }
}

void otnes_v_kopilku(int* monetok_s_soboi, int* monetok_v_kopilke, int* x , int* y , int* moneta_x,int* moneta_y){
    if (abs (*x - 650 ) + abs (*y - 650) < 150)     {
        if (*monetok_s_soboi <=5) {
            *monetok_v_kopilke = *monetok_v_kopilke + *monetok_s_soboi;
            *monetok_s_soboi = 0;
        }
    }
}

void stolknovenie_s_prep (bool* game_over, Vrag* alisa, Vrag* bazilla, int* x , int* y, int* zhizhey) {

    if (alisa->x >= 800)
    {
        alisa->speed = -5;
    }
    else if (alisa->x <= 0)
    {
        alisa->speed = 5;
    }

    if (bazilla->y >= 800)
    {
        bazilla->speed = -5;
    }
    else if (bazilla->y <= 120)
    {
        bazilla->speed = 5;
    }

    bazilla->y = bazilla->y + bazilla->speed;
    txTransparentBlt (txDC(), bazilla->x, bazilla->y, bazilla->shir, bazilla->vys, bazilla->pic, 0, 0, TX_WHITE);
    if (abs(*x- bazilla->x) < 100 && abs(*y- bazilla->y) < 80) {

        *zhizhey = *zhizhey -1;
          *x = *x-70;
    }

    alisa->x = alisa->x + alisa->speed;
    txTransparentBlt (txDC(), alisa->x, alisa->y, alisa->shir, alisa->vys, alisa->pic, 0, 0, TX_WHITE);
    if (abs(*x- alisa->x) < 100 && abs(*y- alisa->y) < 80) {

        *zhizhey = *zhizhey -1;
        *x = *x-70;





    }
    if (*zhizhey < 1){

             *game_over = true;
    }
}

void perehodklabirintu (bool* uroven_proiden, int monetok_v_kopilke, HDC perehod, HDC perehod2, HDC perehod3) {

    if (monetok_v_kopilke == 10) {
        risovat_perehod(perehod);
        txSleep(2500);
        risovat_perehod(perehod2);
        txSleep(2500);
        risovat_perehod(perehod3);
        txSleep(2500);
        *uroven_proiden = true;
    }
}

void Hplay (HDC vstuplenye ) {

    if (GetAsyncKeyState('H')) {
        risovat_vstuplenye(vstuplenye);
        txSleep(2500);
    }
}



int main() {
    txDisableAutoPause();
    txCreateWindow (1000,1000);
    txDisableAutoPause();


    Vrag bazilla = {200, 300, 120, 212, 5, txLoadImage("Pictures\\kotbazilla.bmp")};
    Vrag alisa = {500, 300, 194, 278, 5, txLoadImage("Pictures\\lisalevo.bmp")};

//��������� "��������" (4 ��������, ������� ��������, ����������)
    int x = 80;
    int y = 80;
    int speed = 15;
    int monetok_s_soboi = 0;
    int monetok_v_kopilke = 0;
    int zhizhey = 5;
    int razmer_ekran= 800;
    int xl = 0;
    bool game_over = false;
    bool uroven_proiden = false;int yl = 0;


     //HDC FON = txLoadImage("FON.bmp");


    HDC moneta = txLoadImage("Pictures\\moneta.bmp");
    int moneta_x = random(razmer_ekran);
    int moneta_y = random(razmer_ekran);

    int i;
    HDC buratinoPic;
    HDC buratino = txLoadImage("Pictures\\buratino.bmp");
    HDC buratino2 = txLoadImage("Pictures\\buratino2.bmp");
    HDC buratino_niz = txLoadImage("Pictures\\buratinopered.bmp");
    HDC buratino_verh = txLoadImage("Pictures\\buratinozad.bmp");

    HDC kopilka = txLoadImage("Pictures\\kopilka.bmp");


    HDC panel = txLoadImage("Pictures\\panel.bmp");

    HDC menu = txLoadImage("Pictures\\menushka.bmp");

    HDC perehod = txLoadImage ("Pictures\\perehod.bmp");
    HDC perehod2 = txLoadImage ("Pictures\\perehod2.bmp");
    HDC perehod3 = txLoadImage ("Pictures\\perehod3.bmp");
    HDC vstuplenye = txLoadImage ("Pictures\\labirintHistory.bmp");
    HDC labirint = txLoadImage ("Pictures\\labirint.bmp");
        HDC labirint2 = txLoadImage ("Pictures\\labirint2.bmp");
    HDC kartinka;

    risovatMenu(menu);
   while (!GetAsyncKeyState('G')) {
        1;
    }
    while (GetAsyncKeyState('Z')){
        game_over = true;
    }

    while (game_over == false && uroven_proiden == false)
    {
        txClear();
        txBegin();

        risovat_kopilka(kopilka);
        risovat_moneta(moneta_x, moneta_y, moneta);
        risovat_panel(panel, monetok_s_soboi, monetok_v_kopilke, zhizhey);
        txSetFillColor (TX_WHITE);

        dvigenie_buratino(&buratinoPic, buratino2, buratino, buratino_verh, buratino_niz, &x ,&y , speed);
        risovat_buratino(x, y, buratinoPic);

        sobral_monetu (&monetok_s_soboi, &monetok_v_kopilke, &x ,  &y ,  &moneta_x, &moneta_y);

        otnes_v_kopilku( &monetok_s_soboi, &monetok_v_kopilke,  &x , &y ,&moneta_x, &moneta_y);

        stolknovenie_s_prep(&game_over, &alisa, &bazilla, &x , &y, &zhizhey);
       // monetok_v_kopilke = 10;

        perehodklabirintu (&uroven_proiden, monetok_v_kopilke, perehod ,perehod2, perehod3) ;
        Hplay (vstuplenye );

        txSleep(30);
        txEnd();
    }
    uroven_proiden = true;
    if (game_over == false && uroven_proiden == true)
    {
        x = 130;
        y = 30;
        xl = 0;
        yl = 0;
        int xPred = 0;
        int yPred = 0;
        int xlPred = 0;
        int ylPred = 0;
        while (!GetAsyncKeyState('R')) {

            txClear();

            txBegin();

            xPred = x;
            yPred = y;
            xlPred = xl;
            ylPred = yl;

            dvigenie_buratino_lab(&buratinoPic ,  buratino2 ,  buratino ,  buratino_verh, buratino_niz, &x ,  &y , speed,&xl,&yl);

            risovat_labirint(labirint, xl,yl);

            bool popal = false;
            proverka_v_labirinte(x, y, xl, yl, &popal);

            if (popal)
            {
                x = xPred;
                y = yPred;
                xl = xlPred;
                yl = ylPred;
            }

            //x = 4000;
            //������� ����
            if (x>3933)
            {
                x = 0;
                y = 0;
                xl = 0;
                yl = 0;
                xPred = 0;
                yPred = 0;
                xlPred = 0;
                ylPred = 0;

                while (!GetAsyncKeyState('R')) {

                    txClear();

                    txBegin();

                    xPred = x;
                    yPred = y;
                    xlPred = xl;
                    ylPred = yl;

                    dvigenie_buratino_lab(&buratinoPic ,  buratino2 ,  buratino ,  buratino_verh, buratino_niz, &x ,  &y , speed,&xl,&yl);

                    risovat_labirint2(labirint2, xl,yl);


                    proverka_v_labirinte(x, y, xl, yl, &popal);

                    if (popal)
                    {
                        x = xPred;
                        y = yPred;
                        xl = xlPred;
                        yl = ylPred;
                    }

                    txSetFillColor(TX_RED);

                    risovat_buratino(x-xl, y- yl, buratinoPic);

                    txSleep(10);
                    txEnd();
                }
            }
            txSetFillColor(TX_RED);

            risovat_buratino(x-xl, y- yl, buratinoPic);

            txSleep(10);
            txEnd();
        }

        game_over = true;
    }

    return 0;
}
