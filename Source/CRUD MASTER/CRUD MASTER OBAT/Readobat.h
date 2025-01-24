void updateDataObat(){
    i = 1;
    y = 13;
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(42, y);
    generateid("OBT",alt.id_Alat);
    gotoxy(59, y);
    printf("%s\n", alt.nama_Alat);
    gotoxy(83, y);
    printf("%.2f",   alt.harga_Alat);
    gotoxy(107, y);
    rupiah(alt.harga_Alat,inputrp);
    printf("%s",inputrp);
    gotoxy(110, y);
    printf("%d", obt.jumlahObat);
}

void readDataObat() {
    i = 1;
    y = 13;
    arspobat = fopen("../Source/../Database/Dat/obat.dat", "rb+");
    while (fread(&obt, sizeof(obt), 1, arspobat) == 1 ) {
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
            generateid("ALT",obt.id_Obat);
            gotoxy(67, y);
            printf("%s\n", obt.nama_Obat);
            gotoxy(77, y);
            printf("%s\n", obt.nama_Jenis);
            gotoxy(90, y);
            rupiah(obt.harga_Obat,inputrp);
            printf("%s",inputrp);
            gotoxy(110, y);
            printf("%d\n", obt.tanggalKedaluwarsa.tahun);
            gotoxy(120, y);
            printf("%d\n", obt.jumlahObat);
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
            generateid("ALT",obt.id_Obat);
            gotoxy(67, y);
            printf("%s\n", obt.nama_Obat);
            gotoxy(77, y);
            printf("%s\n", obt.nama_Jenis);
            gotoxy(90, y);
            rupiah(obt.harga_Obat,inputrp);
            printf("%s",inputrp);
            gotoxy(110, y);
            printf("%d\n", obt.tanggalKedaluwarsa.tahun);
            gotoxy(120, y);
            printf("%d\n", obt.jumlahObat);
        }
        i++;
        y++;
    }
    fclose(arspobat);
    SetColorBlock(15,12);
    gotoprinttext(150,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,19,28,4);
        menuOpsiDashboardOwner();
    }
}

void readAllDataObat() {
    i = 1;
    y = 13;
    arspobat = fopen("../Database/obat.dat", "rb+");
    while (fread(&obt, sizeof(obt), 1, arspobat) == 1) {
        if (i % 2 == 0) {
            SetColorBlock(15, 4);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            // Menampilkan data kelas pada baris tertentu
            dataObat();

        } else {
            SetColorBlock(15, 12);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            // Menampilkan data kelas pada baris tertentu
            dataObat();
        }
        batasTable();
        i++;
        y++;
    }
    fclose(arspobat);
    tampilanTableObat();
}

void readUpdateDataObat() {
    i = 1;
    y = 13;
    arspobat = fopen("../Source/../Database/Dat/obat.dat", "rb+");
    while (fread(&obt, sizeof(obt), 1, arspobat) == 1) {
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
            generateid("ALT",obt.id_Obat);
            gotoxy(67, y);
            printf("%s\n", obt.nama_Obat);
            gotoxy(77, y);
            printf("%s\n", obt.nama_Jenis);
            gotoxy(90, y);
            rupiah(obt.harga_Obat,inputrp);
            printf("%s",inputrp);
            gotoxy(110, y);
            printf("%d\n", obt.tanggalKedaluwarsa.tahun);
            gotoxy(120, y);
            printf("%d\n", obt.jumlahObat);
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
            generateid("ALT",obt.id_Obat);
            gotoxy(67, y);
            printf("%s\n", obt.nama_Obat);
            gotoxy(77, y);
            printf("%s\n", obt.nama_Jenis);
            gotoxy(90, y);
            rupiah(obt.harga_Obat,inputrp);
            printf("%s",inputrp);
            gotoxy(110, y);
            printf("%d\n", obt.tanggalKedaluwarsa.tahun);
            gotoxy(120, y);
            printf("%d\n", obt.jumlahObat);
        }
        i++;
        y++;
    }
    fclose(arspobat);
}