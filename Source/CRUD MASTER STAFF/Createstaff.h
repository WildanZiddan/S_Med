void inputUsernamedanPass();
void inputStaff(int output);

void createData(int output){
    SetColorBlock(4,15);
    DrawFile(50,9,"../Source/../Desaintxt/Dashboard/tambahData.txt");
    DrawFile(130,21,"../Source/../Desaintxt/elemen/pensil.txt");
    showCursor();
    gotoxy(135,16);
    printf("Ketik 0 lalu enter untuk Batal");
    inputStaff(output);
    hideCursor();
    fflush(stdin);
    showCursor();
    gotoxy(40, 19);
    printf("N A M A  L E N G K A P    :");
    gotoxy(69, 19);
    getinput(tempk.FName,25,2);
    hideCursor();
    cancelCharOwner(tempk.FName);

    do{
    fflush(stdin);
    showCursor();
    gotoxy(40, 21);
    printf("N O.  T E L E P O N E     :");
    gotoxy(69, 21);
    getallinput(tempk.No_telp,12,13,3);
    hideCursor();
    cancelCharOwner(tempk.No_telp);
    strcpy(k.No_telp, "08");
    if(strstr(tempk.No_telp,k.No_telp) == NULL) {
        MessageBox(NULL, "Nomor telepon harus diawali 08", "Pemberitahuan!",
                   MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        for (i = 69; i < 83; i++) {
            gotoprintchar(i, 21, 32);
        }
        showCursor();
    }
    }while(strstr(tempk.No_telp,k.No_telp) == NULL);

    fflush(stdin);
    showCursor();
    gotoxy(40, 23);
    printf("T A N G G A L  L A H I R  :");
    gotoprinttext(69, 23, "  /  /     \n");
    do {
        gotoxy(69, 23);
        getnum(&tempk.tanggalLahir.hari,2);
        if(tempk.tanggalLahir.hari > 31 || tempk.tanggalLahir.hari < 1 ){
            MessageBox(NULL,"Jangka Inputan hari 1 - 31","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(69,23,2,1);
        }
    }
    while(tempk.tanggalLahir.hari > 31 || tempk.tanggalLahir.hari < 1 );
    do {
        gotoxy(72, 23);
        getnum(&tempk.tanggalLahir.bulan,2);
        if(tempk.tanggalLahir.bulan > 12 || tempk.tanggalLahir.bulan < 1 ){
            MessageBox(NULL,"Jangka Inputan bulan 1 - 12","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(72,23,2,1);
        }
    }while(tempk.tanggalLahir.bulan > 12 || tempk.tanggalLahir.bulan < 1);
    do {
        gotoxy(75, 23);
        getnum(&tempk.tanggalLahir.tahun, 4);
        hideCursor();
        if (tempk.tanggalLahir.tahun < 1900 || tempk.tanggalLahir.tahun > 2015) {
            MessageBox(NULL, "Jangka Inputan tahun 1900 - 2015", "NOTIFICATION!",
                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(75, 23, 4, 1);
        }
    }while(tempk.tanggalLahir.tahun < 1900 || tempk.tanggalLahir.tahun > 2015);
    if (tempk.tanggalLahir.hari == 0 || tempk.tanggalLahir.bulan == 0 || tempk.tanggalLahir.tahun == 0) {
        BlankDashboard();
        menuCreateDataModifikasiOwner();
    }

    inputUsernamedanPass();

    arspstaff = fopen("../Source/../Database/Dat/staff.dat", "ab+");

    k.idStaff = tempk.idStaff;
    strcpy(k.FName,tempk.FName);
    strcpy(k.No_telp,tempk.No_telp);
    k.tanggalLahir.hari = tempk.tanggalLahir.hari;
    k.tanggalLahir.bulan = tempk.tanggalLahir.bulan;
    k.tanggalLahir.tahun = tempk.tanggalLahir.tahun;
    strcpy(k.username,tempk.username);


    switch (output) {
            case 1 :
                strcpy(k.role, "Owner");
                break;
            case 2:
                strcpy(k.role, "Kasir");
                break;
            case 3:
                strcpy(k.role, "Apoteker");
                break;
        }

        gotoxy(83,36);printf("Data ini ingin anda simpan ?");
        SpecialKeyYesorNoDashboard(100, 38,10,4,15,&output);
        if(output == 1) {
            MessageBox(NULL,"Data Berhasil Ditambahkan!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            fwrite(&k, sizeof(k), 1, arspstaff);
            fclose(arspstaff);
            clearArea(83,36,40,3);
            SetColorBlock(4,15);
        } else if(output == 2) {
        fclose(arspstaff);
        clearArea(83,36,40,3);
        }
    }

void inputStaff(int output) {
    /*Create Data Manajer*/
    if (output == 1) {
        arspstaff = fopen("../Source/../Database/Dat/staff.dat", "ab+");
        i = 0;
        fread(&k, sizeof(k), 1, arspstaff);
        while (!feof(arspstaff)) {
            fread(&k, sizeof(k), 1, arspstaff);
            id = k.idStaff.id_owner;
            i++;
        }

        if (i == 0) {
            k.idStaff.id_owner = 1;
        } else {
            k.idStaff.id_owner= id + 1;
        }

        tempk.idStaff.id_owner = k.idStaff.id_owner;
        fflush(stdin);
        gotoxy(40, 17);
        printf("I D   M A N A G E R       :");
        gotoxy(69, 17);
        generateid("OWN", tempk.idStaff.id_owner);
        hideCursor();
        fclose(arspstaff);
//    Create Data Admin
    } else if (output == 2) {
        arspstaff = fopen("../Source/../Database/Dat/staff.dat", "ab+");
        i = 0;
        fread(&k, sizeof(k), 1, arspstaff);
        while (!feof(arspstaff)) {
            fread(&k, sizeof(k), 1, arspstaff);
            id = k.idStaff.id_kasir;
            i++;
        }

        if (i == 0) {
            k.idStaff.id_kasir = 1;
        } else {
            k.idStaff.id_kasir = id + 1;
        }

        tempk.idStaff.id_kasir = k.idStaff.id_kasir;
        gotoxy(40, 17);
        printf("I D   A D M I N           :");
        gotoxy(69, 17);
        generateid("ADM", tempk.idStaff.id_kasir);
        hideCursor();
        fclose(arspstaff);
    }
    /*Create Data Kasir*/
    else if (output == 3) {
        arspstaff = fopen("../Source/../Database/Dat/staff.dat", "ab+");
        i = 0;
        fread(&k, sizeof(k), 1, arspstaff);
        while (!feof(arspstaff)) {
            fread(&k, sizeof(k), 1, arspstaff);
            id = k.idStaff.id_apoteker;
            i++;
        }

        if (i == 0) {
            k.idStaff.id_apoteker = 1;
        } else {
            k.idStaff.id_apoteker = id + 1;
        }

        tempk.idStaff.id_apoteker = k.idStaff.id_apoteker;
        fflush(stdin);
        gotoxy(40, 17);
        printf("I D  K A S I R            :");
        gotoxy(69, 17);
        generateid("APT",tempk.idStaff.id_apoteker);
        hideCursor();
        fclose(arspstaff);
        }
    }

void    inputUsernamedanPass() {
    do {
        fflush(stdin);
        showCursor();
        gotoxy(40, 27);
        printf("U S E R N A M E           :");
        gotoxy(69, 27);
        getinput(tempk.username,20,1);
        found = 0;
        arspstaff = fopen("../Source/../Database/Dat/staff.dat","rb");
        while(fread(&k,sizeof (k),1,arspstaff)==1){
            if(strcmp(k.username,tempk.username)==0){
                found = 1;
                MessageBox(NULL, "Username Sudah Ada!", "Duplikasi Username",
                           MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                for (i = 69; i < 80; i++) {
                    gotoprintchar(i, 27, 32);
                }
            }
            if(found == 0){
            strcpy(k.username,tempk.username);
        }
        }
        hideCursor();
    }while(found == 1);
    fclose(arspstaff);
    hideCursor();

        fflush(stdin);
        showCursor();
        gotoxy(40, 29);
        printf("P A S S W O R D           :");
        gotoxy(69, 29);
        inputPass(k.password);
        hideCursor();
    }

void menuCreateDataModifikasiOwner(){
    char exit[2] = "y";
    SetColorBlock(4,15);
    //DrawFile(48,9,"../Source/../Desaintxt/Dashboard/tambahData.txt");
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
            SetColorBlock(4,15);
            do {
                createData(output);
                SetColorBlock(4,15);
                gotoxy(80,36);
                printf("Anda Ingin Menambahkan data [Y/N]");
                SpecialKeyYesorNoDashboard(100, 38,10,4,15,&input);
                if(input==1){
                    BlankDashboard();
                }
            } while(input == 1);
            hideCursor();
            SetColorBlock(15,4);
            gotoprinttext(150,40,"K E M B A L I");
            if(getch()){
                BlankDashboard();
                menuCreateDataModifikasiOwner();
            }
            break;
        case 2:
            hideCursor();
            BlankDashboard();
            SetColorBlock(4,15);
            do {
                createData(output);
                showCursor();
                SetColorBlock(4,15);
                gotoxy(80,36);printf("Anda Ingin Menambahkan data ?");
                SpecialKeyYesorNoDashboard(100, 38,10,4,15,&input);
                hideCursor();
                if(input==1){
                    BlankDashboard();
                }
            } while(input == 1);
            hideCursor();
            SetColorBlock(15,4);
            gotoprinttext(150,40,"K E M B A L I");
            if(getch()){
                BlankDashboard();
                menuCreateDataModifikasiOwner();
            }
            break;
        case 3:
            hideCursor();
            BlankDashboard();
            do{
                createData(output);
                showCursor();
                gotoxy(80,36);
                SetColorBlock(4,15);
                printf("Anda Ingin Menambahkan data [Y/N]");
                SpecialKeyYesorNoDashboard(100, 38,10,15,4,&input);
                hideCursor();
                if(input==1){
                    BlankDashboard();
                }
            } while(input == 1);
            hideCursor();
            SetColorBlock(15,4);
            gotoprinttext(150,40,"K E M B A L I");
            if(getch()){
                BlankDashboard();
                menuCreateDataModifikasiOwner();
            }
            break;
        case 4:
            hideCursor();
            BlankDashboard();
            dataStaffMenu();
            break;
    }
}

// void inputKaryawanAdmin(int output){
//     /*Create Data Manajer*/
//     if(output == 1) {
//         arspstaff = fopen("../Source/../Database/Dat/staff.dat", "ab+");
//         i = 0;
//         fread(&k, sizeof(k), 1, arspstaff);
//         while (!feof(arspstaff)) {
//             fread(&k, sizeof(k), 1, arspstaff);
//             id = k.idStaff.id_owner;
//             i++;
//         }
//
//         if (i == 0) {
//             k.idStaff.id_owner = 1;
//         } else {
//             k.idStaff.id_owner = id + 1;
//         }
//
//         tempk.idStaff.id_owner = k.idStaff.id_owner;
//         fclose(arspstaff);
//         fflush(stdin);
//         gotoxy(40, 17);
//         printf("I D   O W N E R      :");
//         gotoxy(69, 17);
//         generateid("OWN", tempk.idStaff.id_owner);
//         hideCursor();
//         /*Create Data Admin*/
//     } else if(output == 2){
//         arspstaff = fopen("../Source/../Database/Dat/staff.dat", "ab+");
//         i = 0;
//         fread(&k, sizeof(k), 1, arspstaff);
//         while (!feof(arspstaff)) {
//             fread(&k, sizeof(k), 1, arspstaff);
//             id = k.idStaff.id_kasir;
//             i++;
//         }
//
//         if (i == 0) {
//             k.idStaff.id_kasir = 1;
//         } else {
//             k.idStaff.id_kasir = id + 1;
//         }
//
//         tempk.idStaff.id_kasir = k.idStaff.id_kasir;
//         fclose(arspstaff);
//         gotoxy(40, 17);
//         printf("I D   K A S I R           :");
//         gotoxy(69, 17);
//         generateid("KSR", tempk.idStaff.id_kasir);
//         hideCursor();
//
//     } else if(output ==  3 ){
//         arspstaff = fopen("../Source/../Database/Dat/staff.dat", "ab+");
//         i = 0;
//         fread(&k, sizeof(k), 1, arspstaff);
//         while (!feof(arspstaff)) {
//             fread(&k, sizeof(k), 1, arspstaff);
//             id = k.idStaff.id_apoteker;
//             i++;
//         }
//
//         if (i == 0) {
//             k.idStaff.id_apoteker = 1;
//         } else {
//             k.idStaff.id_apoteker = id + 1;
//         }
//
//         tempk.idStaff.id_apoteker = k.idStaff.id_apoteker;
//         fclose(arspstaff);
//         fflush(stdin);
//         gotoxy(40, 17);
//         printf("I D  A P O T E K E R            :");
//         gotoxy(69, 17);
//         generateid("APT",tempk.idStaff.id_apoteker);
//         hideCursor();
//     }
// }
//
// void createDataAdmin(int output){
//     SetColorBlock(1,7);
//     DrawFile(50,9,"../Source/../Desaintxt/Dashboard/tambahData.txt");
//     DrawFile(130,21,"../Source/../Desaintxt/elemen/pensil.txt");
//     showCursor();
//     gotoxy(135,16);
//     printf("Ketik 0 lalu enter untuk Batal");
//     inputKaryawanAdmin(output);
//     hideCursor();
//     fflush(stdin);
//     showCursor();
//     gotoxy(40, 19);
//     printf("N A M A  L E N G K A P    :");
//     gotoxy(69, 19);
//     getinput(tempk.FName,25,2);
//     hideCursor();
//     cancelCharAdmin(tempk.FName);
//
//     do{
//         fflush(stdin);
//         showCursor();
//         gotoxy(40, 21);
//         printf("N O.  T E L E P O N E     :");
//         gotoxy(69, 21);
//         getallinput(tempk.No_telp,12,13,3);
//         hideCursor();
//         cancelCharAdmin(tempk.No_telp);
//         strcpy(k.No_telp, "08");
//         if(strstr(tempk.No_telp,k.No_telp) == NULL) {
//             MessageBox(NULL, "Nomor telepon harus diawali 08", "Pemberitahuan!",
//                        MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
//             for (i = 69; i < 83; i++) {
//                 gotoprintchar(i, 21, 32);
//             }
//             showCursor();
//         }
//     }while(strstr(tempk.No_telp,k.No_telp) == NULL);
//
//     fflush(stdin);
//     showCursor();
//     gotoxy(40, 23);
//     printf("T A N G G A L  L A H I R  :");
//     gotoprinttext(69, 23, "  /  /     \n");
//     do {
//         gotoxy(69, 23);
//         getnum(&tempk.tanggalLahir.hari,2);
//         if(tempk.tanggalLahir.hari > 31 || tempk.tanggalLahir.hari < 1 ){
//             MessageBox(NULL,"Jangka Inputan hari 1 - 31","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//             clearArea(69,23,2,1);
//         }
//     }
//     while(tempk.tanggalLahir.hari > 31 || tempk.tanggalLahir.hari < 1 );
//     do {
//         gotoxy(72, 23);
//         getnum(&tempk.tanggalLahir.bulan,2);
//         if(tempk.tanggalLahir.bulan > 12 || tempk.tanggalLahir.bulan < 1 ){
//             MessageBox(NULL,"Jangka Inputan bulan 1 - 12","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//             clearArea(72,23,2,1);
//         }
//     }while(tempk.tanggalLahir.bulan > 12 || tempk.tanggalLahir.bulan < 1);
//     do {
//         gotoxy(75, 23);
//         getnum(&tempk.tanggalLahir.tahun, 4);
//         hideCursor();
//         if (tempk.tanggalLahir.tahun < 1900 || tempk.tanggalLahir.tahun > 2015) {
//             MessageBox(NULL, "Jangka Inputan tahun 1900 - 2015", "NOTIFICATION!",
//                        MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//             clearArea(75, 23, 4, 1);
//         }
//     }while(tempk.tanggalLahir.tahun < 1900 || tempk.tanggalLahir.tahun > 2015);
//     if (tempk.tanggalLahir.hari == 0 || tempk.tanggalLahir.bulan == 0 || tempk.tanggalLahir.tahun == 0) {
//         BlankDashboard();
//         menuCreateDataModifikasiAdmin();
//     }
//
//     fflush(stdin);
//     showCursor();
//     gotoxy(40, 25);
//     printf("G A J I                   :  Rp.");
//     gotoxy(73, 25);
//     getRp(&tempk.gaji,4,9,73,25);
//     hideCursor();
//     if (tempk.gaji == 0) {
//         BlankDashboard();
//         menuCreateDataModifikasiAdmin();
//     }
//
//     inputUsernamedanPass();
//     arspkaryawan = fopen("../Source/../Database/Dat/karyawan.dat", "ab+");
//
//     k.id_Karyawan = tempk.id_Karyawan;
//     strcpy(k.FName,tempk.FName);
//     strcpy(k.No_telp,tempk.No_telp);
//     k.tanggalLahir.hari = tempk.tanggalLahir.hari;
//     k.tanggalLahir.bulan = tempk.tanggalLahir.bulan;
//     k.tanggalLahir.tahun = tempk.tanggalLahir.tahun;
//     k.gaji = tempk.gaji;
//
//     if(output == 1) {
//         fflush(stdin);
//         showCursor();
//         gotoxy(40, 31);
//         printf("T U N J A N G A N         :  Rp.");
//         gotoxy(73, 31);
//         getRp(&k.tunjangan,4,9,73,31);
//         hideCursor();
//         if (k.tunjangan == 0) {
//             BlankDashboard();
//             menuCreateDataModifikasiAdmin();
//         }
//     }
//
//     if(output == 2){
//         showCursor();
//         gotoxy(40, 31);
//         printf("B E N E F I T             :  Rp.");
//         gotoxy(73, 31);
//         getRp(&k.benefit,4,9,73,31);
//         hideCursor();
//         if (k.benefit == 0) {
//             BlankDashboard();
//             menuCreateDataModifikasiAdmin();
//         }
//     }
//
//     if(output == 3) {
//         MessageBox(NULL, "Loket Tiket & Merchandise : 1,2,3\nLoket Makanan : 4,5", "Pemberitahuan",
//                    MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//         showCursor();
//         gotoxy(40, 31);
//         printf("L O K E T                 :");
//         do {
//             gotoxy(69, 31);
//             getnum(&k.loket,1);
//             if(k.loket < 1){
//                 MessageBox(NULL,"Mohon maaf loket hanya tersedia 1 s/d 5","NOTIFICATION",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 clearArea(69,31,1,1);
//             } else if(k.loket > 5){
//                 MessageBox(NULL,"Mohon maaf loket hanya tersedia 1 s/d 5","NOTIFICATION",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
//                 clearArea(69,31,1,1);
//             }
//         }while(k.loket < 1 || k.loket > 5);
//         hideCursor();
//         if (k.loket == 0) {
//             BlankDashboard();
//             menuCreateDataModifikasiAdmin();
//         }
//     }
//
//
//     switch (output) {
//         case 1 :
//             strcpy(k.role, "Manajer");
//             break;
//         case 2:
//             strcpy(k.role, "Admin");
//             break;
//         case 3:
//             strcpy(k.role, "Kasir");
//             break;
//     }
//
//     gotoxy(83,36);printf("Data ini ingin anda simpan ?");
//     SpecialKeyYesorNoDashboard(100, 38,10,1,7,&output);
//     if(output == 1) {
//         MessageBox(NULL,"Data Berhasil Ditambahkan!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//         fwrite(&k, sizeof(k), 1, arspkaryawan);
//         fclose(arspkaryawan);
//         clearArea(83,36,40,3);
//         SetColorBlock(1,7);
//     } else if(output == 2) {
//         fclose(arspkaryawan);
//         clearArea(83,36,40,3);
//     }
// }
//
// void menuCreateDataModifikasiAdmin(){
//     char exit[2] = "y";
//     SetColorBlock(1,7);
//     DrawFile(48,9,"../Source/../Desaintxt/Dashboard/tambahData.txt");
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
//             SetColorBlock(1,7);
//             do{
//                 createDataAdmin(output);
//                 showCursor();
//                 SetColorBlock(1,7);
//                 gotoxy(80,36);printf("Anda Ingin Menambahkan data [Y/N]");
//                 SpecialKeyYesorNoDashboard(100, 38,10,1,7,&input);
//                 hideCursor();
//                 if(input==1){
//                     BlankDashboard();
//                 }
//             }while(input==1);
//             hideCursor();
//             SetColorBlock(7,1);
//             gotoprinttext(150,40,"K E M B A L I");
//             if(getch()){
//                 BlankDashboard();
//                 menuCreateDataModifikasiAdmin();
//             }
//             break;
//         case 2:
//             hideCursor();
//             BlankDashboard();
//             SetColorBlock(1,7);
//             do {
//                 createDataAdmin(output);
//                 showCursor();
//                 SetColorBlock(1,7);
//                 gotoxy(80,36);printf("Anda Ingin Menambahkan data [Y/N]");
//                 SpecialKeyYesorNoDashboard(100, 38,10,1,7,&input);
//                 hideCursor();
//                 if(input==1){
//                     BlankDashboard();
//                 }
//             }while(output==1);
//             hideCursor();
//             SetColorBlock(7,1);
//             gotoprinttext(150,40,"K E M B A L I");
//             if(getch()){
//                 BlankDashboard();
//                 menuCreateDataModifikasiAdmin();
//             }
//             break;
//         case 3:
//             hideCursor();
//             BlankDashboard();
//             do{
//                 createDataAdmin(output);
//                 showCursor();
//                 SetColorBlock(1,7);
//                 gotoxy(80,36);printf("Anda Ingin Menambahkan data [Y/N]");
//                 SpecialKeyYesorNoDashboard(100, 38,10,1,7,&input);
//                 hideCursor();
//                 if(input==1){
//                     BlankDashboard();
//                 }
//             }while(input==1);
//             hideCursor();
//             SetColorBlock(7,1);
//             gotoprinttext(150,40,"K E M B A L I");
//             if(getch()){
//                 BlankDashboard();
//                 menuCreateDataModifikasiAdmin();
//             }
//             break;
//         case 4:
//             hideCursor();
//             BlankDashboard();
//             dataKaryawanMenuAdmin();
//             break;
//     }
//
// }
