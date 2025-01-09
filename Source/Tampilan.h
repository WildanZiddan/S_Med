void login();
void playCustomSound(char *audioFile);

void tampilanAwal(){
    BorderScreen();
    desainAtas();
    desainBawah();
    SetColorBlock(4, 15);
    logo1(54,15);
    SetColorBlock(4, 15);
    logo2(28,23);
    SetColorBlock(4,15);
    gotoprinttext(75,34,"8  S - M E D");
    gotoprinttext(45,35,"Deven Feodora Pranata Dauhan | Marsha Putri Andita | Wildan Yazid Ziddan");
    Sleep(800);
    Beep(5500,200);
    clearArea(30,34,100,2);
    gotoprinttext(83, 34, "M U L A I");
    gotoprinttext(69, 35, "(Tekan Apa Saja Untuk Melanjutkan)...");
    getch();
    clearArea(69,34,38,2);
    loadingAnimation(3);
    audioFile = "../Sound/selamatdatang.wav";
    playCustomSound(audioFile);
    //    Beep(3000,300);
    clearArea(3,2,169,41);
    login();
}

