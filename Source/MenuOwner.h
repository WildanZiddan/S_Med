void menuReadDataModifikasiOwner();
void menuCreateDataModifikasiOwner();
void menuUpdateDataModifikasiOwner();
void menuDeleteDataModifikasiOwner();
void readAkunDataOwner();
void readAllDataOwner();
void createDataAlat();
void readDataAlat();
void SpecialkeyloginMenuDataOwner(int x, int y, int lebar,int tinggi, int *output);
void SpecialkeyDashboardMenuDataOwner(int x, int y, int lebar,int tinggi, int *output);
void SpecialkeyDashboardOwner(int x, int y, int lebar,int tinggi, int *output);

void dataAkun();
void dataPenjualan();
void dataAlat();

void menuOpsiDashboardOwner();

void profileOwner(){
    arspstaff = fopen("../Source/../Database/Dat/staff.dat","rb");
    while (fread(&k, sizeof(k), 1, arspstaff) == 1 ) {
        if(strcmp(inputUsername,k.username)==0 && strcmp(k.role,"Owner")==0){
            found = 1;
            break;
        }
    }
    if(strcmp(inputUsername, "Owner") == 0){
        gotoprinttext(139,4,"Master Owner");
        SetColorBlock(4,15);
        clearArea(74,21,58,12);
        gotoxy(74,21);
        printf("STF000");
        gotoprinttext(74,23,"Master Owner");
        gotoprinttext(74,25,"NULL");

    }else {
        SetColorBlock(15, 4);
        gotoprinttext(139, 4, k.FName);
    }
    fclose(arspstaff);
    SetColorBlock(4,15);
//    DrawFile(44,9,"../Desaintxt/Dashboard/profileManajer.txt");
//    DrawFile(130,21,"../Desaintxt/elemen/pensil.txt");
    gotoprinttext(45,21,"I D  O W N E R\t\t:");
    gotoprinttext(45,23,"N A M A  L E N G K A P\t:");
    gotoprinttext(45,25,"N O.  T E L E P O N E\t:");
    gotoprinttext(45,27,"T A N G G A L  L A H I R\t:       ");
    gotoprinttext(45,29,"R O L E\t\t\t:       \n");
    if(found){
        clearArea(74,21,58,12);
        gotoxy(74,21);
        generateid("STF",k.idStaff);
        gotoprinttext(74,23,k.FName);
        gotoprinttext(74,25,k.No_telp);
        gotoxy(74,27);
        printf("%02d/%02d/%04d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
        gotoprinttext(74,29,k.role);

    }
    fclose(arspstaff);
}

void dataStaffMenu(){
    SetColorBlock(4,15);
//    DrawFile(48,9,"../Desaintxt/Dashboard/dataKaryawan.txt");
    DrawFile(130,22,"../Desaintxt/Elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,40,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
    SetColorBlock(4,15);
    SpecialkeyloginMenuDataOwner(79,24,20,3,&output);
    switch (output) {
         case 1 :
            BlankDashboard();
            dataAkun();
        break;
        case 2 :
            BlankDashboard();
            menuCreateDataModifikasiOwner();
        break;
        case 3 :
            BlankDashboard();
            menuUpdateDataModifikasiOwner();
        break;
        case 4 :
            BlankDashboard();
            menuDeleteDataModifikasiOwner();
        break;
        case 5 :
            BlankDashboard();
        clearArea(5,24,28,4);
        menuOpsiDashboardOwner();
        break;
    }
}

void dataAlatMenu(){
    SetColorBlock(4,15);
    //    DrawFile(48,9,"../Desaintxt/Dashboard/dataKaryawan.txt");
    DrawFile(130,22,"../Desaintxt/Elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,40,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
    SetColorBlock(4,15);
    SpecialkeyloginMenuDataOwner(79,24,20,3,&output);
    switch (output) {
        case 1 :
            BlankDashboard();
            dataAlat();
        break;
        case 2 :
            BlankDashboard();
            createDataAlat();
        break;
        // case 3 :
        //     BlankDashboard();
        // menuUpdateDataModifikasiOwner();
        // break;
        // case 4 :
        //     BlankDashboard();
        // menuDeleteDataModifikasiOwner();
        // break;
        case 5 :
            BlankDashboard();
        clearArea(5,24,28,4);
        menuOpsiDashboardOwner();
        break;
    }
}

void dataPenjualanMenu(){
    SetColorBlock(4,15);
    //    DrawFile(48,9,"../Desaintxt/Dashboard/dataKaryawan.txt");
    DrawFile(130,22,"../Desaintxt/Elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,40,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
    SetColorBlock(4,15);
    SpecialkeyDashboardMenuDataOwner(79,24,20,3,&output);
    switch (output) {
        // case 1 :
        //     BlankDashboard();
        //     dataAkun();
        // break;
        case 2 :
            BlankDashboard();
            dataAlatMenu();
        break;
        case 3 :
            BlankDashboard();
            clearArea(5,24,28,4);
            menuOpsiDashboardOwner();
        break;
    }
}

void dataAkun(){
    SetColorBlock(4,15);
//    DrawFile(52,9,"../Source/../Desaintxt/Dashboard/lihatData.txt");
    DrawFile(130,22,"../Desaintxt/Elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,38,220);
    frameLayout(119,18,120,38,220);
    frameLayout(60,37,120,38,223);
    SetColorBlock(15,12);
    BlankDashboard();
    SetColorBlock(4,15);
    BlankDashboard();
    tampilanTableAkunOwner();
    readAkunDataOwner();

}

void dataAlat() {
    SetColorBlock(4,15);
    //    DrawFile(52,9,"../Source/../Desaintxt/Dashboard/lihatData.txt");
    DrawFile(130,22,"../Desaintxt/Elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,38,220);
    frameLayout(119,18,120,38,220);
    frameLayout(60,37,120,38,223);
    SetColorBlock(15,12);
    BlankDashboard();
    SetColorBlock(4,15);
    BlankDashboard();
    tampilanTableAlat();
    readDataAlat();
}

    void menuOpsiDashboardOwner(){
    SetColorBlock(15,4);
    SpecialkeyDashboardOwner(5,9,26,4,&output);
    switch (output) {
        case 1 :
            BlankDashboard();
            profileOwner();
            menuOpsiDashboardOwner();
            break;
        case 2 :
            BlankDashboard();
            dataStaffMenu();
        break;
        // case 3 :
        //     BlankDashboard();
        //     dataAkun();
        //     break;
        case 4 :
            BlankDashboard();
            dataPenjualanMenu();
            break;
        // case 5 :
        //     laporanFilmTerfavorit();
        //     break;
        case 6:
            // audioFile = "../Sound/andayakininginkeluar.wav";
            // playCustomSound(audioFile);
            out = MessageBox(NULL,"Anda yakin ingin keluar?","Keluar Akun",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
            if(out == IDOK) {
                audioFile = "../Sound/keluarakunberhasil.wav";
                playCustomSound(audioFile);
                blankScreen();
                login();
            } else if(out == IDCANCEL){
                menuOpsiDashboardOwner();
            }
            break;
    }
}