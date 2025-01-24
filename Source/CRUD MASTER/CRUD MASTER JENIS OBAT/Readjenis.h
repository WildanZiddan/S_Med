
void updateDataJenis(){
    i = 1;
    y = 13;
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(42, y);
    generateid("JNS",jns_obt.id_JenisObat);
    gotoxy(59, y);
    printf("%s\n", jns_obt.nama_Jenis);
}

void readDataJenis() {
    i = 1;
    y = 13;
    arspjenisobat = fopen("../Source/../Database/Dat/jenisobat.dat", "rb+");
    while (fread(&jns_obt, sizeof(jns_obt), 1, arspjenisobat) == 1 ) {
        if (i % 2 == 0) {
            SetColorBlock(15,4);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            gotoxy(38, y);
            printf("%d", i);
            gotoxy(50, y);
            generateid("JNS",jns_obt.id_JenisObat);
            gotoxy(67, y);
            printf("%s\n", jns_obt.nama_Jenis);
        } else {
            SetColorBlock(15, 12);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            gotoxy(38, y);
            printf("%d", i);
            gotoxy(50, y);
            generateid("JNS", jns_obt.id_JenisObat);
            gotoxy(67, y);
            printf("%s\n", jns_obt.nama_Jenis);
        }
        i++;
        y++;
    }
    fclose(arspjenisobat);
    SetColorBlock(15,12);
    gotoprinttext(150,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,19,28,4);
        menuOpsiDashboardOwner();
    }
}

void readAllDataJenis() {
    i = 1;
    y = 13;
    arspjenisobat = fopen("../Database/jenisobat.dat", "rb+");
    while (fread(&sp, sizeof(sp), 1, arspjenisobat) == 1) {
        if (i % 2 == 0) {
            SetColorBlock(15, 4);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            // Menampilkan data kelas pada baris tertentu
            dataJenis();

        } else {
            SetColorBlock(15, 12);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            // Menampilkan data kelas pada baris tertentu
            dataJenis();
        }
        batasTable();
        i++;
        y++;
    }
    fclose(arspjenisobat);
    tampilanTableJenis();
}

void readCreateJenisinObat(){
    SetColorBlock(15,4);
    for(i = 17; i <= 19;i++){
        for(j = 130; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }

    gotoprinttext(131,18,"NO.");
    gotoprinttext(134,18,"ID JENIS");
    gotoprinttext(147,18,"NAMA JENIS");
    i = 1;
    y = 20;
    arspjenisobat = fopen("../CRUD MASTER/../Source/../Database/Dat/jenisobat.dat", "rb+");
    while (fread(&jns_obt, sizeof(jns_obt), 1, arspjenisobat) == 1 ) {
        if (i % 2 == 0) {
            SetColorBlock(15,4);
            for(x = y; x <= y;x++){
                for(j = 130; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            gotoxy(131, y);
            printf("%d", i);
            gotoxy(134, y);
            generateid("JNS",jns_obt.id_JenisObat);
            gotoxy(147, y);
            printf("%s\n", jns_obt.nama_Jenis);
        } else {
            SetColorBlock(15,12);
            for(x = y; x <= y;x++){
                for(j = 130; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            gotoxy(131, y);
            printf("%d", i);
            gotoxy(134, y);
            generateid("JNS",jns_obt.id_JenisObat);
            gotoxy(147, y);
            printf("%s\n", jns_obt.nama_Jenis);
        }
        i++;
        y++;
    }
    fclose(arspjenisobat);
}

void readUpdateDataJenis() {
    i = 1;
    y = 13;
    arspjenisobat = fopen("../Source/../Database/Dat/jenisobat.dat", "rb+");
    while (fread(&jns_obt, sizeof(jns_obt), 1, arspjenisobat) == 1) {
        if (i % 2 == 0) {
            SetColorBlock(15, 4);
            for (x = y; x <= y; x++) {
                for (j = 36; j < 128; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            gotoxy(38, y);
            printf("%d", i);
            gotoxy(50, y);
            generateid("JNS",jns_obt.id_JenisObat);
            gotoxy(67, y);
            printf("%s\n", jns_obt.nama_Jenis);
        } else {
            SetColorBlock(15, 12);
            for (x = y; x <= y; x++) {
                for (j = 36; j < 128; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            gotoxy(38, y);
            printf("%d", i);
            gotoxy(50, y);
            generateid("JNS",jns_obt.id_JenisObat);
            gotoxy(67, y);
            printf("%s\n", jns_obt.nama_Jenis);
        }
        i++;
        y++;
    }
    fclose(arspjenisobat);
}