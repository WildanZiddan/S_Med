void inputUsernamedanPass();
void inputStaff(int output);

void createData(int output){
    SetColorBlock(4,15);
    //DrawFile(50,9,"../Source/../Desaintxt/Dashboard/tambahData.txt");
    //DrawFile(130,21,"../Source/../Desaintxt/elemen/pensil.txt");
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
    printf("N O.  T E L E P O N       :");
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
        if (tempk.tanggalLahir.tahun < 1900 || tempk.tanggalLahir.tahun > 2008) {
            MessageBox(NULL, "Jangka Inputan tahun 1900 - 2008", "NOTIFICATION!",
                       MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(75, 23, 4, 1);
        }
    }while(tempk.tanggalLahir.tahun < 1900 || tempk.tanggalLahir.tahun > 2008);
    if (tempk.tanggalLahir.hari == 0 || tempk.tanggalLahir.bulan == 0 || tempk.tanggalLahir.tahun == 0) {
        BlankDashboard();
        dataStaffMenu();
    }
    fflush(stdin);
    showCursor();
    gotoxy(40, 25);
    printf("R O L E                   :");
    gotoxy(69, 25);
    getinput(tempk.role,25,2);
    hideCursor();
    cancelCharOwner(tempk.role);

    inputUsernamedanPass();

    arspstaff = fopen("../Source/../Database/Dat/staff.dat", "ab+");

    k.idStaff = tempk.idStaff;
    strcpy(k.FName,tempk.FName);
    strcpy(k.No_telp,tempk.No_telp);
    k.tanggalLahir.hari = tempk.tanggalLahir.hari;
    k.tanggalLahir.bulan = tempk.tanggalLahir.bulan;
    k.tanggalLahir.tahun = tempk.tanggalLahir.tahun;
    strcpy(k.username,tempk.username);
    strcpy(k.role,tempk.role);

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
        fp = fopen("../Source/../Database/Dat/staff.dat", "ab+");
        i = 0;
        fread(&k, sizeof(k), 1, fp);
        while (!feof(fp)) {
            fread(&k, sizeof(k), 1, fp);
            id = k.idStaff;
            i++;
        }

        if (i == 0) {
            k.idStaff = 1;
        } else {
            k.idStaff= id + 1;
        }

        tempk.idStaff = k.idStaff;
        fflush(stdin);
        gotoxy(40, 17);
        printf("I D   S T A F F       :");
        gotoxy(69, 17);
        generateid("STF", tempk.idStaff);
        hideCursor();
        fclose(fp);
}

void inputUsernamedanPass() {
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
                    menuOpsiDashboardOwner();
                }
            } while(input == 1);
            hideCursor();
            SetColorBlock(15,4);
            gotoprinttext(150,40,"K E M B A L I");
            if(getch()){
                BlankDashboard();
                dataStaffMenu();
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
                dataStaffMenu();
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
                dataStaffMenu();
            }
            break;
        case 4:
            hideCursor();
            BlankDashboard();
            dataStaffMenu();
            break;
    }
}

