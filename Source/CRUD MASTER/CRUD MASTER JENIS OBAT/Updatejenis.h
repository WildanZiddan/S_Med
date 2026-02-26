void SpecialkeyDashboardMenuUpdateDataSupplier(int *output);
void menuUpdateDataModifikasiJenis();
void updateJenis() {
    SetColorBlock(15, 12);
    showCursor();
    gotoprinttext(140, 22, "U P D A T E  D A T A");
    gotoxy(132, 24);printf("Masukkan ID Jenis    : JNS");
    gotoxy(160, 24);
    getnum(&id, 3);
    hideCursor();
    if(id == 0){
        BlankDashboard();
        clearArea(5,24,28,4);
        profileOwner();
        menuOpsiDashboardOwner();
    }
    SpecialKeyUpdate(152, 26, 13, 3, &output);
    switch (output) {
        case 1:
            arspjenisobat = fopen("../Database/Dat/jenisobat.dat", "rb");
            ft = fopen("../Database/Dat/temp.dat", "wb");
            found = 0;
            while (fread(&jns_obt, sizeof(jns_obt), 1, arspjenisobat) == 1) {
                if (jns_obt.id_JenisObat == id) {
                    MessageBox(NULL, "ID Jenis Ditemukan", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    found = 1;
                    break;
                }
                fwrite(&jns_obt, sizeof(jns_obt), 1, ft);
            }
            if (found) {
                clearTengah();
                DashboardDetail(55, 102, 10, 31, 103, 56, 32, 11);
                seluruhDataSupplier();
                gotoxy(72, 16);generateid("JNS", jns_obt.id_JenisObat);
                gotoxy(72, 18);printf("%s", jns_obt.nama_Jenis);
                clearKanan();
                SetColorBlock(15, 12);
                gotoprinttext(140, 12, "U P D A T E  D A T A");
                menuUpdateDataSupplier();
                SpecialkeyDashboardMenuUpdateDataSupplier(&output);
                switch (output) {
                    case 1:
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15,12);
                        printf("Masukkan Nama Baru:");
                        gotoxy(154, 24);
                        getinput(jns_obt.nama_Jenis, 25, 2);
                        hideCursor();
                        break;
                    case 2:
                        fclose(arspjenisobat);
                        fclose(ft);
                        BlankDashboard();
                        menuDashboardOwner();
                        return;
                }
                fwrite(&jns_obt, sizeof(jns_obt), 1, ft);
                while (fread(&jns_obt, sizeof(jns_obt), 1, arspjenisobat) == 1) {
                    fwrite(&jns_obt, sizeof(jns_obt), 1, ft);
                }
                fclose(arspjenisobat);
                fclose(ft);
                remove("../Database/Dat/jenisobat.dat");
                rename("../Database/Dat/temp.dat", "../Database/Dat/jenisobat.dat");
            } else {
                MessageBox(NULL,"ID Jenis Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                fclose(ft);
                fclose(arspjenisobat);
                updateJenis();
            }
            break;
        case 2:
            BlankDashboard();
            menuUpdateDataModifikasiJenis();
    }
}

void menuUpdateDataModifikasiJenis(){
    char exit[2] = "y";
    SetColorBlock(4,15);
    //DrawFile(48,9,"../Source/../Desaintxt/Dashboard/updatedata.txt");
    DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    do {
        BlankDashboard();
        tampilanCRUDJenisObat();
        DashboardCRUD();
        readUpdateDataJenisObat();
        updateJenis();
        clearTengah();
        tampilanCRUDJenisObat();
        readUpdateDataJenisObat();
        clearKanan();
        SetColorBlock(15,12);
        gotoxy(135,23);printf("Anda Ingin Mengupdate Data Lagi?");
        SpecialKeyYesorNoDashboard(153, 25,10,15,12,&output);
    }while(output == 1);


    clearKanan();
    SetColorBlock(15,12);
    gotoprinttext(114,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,24,28,4);
        profileOwner();
        menuOpsiDashboardOwner();
    }
}