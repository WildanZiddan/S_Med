void Specialkeylogin(int x, int y, int lebar,int tinggi, int *output) {
    //Declaration
    int count = 1;
    char ch;


    //Algorithm
    menuMasuk();
    BorderSwitchRole(x, y, 20);

    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 2 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 3 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 4 :
                    Beep(3000, 100);
                    *output = count;
                    break;
            }
            break;
        } else if (ch == UP_KEY) {
            if (count > 1) {
                Beep(1000, 100);
                clearArea(x, y, lebar + 2, tinggi);
                y -= 4;  // Geser ke atas sebanyak 4 unit
                BorderSwitchRole(x, y, lebar);
                menuMasuk();
                count--;
            }
        } else if (ch == DWN_KEY) {
            if (count < 4) {
                Beep(1000, 100);
                clearArea(x, y, lebar + 2, tinggi);
                y += 4;  // Geser ke bawah sebanyak 4 unit
                BorderSwitchRole(x, y, lebar);
                menuMasuk();
                count++;
            }
        }
    }
}

void SpecialKeyLoginProses(int x, int y, int lebar,int tinggi,int *output) {
    int count = 1;
    char ch;
    //Algorithm
    SetColorBlock(4, 15);
    BorderSwitchRole(x, y, lebar);
    menuBackSign();
    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 2 :
                    Beep(3000, 100);
                    *output = count;
                    break;
            }
            break;
        } else if (ch == RGHT_KEY) {
            if (count > 1) {
                Beep(1000, 100);
                clearArea(x, y, lebar+2,tinggi);
                x += 20;
                BorderSwitchRole(x, y, lebar);
                menuBackSign();
                count--;
            }
        } else if (ch == LEFT_KEY) {
            if (count < 2) {
                Beep(1000, 100);
                clearArea(x, y, lebar+2, tinggi);
                x -= 20;
                BorderSwitchRole(x,y,lebar);
                menuBackSign();
                count++;
            }
        }
    }
}


void SpecialKeyYesorNoDashboard(int x, int y,int jarak,int fore,int back,int *output) {
    hideCursor();
    int count = 1;
    char ch;
    //Algorithm
    SetColorBlock(fore, back);
    menuYesorNo(x,y,jarak);
    if(count == 1){
        SetColorBlock(0,back);
        gotoprinttext(x,y,"    Y A");
    }

    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(1000, 120);
                    *output = count;
                    break;

                case 2 :
                    Beep(1000, 120);
                    *output = count;
                    break;
            }
            break;
        } else if (ch == RGHT_KEY) {
            if (count > 1) {
                Beep(700, 120);
                SetColorBlock(fore, back);
                menuYesorNo(x,y,jarak);
                count--;
                if(count == 1){
                    SetColorBlock(0,back);
                    gotoprinttext(x,y,"    Y A");
                } else if(count == 2){
                    SetColorBlock(0,back);
                    gotoprinttext(x-jarak,y,"T I D A K");
                }
            }
        } else if (ch == LEFT_KEY) {
            if (count < 2) {
                Beep(700, 120);
                SetColorBlock(fore, back);
                menuYesorNo(x,y,jarak);
                count++;
                if(count == 1){
                    SetColorBlock(0,back);
                    gotoprinttext(x,y,"    Y A");
                } else if(count == 2){
                    SetColorBlock(0,back);
                    gotoprinttext(x-jarak,y,"T I D A K");
                }
            }
        }
    }
}


void SpecialKeyCariorBackDashboard(int x, int y,int jarak,int fore,int back,int *output) {
    hideCursor();
    int count = 1;
    char ch;
    //Algorithm
    SetColorBlock(fore, back);
    menuLihatorBack(x,y,jarak);
    if(count == 1){
        SetColorBlock(0,back);
        gotoprinttext(x,y,"LIHAT DETAIL");
    }

    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(1000, 120);
                    *output = count;
                    break;

                case 2 :
                    Beep(1000, 120);
                    *output = count;
                    break;
            }
            break;
        } else if (ch == RGHT_KEY) {
            if (count > 1) {
                Beep(700, 120);
                SetColorBlock(fore, back);
                menuLihatorBack(x,y,jarak);
                count--;
                if(count == 1){
                    SetColorBlock(0,back);
                    gotoprinttext(x,y,"LIHAT DETAIL");
                } else if(count == 2){
                    SetColorBlock(0,back);
                    gotoprinttext(x-jarak,y,"KEMBALI");
                }
            }
        } else if (ch == LEFT_KEY) {
            if (count < 2) {
                Beep(700, 120);
                SetColorBlock(fore, back);
                menuLihatorBack(x,y,jarak);
                count++;
                if(count == 1){
                    SetColorBlock(0,back);
                    gotoprinttext(x,y,"LIHAT DETAIL");
                } else if(count == 2){
                    SetColorBlock(0,back);
                    gotoprinttext(x-jarak,y,"KEMBALI");
                }
            }
        }
    }
}