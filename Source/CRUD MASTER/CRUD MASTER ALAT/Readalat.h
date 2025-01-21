void updateDataAlat(){
    i = 1;
    y = 13;
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(42, y);
    generateid("alt",alt.id_Alat);
    gotoxy(59, y);
    printf("%s\n", alt.nama_Alat);
    gotoxy(83, y);
    printf("%.2f",   alt.harga_Alat);
    gotoxy(107, y);
    rupiah(alt.harga_Alat,inputrp);
    printf("%s",inputrp);
    gotoxy(110, y);
    printf("%d", alt.jumlahAlat);
}

void readDataAlat() {
    i = 1;
    y = 13;
    arspalat = fopen("../Source/../Database/Dat/alatkesehatan.dat", "rb+");
    while (fread(&alt, sizeof(alt), 1, arspalat) == 1 ) {
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
            generateid("ALT",alt.id_Alat);
            gotoxy(67, y);
            printf("%s\n", alt.nama_Alat);
            gotoxy(90, y);
            rupiah(alt.harga_Alat,inputrp);
            printf("%s",inputrp);
            gotoxy(120, y);
            printf("%d\n", alt.jumlahAlat);
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
            generateid("ALT",alt.id_Alat);
            gotoxy(67, y);
            printf("%s\n", alt.nama_Alat);
            gotoxy(90, y);
            rupiah(alt.harga_Alat,inputrp);
            printf("%s",inputrp);
            gotoxy(120, y);
            printf("%d\n", alt.jumlahAlat);
        }
        i++;
        y++;
    }
    fclose(arspalat);
    SetColorBlock(15,12);
    gotoprinttext(150,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,19,28,4);
        menuOpsiDashboardOwner();
    }
}

void readAllDataAlat() {
    i = 1;
    y = 13;
    arspalat = fopen("../Database/alatkesehatan.dat", "rb+");
    while (fread(&alt, sizeof(alt), 1, arspalat) == 1) {
        if (i % 2 == 0) {
            SetColorBlock(15, 4);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            // Menampilkan data kelas pada baris tertentu
            dataAlat();

        } else {
            SetColorBlock(15, 12);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            // Menampilkan data kelas pada baris tertentu
            dataAlat();
        }
        batasTable();
        i++;
        y++;
    }
    fclose(arspalat);
    tampilanTableAlat();
}

void readUpdateDataAlat() {
    i = 1;
    y = 13;
    arspalat = fopen("../Source/../Database/Dat/alatkesehatan.dat", "rb+");
    while (fread(&alt, sizeof(alt), 1, arspalat) == 1) {
        if (i % 2 == 0) {
            SetColorBlock(15, 4);
            for (x = y; x <= y; x++) {
                for (j = 36; j < 128; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            gotoxy(38, y);
            printf("%d", i);
            gotoxy(47, y);
            generateid("ALT",alt.id_Alat);
            gotoxy(64, y);
            printf("%s\n", alt.nama_Alat);
            gotoxy(92, y);
            rupiah(alt.harga_Alat,inputrp);
            printf("%s",inputrp);
            gotoxy(110, y);
            printf("%d", alt.jumlahAlat);
        } else {
            SetColorBlock(15, 12);
            for (x = y; x <= y; x++) {
                for (j = 36; j < 128; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            gotoxy(38, y);
            printf("%d", i);
            gotoxy(47, y);
            generateid("ALT",alt.id_Alat);
            gotoxy(64, y);
            printf("%s\n", alt.nama_Alat);
            gotoxy(92, y);
            rupiah(alt.harga_Alat,inputrp);
            printf("%s",inputrp);
            gotoxy(110, y);
            printf("%d", alt.jumlahAlat);
        }
        i++;
        y++;
    }
    fclose(arspalat);
}