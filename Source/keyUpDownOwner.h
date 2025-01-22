

void SpecialkeyDashboardOwner(int x, int y, int lebar,int tinggi, int *output) {
    //Declaration
    int count = 1;
    char ch;


    //Algorithm
    SetColorBlock(15, 4);
    BorderSwitchRoleDashboard(x, y, lebar, tinggi);
    menuDashboardOwner();

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

                case 5 :
                    Beep(3000, 100);
                *output = count;
                break;

                case 6 :
                    Beep(3000, 100);
                *output = count;
                break;
            }
            break;
        } else if (ch == UP_KEY) {
            if (count > 5) {
                Beep(1000, 50);
                clearArea(x, y, lebar + 2, tinggi);
                y -= 10;  // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,4);
                BorderSwitchRoleDashboard(x, y, lebar,tinggi);
                menuDashboardOwner();
                count--;
            } else if(count > 1){
                Beep(1000, 50);
                clearArea(x, y, lebar + 2, tinggi);
                y -= 5;  // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,4);
                BorderSwitchRoleDashboard(x, y, lebar,tinggi);
                menuDashboardOwner();
                count--;
            }
        } else if (ch == DWN_KEY) {
            if (count < 5) {
                Beep(1000, 50);
                clearArea(x, y, lebar + 2, tinggi);
                y += 5;  // Geser ke bawah sebanyak 4 unit
                BorderSwitchRoleDashboard(x, y, lebar,tinggi);
                SetColorBlock(15,4);
                menuDashboardOwner();
                count++;
            } else if(count < 6){
                Beep(1000, 50);
                clearArea(x, y, lebar + 2, tinggi);
                y += 10;  // Geser ke bawah sebanyak 15 unit
                menuDashboardOwner();
                SetColorBlock(4,15);
                gotoprinttext(13,39,"K E L U A R");
                count++;
            }
        }
    }
}

void SpecialkeyloginMenuDataOwner(int x, int y, int lebar,int tinggi, int *output) {
    //Declaration
    int count = 1;
    char ch;

    //Algorithm
//    BorderSwitchRole(x, y, lebar);
    SetColorBlock(15,12);
    menuDataSupplierOwner();
    if(count == 1){
        SetColorBlock(0,12);
        gotoprinttext(80,25," L I H A T  D A T A");
    }
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
                case 5 :
                    Beep(3000, 100);
                *output = count;
                break;
            }
            break;
        } else if (ch == UP_KEY) {
            if (count > 1) {
                Beep(700, 50);
//                clearArea(x, y, lebar + 2, tinggi);
                y -= 3;  // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,12);
//               BorderSwitchRole(x, y, lebar);
                menuDataSupplierOwner();
                count--;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(80,25," L I H A T  D A T A");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(80,28,"T A M B A H  D A T A");
            } else if(count==3){
                SetColorBlock(0,12);
                gotoprinttext(80,31,"U P D A T E  D A T A");
            } else if(count == 4){
                SetColorBlock(0,12);
                gotoprinttext(80,34," H A P U S  D A T A");
            } else if(count == 5){
                SetColorBlock(0,12);
                gotoprinttext(80,37,"    K E M B A L I");
            }
        } else if (ch == DWN_KEY) {
            if (count < 5) {
                Beep(700, 50);
//                clearArea(x, y, lebar + 2, tinggi);
                y += 3;  // Geser ke bawah sebanyak 4 unit
//                BorderSwitchRole(x, y, lebar);
                SetColorBlock(15,12);
                menuDataSupplierOwner();
                count++;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(80,25," L I H A T  D A T A");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(80,28,"T A M B A H  D A T A");
            } else if(count==3){
                SetColorBlock(0,12);
                gotoprinttext(80,31,"U P D A T E  D A T A");
            } else if(count == 4){
                SetColorBlock(0,12);
                gotoprinttext(80,34," H A P U S  D A T A");
            } else if(count == 5){
                SetColorBlock(0,12);
                gotoprinttext(80,37,"    K E M B A L I");
            }
        }
    }
}

