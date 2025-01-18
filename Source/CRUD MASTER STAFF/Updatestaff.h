void SpecialkeyDashboardMenuUpdateDataOwner(int *output);
void menuUpdateDataModifikasiOwner();
void updateDataOwner(){
    SetColorBlock(15,12);
    showCursor();
    gotoprinttext(140,22,"U P D A T E  D A T A");
    gotoxy(132,24);printf("Masukan ID Staff: STF");
    gotoxy(153,24);
    getnum(&id,3);
    hideCursor();
    SpecialKeyUpdate(152,26,13,3,&output);
    switch (output) {
        case 1:
        arspstaff = fopen("../Source/../Database/Dat/staff.dat", "rb");
        ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
        found = 0;
        while (found == 0 && fread(&k, sizeof(k), 1, arspstaff) == 1) {
            if (k.idStaff == id && strcmp(k.role,"Owner")==0 || strcmp(k.role,"Kasir")==0 || strcmp(k.role,"Apoteker")==0) {
                MessageBox(NULL,"ID Staff Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                found = 1;
            }
            else{
                fwrite(&k, sizeof(k), 1, ft);
                found = 0;
            }
        }
        if(found == 1){
            clearTengah();
            DashboardDetail(55,102,10,31,103,56,32,11);
            seluruhDataOwner();
            gotoxy(72,14);
            generateid("STF",k.idStaff);
            gotoxy(72,16);printf("%s",k.FName);
            gotoxy(72,18);printf("%s",k.No_telp);
            gotoxy(72,20);printf("%02d/%02d/%04d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
            gotoxy(72,22);printf("%s",k.username);
            gotoxy(72,24);printf("%s",k.password);
            gotoxy(72,26);printf("%s",k.role);
            //Menu update data
                clearKanan();
                SetColorBlock(15, 12);
                gotoprinttext(140, 12, "U P D A T E  D A T A");
                menuUpdateDataOwner();
                SpecialkeyDashboardMenuUpdateDataOwner(&output);
                switch (output) {
                    case 1:
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15,12);
                        printf("Masukan No. Telepon:");
                        gotoxy(154, 24);
                        getinput(k.No_telp,14,3);
                        hideCursor();
                        fwrite(&k, sizeof(k), 1, ft);
                        MessageBox(NULL, "No Telepon Berhasil Diubah", "NOTIFICATION!",
                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        while (fread(&k, sizeof(k), 1, arspstaff) == 1) {
                            fwrite(&k, sizeof(k), 1, ft);
                        }
                        fclose(arspstaff);
                        fclose(ft);
                        remove("../Source/../Database/Dat/staff.dat");
                        rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/staff.dat");
                        break;
                    case 2:
                        clearKanan();
                    showCursor();
                    gotoxy(132, 24);
                    SetColorBlock(15,12);
                    printf("Masukan Username:");
                    gotoxy(150, 24);
                    getinput(k.username, 14, 2);
                    hideCursor();
                    MessageBox(NULL, "Username Berhasil Diubah", "NOTIFICATION!",
                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    fwrite(&k, sizeof(k), 1, ft);
                    while (fread(&k, sizeof(k), 1, arspstaff) == 1) {
                        fwrite(&k, sizeof(k), 1, ft);
                    }
                    fclose(arspstaff);
                    fclose(ft);
                    remove("../Source/../Database/Dat/staff.dat");
                    rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/staff.dat");
                    break;

                    case 3:
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15,12);
                        printf("Masukan Password:");
                        gotoxy(150, 24);
                        inputPass(k.password);
                        hideCursor();
                        MessageBox(NULL, "Password Berhasil Diubah", "NOTIFICATION!",
                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        fwrite(&k, sizeof(k), 1, ft);
                        while (fread(&k, sizeof(k), 1, arspstaff) == 1) {
                            fwrite(&k, sizeof(k), 1, ft);
                        }
                        fclose(arspstaff);
                        fclose(ft);
                        remove("../Source/../Database/Dat/staff.dat");
                        rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/staff.dat");
                        break;
                    case 4 :
                        fclose(arspstaff);
                        fclose(ft);
                        BlankDashboard();
                        dataStaffMenu();
                        break;
                }
        } else {
            MessageBox(NULL,"ID Staff Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            SetColorBlock(12,12);
            for(i = 154; i < 169; i++){
                gotoprintchar(i,24,32);
            }
            for(i = 26; i < 29; i++) {
                for (j = 132; j < 169; j++){
                gotoprintchar(j, i, 32);
                }
            }
            fclose(ft);
            fclose(arspstaff);
            updateDataOwner();
        }
        break;
        case 2:
            BlankDashboard();
        menuUpdateDataModifikasiOwner();
    }
}

void menuUpdateDataModifikasiOwner(){
    char exit[2] = "y";
    SetColorBlock(4,15);
    //DrawFile(48,9,"../Source/../Desaintxt/Dashboard/updatedata.txt");
    DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    do {
        BlankDashboard();
        tampilanCRUDStaff();
        DashboardCRUD();
        readUpdateDataOwner();
        updateDataOwner();
        clearTengah();
        tampilanCRUDStaff();
        readUpdateDataOwner();
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
            dataStaffMenu();
    }
}