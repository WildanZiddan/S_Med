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
        case 4:
            BlankDashboard();
            dataStaffMenu();
            break;
    }
}