void SpecialkeyloginMenuLaporanOwner(int x, int y, int lebar,int tinggi, int *output) {
    //Declaration
    int count = 1;
    char ch;


    //Algorithm
//    BorderSwitchRole(x, y, lebar);
    // menuLaporanKeuanganOwner();
    if(count == 1){
        SetColorBlock(0,12);
        gotoprinttext(77,25,"L A P O R A N  T I K E T");
    }

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
//                clearArea(x, y, lebar + 2, tinggi);
                y -= 3;  // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,12);
//                BorderSwitchRole(x, y, lebar);
                // menuLaporanKeuanganManajer();
                count--;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(77,25,"L A P O R A N  T I K E T");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(75,28,"L A P O R A N  M A K A N A N");
            }  else if(count == 3){
                SetColorBlock(0,12);
                gotoprinttext(71,31,"L A P O R A N  M E R C H A N D I S E");
            } else if(count==4){
                SetColorBlock(0,12);
                gotoprinttext(80,34,"    K E M B A L I");
            }
        } else if (ch == DWN_KEY) {
            if (count < 4) {
                Beep(1000, 100);
//                clearArea(x, y, lebar + 2, tinggi);
                y += 3;  // Geser ke bawah sebanyak 4 unit
//                BorderSwitchRole(x, y, lebar);
                SetColorBlock(15,12);
                // menuLaporanKeuanganManajer();
                count++;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(77,25,"L A P O R A N  T I K E T");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(75,28,"L A P O R A N  M A K A N A N");
            }  else if(count == 3){
                SetColorBlock(0,12);
                gotoprinttext(71,31,"L A P O R A N  M E R C H A N D I S E");
            } else if(count==4){
                SetColorBlock(0,12);
                gotoprinttext(80,34,"    K E M B A L I");
            }
        }
    }
}

void SpecialkeyloginMenuFilmOwner(int x, int y, int lebar,int tinggi, int *output) {
    //Declaration
    int count = 1;
    char ch;


    //Algorithm
//    BorderSwitchRole(x, y, lebar);
    // menuLaporanFilmManajer();
    if(count == 1){
        SetColorBlock(0,12);
        gotoprinttext(75,25,"P E N J U A L A N  T I K E T");
    }
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
            }
            break;
        } else if (ch == UP_KEY) {
            if (count > 1) {
                Beep(1000, 100);
//                clearArea(x, y, lebar + 2, tinggi);
                y -= 3;  // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,12);
//                BorderSwitchRole(x, y, lebar);
                // menuLaporanFilmManajer();
                count--;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(75,25,"P E N J U A L A N  T I K E T");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(75,28,"F I L M  T E R F A V O R I T");
            } else if(count==3){
                SetColorBlock(0,12);
                gotoprinttext(80,31,"  K E M B A L I");
            }
        } else if (ch == DWN_KEY) {
            if (count < 3) {
                Beep(1000, 100);
//                clearArea(x, y, lebar + 2, tinggi);
                y += 3;  // Geser ke bawah sebanyak 4 unit
//                BorderSwitchRole(x, y, lebar);
                SetColorBlock(15,12);
                // menuLaporanFilmManajer();
                count++;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(75,25,"P E N J U A L A N  T I K E T");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(75,28,"F I L M  T E R F A V O R I T");
            } else if(count==3){
                SetColorBlock(0,12);
                gotoprinttext(80,31,"  K E M B A L I");
            }
        }
    }
}


