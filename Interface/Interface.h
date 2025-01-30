#define NMAX 300
void BlankDashboard();
void menuCreateDataModifikasiOwner();
void menuDeleteDataModifikasiOwner();
void menuCreateDataModifikasiKasir();
void menuDeleteDataModifikasiKasir();
void dataMakananMenuKasir();
void dataMembershipMenuKasir();
void dataMerchandiseMenuKasir();
void menuCRUDObat();
void menuCRUDAlat();
void menuCRUDSupplier();
void cancelCharSupplier(char batal[255]);

// Deklarasi prosedur untuk menyembunyikan kursor
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// Deklarasi prosedur untuk menampilkan kursor
void showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
/*--------------------------------------untuk mengatur posisi--------------------------------*/
void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*--------------------------------------Fullscreen Layar---------------------------------------*/
void fullscreen(){
    keybd_event(VK_MENU,0x39,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x39,KEYEVENTF_KEYUP,0);

    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

/*--------------------------------------Gotoprint Character------------------------------------*/
void gotoprintchar(int x, int y, int dec){
    gotoxy(x,y);
    printf("%c",dec);
}

/*--------------------------------------Gotoprint Text------------------------------------*/
void gotoprinttext(int x, int y, char text[255]){
    gotoxy(x,y);
    printf("%s",text);
}

/*---------------------------------------Untuk mewarnai huruf dan background---------------------*/
void SetColorBlock(int foreground, int background) {
    int color = foreground + (background << 4);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

/*----------------------------------------Menghapus semua block-----------------------------------*/
void clearArea(int x, int y, int width, int height) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = {(SHORT) x, (SHORT) y};
    DWORD written;

    for (int row = 0; row < height; ++row) {
        FillConsoleOutputCharacterA(console, ' ', width, topLeft, &written);
        topLeft.Y++;
    }
}

/*-------------------------------------Mematikan scrollbar CMD----------------------------------------*/
void disableScrollBar() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // Mendapatkan informasi tentang jendela console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);

    // Menyusun atribut baru untuk mengunci scrollbar
    csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;

    // Menyetel ukuran jendela console
    SetConsoleScreenBufferSize(hOut, csbi.dwSize);

    // Menonaktifkan scrollbar
    SetConsoleMode(hOut, ENABLE_EXTENDED_FLAGS);
}

/*--------------------------------------untuk mencetak file txt----------------------------------------*/
void DrawFile(int x, int y, char filename[255]) {
    FILE *fp;
    char str[MAXCHAR];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s", filename);
    }
    i = 0;
    while (fgets(str, MAXCHAR, fp) != NULL) {
        gotoxy(x, y + i);
        printf("%s", str);
        i++;
    }
    fclose(fp);
}

