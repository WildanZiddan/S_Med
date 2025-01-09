void SpecialkeyDashboardMenuUpdateDataOwner(int *output);
void menuUpdateDataModifikasiAdmin();
void updateDataOwner(){
    SetColorBlock(15,12);
    showCursor();
    gotoprinttext(140,22,"U P D A T E  D A T A");
    gotoxy(132,24);printf("Masukan ID Karyawan: OWN");
    gotoxy(156,24);
    getnum(&id,3);
    hideCursor();
    SpecialKeyUpdate(152,26,13,3,&output);
    switch (output) {
        case 1:
        arspstaff = fopen("../Source/../Database/Dat/staff.dat", "rb");
        ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
        found = 0;
        while (found == 0 && fread(&k, sizeof(k), 1, arspstaff) == 1) {
            if (k.idStaff.id_owner == id && strcmp(k.role,"Owner")==0) {
                MessageBox(NULL,"ID Owner Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
                found = 1;
            }else{
                fwrite(&k, sizeof(k), 1, ft);
                found = 0;
            }
        }
        if(found == 1){
            clearTengah();
            DashboardDetail(55,102,10,31,103,56,32,11);
            seluruhDataOwner();
            gotoxy(72,14);
            generateid("OWN",k.idStaff.id_owner);
            gotoxy(72,16);printf("%s",k.FName);
            gotoxy(72,18);printf("%s",k.No_telp);
            gotoxy(72,20);printf("%02d/%02d/%04d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
            gotoxy(72,22);printf("%s",k.username);
            gotoxy(72,24);printf("%s",k.password);
            //Menu update data
                clearKanan();
                SetColorBlock(7, 9);
                gotoprinttext(140, 12, "U P D A T E  D A T A");
                menuUpdateDataOwner();
                SpecialkeyDashboardMenuUpdateDataOwner(&output);
                switch (output) {
                    case 1:
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(7,9);
                        printf("Masukan No. Telepone:");
                        gotoxy(154, 24);
                        getinput(k.No_telp,14,3);
                        hideCursor();
                        fwrite(&k, sizeof(k), 1, ft);
                        MessageBox(NULL, "No Telepone Berhasil Diubah", "NOTIFICATION!",
                                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        while (fread(&k, sizeof(k), 1, arspstaff) == 1) {
                            fwrite(&k, sizeof(k), 1, ft);
                        }
                        fclose(arspstaff);
                        fclose(ft);
                        remove("../Source/../Database/Dat/staff.dat");
                        rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/staff.dat");
                        break;
                    // case 2:
                    //     clearKanan();
                    //     showCursor();
                    //     gotoxy(132, 24);
                    //     SetColorBlock(7,9);
                    //     printf("Masukan Gaji: Rp.");
                    //     gotoxy(150, 24);
                    //     getRp(&k.gaji,4,9,151,24);
                    //     hideCursor();
                    //     MessageBox(NULL, "Gaji Berhasil Diubah", "NOTIFICATION!",
                    //                MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                    //     fwrite(&k, sizeof(k), 1, ft);
                    //     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
                    //         fwrite(&k, sizeof(k), 1, ft);
                    //     }
                    //     fclose(arspkaryawan);
                    //     fclose(ft);
                    //     remove("../Source/../Database/Dat/karyawan.dat");
                    //     rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
                    //     break;
//                    case 3:
//                        clearKanan();
//                        do{
//                            showCursor();
//                            gotoxy(132, 24);
//                            SetColorBlock(7,9);
//                            printf("U S E R N A M E :");
//                            gotoxy(150, 24);
//                            getinput(tempk.username,18,1);
//                            hideCursor();
//                            found = 4;
//                            fp = fopen("../Source/../Database/Dat/karyawan.dat","rb");
//                            while(found == 4 && fread(&k,sizeof (k),1,fp)==1){
//                                if(strcmp(k.username,tempk.username)==0) {
//                                    found = 1;
//                                    MessageBox(NULL, "Username Sudah Ada!", "Duplikasi Username",
//                                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                                    for (i = 150; i < 169; i++) {
//                                        gotoprintchar(i, 24, 32);
//                                    }
//                                } else {
//                                    found = 4;
//                                }
//                            }
//                        }while (found == 1);
//                        if(found == 4){
//                            strcpy(k.username,tempk.username);
//                        }
//                        fclose(fp);
//                        hideCursor();
//                        arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//                        MessageBox(NULL, "Username Berhasil Diubah", "NOTIFICATION!",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                        fwrite(&k, sizeof(k), 1, ft);
//                        while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                            fwrite(&k, sizeof(k), 1, ft);
//                        }
//                        fclose(arspkaryawan);
//                        fclose(ft);
//                        remove("../Source/../Database/Dat/karyawan.dat");
//                        rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                        break;
                    case 3:
                        clearKanan();
                        showCursor();
                        gotoxy(132, 24);
                        SetColorBlock(7,9);
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
                        menuUpdateDataModifikasiOwner();
                        break;
                }
        } else {
            MessageBox(NULL,"ID Karyawan Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            SetColorBlock(9,9);
            for(i = 154; i < 169; i++){
                gotoprintchar(i,24,32);
            }
            for(i = 26; i < 29; i++) {
                for (j = 132; j < 169; j++){
                gotoprintchar(j, i, 32);
                }
            }
            updateDataOwner();
        }
        break;
        case 2:
            BlankDashboard();
            menuUpdateDataModifikasiOwner();
    }
}


// void updateDataAdmin(){
//     SetColorBlock(7,9);
//     showCursor();
//     gotoprinttext(140,22,"U P D A T E  D A T A");
//     gotoxy(132,24);printf("Masukan ID Karyawan: ADM");
//     gotoxy(156,24);getnum(&id,3);
//     hideCursor();
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_admin == id && strcmp(k.role,"Admin")==0) {
//                     MessageBox(NULL,"ID Karyawan Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                     found = 1;
//                 }else{
//                     fwrite(&k, sizeof(k), 1, ft);
//                     found = 0;
//                 }
//             }
//             if(found == 1){
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataAdmin();
//                 gotoxy(72,14);
//                 generateid("ADM",k.id_Karyawan.id_admin);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%02d/%02d/%04d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);rupiah(k.benefit,inputrp);
//                 printf("%s",inputrp);
//                     clearKanan();
//                     SetColorBlock(7, 9);
//                     gotoprinttext(140, 12, "U P D A T E  D A T A");
//                     menuUpdateDataManajer();
//                     SpecialkeyDashboardMenuUpdateDataManajer(&output);
//                     switch (output) {
//                         case 1:
//                             clearKanan();
//                             showCursor();
//                             gotoxy(132, 24);
//                             SetColorBlock(7,9);
//                             printf("Masukan No. Telepone:");
//                             gotoxy(154, 24);
//                             getinput(k.No_telp,14,3);
//                             hideCursor();
//                             MessageBox(NULL, "No Telepone Berhasil Diubah", "NOTIFICATION!",
//                                        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                             fwrite(&k, sizeof(k), 1, ft);
//                             while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                                 fwrite(&k, sizeof(k), 1, ft);
//                             }
//                             fclose(arspkaryawan);
//                             fclose(ft);
//                             remove("../Source/../Database/Dat/karyawan.dat");
//                             rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                             break;
//                         case 2:
//                             clearKanan();
//                             showCursor();
//                             gotoxy(132, 24);
//                             SetColorBlock(7,9);
//                             printf("Masukan Gaji: Rp.");
//                             gotoxy(151, 24);
//                             getRp(&k.gaji,4,9,151,24);
//                             hideCursor();
//                             MessageBox(NULL, "Gaji Berhasil Diubah", "NOTIFICATION!",
//                                        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                             fwrite(&k, sizeof(k), 1, ft);
//                             while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                                 fwrite(&k, sizeof(k), 1, ft);
//                             }
//                             fclose(arspkaryawan);
//                             fclose(ft);
//                             remove("../Source/../Database/Dat/karyawan.dat");
//                             rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                             break;
// //                        case 3:
// //                            clearKanan();
// //                            do{
// //                                fflush(stdin);
// //                                showCursor();
// //                                SetColorBlock(7,9);
// //                                gotoxy(132, 24);
// //                                printf("U S E R N A M E :");
// //                                gotoxy(152, 24);
// //                                getinput(tempk.username,20,1);
// //                                hideCursor();
// //                                found = 0;
// //                                fp = fopen("../Source/../Database/Dat/karyawan.dat","rb");
// //                                while(fread(&k,sizeof (k),1,fp)==1){
// //                                    if(strcmp(k.username,tempk.username)==0){
// //                                        found = 1;
// //                                        MessageBox(NULL, "Username Sudah Ada!", "Duplikasi Username",
// //                                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
// //                                        for (i = 69; i < 80; i++) {
// //                                            gotoprintchar(i, 27, 32);
// //                                        }
// //                                    }
// //                                    if(found == 0){
// //                                        strcpy(k.username,tempk.username);
// //                                    }
// //                                }
// //                                fclose(fp);
// //                            }while (found == 1);
// //                            MessageBox(NULL, "Username Berhasil Diubah", "NOTIFICATION!",
// //                                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
// //                            fwrite(&k, sizeof(k), 1, ft);
// //                            break;
//                         case 3:
//                             clearKanan();
//                             showCursor();
//                             gotoxy(132, 24);
//                             SetColorBlock(7,9);
//                             printf("Masukan Password:");
//                             gotoxy(150, 24);
//                             inputPass(k.password);
//                             hideCursor();
//                             MessageBox(NULL, "Password Berhasil Diubah", "NOTIFICATION!",
//                                        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                             fwrite(&k, sizeof(k), 1, ft);
//                             while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                                 fwrite(&k, sizeof(k), 1, ft);
//                             }
//                             fclose(arspkaryawan);
//                             fclose(ft);
//                             remove("../Source/../Database/Dat/karyawan.dat");
//                             rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                             break;
//                         case 4 :
//                             fclose(arspkaryawan);
//                             fclose(ft);
//                             BlankDashboard();
//                             menuUpdateDataModifikasiManajer();
//                             break;
//                     }
//             } else {
//                 MessageBox(NULL,"ID Karyawan Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 SetColorBlock(9,9);
//                 for(i = 154; i < 169; i++){
//                     gotoprintchar(i,24,32);
//                 }
//                 for(i = 26; i < 29; i++) {
//                     for (j = 132; j < 169; j++){
//                         gotoprintchar(j, i, 32);
//                     }
//                 }
//                 updateDataAdmin();
//             }
//
//             break;
//         case 2:
//             BlankDashboard();
//             menuUpdateDataModifikasiManajer();
//     }
// }
//
// void updateDataKasir(){
//     SetColorBlock(7,9);
//     showCursor();
//     gotoprinttext(140,22,"U P D A T E  D A T A");
//     gotoxy(132,24);printf("Masukan ID Karyawan: KSR");
//     gotoxy(156,24);
//     getnum(&id,3);
//     hideCursor();
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_kasir == id && strcmp(k.role,"Kasir")==0) {
//                     MessageBox(NULL,"ID Karyawan Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                     found = 1;
//                 }else{
//                     fwrite(&k, sizeof(k), 1, ft);
//                     found = 0;
//                 }
//             }
//             if(found == 1){
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataKasir();
//                 gotoxy(72,14);
//                 generateid("KSR",k.id_Karyawan.id_kasir);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%02d/%02d/%04d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);printf("%d",k.loket);
//                     clearKanan();
//                     SetColorBlock(7, 9);
//                     gotoprinttext(140, 12, "U P D A T E  D A T A");
//                     menuUpdateDataManajer();
//                     SpecialkeyDashboardMenuUpdateDataManajer(&output);
//                     switch (output) {
//                         case 1:
//                             clearKanan();
//                             showCursor();
//                             gotoxy(132, 24);
//                             SetColorBlock(7,9);
//                             printf("Masukan No. Telepone:");
//                             gotoxy(154, 24);
//                             getinput(k.No_telp,14,3);
//                             hideCursor();
//                             MessageBox(NULL, "No Telepone Berhasil Diubah", "NOTIFICATION!",
//                                        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                             fwrite(&k, sizeof(k), 1, ft);
//                             while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                                 fwrite(&k, sizeof(k), 1, ft);
//                             }
//                             fclose(arspkaryawan);
//                             fclose(ft);
//                             remove("../Source/../Database/Dat/karyawan.dat");
//                             rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                             break;
//                         case 2:
//                             clearKanan();
//                             showCursor();
//                             gotoxy(132, 24);
//                             SetColorBlock(7,9);
//                             printf("Masukan Gaji: Rp.");
//                             gotoxy(151, 24);
//                             getRp(&k.gaji,4,9,151,24);
//                             hideCursor();
//                             MessageBox(NULL, "Gaji Berhasil Diubah", "NOTIFICATION!",
//                                        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                             fwrite(&k, sizeof(k), 1, ft);
//                             while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                                 fwrite(&k, sizeof(k), 1, ft);
//                             }
//                             fclose(arspkaryawan);
//                             fclose(ft);
//                             remove("../Source/../Database/Dat/karyawan.dat");
//                             rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                             break;
//                        case 3:
//                            clearKanan();
//                            do{
//                                fflush(stdin);
//                                showCursor();
//                                gotoxy(132, 24);
//                                SetColorBlock(7,9);
//                                printf("U S E R N A M E :");
//                                gotoxy(152, 24);
//                                getinput(tempk.username,20,1);
//                                hideCursor();
//                                found = 0;
//                                fp = fopen("../Source/../Database/Dat/karyawan.dat","rb");
//                                while(fread(&k,sizeof (k),1,fp)==1){
//                                    if(strcmp(k.username,tempk.username)==0){
//                                        found = 1;
//                                        MessageBox(NULL, "Username Sudah Ada!", "Duplikasi Username",
//                                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                                        for (i = 69; i < 80; i++) {
//                                            gotoprintchar(i, 27, 32);
//                                        }
//                                    }
//                                    if(found == 0){
//                                        strcpy(k.username,tempk.username);
//                                    }
//                                }
//                                fclose(fp);
//                            }while (found == 1);
//
//                            MessageBox(NULL, "Username Berhasil Diubah", "NOTIFICATION!",
//                                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                            fwrite(&k, sizeof(k), 1, ft);
//                            break;
//                         case 3:
//                             clearKanan();
//                             showCursor();
//                             gotoxy(132, 24);
//                             SetColorBlock(7,9);
//                             printf("Masukan Password:");
//                             gotoxy(150, 24);
//                             inputPass(k.password);
//                             hideCursor();
//                             MessageBox(NULL, "Password Berhasil Diubah", "NOTIFICATION!",
//                                        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                             fwrite(&k, sizeof(k), 1, ft);
//                             while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                                 fwrite(&k, sizeof(k), 1, ft);
//                             }
//                             fclose(arspkaryawan);
//                             fclose(ft);
//                             remove("../Source/../Database/Dat/karyawan.dat");
//                             rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                             break;
//                         case 4 :
//                             fclose(arspkaryawan);
//                             fclose(ft);
//                             BlankDashboard();
//                             menuUpdateDataModifikasiManajer();
//                             break;
//                     }
//             } else {
//                 MessageBox(NULL,"ID Karyawan Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 SetColorBlock(9,9);
//                 for(i = 154; i < 169; i++){
//                     gotoprintchar(i,24,32);
//                 }
//                 for(i = 26; i < 29; i++) {
//                     for (j = 132; j < 169; j++){
//                         gotoprintchar(j, i, 32);
//                     }
//                 }
//                 updateDataKasir();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuUpdateDataModifikasiManajer();
//     }
// }

void menuUpdateDataModifikasiOwner(){
    char exit[2] = "y";
    SetColorBlock(1,7);
    DrawFile(48,9,"../Source/../Desaintxt/Dashboard/updatedata.txt");
    DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
    SetColorBlock(9,9);
    frameLayout(60,18,120,38,32);
    SetColorBlock(7,1);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,38,220);
    frameLayout(119,18,120,38,220);
    frameLayout(60,37,120,38,223);
    SetColorBlock(7,9);
    SpecialkeyDashboardMenuDataOwner(79,24,20,3,&output);
    switch (output) {
        case 1:
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
                SetColorBlock(7,9);
                gotoxy(135,23);printf("Anda Ingin Mengupdate Data Lagi?");
                SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
            }while(output == 1);
            clearKanan();
            SetColorBlock(7,9);
            gotoprinttext(114,40,"K E M B A L I");
            if(getch()){
                BlankDashboard();
                menuUpdateDataModifikasiOwner();
            }
            break;
        // case 2:
        //     do {
        //         hideCursor();
        //         BlankDashboard();
        //         tampilanCRUDStaff();
        //         DashboardCRUD();
        //         readUpdateDataAdmin();
        //         updateDataAdmin();
        //         clearTengah();
        //         tampilanCRUDKaryawan();
        //         readUpdateDataAdmin();
        //         clearKanan();
        //         SetColorBlock(7,9);
        //         gotoxy(135,23);printf("Anda Ingin Mengupdate Data Lagi?");
        //         SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
        //     }while(output == 1);
        //     clearKanan();
        //     SetColorBlock(7,9);
        //     gotoprinttext(114,40,"K E M B A L I");
        //     if(getch()){
        //         BlankDashboard();
        //         menuUpdateDataModifikasiOwner();
        //     }
        //     break;
        // case 3:
        //     do{
        //     hideCursor();
        //     BlankDashboard();
        //     tampilanCRUDStaff();
        //     DashboardCRUD();
        //     // readUpdateDataKasir();
        //     // updateDataKasir();
        //     clearTengah();
        //     tampilanCRUDKaryawan();
        //     // readUpdateDataKasir();
        //     clearKanan();
        //     SetColorBlock(7,9);
        //     gotoxy(135,23);printf("Anda Ingin Mengupdate Data Lagi?");
        //     SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
        //     }while(output == 1);
        //     clearKanan();
        //     clearKanan();
        //     SetColorBlock(7,9);
        //     gotoprinttext(114,40,"K E M B A L I");
        //     if(getch()){
        //         BlankDashboard();
        //         menuUpdateDataModifikasiOwner();
        //     }
        //break;
        case 4:
            hideCursor();
            BlankDashboard();
            dataStaffMenu();
            break;
    }
}

// void updateDataManajerAdmin(){
//     SetColorBlock(7,9);
//     showCursor();
//     gotoprinttext(140,22,"U P D A T E  D A T A");
//     gotoxy(132,24);printf("Masukan ID Karyawan: MJR");
//     gotoxy(158,24);
//     getnum(&id,3);
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_manajer == id && strcmp(k.role,"Manajer")==0) {
//                     MessageBox(NULL,"ID Karyawan Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                     found = 1;
//                 }else{
//                     fwrite(&k, sizeof(k), 1, ft);
//                     found = 0;
//                 }
//             }
//
//             if(found == 1){
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataManajer();
//                 gotoxy(72,14);
//                 generateid("MJR",k.id_Karyawan.id_manajer);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);rupiah(k.tunjangan,inputrp);
//                 printf("%s",inputrp);
//                 clearKanan();
//                 SetColorBlock(7, 9);
//                 gotoprinttext(140, 12, "U P D A T E  D A T A");
//                 menuUpdateDataManajer();
//                 SpecialkeyDashboardMenuUpdateDataManajer(&output);
//                 switch (output) {
//                     case 1:
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(7,9);
//                         printf("Masukan No. Telepone:");
//                         gotoxy(154, 24);
//                         getinput(k.No_telp,14,3);
//                         hideCursor();
//                         MessageBox(NULL, "No Telepone Berhasil Diubah", "NOTIFICATION!",
//                                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&k, sizeof(k), 1, ft);
//                         while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                             fwrite(&k, sizeof(k), 1, ft);
//                         }
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         remove("../Source/../Database/Dat/karyawan.dat");
//                         rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                         break;
//                     case 2:
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(7,9);
//                         printf("Masukan Gaji: Rp.");
//                         gotoxy(151, 24);
//                         getnumfloat(&k.gaji,12);
//                         hideCursor();
//                         MessageBox(NULL, "Gaji Berhasil Diubah", "NOTIFICATION!",
//                                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&k, sizeof(k), 1, ft);
//                         while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                             fwrite(&k, sizeof(k), 1, ft);
//                         }
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         remove("../Source/../Database/Dat/karyawan.dat");
//                         rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                         break;
//                    case 3:
//                        clearKanan();
//                        do{
//                            fflush(stdin);
//                            showCursor();
//                            SetColorBlock(7,9);
//                            gotoxy(132, 24);
//                            printf("U S E R N A M E :");
//                            gotoxy(152, 24);
//                            getinput(tempk.username,20,1);
//                            hideCursor();
//                            found = 0;
//                            fp = fopen("../Source/../Database/Dat/karyawan.dat","rb");
//                            while(fread(&k,sizeof (k),1,fp)==1){
//                                if(strcmp(k.username,tempk.username)==0){
//                                    found = 1;
//                                    MessageBox(NULL, "Username Sudah Ada!", "Duplikasi Username",
//                                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                                    for (i = 69; i < 80; i++) {
//                                        gotoprintchar(i, 27, 32);
//                                    }
//                                }
//                                if(found == 0){
//                                    strcpy(k.username,tempk.username);
//                                }
//                            }
//                            fclose(fp);
//                        }while (found == 1);
//                        MessageBox(NULL, "Username Berhasil Diubah", "NOTIFICATION!",
//                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                        fwrite(&k, sizeof(k), 1, ft);
//                        break;
//                     case 3:
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(7,9);
//                         printf("Masukan Password:");
//                         gotoxy(150, 24);
//                         inputPass(k.password);
//                         hideCursor();
//                         MessageBox(NULL, "Password Berhasil Diubah", "NOTIFICATION!",
//                                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&k, sizeof(k), 1, ft);
//                         while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                             fwrite(&k, sizeof(k), 1, ft);
//                         }
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         remove("../Source/../Database/Dat/karyawan.dat");
//                         rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                         break;
//                     case 4 :
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         BlankDashboard();
//                         menuUpdateDataModifikasiAdmin();
//                         break;
//                 }
//             } else {
//                 MessageBox(NULL,"ID Karyawan Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 SetColorBlock(9,9);
//                 for(i = 154; i < 169; i++){
//                     gotoprintchar(i,24,32);
//                 }
//                 for(i = 26; i < 29; i++) {
//                     for (j = 132; j < 169; j++){
//                         gotoprintchar(j, i, 32);
//                     }
//                 }
//                 updateDataManajerAdmin();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuUpdateDataModifikasiAdmin();
//     }
//
// }
//
//
// void updateDataAdminAdmin(){
//     SetColorBlock(7,9);
//     showCursor();
//     gotoprinttext(140,22,"U P D A T E  D A T A");
//     gotoxy(132,24);printf("Masukan ID Karyawan: ADM");
//     gotoxy(158,24);
//     getnum(&id,3);
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_admin == id && strcmp(k.role,"Admin")==0) {
//                     MessageBox(NULL,"ID Karyawan Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                     found = 1;
//                 }else{
//                     fwrite(&k, sizeof(k), 1, ft);
//                     found = 0;
//                 }
//             }
//             if(found == 1){
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataAdmin();
//                 gotoxy(72,14);
//                 generateid("ADM",k.id_Karyawan.id_admin);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);rupiah(k.benefit,inputrp);
//                 printf("%s",inputrp);
//                 clearKanan();
//                 SetColorBlock(7, 9);
//                 gotoprinttext(140, 12, "U P D A T E  D A T A");
//                 menuUpdateDataManajer();
//                 SpecialkeyDashboardMenuUpdateDataManajer(&output);
//                 switch (output) {
//                     case 1:
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(7,9);
//                         printf("Masukan No. Telepone:");
//                         gotoxy(154, 24);
//                         getinput(k.No_telp,14,3);
//                         hideCursor();
//                         MessageBox(NULL, "No Telepone Berhasil Diubah", "NOTIFICATION!",
//                                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&k, sizeof(k), 1, ft);
//                         while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                             fwrite(&k, sizeof(k), 1, ft);
//                         }
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         remove("../Source/../Database/Dat/karyawan.dat");
//                         rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                         break;
//                     case 2:
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(7,9);
//                         printf("Masukan Gaji: Rp.");
//                         gotoxy(151, 24);
//                         getnumfloat(&k.gaji,12);
//                         hideCursor();
//                         MessageBox(NULL, "Gaji Berhasil Diubah", "NOTIFICATION!",
//                                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&k, sizeof(k), 1, ft);
//                         while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                             fwrite(&k, sizeof(k), 1, ft);
//                         }
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         remove("../Source/../Database/Dat/karyawan.dat");
//                         rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                         break;
//                    case 3:
//                        clearKanan();
//                        do{
//                            fflush(stdin);
//                            showCursor();
//                            SetColorBlock(7,9);
//                            gotoxy(132, 24);
//                            printf("U S E R N A M E :");
//                            gotoxy(152, 24);
//                            getinput(tempk.username,20,1);
//                            hideCursor();
//                            found = 0;
//                            fp = fopen("../Source/../Database/Dat/karyawan.dat","rb");
//                            while(fread(&k,sizeof (k),1,fp)==1){
//                                if(strcmp(k.username,tempk.username)==0){
//                                    found = 1;
//                                    MessageBox(NULL, "Username Sudah Ada!", "Duplikasi Username",
//                                               MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                                    for (i = 69; i < 80; i++) {
//                                        gotoprintchar(i, 27, 32);
//                                    }
//                                }
//                                if(found == 0){
//                                    strcpy(k.username,tempk.username);
//                                }
//                            }
//                            fclose(fp);
//                        }while (found == 1);
//                        MessageBox(NULL, "Username Berhasil Diubah", "NOTIFICATION!",
//                                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                        fwrite(&k, sizeof(k), 1, ft);
//                        break;
//                     case 3:
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(7,9);
//                         printf("Masukan Password:");
//                         gotoxy(150, 24);
//                         inputPass(k.password);
//                         hideCursor();
//                         MessageBox(NULL, "Password Berhasil Diubah", "NOTIFICATION!",
//                                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&k, sizeof(k), 1, ft);
//                         while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                             fwrite(&k, sizeof(k), 1, ft);
//                         }
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         remove("../Source/../Database/Dat/karyawan.dat");
//                         rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                         break;
//                     case 4 :
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         BlankDashboard();
//                         menuUpdateDataModifikasiAdmin();
//                         break;
//                 }
//             } else {
//                 MessageBox(NULL,"ID Karyawan Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 SetColorBlock(9,9);
//                 for(i = 154; i < 169; i++){
//                     gotoprintchar(i,24,32);
//                 }
//                 for(i = 26; i < 29; i++) {
//                     for (j = 132; j < 169; j++){
//                         gotoprintchar(j, i, 32);
//                     }
//                 }
//                 updateDataAdminAdmin();
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuUpdateDataModifikasiAdmin();
//     }
// }
//
// void updateDataKasirAdmin(){
//     SetColorBlock(7,9);
//     showCursor();
//     gotoprinttext(140,22,"U P D A T E  D A T A");
//     gotoxy(132,24);printf("Masukan ID Karyawan: KSR");
//     gotoxy(158,24);
//     getnum(&id,3);
//     hideCursor();
//     SpecialKeyUpdate(152,26,13,3,&output);
//     switch (output) {
//         case 1:
//             arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "rb");
//             ft = fopen("../Source/../Database/Dat/temp.dat", "wb");
//             found = 0;
//             while (found == 0 && fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 if (k.id_Karyawan.id_kasir == id && strcmp(k.role,"Kasir")==0) {
//                     MessageBox(NULL,"ID Karyawan Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                     found = 1;
//                 }else{
//                     fwrite(&k, sizeof(k), 1, ft);
//                     found = 0;
//                 }
//             }
//
//             if(found == 1){
//                 clearTengah();
//                 DashboardDetail(55,102,10,31,103,56,32,11);
//                 seluruhDataKasir();
//                 gotoxy(72,14);
//                 generateid("KSR",k.id_Karyawan.id_kasir);
//                 gotoxy(72,16);printf("%s",k.FName);
//                 gotoxy(72,18);printf("%s",k.No_telp);
//                 gotoxy(72,20);printf("%d/%d/%d",k.tanggalLahir.hari,k.tanggalLahir.bulan,k.tanggalLahir.tahun);
//                 gotoxy(72,22);printf("%s",k.username);
//                 gotoxy(72,24);printf("%s",k.password);
//                 gotoxy(72,26);rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 gotoxy(72,28);printf("%d",k.loket);
//                 clearKanan();
//                 SetColorBlock(7, 9);
//                 gotoprinttext(140, 12, "U P D A T E  D A T A");
//                 menuUpdateDataManajer();
//                 SpecialkeyDashboardMenuUpdateDataManajer(&output);
//                 switch (output) {
//                     case 1:
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(7,9);
//                         printf("Masukan No. Telepone:");
//                         gotoxy(154, 24);
//                         getinput(k.No_telp,14,3);
//                         hideCursor();
//                         MessageBox(NULL, "No Telepone Berhasil Diubah", "NOTIFICATION!",
//                                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&k, sizeof(k), 1, ft);
//                         while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                             fwrite(&k, sizeof(k), 1, ft);
//                         }
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         remove("../Source/../Database/Dat/karyawan.dat");
//                         rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                         break;
//
//                     case 3:
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(7,9);
//                         printf("Masukan Password:");
//                         gotoxy(150, 24);
//                         inputPass(k.password);
//                         hideCursor();
//                         MessageBox(NULL, "Password Berhasil Diubah", "NOTIFICATION!",
//                                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&k, sizeof(k), 1, ft);
//                         while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                             fwrite(&k, sizeof(k), 1, ft);
//                         }
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         remove("../Source/../Database/Dat/karyawan.dat");
//                         rename("../Source/../Database/Dat/temp.dat", "../Source/../Database/Dat/karyawan.dat");
//                         break;
//                     case 4 :
//                         fclose(arspkaryawan);
//                         fclose(ft);
//                         BlankDashboard();
//                         menuUpdateDataModifikasiAdmin();
//                         break;
//                 }
//             } else {
//                 MessageBox(NULL,"ID Karyawan Tidak Ditemukan","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 SetColorBlock(9,9);
//                 for(i = 154; i < 169; i++){
//                     gotoprintchar(i,24,32);
//                 }
//                 for(i = 26; i < 29; i++) {
//                     for (j = 132; j < 169; j++){
//                         gotoprintchar(j, i, 32);
//                     }
//                 }
//                 updateDataKasirAdmin();
//             }
//
//             while (fread(&k, sizeof(k), 1, arspkaryawan) == 1) {
//                 fwrite(&k, sizeof(k), 1, ft);
//             }
//             break;
//         case 2:
//             BlankDashboard();
//             menuUpdateDataModifikasiAdmin();
//     }
// }
//
//
//
// void menuUpdateDataModifikasiAdmin(){
//     char exit[2] = "y";
//     SetColorBlock(4,15);
//     DrawFile(48,9,"../Source/../Desaintxt/Dashboard/updatedata.txt");
//     DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
//     SetColorBlock(12,12);
//     frameLayout(60,18,120,38,32);
//     SetColorBlock(15,4);
//     frameLayout(60,18,120,19,220);
//     frameLayout(60,18,61,38,220);
//     frameLayout(119,18,120,38,220);
//     frameLayout(60,37,120,38,223);
//     SetColorBlock(15,12);
//     SpecialkeyDashboardMenuDataManajer(79,24,20,3,&output);
//     switch (output) {
//         case 1:
//             do{
//             BlankDashboard();
//             tampilanCRUDKaryawan();
//             DashboardCRUD();
//             readUpdateDataManajer();
//             updateDataManajerAdmin();
//             clearTengah();
//             tampilanCRUDStaff();
//             readUpdateDataOwner();
//                 clearKanan();
//                 SetColorBlock(15,12);
//                 gotoxy(135,23);printf("Anda Ingin Mengupdate Data Lagi?");
//                 SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
//             }while(output == 1);
//             clearKanan();
//             SetColorBlock(15,12);
//             gotoprinttext(114,40,"K E M B A L I");
//             if(getch()){
//                 BlankDashboard();
//                 menuUpdateDataModifikasiAdmin();
//             }
//             break;
        // case 2:
        //     do{
        //     hideCursor();
        //     BlankDashboard();
        //     tampilanCRUDKaryawan();
        //     DashboardCRUD();
        //     readUpdateDataAdmin();
        //     updateDataAdminAdmin();
        //     clearTengah();
        //     tampilanCRUDKaryawan();
        //     readUpdateDataAdmin();
        //         clearKanan();
        //         SetColorBlock(7,9);
        //         gotoxy(135,23);printf("Anda Ingin Mengupdate Data Lagi?");
        //         SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
        //     }while(output == 1);
        //     clearKanan();
        //     SetColorBlock(7,9);
        //     gotoprinttext(114,40,"K E M B A L I");
        //     if(getch()){
        //         BlankDashboard();
        //         menuUpdateDataModifikasiAdmin();
        //     }
        //     break;
        // case 3:
        //     do{
        //     hideCursor();
        //     BlankDashboard();
        //     tampilanCRUDKaryawan();
        //     DashboardCRUD();
        //     readUpdateDataKasir();
        //     updateDataKasirAdmin();
        //     clearTengah();
        //     tampilanCRUDKaryawan();
        //     readUpdateDataKasir();
        //         clearKanan();
        //         SetColorBlock(7,9);
        //         gotoxy(135,23);printf("Anda Ingin Mengupdate Data Lagi?");
        //         SpecialKeyYesorNoDashboard(153, 25,10,7,9,&output);
        //     }while(output == 1);
        //     clearKanan();
        //     SetColorBlock(7,9);
        //     gotoprinttext(114,40,"K E M B A L I");
        //     if(getch()){
        //         BlankDashboard();
        //         menuUpdateDataModifikasiAdmin();
        //     }
        //     break;
//         case 4:
//             hideCursor();
//             BlankDashboard();
//             dataKaryawanMenuAdmin();
//             break;
//     }
// }