void SpecialkeyDashboardMenuDataOwner(int x, int y, int lebar,int tinggi, int *output) {
    //Declaration
    int count = 1;
    char ch;


    //Algorithm
    //BorderSwitchRole(x, y, lebar);
    menuDataPenjualan();
    if(count == 1){
        SetColorBlock(0,12);
        gotoprinttext(80,28,"D A T A  O B A T");
    }
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

            }
            break;
        } else if (ch == UP_KEY) {
            if (count > 1) {
                Beep(1000, 50);
//                clearArea(x, y, lebar + 2, tinggi);
                y -= 3;  // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,12);
//                BorderSwitchRole(x, y, lebar);
                menuDataPenjualan();
                count--;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(80,28,"D A T A  O B A T");
            } else if(count==2){
                SetColorBlock(0,12);
                gotoprinttext(80,31,"D A T A  A L A T");
            } else if(count ==3){
                SetColorBlock(0,12);
                gotoprinttext(80,34,"  K E M B A L I  ");
            }
        } else if (ch == DWN_KEY) {
            if (count < 3) {
                Beep(1000, 50);
//                clearArea(x, y, lebar + 2, tinggi);
                y += 3;  // Geser ke bawah sebanyak 4 unit
//                BorderSwitchRole(x, y, lebar);
                SetColorBlock(15,12);
                menuDataPenjualan();
                count++;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(80,28,"D A T A  O B A T");
            } else if(count==2){
                SetColorBlock(0,12);
                gotoprinttext(80,31,"D A T A  A L A T");
            } else if(count ==3){
                SetColorBlock(0,12);
                gotoprinttext(80,34,"  K E M B A L I ");
            }
        }
    }
}
void SpecialkeyDashboardMenuUpdateDataOwner(int *output){
    //Declaration
    int count = 1;
    char ch;


    //Algorithm
//    BorderSwitchRole(x, y, lebar);
    menuUpdateDataOwner();
    if(count == 1){
        SetColorBlock(0,12);
        gotoprinttext(137,19,"U B A H  N O  T E L E P O N");
    }
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
//                clearArea(x, y, lebar + 2, tinggi);
                 // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,12);
//                BorderSwitchRole(x, y, lebar);
                menuUpdateDataOwner();
                count--;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(137,19,"U B A H  N O  T E L E P O N");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(138,21,"U B A H  U S E R N A M E");
            } else if(count ==3){
                SetColorBlock(0,12);
                gotoprinttext(138,23,"U B A H  P A S S W O R D");
            } else if(count == 4){
                SetColorBlock(0,12);
                gotoprinttext(138,25,"     K E M B A L I ");
            }
        } else if (ch == DWN_KEY) {
            if (count < 4) {
                Beep(1000, 100);
//                clearArea(x, y, lebar + 2, tinggi);
                // Geser ke bawah sebanyak 4 unit
//                BorderSwitchRole(x, y, lebar);
                SetColorBlock(15,12);
                menuUpdateDataOwner();
                count++;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(137,19,"U B A H  N O  T E L E P O N");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(138,21,"U B A H  U S E R N A M E");
            } else if(count ==3){
                SetColorBlock(0,12);
                gotoprinttext(138,23,"U B A H  P A S S W O R D");
            } else if(count == 4){
                SetColorBlock(0,12);
                gotoprinttext(138,25,"     K E M B A L I ");
            }
        }
    }
}

