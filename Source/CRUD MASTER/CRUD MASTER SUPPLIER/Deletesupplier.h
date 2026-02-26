void menuDeleteDataModifikasiSupplier();
void deleteSupplier(){
    SetColorBlock(15,12);
    gotoxy(136,38);
    printf("Ketik 0 untuk batal delete");
    gotoxy(135,22);
    showCursor();
    printf("D E L E T E  S U P P L I E R");
    gotoxy(132,24);
    printf("Masukkan ID Supplier: SUP");
    gotoxy(157,24);
    getnum(&id,3);
    hideCursor();
    if(id == 0){
        BlankDashboard();
        menuOpsiDashboardOwner();
    }
    SpecialKeyUpdate(152,26,13,3,&output);
    switch (output) {
        case 1:
            arspsupplier = fopen("../Source/../Database/Dat/supplier.dat", "rb");
            ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
            found = 0;
            while (found == 0 && fread(&sp, sizeof(sp), 1, arspsupplier) == 1) {
                if (sp.id_Supplier == id) {
                    found = 1;
                }else {
                    fwrite(&sp, sizeof(sp), 1, ft);
                    found = 0;
                }
            }
            if(found == 1){
                clearKanan();
                MessageBox(NULL,"ID Supplier ditemukan!","Delete Berhasil!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                clearTengah();
                DashboardDetail(55,102,10,31,103,56,32,11);
                seluruhDataSupplier();
                gotoxy(72,16);
                printf("SUP%d", sp.id_Supplier);
                gotoxy(72,18); printf("%s", sp.nama_Supplier);
                gotoxy(72,20); printf("%s", sp.company);
                gotoxy(72,22); printf("%s", sp.alamat);
                SetColorBlock(4,15);
                gotoxy(65,36); printf("Detail Data yang anda hapus");
                gotoxy(62,37); printf("Klik apa saja untuk melanjutkan...");
                getch();
                cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
                if(cancel == IDOK) {
                    while (fread(&sp, sizeof(sp), 1, arspsupplier) == 1) {
                        fwrite(&sp, sizeof(sp), 1, ft);
                    }
                    fclose(arspsupplier);
                    fclose(ft);
                    remove("../Source/../Database/Dat/supplier.dat");
                    rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/supplier.dat");
                }else if(cancel == IDCANCEL){
                    fclose(arspsupplier);
                    fclose(ft);
                    remove("../Source/../Database/Dat/temp.dat");
                    BlankDashboard();
                    menuDeleteDataModifikasiSupplier();
                }
            }else{
                MessageBox(NULL,"ID Supplier Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
                fclose(arspsupplier);
                fclose(ft);
                clearKanan();
                deleteSupplier();
            }
            break;
        case 2:
            BlankDashboard();
            menuOpsiDashboardOwner();
            break;
    }
}

void menuDeleteDataModifikasiSupplier(){
    char exit[2] = "y";
    SetColorBlock(4,15);
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,38,220);
    frameLayout(119,18,120,38,220);
    frameLayout(60,37,120,38,223);
    SetColorBlock(15,12);
    BlankDashboard();
    SetColorBlock(4,12);
    tampilanCRUDSupplier();
    DashboardCRUD();
    readUpdateDataSupplier();
    do {
        deleteSupplier();
        clearTengah();
        tampilanCRUDSupplier();
        readUpdateDataSupplier();
        clearKanan();
        SetColorBlock(15,12);
        gotoxy(135,23); printf("Anda Ingin Menghapus data lagi ?");
        SpecialKeyYesorNoDashboard(153, 25,10,15,12,&output);
        clearKanan();
    }while(output == 1);
    hideCursor();
    SetColorBlock(15,12);
    gotoprinttext(116,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,19,28,4);
        menuOpsiDashboardOwner();
    }
}
