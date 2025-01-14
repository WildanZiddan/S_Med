void readUpdateDataOwner(){
    i = 1;
    y = 13;
    arspstaff = fopen("../Source/../Database/Dat/staff.dat", "rb+");
    while (fread(&k, sizeof(k), 1, arspstaff) == 1 ) {
            if (i % 2 == 0) {
                SetColorBlock(15,4);
                for(x = y; x <= y;x++){
                    for(j = 36; j < 128; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                gotoxy(38, y);
                printf("%d", i);
                gotoxy(47, y);
                generateid("STF",k.idStaff);
                gotoxy(64, y);
                printf("%s\n", k.FName);
                gotoxy(92, y);
                printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);

            }
            else {
                SetColorBlock(15, 12);
                for (x = y; x <= y; x++) {
                    for (j = 36; j < 128; j++) {
                        gotoprintchar(j, x, 32);
                    }
                }
                gotoxy(38, y);
                printf("%d", i);
                gotoxy(47, y);
                generateid("STF",k.idStaff);
                gotoxy(64, y);
                printf("%s\n", k.FName);
                gotoxy(92, y);
                printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
            }
            i++;
            y++;
        }
    fclose(arspstaff);
}

// void readUpdateDataAdmin(){
//     i = 1;
//     y = 13;
//     arspkaryawan = fopen("../Source/../Database/Dat/Karyawan.dat", "rb+");
//     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1 ) {
//         if(strcmp(k.role,"Admin")==0) {
//             if (i % 2 == 0) {
//                 SetColorBlock(7,1);
//                 for(x = y; x <= y;x++){
//                     for(j = 36; j < 128; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("ADM",k.id_Karyawan.id_admin);
//                 gotoxy(64, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(94, y);
//                 printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
//                 gotoxy(111, y);
//                 rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//             } else {
//                 SetColorBlock(7, 9);
//                 for (x = y; x <= y; x++) {
//                     for (j = 36; j < 128; j++) {
//                         gotoprintchar(j, x, 32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("ADM",k.id_Karyawan.id_admin);
//                 gotoxy(64, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(94, y);
//                 printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
//                 gotoxy(111, y);
//                 rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//             }
//             i++;
//             y++;
//         }
//     }
//     fclose(arspkaryawan);
// }
//
// void readUpdateDataKasir(){
//     i = 1;
//     y = 13;
//     arspkaryawan = fopen("../Source/../Database/Dat/Karyawan.dat", "rb+");
//     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1 ) {
//         if(strcmp(k.role,"Kasir")==0) {
//             if (i % 2 == 0) {
//                 SetColorBlock(7,1);
//                 for(x = y; x <= y;x++){
//                     for(j = 36; j < 128; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("KSR",k.id_Karyawan.id_kasir);
//                 gotoxy(64, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(92, y);
//                 printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
//                 gotoxy(111, y);
//                 rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//             } else {
//                 SetColorBlock(7, 9);
//                 for (x = y; x <= y; x++) {
//                     for (j = 36; j < 128; j++) {
//                         gotoprintchar(j, x, 32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("KSR",k.id_Karyawan.id_kasir);
//                 gotoxy(64, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(92, y);
//                 printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
//                 gotoxy(111, y);
//                 rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//             }
//             i++;
//             y++;
//         }
//     }
//     fclose(arspkaryawan);
// }

void readAkunDataOwner(){
    i = 1;
    y = 13;
    arspstaff = fopen("../Source/../Database/Dat/staff.dat", "rb+");
    while (fread(&k, sizeof(k), 1, arspstaff) == 1 ) {
            if (i % 2 == 0) {
                SetColorBlock(15,4);
                for(x = y; x <= y;x++){
                    for(j = 37; j < 167; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                gotoxy(38, y);
                printf("%d", i);
                gotoxy(47, y);
                generateid("STF",k.idStaff);
                gotoxy(75, y);
                printf("%s\n", k.FName);
                gotoxy(110, y);
                printf("%s\n", k.username);
                gotoxy(140, y);
                printf("%s\n", k.password);
            } else {
                SetColorBlock(15, 12);
                for (x = y; x <= y; x++) {
                    for (j = 37; j < 167; j++) {
                        gotoprintchar(j, x, 32);
                    }
                }
                gotoxy(38, y);
                printf("%d", i);
                gotoxy(47, y);
                generateid("STF",k.idStaff);
                gotoxy(75, y);
                printf("%s\n", k.FName);
                gotoxy(110, y);
                printf("%s\n", k.username);
                gotoxy(140, y);
                printf("%s\n", k.password);
            }
            i++;
            y++;
        }
    fclose(arspstaff);
    SetColorBlock(15,12);
    gotoprinttext(150,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,19,28,4);
        menuOpsiDashboardOwner();
    }
}

// void readAkunDataAdmin(){
//     i = 1;
//     y = 13;
//     arspkaryawan = fopen("../Source/../Database/Dat/Karyawan.dat", "rb+");
//     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1 ) {
//         if(strcmp(k.role,"Admin")==0) {
//             if (i % 2 == 0) {
//                 SetColorBlock(7,1);
//                 for(x = y; x <= y;x++){
//                     for(j = 37; j < 167; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("ADM",k.id_Karyawan.id_admin);
//                 gotoxy(75, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(110, y);
//                 printf("%s\n", k.username);
//                 gotoxy(140, y);
//                 printf("%s\n", k.password);
//             } else {
//                 SetColorBlock(7, 9);
//                 for (x = y; x <= y; x++) {
//                     for (j = 37; j < 167; j++) {
//                         gotoprintchar(j, x, 32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("ADM",k.id_Karyawan.id_admin);
//                 gotoxy(75, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(110, y);
//                 printf("%s\n", k.username);
//                 gotoxy(140, y);
//                 printf("%s\n", k.password);
//             }
//             i++;
//             y++;
//         }
//     }
//     fclose(arspkaryawan);
//     SetColorBlock(7,9);
//     gotoprinttext(150,40,"K E M B A L I");
//     if(getch()){
//         BlankDashboard();
//         dataAkun();
//     }
// }
//
// void readAkunDataKasir(){
//     i = 1;
//     y = 13;
//     arspkaryawan = fopen("../Source/../Database/Dat/Karyawan.dat", "rb+");
//     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1 ) {
//         if(strcmp(k.role,"Kasir")==0) {
//             if (i % 2 == 0) {
//                 SetColorBlock(7,1);
//                 for(x = y; x <= y;x++){
//                     for(j = 37; j < 167; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("KSR",k.id_Karyawan.id_kasir);
//                 gotoxy(75, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(110, y);
//                 printf("%s\n", k.username);
//                 gotoxy(140, y);
//                 printf("%s\n", k.password);
//             } else {
//                 SetColorBlock(7, 9);
//                 for (x = y; x <= y; x++) {
//                     for (j = 37; j < 167; j++) {
//                         gotoprintchar(j, x, 32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("KSR",k.id_Karyawan.id_kasir);
//                 gotoxy(75, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(110, y);
//                 printf("%s\n", k.username);
//                 gotoxy(140, y);
//                 printf("%s\n", k.password);
//             }
//             i++;
//             y++;
//         }
//     }
//     fclose(arspkaryawan);
//     SetColorBlock(7,9);
//     gotoprinttext(150,40,"K E M B A L I");
//     key = getch();
//     if(getch()){
//         BlankDashboard();
//         dataAkun();
//     }
// }

void readAllDataOwner(){
    i = 1;
    y = 13;
    arspstaff = fopen("../Source/../Database/Dat/staff.dat", "rb+");
    while (fread(&k, sizeof(k), 1, arspstaff) == 1 ) {
            if (i % 2 == 0) {
                SetColorBlock(15,4);
                for(x = y; x <= y;x++){
                    for(j = 37; j < 167; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                gotoxy(38, y);
                printf("%d", i);
                gotoxy(47, y);
                generateid("STF",k.idStaff);
                gotoxy(64, y);
                printf("%s\n", k.FName);
                gotoxy(91, y);
                printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
                gotoxy(38, y);
                printf("%d", i);
                gotoxy(47, y);
                generateid("STF",k.idStaff);
                gotoxy(64, y);
                printf("%s\n", k.FName);
                gotoxy(91, y);
                printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
            }
            i++;
            y++;
    }
    fclose(arspstaff);
    tampilanTableOwner();
}

// void readAllDataAdmin(){
//     i = 1;
//     y = 13;
//     arspkaryawan = fopen("../Source/../Database/Dat/Karyawan.dat", "rb+");
//     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1 ) {
//         if(strcmp(k.role,"Admin")==0) {
//             if (i % 2 == 0) {
//                 SetColorBlock(7,1);
//                 for(x = y; x <= y;x++){
//                     for(j = 37; j < 167; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("ADM",k.id_Karyawan.id_admin);
//                 gotoxy(64, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(94, y);
//                 printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
//                 gotoxy(111, y);
//                 rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 if (strcmp(k.role, "Admin") == 0) {
//                     gotoxy(129, y);
//                     printf("%s\n", k.No_telp);
//                     gotoxy(150, y);
//                     rupiah(k.benefit,inputrp);
//                     printf("%s",inputrp);
//
//                 }
//             } else {
//                 SetColorBlock(7,9);
//                 for(x = y; x <= y;x++){
//                     for(j = 37; j < 167; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("ADM",k.id_Karyawan.id_admin);
//                 gotoxy(64, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(94, y);
//                 printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
//                 gotoxy(111, y);
//                 rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 if (strcmp(k.role, "Admin") == 0) {
//                     gotoxy(129, y);
//                     printf("%s\n", k.No_telp);
//                     gotoxy(150, y);
//                     rupiah(k.benefit,inputrp);
//                     printf("%s",inputrp);
//
//                 }
//             }
//             i++;
//             y++;
//         }
//     }
//     fclose(arspkaryawan);
//     tampilanTableAdmin();
// }
//
// void readAllDataKasir(){
//
//     i = 1;
//     y = 13;
//     arspkaryawan = fopen("../Source/../Database/Dat/Karyawan.dat", "rb");
//     while (fread(&k, sizeof(k), 1, arspkaryawan) == 1 ) {
//         if(strcmp(k.role,"Kasir")==0) {
//             if (i % 2 == 0) {
//                 SetColorBlock(7,1);
//                 for(x = y; x <= y;x++){
//                     for(j = 37; j < 167; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("KSR",k.id_Karyawan.id_kasir);
//                 gotoxy(64, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(94, y);
//                 printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
//                 gotoxy(111, y);
//                 rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 if (strcmp(k.role, "Kasir") == 0) {
//                     gotoxy(129, y);
//                     printf("%s\n", k.No_telp);
//                     gotoxy(155, y);
//                     printf("%d\n", k.loket);
//
//                 }
//             } else {
//                 SetColorBlock(7,9);
//                 for(x = y; x <= y;x++){
//                     for(j = 37; j < 167; j++){
//                         gotoprintchar(j,x,32);
//                     }
//                 }
//                 gotoxy(38, y);
//                 printf("%d", i);
//                 gotoxy(47, y);
//                 generateid("KSR",k.id_Karyawan.id_kasir);
//                 gotoxy(64, y);
//                 printf("%s\n", k.FName);
//                 gotoxy(94, y);
//                 printf("%d/%d/%d\n", k.tanggalLahir.hari, k.tanggalLahir.bulan, k.tanggalLahir.tahun);
//                 gotoxy(111, y);
//                 rupiah(k.gaji,inputrp);
//                 printf("%s",inputrp);
//                 if (strcmp(k.role, "Kasir") == 0) {
//                     gotoxy(129, y);
//                     printf("%s\n", k.No_telp);
//                     gotoxy(155, y);
//                     printf("%d\n", k.loket);
//
//                 }
//             }
//             i++;
//             y++;
//         }
//     }
//     fclose(arspkaryawan);
//     tampilanTableKasir();
// }


void menuReadDataModifikasiOwner(){
    SetColorBlock(4,15);
    //   DrawFile(52,9,"../Source/../Desaintxt/Dashboard/lihatData.txt");
    DrawFile(130,22,"../Desaintxt/Elemen/dataBook.txt");
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
            SetColorBlock(4,15);
            readAllDataOwner();
            SetColorBlock(15,12);
            gotoprinttext(150,40,"K E M B A L I");
            getch();
                BlankDashboard();
                menuReadDataModifikasiOwner();
            break;
        // case 2:
        //     BlankDashboard();
        //     SetColorBlock(4,6);
        //     readAllDataAdmin();
        //     SetColorBlock(7,9);
        //     gotoprinttext(150,40,"K E M B A L I");
        //     getch();
        //         BlankDashboard();
        //         menuReadDataModifikasiManajer();
        //     break;
        // case 3:
        //     BlankDashboard();
        //     SetColorBlock(4,6);
        //     readAllDataKasir();
        //     SetColorBlock(7,9);
        //     gotoprinttext(150,40,"K E M B A L I");
        //     getch();
        //         BlankDashboard();
        //         menuReadDataModifikasiManajer();
        //     break;
        case 4:
            BlankDashboard();
            dataStaffMenu();
            break;
    }
}

// void menuReadDataModifikasiAdmin(){
//     SetColorBlock(1,7);
//     DrawFile(52,9,"../Source/../Desaintxt/Dashboard/lihatData.txt");
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
//             SetColorBlock(4,6);
//             readAllDataManajer();
//             SetColorBlock(7,9);
//             gotoprinttext(150,40,"K E M B A L I");
//             getch();
//                 BlankDashboard();
//                 menuReadDataModifikasiAdmin();
//             break;
//         case 2:
//             BlankDashboard();
//             SetColorBlock(4,6);
//             readAllDataAdmin();
//             SetColorBlock(7,9);
//             gotoprinttext(150,40,"K E M B A L I");
//             getch();
//                 BlankDashboard();
//                 menuReadDataModifikasiAdmin();
//             break;
//         case 3:
//             BlankDashboard();
//             SetColorBlock(4,6);
//             readAllDataKasir();
//             SetColorBlock(7,9);
//             gotoprinttext(150,40,"K E M B A L I");
//             getch();
//                 BlankDashboard();
//                 menuReadDataModifikasiAdmin();
//
//             break;
//         case 4:
//             BlankDashboard();
//             dataKaryawanMenuAdmin();
//             break;
//     }
//
// }
