void userPass(char username[],char password[]);
void DashboardOwner();
void DashboardKasir();


void exitLayout(){
    BorderScreen();
    SetColorBlock(4,15);
    loading(54,33);
    clearArea(72,34,16,1);
    SetColorBlock(15,4);
    gotoxy(74,34);
    printf(" Selesai!\n");
    sleep(1);
    exit(1);
}

void userPass(char username[],char password[]){
    showCursor();
    SetColorBlock(4,15);
    gotoprinttext(70,20,"N A M A  P E N G G U N A :");
    borderInput(  70,21,36);
    gotoprinttext(70,25,"K A T A  S A N D I       :");
    borderInput(70,26,36);
    printf("\033]12;#FF0000\007");
    gotoscanf(72,22,username);
    gotoxy(72,27);
    inputPass(password);
    printf("\033]12;\007");
    hideCursor();
}

void login() {
    header(5, 2);
    SetColorBlock(4, 15);
    logologin(63, 4);
    SetColorBlock(4, 15);
    frame(60, 14);
    menuBackSign();
    userPass(inputUsername, inputPassword);
    SpecialKeyLoginProses(92, 30, 13, 3, &input);
    found = 0;
    if (input == 1) {
        arspstaff = fopen("../Database/Dat/staff.dat", "rb");
        while (fread(&k, sizeof(k), 1, arspstaff) == 1) {
            if (strcmp(inputUsername, k.username) == 0 && strcmp(inputPassword, k.password) == 0 &&strcmp(k.role, "Owner") == 0) {
                found = 1;
                break;
            }
            else if (strcmp(inputUsername, k.username) == 0 && strcmp(inputPassword, k.password) == 0 &&strcmp(k.role, "Kasir") == 0) {
                found = 2;
                break;
            }
        }
        fclose(arspstaff);
        if (strcmp(inputUsername, username[0]) == 0 && strcmp(inputPassword, password[0]) == 0 &&strcmp(role[0], "Owner") == 0) {
            MessageBox(NULL, "Selamat Datang Owner", "Login Berhasil", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            blankScreen();
            // char *audioFile = "../Sound/Selamatdatangmanajer.wav";
            // playCustomSound(audioFile);
            SetColorBlock(4, 15);
            desainAtas();
            DrawFile(32, 14, "../Desaintxt/Booting/bootOwner.txt");
            desainBawah();  
            loadingMasuk(55, 33);
            Beep(5000, 500);
            clearArea(72, 34, 20, 1);
            gotoxy(76, 34);
            printf(" Selesai!\n");
            DashboardOwner();
        }
        // else if(strcmp(inputUsername,"Admin")==0 && strcmp(inputPassword,"Admin")==0) {
        //     MessageBox(NULL, "Selamat Datang Manajer", "Login Berhasil", MB_OK | MB_ICONINFORMATION);
        //     blankScreen();
        //     char *audioFile = "../Sound/selamatdatangadmin.wav";
        //     playCustomSound(audioFile);
        //     SetColorBlock(1,7);
        //     desainAtas();
        //     DrawFile(32,14,"../Desaintxt/Booting/bootAdmin.txt");
        //     desainBawah();
        //     loadingMasuk(55,33);
        //     Beep(5000,500);
        //     clearArea(72,34,20,1);
        //     gotoxy(76,34);
        //     printf(" Selesai!\n");
        //     DashboardAdmin();
        // }
        else if (found == 1) {
            strcpy(inputUsername, k.username);
            blankScreen();
            // char *audioFile = "../Sound/Selamatdatangmanajer.wav";
            // playCustomSound(audioFile);
            SetColorBlock(4, 15);
            desainAtas();
            DrawFile(32, 14, "../Desaintxt/Booting/bootOwner.txt");
            desainBawah();
            loadingMasuk(55, 33);
            Beep(5000, 500);
            clearArea(72, 34, 21, 1);
            gotoxy(76, 34);
            printf(" Selesai!\n");
            DashboardOwner();
        }
        else if (found == 2) {
            strcpy(inputUsername, k.username);
            blankScreen();
            // char *audioFile = "../Sound/Selamatdatangmanajer.wav";
            // playCustomSound(audioFile);
            SetColorBlock(4, 15);
            desainAtas();
            DrawFile(32, 14, "../Desaintxt/Booting/bootOwner.txt");
            desainBawah();
            loadingMasuk(55, 33);
            Beep(5000, 500);
            clearArea(72, 34, 21, 1);
            gotoxy(76, 34);
            printf(" Selesai!\n");
            DashboardKasir();
        }
        // else if (found == 3) {
        //     blankScreen();
        //     char *audioFile = "../Sound/selamatdatangkasir.wav";
        //     playCustomSound(audioFile);
        //     SetColorBlock(1,7);
        //     desainAtas();
        //     DrawFile(32,14,"../Desaintxt/Booting/bootKasir.txt");
        //     desainBawah();
        //     loadingMasuk(55,33);
        //     Beep(5000,500);
        //     clearArea(72,34,20,1);
        //     gotoxy(76,34);
        //     printf(" Selesai!\n");
        //     DashboardKasirTiket();
        // }
        else if (strcmp(inputUsername, "") == 0 || strcmp(inputPassword, "") == 0) {
            audioFile = "../Sound/inputanjangankosong.wav";
            playCustomSound(audioFile);
            MessageBox(NULL, "Inputan tidak boleh kosong!", "Inputan Kosong",
                       MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            login();
        }
        else {
            audioFile = "../Sound/passwordsalah.wav";
            playCustomSound(audioFile);
            MessageBox(NULL, "Nama Pengguna atau Kata Sandi Salah!", "Akun Salah", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            login();
        }
    }
    else {
            SetColorBlock(4,15);
            blankScreen();
            exitLayout();
    }
}