/*------------------------------------------Desain header Interface-------------------------------------*/
void header(int x, int y){
    SetColorBlock(15,15);
    for(i = y; i < 11; i++){
        for(j = x; j < 170; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(15,12);
    for(i = y; i <= y; i++){
        for(j = x; j < 170; j++){
            gotoprintchar(j,i,32);
        }
    }

    for(i = y + 9; i <= 11; i++){
        for(j = x; j < 170; j++){
            gotoprintchar(j,i,32);
        }
    }
    for(i = 2; i <= 11; i++){
            gotoprintchar(x - 1,i,32);
    }
    for(i = 2; i <= 11; i++){
        gotoprintchar(x + 165,i,32);
    }

}

/*------------------------------------------Desain Blank Screen-----------------------------------------*/
void blankScreen(){
    SetColorBlock(15,15);
    for(i = 2; i < 43; i++){
        for(j = 3; j < 171; j++){
            gotoprintchar(j,i,32);
        }
    }
}

/*---------------------------------------------Desain Logo Taliwang--------------------------------------*/
void logo1(int x, int y){

    FILE *Tampung;
    char isi[NMAX];
    int arah = y;
    Tampung = fopen("../Desaintxt/Logo/SPLASH-APOTEK.txt", "r");//<-----------Design Logo TI
    while (fgets(isi, sizeof(isi), Tampung)) {
        gotoxy(x, arah);
        printf("%s", isi);
        arah++;
    }

    fclose(Tampung);
}

/*------------------------------------------------Frame untuk menempatkan button menu---------------------------------*/
void frame(int x, int y){
    SetColorBlock(4,15);
    for(i = y; i < 22 + y; i++){
        for(j = x; j < 160; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(15,4);
    /*border frame atas bawah*/
    for(i = y; i < 15; i++){
        for(j = x - 2; j < 122; j++){
            gotoprintchar(j,i,177);
        }
    }

    for(i = 35; i < 36; i++){
        for(j = x - 2; j < 122; j++){
            gotoprintchar(j,i,177);
        }
    }

    SetColorBlock(4,15);
    /*border frame tengah kanan kiri*/
    for(i = y + 1; i < y + 21; i++){
            gotoprintchar(x - 1,i,186);
    }

    for(i = y + 1; i < y + 21; i++){
            gotoprintchar(x+60,i,186);
    }
}

/*-------------------------------MENGUBAH JENIS FONT------------------------------------*/
void setConsoleFont(int fontSizeX, int fontSizeY, const wchar_t* fontName) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

    // Mendapatkan informasi font saat ini
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Mengganti ukuran font
    fontInfo.dwFontSize.X = fontSizeX;
    fontInfo.dwFontSize.Y = fontSizeY;

    // Mengganti nama font
    wcscpy(fontInfo.FaceName, fontName);

    // Mengganti bentuk font
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

void sumbawa(int x,int y){
    FILE *Tampung;
    char isi[NMAX];
    int arah = y;
    Tampung = fopen("../Desaintxt/Logo/LOGO - SOBAT.txt", "r");//<-----------Design Logo TI
    while (fgets(isi, sizeof(isi), Tampung)) {
        gotoxy(x, arah);
        printf("%s", isi);
        arah++;
    }

    fclose(Tampung);
}

void ticket(int x, int y){
    FILE *Tampung;
    char isi[NMAX];
    int arah = y;
    Tampung = fopen("../Desaintxt/Logo/PLUS.txt", "r");//<-----------Design Logo TI
    while (fgets(isi, sizeof(isi), Tampung)) {
        gotoxy(x, arah);
        printf("%s", isi);
        arah++;
    }

    fclose(Tampung);
}
void logo2(int x, int y){

    FILE *Tampung;
    char isi[NMAX];
    int arah = y;
    Tampung = fopen("../Desaintxt/Logo/SPLASH-SAHABAT_MEDIKA.txt", "r");//<-----------Design Logo TI
        while (fgets(isi, sizeof(isi), Tampung)) {
            gotoxy(x, arah);
            printf("%s", isi);
            arah++;
        }

    fclose(Tampung);
}

void logologin(int x, int y){

    FILE *Tampung;
    char isi[NMAX];
    int arah = y;
    Tampung = fopen("../Desaintxt/Logo/LOGO - LOGIN.txt", "r");//<-----------Design Logo TI
    while (fgets(isi, sizeof(isi), Tampung)) {
        gotoxy(x, arah);
        printf("%s", isi);
        arah++;
    }

    fclose(Tampung);
}

void camera(int x,int y){

    FILE *Tampung;
    char isi[NMAX];
    int arah = y;
    Tampung = fopen("../Desaintxt/Logo/PHARMACYLOGO-M.txt", "r");//<-----------Design Logo TI
    SetColorBlock(0, 7);
    while (fgets(isi, sizeof(isi), Tampung)) {
        gotoxy(x, arah);
        printf("%s", isi);
        arah++;
    }

    fclose(Tampung);
}


/*---------------------------------------Untuk menu border atas bawah kanan kiri ALL-----------------------------------*/
void BorderScreen(){
    int i;
    /*pojok kanan atas*/
    SetColorBlock(4,15);
    gotoprintchar(2,1,206);

    /*atas tengah*/
    for(i = 3; i < 172; i++){
    gotoprintchar(i,1,205);
    }

    /*pojok kiri atas*/
    gotoprintchar(172,1,206);

    /*border samping kiri*/
    for(i = 2; i < 43; i++){
        gotoprintchar(2,i,186);
    }

    for(i = 2; i < 43; i++){
        gotoprintchar(172,i,186);
    }

    /*pojok kiri bawah*/
    gotoprintchar(2,43,206);
    /*atas tengah*/
    for(i = 3; i < 172; i++){
        gotoprintchar(i,43,205);
    }
    /*pojok kiri bawah*/
    gotoprintchar(172,43,206);

}

void playCustomSound(char *audioFile) {
    PlaySound(audioFile, NULL, SND_FILENAME | SND_ASYNC);
}


/*--------------------------------------------loading Animation %------------------------------------------------*/
void loadingAnimation(int duration) {
    /*border atas kiri */
    gotoprintchar(74,34,201);
    /*border atas tengah*/
    for(i = 0; i < 22;i++){
        gotoprintchar(75+i,34,205);
    }
    /*border atas kanan*/
    gotoprintchar(96,34,187);

    /*border kanan kiri pinggir*/
    gotoprintchar(74,35,186);
    gotoprintchar(96,35,186);

    /*boder kiri bawah*/
    gotoprintchar(74,36,200);
    /*border tengah bawah*/
    for(i = 0; i < 22;i++){
        gotoprintchar(75+i,36,205);
    }
    /*border kanan bawah*/
    gotoprintchar(96,36,188);

    /*loading animation*/
    int persen = 0;
    x = 84;
    gotoxy(76,35);
    printf("Memuat ");
    for (i = 0; i < 1; i++) {
        for(j = 0; j < 6; j++){
            gotoprintchar(x,35,219);
            x++;
            gotoxy(91,35);printf("%d%%",persen);
            persen += 20;
            fflush(stdout);
            usleep(duration * 100000);
        }// Waktu jeda dalam mikrodetik
    }
    clearArea(76,35,20,1);
    gotoxy(80,35);
    printf(" Selesai!\n");
}



void textBox2(int x, int y, int width, int height) {
    int i, j;

    /* first Line */
    gotoxy(x, y);
    printf("%c", 201);
    for(i = 1; i <= width; i++) {
        printf("%c", 205);
    }
    printf("%c", 187);

    /* looping for height */
    for(i = 1; i <= height; i++) {
        gotoxy(x, y + i);
        printf("%c", 186);
        for(j = 1; j <= width; j++) {
            printf(" ");
        }
        gotoxy(x + width + 1, y + i);
        printf("%c", 186);
    }

    /* last line */
    printf("\n");
    gotoxy(x, y + height);
    printf("%c", 200);
    for(i = 1; i <= width; i++) {
        printf("%c", 205);
    }
    printf("%c", 188);
}

void loading(int x, int y) {
    int i;

    gotoxy(x + 12, y-1);
    textBox2(x, y, 50, 2);
    SetColorBlock(4,15);
    gotoprinttext(72,34,"Menunggu Keluar");
    for(i = 1; i <= 50; i++) {
        SetColorBlock(4,4);
        gotoxy(x + i, y + 1);
        printf("%c", 32);
        Sleep(20);
        if(i >= 17) {
            SetColorBlock(15, 4);
            gotoprinttext(72, 34, "Menunggu Keluar");
        }
    }
}

void loadingMasuk(int x, int y) {
    int i;

    gotoxy(x + 12, y-1);
    textBox2(x, y, 50, 2);
    SetColorBlock(4,15);
    gotoprinttext(72,34,"Menunggu ke Dashboard");
    for(i = 1; i <= 50; i++) {
        SetColorBlock(4,4);
        gotoxy(x + i, y + 1);
        printf("%c", 32);
        Sleep(20);
        if(i >= 14) {
            SetColorBlock(15, 4);
            gotoprinttext(72, 34, "Menunggu ke Dashboard");
        }
    }
}
void BorderSwitchRole(int x, int y, int lebar){
    /*untuk kiri atas*/
    gotoxy(x,y);printf("%c", 201);
    int a;
    a = x + 1;
    for(i = 0; i < lebar; i++){
    gotoxy(a,y);printf("%c",205); /*untuk asci tepi atas =*/
    a++;
    }
    /*untuk kanan atas*/
    gotoxy(a,y);printf("%c", 187);

    gotoxy(x,y+1);printf("%c",186);/*untuk ascii tepi sama dengan miring kiri tengah*/

    gotoxy(a,y+1);printf("%c",186);/*untuk ascii tepi sama dengan miring kanan tengah */

    gotoxy(x,y+2);printf("%c",200);/*untuk sudut kiri bawah*/
    a = x + 1;
    for(i = 0; i < lebar; i++){
    gotoxy(a,y+2);printf("%c",205);/*untuk tepi bawah =*/
    a++;
    }
    gotoxy(a,y+2);printf("%c",188);/*untuk sudut kanan bawah*/
}

void BorderSwitchRoleDashboard(int x, int y, int lebar,int tinggi){
    gotoxy(x,y);printf("%c", 201);
    int a;
    a = x + 1;
    for(i = 0; i < lebar; i++){
        gotoxy(a,y);printf("%c",205); /*untuk asci tepi atas =*/
        a++;
    }
    /*untuk kanan atas*/
    gotoxy(a,y);printf("%c", 187);
    int b = y + 1;
    for(i = 0; i < 2; i++) {
        gotoxy(x, b);
        printf("%c", 186);/*untuk ascii tepi sama dengan miring kiri tengah*/
        b++;
    }
    b = y + 1;
    for(i = 0; i < 2; i++) {
        gotoxy(a, b);
        printf("%c", 186);/*untuk ascii tepi sama dengan miring kiri tengah*/
        b++;
    }
    gotoxy(x,b);printf("%c",200);/*untuk sudut kiri bawah*/
    a = x + 1;
    for(i = 0; i < lebar; i++){
        gotoxy(a,b);printf("%c",205);/*untuk tepi bawah =*/
        a++;
    }
    gotoxy(a,b);printf("%c",188);/*untuk sudut kanan bawah*/
}

void gotoscanf(int x, int y,char text[255]){
    fflush(stdin);
    gotoxy(x,y);
    scanf("%[^\n]", text);

    getchar();
}

void menuMasuk(){
    SetColorBlock(12,12);
    for(i = 100; i < 160; i++){
        gotoprintchar(i,17,178);
    }
    SetColorBlock(12,12);
    for(i = 16; i < 19; i++){
        for(j = 113; j < 145; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(15,12);
    gotoprinttext(115,17,"L O G I N   S E B A G A I  ?");
    SetColorBlock(4,15);
    gotoprinttext(123,20,"M A N A J E R");
    gotoprinttext(125,24,"A D M I N");
    gotoprinttext(125,28,"K A S I R");
    gotoprinttext(124,32,"K E L U A R");
}

void menuBackSign(){
    SetColorBlock(4,15);
    gotoprinttext(93,31,"  M A S U K  \n");
    gotoprinttext(73,31," K E L U A R");
}

void menuCategori(){
    SetColorBlock(4,15);
    gotoprinttext(69,21,"Makanan\n");
    gotoprinttext(80,21,"Minuman");
}

void menuCategoriUpdate(){
    SetColorBlock(15,12);
    gotoprinttext(138,26,"Makanan\n");
    gotoprinttext(155,26,"Minuman");
}

void menuBackApprove(){
    gotoprinttext(153,27,"    O K E    \n");
    gotoprinttext(133,27,"K E M B A L I");
}

void menuBackLihat(int y){
    gotoprinttext(153,y," L I H A T   \n");
    gotoprinttext(134,y," K E M B A L I");
}

void menuYesorNo(int x, int y,int jarak){
    gotoprinttext(x,y,"    Y A\n");
    gotoprinttext(x-jarak,y,"T I D A K");
}

void menuLihatorBack(int x, int y,int jarak){
    gotoprinttext(x,y,"LIHAT DETAIL\n");
    gotoprinttext(x-jarak,y,"KEMBALI");
}

void inputPass(char password[]) {
    fflush(stdin);
    i = 0;
    char ch;
    while (1) {
        ch = _getch();  // Mengambil karakter tanpa menampilkannya
        if (ch == 8) {
            if (i > 0) {
                // Hapus karakter sebelumnya dan mundur satu langkah
                printf("\b \b");
                i--;
            }
        } else if (ch == 13) {
            // 13 adalah nilai ASCII untuk Enter
            break;
        } else {
            // Menambahkan karakter ke dalam password dan menampilkan tanda bintang
            password[i] = ch;
            printf("*");
            i++;
        }
    }
    password[i] = '\0';  // Menambahkan null-terminating character ke akhir string
}
void inputUser(char username[]) {
    fflush(stdin);
    i = 0;
    char ch;
    while (1) {
        ch = _getch();  // Mengambil karakter tanpa menampilkannya
        if (ch == 8) {
            if (i > 0) {
                // Hapus karakter sebelumnya dan mundur satu langkah
                printf("\b \b");
                i--;
            }
        } else if (ch == 13) {
            // 13 adalah nilai ASCII untuk Enter
            break;
        } else {
            // Menambahkan karakter ke dalam password dan menampilkan tanda bintang
            username[i] = ch;

            i++;
        }
    }
    username[i] = '\0';  // Menambahkan null-terminating character ke akhir string
}

void BorderSwitchCategori(int x, int y, int lebar){
    gotoprintchar(x,y,201);
    for(i = x+1; i <= x+lebar;i++){
        gotoprintchar(i,y,205);
    }
    gotoprintchar(x,y+2,200);
    gotoprintchar(x,y+1,186);
    gotoprintchar(x+8,y+1,186);
    gotoprintchar(x+8,y,187);
    for(i = x+1; i <=x+lebar;i++){
        gotoprintchar(i,y+2,205);
    }
    gotoprintchar(x+8,y+2,188);
}


void bulan(){
    gotoprinttext(48,23,"Januari");
    gotoprinttext(48,24,"Februari");
    gotoprinttext(48,25,"Maret");
    gotoprinttext(48,26,"April");
    gotoprinttext(48,27,"Mei");
    gotoprinttext(48,28,"Juni");
    gotoprinttext(48,29,"Juli");
    gotoprinttext(48,30,"Agustus");
    gotoprinttext(48,31,"September");
    gotoprinttext(48,32,"Oktober");
    gotoprinttext(48,33,"November");
    gotoprinttext(48,34,"Desember");

}

void borderInput(int x, int y, int lebar){
    /*sudut kiri atas*/
    gotoprintchar(x,y,201);

    /*tepi atas*/
    int a = x +1;
    for(i = 0; i < lebar;i++){
        gotoprintchar(a,y,205);
        a++;
    }
    /*sudut kanan atas*/
    gotoprintchar(a,y,187);

    /*untuk tepi kiri tengah*/
    gotoprintchar(x,y+1,186);
    /*untuk tepi kanan tengah*/
    gotoprintchar(a,y+1,186);

    /*sudut kiri bawah*/
    gotoprintchar(x,y+2,200);

    /*tepi bawah*/
    a = x +1;
    for(i = 0; i < lebar;i++){
        gotoprintchar(a,y+2,205);
        a++;
    }

    /*sudut kanan bawah*/
    gotoprintchar(a,y + 2,188);

}

void borderType(int x, int y, int lebar){
    gotoprintchar(x,y,218);
    for(i = x+1; i <= x+lebar; i++){
        gotoprintchar(i,y,196);
    }
    gotoprintchar(x+lebar+1,y,191);
    gotoprintchar(x,y+1,179);
    gotoprintchar(x+lebar+1,y+1,179);
    gotoprintchar(x,y+2,192);
    for(i = x+1; i <= x+lebar; i++){
        gotoprintchar(i,y+2,196);
    }
    gotoprintchar(x+lebar+1,y+2,217);
}



void frameLayout(int x, int y,int lebar, int tinggi, int dec){
    for(i = y; i < tinggi; i++){
        for(j = x; j < lebar; j++){
            gotoprintchar(j,i,dec);
        }
    }
}

void cancelCharOwner(char batal[255]){
    if(strcasecmp(batal,"0")==0){
        BlankDashboard();
        menuCreateDataModifikasiOwner();
    }
}


void blankTable(){
    int u;
    SetColorBlock(15,15);
    for(u = 13; u <38; u++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,u,32);
        }
    }
}

void moreTable(int a){
    SetColorBlock(4,15);
    gotoxy(80,40);printf("Klik apa saja untuk melihat data selanjutnya...");
    getch();
    blankTable();
    y = a;
}


void BlankDesain(){
    SetColorBlock(15,15);
    for(i = 16; i < 34; i++){
        for(j = 130; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
}

void BlankTeks(){
    SetColorBlock(12,12);
    for(i = 19; i <= 19; i++){
        for(j = 40; j < 75; j++){
            gotoprintchar(j,i,32);
        }
    }
}

// void cancelCharMakanan(char batal[255]){
//     if(strcasecmp(batal,"0")==0){
//         fclose(arspmakanan);
//         BlankDashboard();
//         dataMakananMenuAdmin();
//     }
// }
//
// void cancelCharDeleteStaff(char batal[255]){
//     if(strcasecmp(batal,"0")==0){
//         BlankDashboard();
//         menuDeleteDataModifikasiOwner();
//     }
// }

//
// void cancelCharDeleteMember(char batal[255]){
//     if(strcasecmp(batal,"0")==0){
//         BlankDashboard();
//         dataMembershipMenuAdmin();
//     }
// }
//
// void cancelIntDeleteMakanan(int batal){
//     if(batal == 0){
//         BlankDashboard();
//         dataMakananMenuAdmin();
//     }
// }
//
//
// void cancelIntDeleteStudio(int batal){
//     if(batal == 0){
//         BlankDashboard();
//         menuDataStudioAdmin();
//     }
// }
//
// void cancelIntDeleteProduser(int batal){
//     if(batal == 0){
//         BlankDashboard();
//         menuCRUDProduser();
//     }
// }
// void cancelIntDeleteMerchandise(int batal){
//     if(batal == 0){
//         BlankDashboard();
//         dataMerchandiseMenuAdmin();
//     }
// }
//
// void cancelIntDeleteMember(int batal){
//     if(batal == 0){
//         BlankDashboard();
//         dataMembershipMenuAdmin();
//     }
// }
//
// void cancelIntDetailJam(int batal){
//     if(batal == 0){
//         BlankDashboard();
//         menuDetailJamTayang();
//     }
// }
//
// void cancelCharDeleteAdmin(char batal[255]){
//     if(strcasecmp(batal,"0")==0){
//         BlankDashboard();
//         menuDeleteDataModifikasiAdmin();
//     }
// }

void  desainAtas(){
    DrawFile(4,2,"../Desaintxt/Logo/PLUS.txt");
    DrawFile(57,2,"../Desaintxt/up tengah.txt");
    DrawFile(150,2,"../Desaintxt/Logo/PLUS.txt");
}

void desainBawah(){
    DrawFile(4,32,"../Desaintxt/Logo/PLUS.txt");
    DrawFile(150,32,"../Desaintxt/Logo/PLUS.txt");
}

void Dashboard(){
    SetColorBlock(4,12);
    frameLayout(4,2,5,43,176);
    frameLayout(4,42,170,43,176);
    frameLayout(33,2,34,43,176);
    frameLayout(170,2,171,43,176);
    SetColorBlock(4,4);
    frameLayout(4,2,171,8,32);
    SetColorBlock(12,4);
    frameLayout(4,2,171,3,223);
    frameLayout(4,2,5,8,223);
    frameLayout(4,8,171,9,220);
    frameLayout(33,2,34,8,223);
    frameLayout(170,2,171,8,223);
    SetColorBlock(15,4);
    frameLayout(5,9,33,42,32);
}

void DashboardCRUD(){
    SetColorBlock(12,12);
    frameLayout(130,9,170,42,32);
    SetColorBlock(4,15);
    frameLayout(130,9,131,42,223);
    frameLayout(130,9,170,10,223);
    frameLayout(169,9,170,42,223);
    frameLayout(130,41,170,42,220);
}

void DashboardDetail(int x1,int x2,int y1, int y2,int l1, int l2, int t1, int t2){
    SetColorBlock(12,12);
    frameLayout(x1,y1,l1,t1,32);
    SetColorBlock(4,15);
    frameLayout(x1,y1,l2,t1,223);
    frameLayout(x1,y1,l1,t2,223);
    frameLayout(x2,y1,l1,t1,223);
    frameLayout(x1,y2,l1,t1,220);
}

void clearKanan(){
    SetColorBlock(12,12);
    frameLayout(131,10,169,41,32);
}

void clearTengah(){
    SetColorBlock(15,15);
    frameLayout(35,9,129,40,32);
}
void BlankDashboard(){
    SetColorBlock(15,15);
    for(i = 9; i < 42; i++){
        for(j = 34; j < 170; j++){
            gotoprintchar(j,i,32);
        }
    }
}

void clearTransaksi(){
    SetColorBlock(12,12);
    for(i = 23; i < 38; i++){
        for(j = 69; j < 110; j++){
            gotoprintchar(j,i,32);
        }
    }
}

void frameDetail(int x, int y, char filename[255]){
    SetColorBlock(12,12);
    for(i = 11; i < 40; i++){
        for(j = 37; j < 90; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(15,15);
    gotoprintchar(37,11,219);
    gotoprintchar(38,11,219);
    gotoprintchar(37,12,219);

    gotoprintchar(37,39,219);
    gotoprintchar(38,39,219);
    gotoprintchar(37,38,219);

    gotoprintchar(88,11,219);
    gotoprintchar(89,11,219);
    gotoprintchar(89,12,219);

    gotoprintchar(88,39,219);
    gotoprintchar(89,39,219);
    gotoprintchar(89,38,219);

    SetColorBlock(15,12);
    gotoprintchar(40,11,201);
    for(i=41; i <= 85;i++){
        gotoprintchar(i,11,205);
    }
    gotoprintchar(86,11,187);

    gotoprintchar(40,12,188);
    gotoprintchar(39,12,201);
    gotoprintchar(39,13,188);
    gotoprintchar(38,13,201);

    for(i = 14; i <=36; i++){
        gotoprintchar(38,i,186);
    }

    gotoprintchar(38,37,200);
    gotoprintchar(39,37,187);
    gotoprintchar(39,38,200);
    gotoprintchar(40,38,187);

    gotoprintchar(40,39,200);
    for(i=41; i <= 85;i++){
        gotoprintchar(i,39,205);
    }
    gotoprintchar(86,39,188);
    gotoprintchar(86,38,201);
    gotoprintchar(87,38,188);
    gotoprintchar(87,37,201);
    gotoprintchar(88,37,188);

    gotoprintchar(86,11,187);
    gotoprintchar(86,12,200);
    gotoprintchar(87,12,187);
    gotoprintchar(87,13,200);
    gotoprintchar(88,13,187);

    for(i = 14; i <=36; i++){
        gotoprintchar(88,i,186);
    }
    SetColorBlock(15,12);
    DrawFile(x,y,filename);
}


void frameTransaksi(int x, int y){
    SetColorBlock(12,12);
    for(i = 11; i < 40; i++){
        for(j = 37; j < 116; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(15,15);
    gotoprintchar(37,11,219);
    gotoprintchar(38,11,219);
    gotoprintchar(37,12,219);

    gotoprintchar(37,39,219);
    gotoprintchar(38,39,219);
    gotoprintchar(37,38,219);

    gotoprintchar(114,11,219);
    gotoprintchar(115,11,219);
    gotoprintchar(115,12,219);

    gotoprintchar(114,39,219);
    gotoprintchar(115,39,219);
    gotoprintchar(115,38,219);

    SetColorBlock(15,12);
    gotoprintchar(40,11,201);
    for(i=41; i <= 111;i++){
        gotoprintchar(i,11,205);
    }
    gotoprintchar(112,11,187);

    gotoprintchar(40,12,188);
    gotoprintchar(39,12,201);
    gotoprintchar(39,13,188);
    gotoprintchar(38,13,201);

    for(i = 14; i <=36; i++){
        gotoprintchar(38,i,186);
    }

    gotoprintchar(38,37,200);
    gotoprintchar(39,37,187);
    gotoprintchar(39,38,200);
    gotoprintchar(40,38,187);

    gotoprintchar(40,39,200);
    for(i=41; i <= 111;i++){
        gotoprintchar(i,39,205);
    }
    gotoprintchar(112,39,188);
    gotoprintchar(112,38,201);
    gotoprintchar(113,38,188);
    gotoprintchar(113,37,201);
    gotoprintchar(114,37,188);

    gotoprintchar(112,11,187);
    gotoprintchar(112,12,200);
    gotoprintchar(113,12,187);
    gotoprintchar(113,13,200);
    gotoprintchar(114,13,187);

    for(i = 14; i <=36; i++){
        gotoprintchar(114,i,186);
    }
    SetColorBlock(15,12);
}
void clearTableTransaksi(){
    SetColorBlock(15,15);
    for(i = 11; i <= 39; i++){
        for(j = 118; j < 169; j++){
            gotoprintchar(j,i,32);
        }
    }
}
void kertas(int x,int y, char namaFile[255]){
    SetColorBlock(15,15);
    for(i = 10; i <= 40;i++){
        for(j = 36; j <= 127; j++){
            gotoprintchar(j,i,219);
        }
    }
    SetColorBlock(4,15);
    DrawFile(x,y,namaFile);
    SetColorBlock(4,15);
    frameLayout(36,10,37,40,223);
    frameLayout(36,10,128,11,223);
    frameLayout(127,10,128,40,223);
    frameLayout(36,40,128,41,220);
}

void tiketDetail(int x,int y, char namaFile[255]){
    SetColorBlock(15,15);
    for(i = 10; i <= 40;i++){
        for(j = 36; j <= 166; j++){
            gotoprintchar(j,i,219);
        }
    }
    SetColorBlock(1,15);
    DrawFile(x,y,namaFile);
    SetColorBlock(1,15);
    frameLayout(36,10,37,40,223);
    frameLayout(36,10,167,11,223);
    frameLayout(166,10,167,40,223);
    frameLayout(36,40,167,41,220);
}
void lembarLaporanBulanan(){
    SetColorBlock(1,15);
    kertas(50,12,"../Desaintxt/Dashboard/bioskopTaliwang.txt");
    gotoprinttext(58,18,"UNTUK PERIODE BULAN  TAHUN ");
    SetColorBlock(7,9);
    DrawFile(132,13,"../Desaintxt/Dashboard/cariLaporan.txt");
    gotoprinttext(133,23,"Bulan");
    borderInput(133,24,32);
    gotoprinttext(133,27,"Tahun");
    borderInput(133,28,32);
    for(j = 20; j <= 22; j++) {
        for (i = 42; i < 120; i++) {
            gotoprintchar(i, j, 32);
        }
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(42,i,32);
    }
    for(i = 42; i< 120;i++){
        gotoprintchar(i,35,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(46,i,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(100,i,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(119,i,32);
    }
    for(i=23; i < 35;i++){
        SetColorBlock(9,15);
        gotoprinttext(102,i,"Rp.");
    }
    for(i = 1; i <=9; i++){
        gotoxy(44,22+i);
        printf("%d.",i);
    }
    for(i = 10; i <=12; i++){
        gotoxy(43,22+i);
        printf("%d.",i);
    }
    SetColorBlock(15,9);
    for(i = 101; i < 117; i++){
        gotoprintchar(i,35,196);
    }
    gotoprinttext(118,35,"+");
    SetColorBlock(9,15);
    gotoprinttext(82,37,"TOTAL KESELURUHAN : Rp.");
    SetColorBlock(15,9);
    gotoprinttext(43,21,"NO.");
    gotoprinttext(67,21,"ID TRANSAKSI");
    gotoprinttext(102,21,"TOTAL PENDAPATAN");
}

void lembarLaporanTahunan(){
    SetColorBlock(1,15);
    kertas(50,12,"../Desaintxt/Dashboard/bioskopTaliwang.txt");
    gotoprinttext(58,18,"U N T U K  P E R I O D E  T A H U N");
    SetColorBlock(7,9);
    DrawFile(132,13,"../Desaintxt/Dashboard/cariLaporan.txt");
    gotoprinttext(133,25,"Tahun");
    borderInput(133,26,32);
    for(j = 20; j <= 22; j++) {
        for (i = 42; i < 120; i++) {
            gotoprintchar(i, j, 32);
        }
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(42,i,32);
    }
    for(i = 42; i< 120;i++){
        gotoprintchar(i,35,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(46,i,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(100,i,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(119,i,32);
    }
    for(i=23; i < 35;i++){
        SetColorBlock(9,15);
        gotoprinttext(102,i,"Rp.");
    }
    for(i = 1; i <=9; i++){
        gotoxy(44,22+i);
        printf("%d.",i);
    }
    for(i = 10; i <=12; i++){
        gotoxy(43,22+i);
        printf("%d.",i);
    }
    SetColorBlock(15,9);
    for(i = 101; i < 117; i++){
        gotoprintchar(i,35,196);
    }
    gotoprinttext(118,35,"+");
    SetColorBlock(9,15);
    bulan();
    gotoprinttext(82,37,"TOTAL KESELURUHAN : Rp.");
    SetColorBlock(15,9);
    gotoprinttext(43,21,"NO.");
    gotoprinttext(72,21,"BULAN");
    gotoprinttext(102,21,"TOTAL PENDAPATAN");
}

void showDetail(){
    SetColorBlock(12,12);
    for(i = 11; i <= 39; i++){
        for(j = 118; j < 169; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(4,15);
    /*border atas*/
    for(j = 119; j <= 167; j++){
        gotoprintchar(j,11,205);
    }
    /*border sudut kiri atas*/
    gotoprintchar(118,11,201);
    /*border sudut kanan atas*/
    gotoprintchar(168,11,187);
    /*border vertikal kebawah kiri*/
    for(i = 12; i <= 38;i++){
        gotoprintchar(118,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 12; i <= 38;i++){
        gotoprintchar(168,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(118,39,200);
    for(j = 119; j <= 167; j++){
        gotoprintchar(j,39,205);
    }

    /*border sudut bawah kanan*/
    gotoprintchar(168,39,188);
}

void boxSearch(){
    SetColorBlock(4,15);
    gotoprintchar(136,9,201);
    for(i = 137; i <= 164;i++){
        gotoprintchar(i,9,205);
    }
    gotoprintchar(165,9,187);
    gotoprintchar(136,10,186);
    gotoprintchar(165,10,186);
    gotoprintchar(136,11,200);
    for(i = 137; i <= 164;i++){
        gotoprintchar(i,11,205);
    }
    gotoprintchar(165,11,188);
}


void Tanggal()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *wday[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};


        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        gotoxy(139,5);printf("Waktu Masuk: %02d:%02d:%02d\n",timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);


    gotoxy(144, 6); printf("%s,%02d-%02d-%d", wday[tm.tm_wday],tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
}

void convertBulan(int bulan){
    if(bulan == 1){
        strcpy(namabulan,"JANUARI");
    } else if(bulan == 2){
        strcpy(namabulan,"FEBRUARI");
    }else if(bulan == 3){
        strcpy(namabulan,"MARET");
    }else if(bulan == 4){
        strcpy(namabulan,"APRIL");
    }else if(bulan == 5){
        strcpy(namabulan,"MEI");
    }else if(bulan == 6){
        strcpy(namabulan,"JUNI");
    }else if(bulan == 7){
        strcpy(namabulan,"JULI");
    }else if(bulan == 8){
        strcpy(namabulan,"AGUSTUS");
    }else if(bulan == 9){
        strcpy(namabulan,"SEPTEMBER");
    }else if(bulan == 10){
        strcpy(namabulan,"OKTOBER");
    }else if(bulan == 11){
        strcpy(namabulan,"NOVEMBER");
    }else if(bulan == 12){
        strcpy(namabulan,"DESEMBER");
    }
}

void rupiah(int number,char output[80]){
    if(number < 1000) sprintf(output, "Rp. %d", number);
    else if(number < 1000000) sprintf(output, "Rp. %d.%03d", number/1000, number%1000);
    else if(number < 1000000000) sprintf(output, "Rp. %d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
    else sprintf(output, "Rp. %d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
}

void uangLaporan(int number,char output[80]){
    if(number < 1000) sprintf(output, "%d", number);
    else if(number < 1000000) sprintf(output, "%d.%03d", number/1000, number%1000);
    else if(number < 1000000000) sprintf(output, "%d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
    else sprintf(output, "%d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
}

void aturkanankekiri(char kata[],int a, int b){
     // Kata yang akan dicetak
    int panjang = strlen(kata);

    // Tentukan posisi awal cetakan
    x = a - panjang; // Kolom 80 sebagai batas, kurangi panjang kata
    y = b; // Baris 10, bisa disesuaikan dengan tinggi layar

    // Cetak kata dari kanan ke kiri
    gotoxy(x, y);
    printf("%s", kata);
    printf("\n");
}

void generateid(char Teks[4],int IDStruct){
    if(IDStruct < 10){
        printf("%s00%d", Teks, IDStruct);
    }
    else if(IDStruct < 100){
        printf("%s0%d", Teks, IDStruct);
    }
    else{
        printf("%s%d", Teks, IDStruct);
    }
}

void getRp(float *nilai, int min, int max, int x, int y) //input rupiah
{
    char input[255];
    char inpkey;
    int i,n,m;
    n = 0;
    do
    {
        inpkey = getch(); // membaca masukan dari keyboard per-karakter //
        if(inpkey == '\b' && n != 0) /* Hapus karakter */
        {
            n--;
            input[n]='\0';

            m = n % 3;
            if((n-m) % 3 == 0 || n == m)
            {
                printf("\b \b");
                printf("\b \b");
            }
            else
            {
                printf("\b \b");
            }

            gotoxy(x, y);		/* Cetak ulang sesuai format */
            for(i = 0; i < n; i++)
            {
                if((i+1) == m || (i+1-m) % 3 == 0)
                {
                    printf("%c", input[i]);
                    if(i != (n-1))
                    {
                        printf(".");
                    }
                }
                else
                {
                    printf("%c", input[i]);
                }
            }
        }
        else if(isprint(inpkey))      /* Karakter yang bisa di print */
        {
            if(n == max)
            {
                continue;
            }
            else
            {
                if(isdigit(inpkey))   /* Print angka */
                {
                    gotoxy(x, y);
                    input[n]=inpkey;
                    n++;
                    m = n % 3;
                    for(i = 0; i < n; i++)  /* Cetak ulang sesuai format */
                    {
                        if((i+1) == m || (i+1-m) % 3 == 0)
                        {
                            printf("%c", input[i]);
                            if(i != (n-1))
                            {
                                printf(".");
                            }
                        }
                        else
                        {
                            printf("%c", input[i]);
                        }
                    }
                }
                else printf("\a"); /* Pemberitahuan suara tidak dapat di input (alert) */
            }
        }
        else if(inpkey == 13)	/* Jika menekan enter sebelum mengisi karakter akan muncul suara tidak dapat diinput (alert) */
        {
            if(n < min)
            {
                printf("\a");
                inpkey = 0;
            }
            else input[n]='\0';
        }
    }
    while(inpkey != 13);

    *nilai = atoi(input);   /* Memasukkan nilai input (char) ke nilai (int) */
}

void getallinput(char input[], int min, int max, int type)
{
    char inpkey;
    int i,n,x,m;
    n = 0;
    x=0;
    do
    {
        inpkey = getch(); // membaca masukan dari keyboard per-karakter //

//---- Menghapus Input ----//
//start//
        if(inpkey == '\b' && n != 0)
        {
            printf("\b \b");
            n--;
            input[n]='\0';
        }
//end//
        else if(isprint(inpkey)){ //karakter yang bisa di print
            if(n == max) {
                continue;
            }
            else{
                if(type == 3){ //isdigit = angka doang
                    if(isdigit(inpkey)) {
                        printf("%c", inpkey);
                        input[n]=inpkey;
                        n++;
                    }
                    else printf("\a"); //pemberitahuan suara tidak dapat di input (allert)
                }
                else if(type == 2){ //isalpha = alpabet dan spasi co : nama
                    if(isalpha(inpkey) || inpkey == ' ') {
                        printf("%c", inpkey);
                        input[n]=inpkey;
                        n++;
                    }
                    else printf("\a");
                }
                else { // inpkeyword //0= bebas
                    if(type == 1)
                    {
                        if (inpkey=='\r')
                        {
                            inpkey='\0';
                            break;
                        }
                        printf("%c", inpkey);
                        input[n]=inpkey;
//                        printf("*");
                        n++;
                    }


                    else
                    {
                        printf("%c", inpkey);
                        input[n]=inpkey;
                        n++;
                    }
                }
            }
        }
        else if(inpkey == 13)
        {
            if(n < min) {
                printf("\a");
                inpkey = 0;
            }
            else input[n]='\0';
        }
        //else if(current == 27) end();
    }
    while(inpkey != 13);
}

void getinput(char input[], int max, int type)
{
    getallinput(input, 1, max, type);
}

void getinputint(int *nilai,int min, int max, int type){
    char input[max];
    getallinput(input, min, max, type);
    *nilai = atoi(input);
}

void getinputtahun(char input[], int max, int type){
    getallinput(input, 4, max, type);
}

void getyear(int *nilai,int max){
    char input[max];
    getinputtahun(input, max, 3);
    *nilai = atoi(input);
}

void getnum(int *nilai, int max)
{
    char input[max];
    getinput(input, max, 3);
    *nilai = atoi(input);
}


void getnumfloat(float *nilai, int max)
{
    char input[max];
    getinput(input, max, 3);
    *nilai = atoi(input);
}

void lembarLaporanFilmTerfavorit(){
    SetColorBlock(15,15);
    for(i = 10;  i < 41; i++){
        for(j = 36; j < 168; j++){
            gotoprintchar(j,i,219);
        }
    }
    SetColorBlock(1,15);
    DrawFile(50,11,"../LAPORAN BIOSKOP/../Source/../Desaintxt/Dashboard/filmTerfavorit.txt");
    gotoprinttext(50,19,"F I L M  T E R F A V O R I T  B I O S K O P  T A L I W A N G  P A L I N G  B A N Y A K  D I T O N T O N");
    SetColorBlock(1,1);
    for(j = 36; j < 168; j++){
        gotoprintchar(j,10,219);
    }
    for(j = 36; j < 168; j++){
        gotoprintchar(j,18,219);
    }
    SetColorBlock(9,9);
    for(i = 20;  i < 23; i++){
        for(j = 38; j < 166; j++){
            gotoprintchar(j,i,219);
        }
    }
    for(j = 23; j < 38; j++){
        gotoprintchar(38,j,219);
    }
    for(j = 38; j < 166; j++){
        gotoprintchar(j,37,219);
    }
    for(j = 23; j < 38; j++){
        gotoprintchar(42,j,219);
    }
    for(j = 23; j < 38; j++){
        gotoprintchar(140,j,219);
    }
    for(j = 23; j < 38; j++){
        gotoprintchar(165,j,219);
    }

    SetColorBlock(15,9);
    gotoprinttext(39,21,"NO.");
    gotoprinttext(75,21,"N A M A  F I L M");
    gotoprinttext(141,21,"T I K E T  T E R J U A L");
}

void batasTable(){
    if (i == 25) {
        moreTable(12);
    }
    if (i == 50) {
        moreTable(12);
    }
    if (i == 75) {
        moreTable(12);
    }
    if (i == 100) {
        moreTable(12);
    }
    if (i == 125) {
        moreTable(12);
    }
    if (i == 150) {
        moreTable(12);
    }
    if (i == 175) {
        moreTable(12);
    }if (i == 200) {
        moreTable(12);
    }if (i == 225) {
        moreTable(12);
    }if (i == 250) {
        moreTable(12);
    }if (i == 275) {
        moreTable(12);
    }if (i == 300) {
        moreTable(12);
    }if (i == 325) {
        moreTable(12);
    }if (i == 350) {
        moreTable(12);
    }if (i == 375) {
        moreTable(12);
    }if (i == 400) {
        moreTable(12);
    }if (i == 425) {
        moreTable(12);
    }if (i == 450) {
        moreTable(12);
    }
    if (i == 475) {
        moreTable(12);
    }if (i == 500) {
        moreTable(12);
    }if (i == 525) {
        moreTable(12);
    }if (i == 550) {
        moreTable(12);
    }if (i == 575) {
        moreTable(12);
    }if (i == 600) {
        moreTable(12);
    }if (i == 625) {
        moreTable(12);
    }if (i == 650) {
        moreTable(12);
    }if (i == 675) {
        moreTable(12);
    }if (i == 700) {
        moreTable(12);
    }if (i == 725) {
        moreTable(12);
    }if (i == 750) {
        moreTable(12);
    }if (i == 775) {
        moreTable(12);
    }if (i == 800) {
        moreTable(12);
    }if (i == 825) {
        moreTable(12);
    }if (i == 850) {
        moreTable(12);
    }if (i == 875) {
        moreTable(12);
    }if (i == 900) {
        moreTable(12);
    }if (i == 925) {
        moreTable(12);
    }if (i == 950) {
        moreTable(12);
    }if (i == 975) {
        moreTable(12);
    }if (i == 1000) {
        moreTable(12);
    }if (i == 1025) {
        moreTable(12);
    }if (i == 1050) {
        moreTable(12);
    }if (i == 1075) {
        moreTable(12);
    }if (i == 1100) {
        moreTable(12);
    }if (i == 1125) {
        moreTable(12);
    }if (i == 1150) {
        moreTable(12);
    }if (i == 1175) {
        moreTable(12);
    }if (i == 1200) {
        moreTable(12);
    }if (i == 1225) {
        moreTable(12);
    }if (i == 1250) {
        moreTable(12);
    }if (i == 1275) {
        moreTable(12);
    }if (i == 1300) {
        moreTable(12);
    }if (i == 1325) {
        moreTable(12);
    }if (i == 1350) {
        moreTable(12);
    }if (i == 1375) {
        moreTable(12);
    }if (i == 1400) {
        moreTable(12);
    }if (i == 1425) {
        moreTable(12);
    }if (i == 1450) {
        moreTable(12);
    }if (i == 1475) {
        moreTable(12);
    }if (i == 1500) {
        moreTable(12);
    }
}