void SpecialkeyDashboardMenuUpdateDataAlat(int *output){
    //Declaration
    int count = 1;
    char ch;


    //Algorithm
//    BorderSwitchRole(x, y, lebar);
    menuUpdateDataAlat();
    if(count == 1){
        SetColorBlock(0,12);
        gotoprinttext(138,19,"U B A H  N A M A  A L A T");
    }
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
//                clearArea(x, y, lebar + 2, tinggi);
                 // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,12);
//                BorderSwitchRole(x, y, lebar);
                menuUpdateDataAlat();
                count--;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(138,19,"U B A H  N A M A  A L A T");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(142,21,"U B A H  H A R G A");
            } else if(count ==3){
                SetColorBlock(0,12);
                gotoprinttext(140,23,"U B A H  J U M L A H");
            } else if(count == 4){
                SetColorBlock(0,12);
                gotoprinttext(140,25,"     K E M B A L I ");
            }
        } else if (ch == DWN_KEY) {
            if (count < 4) {
                Beep(1000, 100);
//                clearArea(x, y, lebar + 2, tinggi);
                // Geser ke bawah sebanyak 4 unit
//                BorderSwitchRole(x, y, lebar);
                SetColorBlock(15,12);
                menuUpdateDataAlat();
                count++;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(138,19,"U B A H  N A M A  A L A T");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(142,21,"U B A H  H A R G A");
            } else if(count ==3){
                SetColorBlock(0,12);
                gotoprinttext(140,23,"U B A H  J U M L A H");
            } else if(count == 4){
                SetColorBlock(0,12);
                gotoprinttext(140,25,"     K E M B A L I ");
            }
        }
    }
}

void SpecialKeyUpdate(int x, int y, int lebar,int tinggi,int *output) {
    int count = 1;
    char ch;
    //Algorithm
    SetColorBlock(15, 12);
    BorderSwitchRole(x, y, lebar);
    menuBackApprove();
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
                menuBackApprove();
                count--;
            }
        } else if (ch == LEFT_KEY) {
            if (count < 2) {
                Beep(1000, 100);
                clearArea(x, y, lebar+2, tinggi);
                x -= 20;
                BorderSwitchRole(x,y,lebar);
                menuBackApprove();
                count++;
            }
        }
    }

}

void SpecialkeyLaporanOwner(int x, int y, int lebar,int tinggi, int *output) {
    //Declaration
    int count = 1;
    char ch;

    //Algorithm
//    BorderSwitchRole(x, y, lebar);

    if(count == 1){
        SetColorBlock(0,12);
        gotoprinttext(82,25,"B U L A N A N");
    }
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
            }
            break;
        } else if (ch == UP_KEY) {
            if (count > 1) {
                Beep(700, 120);
//                clearArea(x, y, lebar + 2, tinggi);
                y -= 3;  // Geser ke atas sebanyak 4 unit
                SetColorBlock(15,12);
//               BorderSwitchRole(x, y, lebar);

                count--;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(82,25,"B U L A N A N");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(82,28,"T A H U N A N");
            } else if(count==3){
                SetColorBlock(0,12);
                gotoprinttext(82,31,"K E M B A L I");
            }
        } else if (ch == DWN_KEY) {
            if (count < 3) {
                Beep(700, 120);
//                clearArea(x, y, lebar + 2, tinggi);
                y += 3;  // Geser ke bawah sebanyak 4 unit
//                BorderSwitchRole(x, y, lebar);
                SetColorBlock(15,12);

                count++;
            }
            if(count == 1){
                SetColorBlock(0,12);
                gotoprinttext(82,25,"B U L A N A N");
            } else if(count == 2){
                SetColorBlock(0,12);
                gotoprinttext(82,28,"T A H U N A N");
            } else if(count==3){
                SetColorBlock(0,12);
                gotoprinttext(82,31,"K E M B A L I");
            }
        }
    }
}


void SpecialKeyCariDataLaporan(int x, int y, int lebar,int tinggi,int *output) {
    int count = 1;
    char ch;
    //Algorithm
    SetColorBlock(15, 12);
    BorderSwitchRole(x, y, lebar);
    menuBackLihat(y+1);
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
                Beep(1000, 50);
                clearArea(x, y, lebar+2,tinggi);
                x += 17;
                BorderSwitchRole(x, y, lebar);
                menuBackLihat(y+1);
                count--;
            }
        } else if (ch == LEFT_KEY) {
            if (count < 2) {
                Beep(1000, 50);
                clearArea(x, y, lebar+2, tinggi);
                x -= 17;
                BorderSwitchRole(x,y,lebar);
                menuBackLihat(y+1);
                count++;
            }
        }
    }
}
