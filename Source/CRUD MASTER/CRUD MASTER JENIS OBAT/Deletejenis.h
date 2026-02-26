void menuDeleteDataModifikasiJenisObat();
void deleteJenisObat(){
    SetColorBlock(15,12);
    gotoxy(136,38);
    printf("Ketik 0 untuk batal delete");
    gotoxy(134,22);
    printf("D E L E T E  J E N I S  O B A T");
    gotoxy(132,24);
    printf("Masukkan ID Jenis Obat: JNS");
    gotoxy(159,24);
    showCursor();
    getnum(&id,3);
    hideCursor();
    if(id == 0){
        BlankDashboard();
        clearArea(5,24,28,4);
        profileOwner();
        menuOpsiDashboardOwner();
    }
    SpecialKeyUpdate(152,26,13,3,&output);
    switch (output) {
        case 1:
            arspjenisobat = fopen("../Database/Dat/jenisobat.dat", "rb");
            ft = fopen("../Database/Dat/temp.dat", "wb");
            found = 0;
            while (found == 0 && fread(&jns_obt, sizeof(jns_obt), 1, arspjenisobat) == 1) {
                if (jns_obt.id_JenisObat == id) {
                    found = 1;
                } else {
                    fwrite(&jns_obt, sizeof(jns_obt), 1, ft);
                }
            }
            if(found==1){
                clearKanan();
                MessageBox(NULL,"ID Jenis Obat ditemukan!","Delete Berhasil!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                clearTengah();
                DashboardDetail(55,102,10,31,103,56,32,11);
                seluruhDataJenisObat();
                gotoxy(77,16);
                printf("JNS%d", jns_obt.id_JenisObat);
                gotoxy(77,18);printf("%s",jns_obt.nama_Jenis);
                SetColorBlock(4,15);
                gotoxy(65,36);printf("Detail Data yang anda hapus");
                gotoxy(62,37);printf("Klik apa saja untuk melanjutkan...");
                getch();
                cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
                if(cancel == IDOK) {
                    while (fread(&jns_obt, sizeof(jns_obt), 1, arspjenisobat) == 1) {
                        fwrite(&jns_obt, sizeof(jns_obt), 1, ft);
                    }
                    fclose(arspjenisobat);
                    fclose(ft);
                    remove("../Database/Dat/jenisobat.dat");
                    rename("../Database/Dat/temp.dat", "../Database/Dat/jenisobat.dat");
                } else {
                    fclose(arspjenisobat);
                    fclose(ft);
                    remove("../Database/Dat/temp.dat");
                    BlankDashboard();
                    menuDeleteDataModifikasiJenisObat();
                }
            }
            else {
                MessageBox(NULL,"ID Jenis Obat Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
                fclose(arspjenisobat);
                fclose(ft);
                BlankDashboard();
                menuDeleteDataModifikasiJenisObat();
            }
            break;
        case 2:
            BlankDashboard();
        clearArea(5,24,28,4);
        profileOwner();
        menuOpsiDashboardOwner();
            break;
    }
}

void menuDeleteDataModifikasiJenisObat(){
    SetColorBlock(4,15);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,38,220);
    frameLayout(119,18,120,38,220);
    frameLayout(60,37,120,38,223);
    SetColorBlock(15,12);
    BlankDashboard();
    SetColorBlock(4,12);
    tampilanCRUDJenisObat();
    DashboardCRUD();
    readUpdateDataJenisObat();
    do {
        deleteJenisObat();
        clearTengah();
        tampilanCRUDJenisObat();
        readUpdateDataJenisObat();
        clearKanan();
        SetColorBlock(15,12);
        gotoxy(135,23);printf("Anda Ingin Menghapus data lagi ?");
        SpecialKeyYesorNoDashboard(153, 25,10,15,12,&output);
        clearKanan();
    } while(output == 1);
    hideCursor();
    SetColorBlock(15,12);
    gotoprinttext(116,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,24,28,4);
        profileOwner();
        menuOpsiDashboardOwner();
}
}
