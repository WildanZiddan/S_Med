void SpecialkeyDashboardMenuUpdateDataAlat(int *output);
void menuUpdateDataModifikasiObat();
void updateObat() {
    SetColorBlock(15, 12);
    showCursor();
    gotoprinttext(140, 22, "U P D A T E  D A T A");
    gotoxy(132, 24);printf("Masukkan ID Obat : OBT");
    gotoxy(154, 24);
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
            arspobat = fopen("../Database/Dat/obat.dat", "rb");
            ft = fopen("../Database/Dat/temp.dat", "wb");
            found = 0;
            while (fread(&obt, sizeof(obt), 1, arspobat) == 1) {
                if (obt.id_Obat == id) {
                    MessageBox(NULL, "ID Obat Ditemukan", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    found = 1;
                    break;
                }
                fwrite(&obt, sizeof(obt), 1, ft);
            }
            if (found) {
                clearTengah();
                DashboardDetail(55, 102, 10, 31, 103, 56, 32, 11);
                seluruhDataObat();
                gotoxy(72, 16);generateid("OBT", obt.id_Obat);
                gotoxy(72, 18);printf("%s", obt.nama_Obat);
                gotoxy(72, 20);rupiah(obt.harga_Obat, inputrp);
                printf("%s", inputrp);
                gotoxy(72, 22); printf("%d", obt.jumlahObat);
                clearKanan();
                SetColorBlock(15, 12);
                gotoprinttext(140, 12, "U P D A T E  D A T A");
                menuUpdateDataAlat();
                SpecialkeyDashboardMenuUpdateDataAlat(&output);
                switch (output) {
                    case 1:
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15,12);
                        printf("Masukkan Nama Baru:");
                        gotoxy(154, 24);
                        getinput(obt.nama_Obat, 25, 2);
                        hideCursor();
                        break;
                    case 2:
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15, 12);
                        printf("Masukkan Harga Obat Baru: ");
                        gotoxy(154, 24);
                        getRp(&obt.harga_Obat,4,9,79,21);
                        hideCursor();
                        break;
                    case 3:
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15, 12);
                        printf("Masukkan Jumlah Obat: ");
                        gotoxy(154, 24);
                        scanf("%d", &obt.jumlahObat);
                        hideCursor();
                        break;
                    case 4:
                        fclose(arspobat);
                        fclose(ft);
                        BlankDashboard();
                        dataPenjualanMenu();
                        return;
                }
                fwrite(&obt, sizeof(obt), 1, ft);
                while (fread(&obt, sizeof(obt), 1, arspobat) == 1) {
                    fwrite(&obt, sizeof(obt), 1, ft);
                }
                fclose(arspobat);
                fclose(ft);
                remove("../Database/Dat/obat.dat");
                rename("../Database/Dat/temp.dat", "../Database/Dat/obat.dat");
            } else {
                MessageBox(NULL,"ID Obat Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                fclose(ft);
                fclose(arspobat);
                updateObat();
            }
            break;
        case 2:
            BlankDashboard();
            menuUpdateDataModifikasiObat();
    }
}

void menuUpdateDataModifikasiObat(){
    char exit[2] = "y";
    SetColorBlock(4,15);
    //DrawFile(48,9,"../Source/../Desaintxt/Dashboard/updatedata.txt");
    DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    do {
        BlankDashboard();
        tampilanCRUDObat();
        DashboardCRUD();
        readUpdateDataObat();
        updateObat();
        clearTengah();
        tampilanCRUDObat();
        readUpdateDataObat();
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
        dataPenjualanMenu();
    }
}