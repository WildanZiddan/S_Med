void SpecialkeyDashboardMenuUpdateDataSupplier(int *output);
void menuUpdateDataModifikasiSupplier();
void updateSupplier() {
    SetColorBlock(15, 12);
    showCursor();
    gotoprinttext(140, 22, "U P D A T E  D A T A");
    gotoxy(132, 24);printf("Masukkan ID Supplier : SUP");
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
            arspsupplier = fopen("../Database/Dat/supplier.dat", "rb");
            ft = fopen("../Database/Dat/temp.dat", "wb");
            found = 0;
            while (fread(&sp, sizeof(sp), 1, arspsupplier) == 1) {
                if (sp.id_Supplier == id) {
                    MessageBox(NULL, "ID Supplier Ditemukan", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    found = 1;
                    break;
                }
                fwrite(&sp, sizeof(sp), 1, ft);
            }
            if (found) {
                clearTengah();
                DashboardDetail(55, 102, 10, 31, 103, 56, 32, 11);
                seluruhDataSupplier();
                gotoxy(72, 16);generateid("SUP", sp.id_Supplier);
                gotoxy(72, 18);printf("%s", sp.nama_Supplier);
                gotoxy(72, 20);printf("%s", sp.company);
                gotoxy(72, 22); printf("%s", sp.alamat);
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
                        getinput(sp.nama_Supplier, 25, 2);
                        hideCursor();
                        break;
                    case 2:
                        fclose(arspsupplier);
                        fclose(ft);
                        BlankDashboard();
                        menuDashboardOwner();
                        return;
                }
                fwrite(&sp, sizeof(sp), 1, ft);
                while (fread(&sp, sizeof(sp), 1, arspsupplier) == 1) {
                    fwrite(&sp, sizeof(sp), 1, ft);
                }
                fclose(arspsupplier);
                fclose(ft);
                remove("../Database/Dat/supplier.dat");
                rename("../Database/Dat/temp.dat", "../Database/Dat/supplier.dat");
            } else {
                MessageBox(NULL,"ID Supplier Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                fclose(ft);
                fclose(arspsupplier);
                updateSupplier();
            }
            break;
        case 2:
            BlankDashboard();
            menuUpdateDataModifikasiSupplier();
    }
}

void menuUpdateDataModifikasiSupplier(){
    char exit[2] = "y";
    SetColorBlock(4,15);
    //DrawFile(48,9,"../Source/../Desaintxt/Dashboard/updatedata.txt");
    DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    do {
        BlankDashboard();
        tampilanCRUDSupplier();
        DashboardCRUD();
        readUpdateDataSupplier();
        updateSupplier();
        clearTengah();
        tampilanCRUDSupplier();
        readUpdateDataSupplier();
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