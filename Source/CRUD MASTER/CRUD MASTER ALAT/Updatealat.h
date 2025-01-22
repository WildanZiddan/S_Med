void SpecialkeyDashboardMenuUpdateDataAlat(int *output);
void menuUpdateDataModifikasiAlat();
void updateAlat() {
    SetColorBlock(15, 12);
    showCursor();
    gotoprinttext(140, 22, "U P D A T E  D A T A");
    gotoxy(132, 24);printf("Masukkan ID Alat : ALT");
    gotoxy(154, 24);
    getnum(&id, 3);  // Ambil input ID kelas
    hideCursor();
    SpecialKeyUpdate(152, 26, 13, 3, &output);  // Ambil input pilihan menu update
    switch (output) {
        case 1:  // Mengupdate data kelas berdasarkan ID
            arspalat = fopen("../Source/../Database/Dat/alatkesehatan.dat", "rb");
            ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
            found = 0;
            while (found == 0 && fread(&alt, sizeof(alt), 1, arspalat) == 1) {
                if (alt.id_Alat == id) {
                    MessageBox(NULL, "ID Alat Ditemukan", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    found = 1;
                }
                else {
                    fwrite(&alt, sizeof(alt), 1, ft);  // Simpan data lama ke file sementara
                    found = 0;
                }
            }

            if (found == 1) {
                clearTengah();
                DashboardDetail(55, 102, 10, 31, 103, 56, 32, 11);
                seluruhDataAlat();  // Menampilkan data kelas saat ini
                gotoxy(72, 16);generateid("ALT", alt.id_Alat);
                gotoxy(72, 18);printf("%s", 	alt.nama_Alat);
                gotoxy(72,20);rupiah(alt.harga_Alat,inputrp);
                printf("%s",inputrp);
                gotoxy(72, 22); printf("%d", 	alt.jumlahAlat);
                //Menu update data
                clearKanan();
                SetColorBlock(15, 12);
                gotoprinttext(140, 12, "U P D A T E  D A T A");
                menuUpdateDataAlat();  // Menampilkan menu opsi update
                SpecialkeyDashboardMenuUpdateDataAlat(&output);  // Ambil input opsi update

                switch (output) {
                    case 1:  // Update Nama Kelas
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15,12);
                        printf("Masukan No. Telepon:");
                        gotoxy(154, 24);
                        getinput(alt.nama_Alat, 25, 2);
                        hideCursor();
                        fwrite(&alt, sizeof(alt), 1, ft);
                        MessageBox(NULL, "Nama Alat Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    while (fread(&alt, sizeof(alt), 1, arspalat) == 1) {
                        fwrite(&alt, sizeof(alt), 1, ft);
                    }
                    fclose(arspalat);
                    fclose(ft);
                    remove("../Source/../Database/Dat/alatkesehatan.dat");
                    rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/alatkesehatan.dat");
                    break;

                    case 2:  // Update Harga Alat
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15, 12);
                        printf("Masukkan Harga Alat Baru: ");
                        gotoxy(154, 24);
                        getRp(&alt.harga_Alat,4,9,79,21);  // Ambil input harga baru
                        hideCursor();
                        MessageBox(NULL, "Harga Alat Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        while (fread(&alt, sizeof(alt), 1, arspalat) == 1) {
                            fwrite(&alt, sizeof(alt), 1, ft);
                        }
                        fclose(arspalat);
                        fclose(ft);
                        remove("../Source/../Database/Dat/alatkesehatan.dat");
                        rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/alatkesehatan.dat");
                        break;

                    case 3:  // Update Jumlah Alat
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(15, 12);
                        printf("Masukkan Jumlah Alat: ");
                        gotoxy(154, 24);
                        scanf("%d", &alt.jumlahAlat);  // Ambil input tingkat kelas baru
                        hideCursor();
                        MessageBox(NULL, "Jumlah Alat Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    while (fread(&alt, sizeof(alt), 1, arspalat) == 1) {
                        fwrite(&alt, sizeof(alt), 1, ft);
                    }
                    fclose(arspalat);
                    fclose(ft);
                    remove("../Source/../Database/Dat/alatkesehatan.dat");
                    rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/alatkesehatan.dat");
                    break;
                    case 4 :
                        fclose(arspalat);
                        fclose(ft);
                        BlankDashboard();
                        dataPenjualanMenu();
                    break;
                }
            }
            else {
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
                fclose(arspalat);
                updateAlat();
            }
        break;
        case 2:
            BlankDashboard();
        menuUpdateDataModifikasiAlat();
    }
}

void menuUpdateDataModifikasiAlat(){
    char exit[2] = "y";
    SetColorBlock(4,15);
    //DrawFile(48,9,"../Source/../Desaintxt/Dashboard/updatedata.txt");
    DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    do {
        BlankDashboard();
        tampilanCRUDAlat();
        DashboardCRUD();
        readUpdateDataAlat();
        updateAlat();
        clearTengah();
        tampilanCRUDAlat();
        readUpdateDataAlat();
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