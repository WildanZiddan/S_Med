void deleteStaffOwner(){
    SetColorBlock(15,12);
    gotoxy(136,38);
    printf("Ketik 0 untuk batal delete");
    gotoxy(140,22);
    showCursor();
    printf("D E L E T E  D A T A");
    gotoxy(132,24);
    printf("Masukkan ID STAFF: STF");
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
            arspstaff = fopen("../Source/../Database/Dat/staff.dat", "rb");
            ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
            found = 0;
            while (found == 0 && fread(&k, sizeof(k), 1, arspstaff) == 1) {
                if (k.idStaff == id && strcmp(k.role,"Owner")==0 || strcmp(k.role,"Kasir")==0 || strcmp(k.role,"Apoteker")==0) {
                    found = 1;
                }else {
                    fwrite(&k, sizeof(k), 1, ft);
                }
            }
            if(found){
                clearKanan();
                MessageBox(NULL,"ID Staff ditemukan!","Delete Berhasil!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                clearTengah();
                DashboardDetail(55,102,10,31,103,56,32,11);
                seluruhDataOwner();
                gotoxy(72,14);
                generateid("STF",k.idStaff);
                gotoxy(72,16);printf("%s",k.FName);
                gotoxy(72,18);printf("%s",k.No_telp);
                gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
                gotoxy(72,22);printf("%s",k.username);
                gotoxy(72,24);printf("%s",k.password);
                SetColorBlock(4,15);
                gotoxy(65,36);printf("Detail Data yang anda hapus");
                gotoxy(62,37);printf("Klik apa saja untuk melanjutkan...");
                getch();
                cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
                if(cancel == IDOK) {
                    while (fread(&k, sizeof(k), 1, arspstaff) == 1) {
                        fwrite(&k, sizeof(k), 1, ft);
                    }
                    fclose(arspstaff);
                    fclose(ft);
                    remove("../Source/../Database/Dat/staff.dat");
                    rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/staff.dat");
                }else if(cancel == IDCANCEL){
                    fclose(arspstaff);
                    fclose(ft);
                    remove("../Source/../Database/Dat/temp.dat");
                    BlankDashboard();
                    menuDeleteDataModifikasiOwner();
                }
            }else{
                MessageBox(NULL,"ID Staff Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
                clearKanan();
                deleteStaffOwner();
            }
            break;
        case 2:
            BlankDashboard();
            menuOpsiDashboardOwner();
            break;
    }
}


// void deleteKaryawanAdmin(){
//     SetColorBlock(7,9);
//     gotoxy(136,38);
//     printf("Ketik 0 untuk batal delete");
//     gotoxy(140,22);
//     showCursor();
//     printf("D E L E T E  D A T A");
//     gotoxy(132,24);
//     printf("Masukkan ID Karyawan: ADM");
//     gotoxy(157,24);
//     getnum(&id,3);
//     hideCursor();
//     if(id == 0){
//         BlankDashboard();
//         menuDeleteDataModifikasiManajer();
//     }
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_admin == id && strcmp(k.role,"Admin")==0) {
//                     found = 1;
//                 }else {
//                     fwrite(&k, sizeof(k), 1, ft);
//                 }
//             }
//             if(found){
//                 clearKanan();
//                 MessageBox(NULL,"ID Karyawan ditemukan!","Delete Berhasil!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataAdmin();
//                 gotoxy(72,14);printf("ADM%d",k.id_Karyawan.id_admin);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);rupiah(k.benefit,inputrp);
//                 printf("%s",inputrp);
//                 SetColorBlock(1,7);
//                 gotoxy(65,36);printf("Detail Data yang anda hapus");
//                 gotoxy(62,37);printf("Klik apa saja untuk melanjutkan...");
//                 getch();
//                 cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
//                 if(cancel == IDOK) {
//                     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                         fwrite(&k, sizeof(k), 1, ft);
//                     }
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/karyawan.dat");
//                     rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                 }else if(cancel == IDCANCEL){
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/temp.dat");
//                     BlankDashboard();
//                     menuDeleteDataModifikasiManajer();
//                 }
//             }
//             if(!found){
//                 MessageBox(NULL,"ID Karyawan Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
//                 clearKanan();
//                 deleteKaryawanAdmin();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuDeleteDataModifikasiManajer();
//             break;
//     }}
//
// void deleteKaryawankasir(){
//     SetColorBlock(7,9);
//     gotoxy(136,38);
//     printf("Ketik 0 untuk batal delete");
//     gotoxy(140,22);
//     showCursor();
//     printf("D E L E T E  D A T A");
//     gotoxy(132,24);
//     printf("Masukkan ID Karyawan: KSR");
//     gotoxy(157,24);
//     getnum(&id,3);
//     hideCursor();
//     if(id == 0){
//         BlankDashboard();
//         menuDeleteDataModifikasiManajer();
//     }
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_kasir && strcmp(k.role,"Kasir")==0) {
//                     found = 1;
//                 }else {
//                     fwrite(&k, sizeof(k), 1, ft);
//                 }
//             }
//             if(found){
//                 clearKanan();
//                 MessageBox(NULL,"ID Karyawan ditemukan!","Delete Berhasil!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataAdmin();
//                 gotoxy(72,14);printf("KSR%d",k.id_Karyawan.id_kasir);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);
//                 printf("%d",k.loket);
//                 SetColorBlock(1,7);
//                 gotoxy(65,36);printf("Detail Data yang anda hapus");
//                 gotoxy(62,37);printf("Klik apa saja untuk melanjutkan...");
//                 getch();
//                 cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
//                 if(cancel == IDOK) {
//                     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                         fwrite(&k, sizeof(k), 1, ft);
//                     }
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/karyawan.dat");
//                     rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                 }else if(cancel == IDCANCEL){
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/temp.dat");
//                     BlankDashboard();
//                     menuDeleteDataModifikasiManajer();
//                 }
//             }else{
//                 MessageBox(NULL,"ID Karyawan Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
//                 clearKanan();
//                 deleteKaryawankasir();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuDeleteDataModifikasiManajer();
//             break;
//     }
// }

void menuDeleteDataModifikasiOwner(){
    char exit[2] = "y";
    SetColorBlock(4,15);
    //DrawFile(48,9,"../Source/../Desaintxt/Dashboard/dataStaff.txt");
    //DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,38,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,38,220);
    frameLayout(119,18,120,38,220);
    frameLayout(60,37,120,38,223);
    SetColorBlock(15,12);
    SpecialkeyDashboardMenuDataOwner(79,24,20,3,&output);
    switch (output) {
        case 1:
            BlankDashboard();
            SetColorBlock(4,12);
            tampilanCRUDStaff();
            DashboardCRUD();
            readUpdateDataOwner();
            do {
                deleteStaffOwner();
                clearTengah();
                tampilanCRUDStaff();
                readUpdateDataOwner();
                clearKanan();
                SetColorBlock(15,12);
                gotoxy(135,23);printf("Anda Ingin Menghapus data lagi ?");
                SpecialKeyYesorNoDashboard(153, 25,10,15,12,&output);
                clearKanan();
            }while(output == 1);
            hideCursor();
            SetColorBlock(15,12);
            gotoprinttext(116,40,"K E M B A L I");
            if(getch()){
                BlankDashboard();
                menuDeleteDataModifikasiOwner();
            }
            break;
        // case 2:
        //     BlankDashboard();
        //     SetColorBlock(1,9);
        //     tampilanCRUDKaryawan();
        //     DashboardCRUD();
        //     readUpdateDataAdmin();
        //     do {
        //         deleteKaryawanAdmin();
        //         clearTengah();
        //         tampilanCRUDKaryawan();
        //         readUpdateDataAdmin();
        //         clearKanan();
        //         SetColorBlock(7,9);
        //         gotoxy(135,23);printf("Anda Ingin Menghapus data lagi ?");
        //         SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
        //     }while(output == 1);
        //     hideCursor();
        //     SetColorBlock(7,9);
        //     gotoprinttext(116,40,"K E M B A L I");
        //     if(getch()){
        //         BlankDashboard();
        //         menuDeleteDataModifikasiManajer();
        //     }
        //     break;
        // case 3:
        //     BlankDashboard();
        //     SetColorBlock(1,9);
        //     tampilanCRUDKaryawan();
        //     DashboardCRUD();
        //     readUpdateDataKasir();
        //     do {
        //         deleteKaryawankasir();
        //         clearTengah();
        //         tampilanCRUDKaryawan();
        //         readUpdateDataKasir();
        //         clearKanan();
        //         SetColorBlock(7,9);
        //         gotoxy(135,23);printf("Anda Ingin Menghapus data lagi ?");
        //         SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
        //     }while(output == 1);
        //     hideCursor();
        //     SetColorBlock(7,9);
        //     gotoprinttext(116,40,"K E M B A L I");
        //     if(getch()){
        //         BlankDashboard();
        //         menuDeleteDataModifikasiManajer();
        //     }
        //     break;
        case 4:
            hideCursor();
            BlankDashboard();
            dataStaffMenu();
            break;
    }
}

// void deleteKaryawanManajerAdmin(){
//     SetColorBlock(7,9);
//     gotoxy(136,38);
//     printf("Ketik 0 untuk batal delete");
//     gotoxy(140,22);
//     showCursor();
//     printf("D E L E T E  D A T A");
//     gotoxy(132,24);
//     printf("Masukkan ID Karyawan: MJR");
//     gotoxy(157,24);
//     getnum(&id,3);
//     hideCursor();
//     if(id == 0) {
//         BlankDashboard();
//         menuDeleteDataModifikasiAdmin();
//     }
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_manajer == id && strcmp(k.role,"Manajer")==0) {
//                     found = 1;
//                 }else {
//                     fwrite(&k, sizeof(k), 1, ft);
//                 }
//             }
//             if(found){
//                 clearKanan();
//                 MessageBox(NULL,"ID Karyawan ditemukan!","Delete Berhasil!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataManajer();
//                 gotoxy(72,14);printf("MJR%d",k.id_Karyawan.id_manajer);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);rupiah(k.tunjangan,inputrp);
//                 printf("%s",inputrp);
//                 SetColorBlock(1,7);
//                 gotoxy(65,36);printf("Detail Data yang anda hapus");
//                 gotoxy(62,37);printf("Klik apa saja untuk melanjutkan...");
//                 getch();
//                 cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
//                 if(cancel == IDOK) {
//                     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                         fwrite(&k, sizeof(k), 1, ft);
//                     }
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/karyawan.dat");
//                     rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                 }else if(cancel == IDCANCEL){
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/temp.dat");
//                     BlankDashboard();
//                     menuDeleteDataModifikasiAdmin();
//                 }
//             }
//             if(!found){
//                 MessageBox(NULL,"ID Karyawan Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
//                 clearKanan();
//                 deleteKaryawanManajerAdmin();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuDeleteDataModifikasiAdmin();
//             break;
//     }
// }
//
//
// void deleteKaryawanAdminAdmin(){
//     SetColorBlock(7,9);
//     gotoxy(136,38);
//     printf("Ketik 0 untuk batal delete");
//     gotoxy(140,22);
//     showCursor();
//     printf("D E L E T E  D A T A");
//     gotoxy(132,24);
//     printf("Masukkan ID Karyawan: ADM");
//     gotoxy(157,24);
//     getnum(&id,3);
//     hideCursor();
//     if(id == 0) {
//         BlankDashboard();
//         menuDeleteDataModifikasiAdmin();
//     }
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_admin == id && strcmp(k.role,"Admin")==0) {
//                     found = 1;
//                 }else {
//                     fwrite(&k, sizeof(k), 1, ft);
//                 }
//             }
//             if(found){
//                 clearKanan();
//                 MessageBox(NULL,"ID Karyawan ditemukan!","Delete Berhasil!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataAdmin();
//                 gotoxy(72,14);printf("ADM%d",k.id_Karyawan.id_admin);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);rupiah(k.benefit,inputrp);
//                 printf("%s",inputrp);
//                 SetColorBlock(1,7);
//                 gotoxy(65,36);printf("Detail Data yang anda hapus");
//                 gotoxy(62,37);printf("Klik apa saja untuk melanjutkan...");
//                 getch();
//                 cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
//                 if(cancel == IDOK) {
//                     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                         fwrite(&k, sizeof(k), 1, ft);
//                     }
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/karyawan.dat");
//                     rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                 }else if(cancel == IDCANCEL){
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/temp.dat");
//                     BlankDashboard();
//                     menuDeleteDataModifikasiAdmin();
//                 }
//             }
//             if(!found){
//                 MessageBox(NULL,"ID Karyawan Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
//                 clearKanan();
//                 deleteKaryawanAdminAdmin();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuDeleteDataModifikasiAdmin();
//             break;
//     }
// }
//
//
// void deleteKaryawankasirAdmin(){
//     SetColorBlock(7,9);
//     gotoxy(136,38);
//     printf("Ketik 0 untuk batal delete");
//     gotoxy(140,22);
//     showCursor();
//     printf("D E L E T E  D A T A");
//     gotoxy(132,24);
//     printf("Masukkan ID Karyawan: KSR");
//     gotoxy(157,24);
//     getnum(&id,3);
//     hideCursor();
//     if(id == 0) {
//         BlankDashboard();
//         menuDeleteDataModifikasiAdmin();
//     }
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_kasir == id && strcmp(k.role,"Kasir")==0) {
//                     found = 1;
//                 }else {
//                     fwrite(&k, sizeof(k), 1, ft);
//                 }
//             }
//
//             if(found){
//                 clearKanan();
//                 MessageBox(NULL,"ID Karyawan ditemukan!","Delete Berhasil!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataAdmin();
//                 gotoxy(72,14);printf("KSR%d",k.id_Karyawan.id_kasir);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);
//                 printf("%d",k.loket);
//                 SetColorBlock(1,7);
//                 gotoxy(65,36);printf("Detail Data yang anda hapus");
//                 gotoxy(62,37);printf("Klik apa saja untuk melanjutkan...");
//                 getch();
//                 cancel = MessageBox(NULL,"Anda yakin ingin menghapus?","DELETE DATA",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
//                 if(cancel == IDOK) {
//                     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                         fwrite(&k, sizeof(k), 1, ft);
//                     }
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/karyawan.dat");
//                     rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                 }else if(cancel == IDCANCEL){
//                     fclose(arspkaryawan);
//                     fclose(ft);
//                     remove("../Source/../Database/Dat/temp.dat");
//                     BlankDashboard();
//                     menuDeleteDataModifikasiAdmin();
//                 }
//             }else{
//                 MessageBox(NULL,"ID Karyawan Tidak ditemukan!","Delete Gagal!",MB_OK|MB_ICONERROR|MB_DEFAULT_DESKTOP_ONLY);
//                 clearKanan();
//                 deleteKaryawankasirAdmin();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuDeleteDataModifikasiAdmin();
//             break;
//     }
// }
//
//
// void menuDeleteDataModifikasiAdmin(){
//     char exit[2] = "y";
//     SetColorBlock(1,7);
//     DrawFile(48,9,"../Source/../Desaintxt/Dashboard/dataKaryawan.txt");
//     DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
//     SetColorBlock(9,9);
//     frameLayout(60,18,120,38,32);
//     SetColorBlock(7,1);
//     frameLayout(60,18,120,19,220);
//     frameLayout(60,18,61,38,220);
//     frameLayout(119,18,120,38,220);
//     frameLayout(60,37,120,38,223);
//     SetColorBlock(7,9);
//     SpecialkeyDashboardMenuDataManajer(79,24,20,3,&output);
//     switch (output) {
//         case 1:
//             BlankDashboard();
//             SetColorBlock(1,9);
//             tampilanCRUDKaryawan();
//             DashboardCRUD();
//             readUpdateDataManajer();
//             do {
//                 deleteKaryawanManajerAdmin();
//                 clearTengah();
//                 tampilanCRUDKaryawan();
//                 readUpdateDataManajer();
//                 clearKanan();
//                 SetColorBlock(7,9);
//                 gotoxy(135,23);printf("Anda Ingin Menghapus data lagi ?");
//                 SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
//             }while(output == 1);
//             hideCursor();
//             SetColorBlock(7,9);
//             gotoprinttext(116,40,"K E M B A L I");
//             if(getch()){
//                 BlankDashboard();
//                 menuDeleteDataModifikasiAdmin();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             SetColorBlock(1,9);
//             tampilanCRUDKaryawan();
//             DashboardCRUD();
//             readUpdateDataAdmin();
//             do{
//                 deleteKaryawanAdminAdmin();
//                 clearTengah();
//                 tampilanCRUDKaryawan();
//                 readUpdateDataAdmin();
//                 clearKanan();
//                 SetColorBlock(7,9);
//                 gotoxy(135,23);printf("Anda Ingin Menghapus data lagi ?");
//                 SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
//             }while(output == 1);
//             hideCursor();
//             SetColorBlock(7,9);
//             gotoprinttext(116,40,"K E M B A L I");
//             if(getch()){
//                 BlankDashboard();
//                 menuDeleteDataModifikasiAdmin();
//             }
//             break;
//         case 3:
//             BlankDashboard();
//             SetColorBlock(1,9);
//             tampilanCRUDKaryawan();
//             DashboardCRUD();
//             readUpdateDataKasir();
//             do{
//                 deleteKaryawankasirAdmin();
//                 clearTengah();
//                 tampilanCRUDKaryawan();
//                 readUpdateDataKasir();
//                 clearKanan();
//                 SetColorBlock(7,9);
//                 gotoxy(135,23);printf("Anda Ingin Menghapus data lagi ?");
//                 SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
//             }while(output == 1);
//             hideCursor();
//             SetColorBlock(7,9);
//             gotoprinttext(116,40,"K E M B A L I");
//             if(getch()){
//                 BlankDashboard();
//                 menuDeleteDataModifikasiAdmin();
//             }
//             break;
//         case 4:
//             hideCursor();
//             BlankDashboard();
//             dataKaryawanMenuAdmin();
//             break;
//     }
// }
