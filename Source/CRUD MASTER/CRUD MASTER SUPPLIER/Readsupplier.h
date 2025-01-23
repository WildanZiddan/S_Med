
void updateDataSupplier(){
    i = 1;
    y = 13;
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(42, y);
    generateid("SUP",sp.id_Supplier);
    gotoxy(59, y);
    printf("%s\n", sp.nama_Supplier);
    gotoxy(83, y);
    printf("%s\n",   sp.company);
    gotoxy(107, y);
    printf("%s", sp.alamat);
}

void readDataSupplier() {
    i = 1;
    y = 13;
    arspsupplier = fopen("../Source/../Database/Dat/supplier.dat", "rb+");
    while (fread(&sp, sizeof(sp), 1, arspsupplier) == 1 ) {
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
            generateid("SUP",sp.id_Supplier);
            gotoxy(67, y);
            printf("%s\n", sp.nama_Supplier);
            gotoxy(90, y);
            printf("%s\n",   sp.company);
            gotoxy(120, y);
            printf("%s", sp.alamat);
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
            generateid("SUP",sp.id_Supplier);
            gotoxy(67, y);
            printf("%s\n", sp.nama_Supplier);
            gotoxy(90, y);
            printf("%s\n",   sp.company);
            gotoxy(120, y);
            printf("%s", sp.alamat);
        }
        i++;
        y++;
    }
    fclose(arspsupplier);
    SetColorBlock(15,12);
    gotoprinttext(150,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,19,28,4);
        menuOpsiDashboardOwner();
    }
}

void readAllDataSupplier() {
    i = 1;
    y = 13;
    arspsupplier = fopen("../Database/supplier.dat", "rb+");
    while (fread(&sp, sizeof(sp), 1, arspsupplier) == 1) {
        if (i % 2 == 0) {
            SetColorBlock(15, 4);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            // Menampilkan data kelas pada baris tertentu
            dataSupplier();

        } else {
            SetColorBlock(15, 12);
            for (x = y; x <= y; x++) {
                for (j = 37; j < 167; j++) {
                    gotoprintchar(j, x, 32);
                }
            }
            // Menampilkan data kelas pada baris tertentu
            dataSupplier();
        }
        batasTable();
        i++;
        y++;
    }
    fclose(arspsupplier);
    tampilanTableSupplier();
}

void readUpdateDataSupplier() {
    i = 1;
    y = 13;
    arspsupplier = fopen("../Source/../Database/Dat/supplier.dat", "rb+");
    while (fread(&sp, sizeof(sp), 1, arspsupplier) == 1) {
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
            generateid("SUP",sp.id_Supplier);
            gotoxy(67, y);
            printf("%s\n", sp.nama_Supplier);
            gotoxy(90, y);
            printf("%s\n",   sp.company);
            gotoxy(120, y);
            printf("%s", sp.alamat);
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
            generateid("SUP",sp.id_Supplier);
            gotoxy(67, y);
            printf("%s\n", sp.nama_Supplier);
            gotoxy(90, y);
            printf("%s\n",   sp.company);
            gotoxy(120, y);
            printf("%s", sp.alamat);
        }
        i++;
        y++;
    }
    fclose(arspsupplier);
}