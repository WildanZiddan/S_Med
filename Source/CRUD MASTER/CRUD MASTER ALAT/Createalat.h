void createDataAlat(){
    SetColorBlock(4,15);
    //DrawFile(50,9,"../CRUD MASTER/../Source/../Desaintxt/Dashboard/tambahData.txt");
    //DrawFile(130,21,"../CRUD MASTER/../Source/../Desaintxt/elemen/pensil.txt");
    gotoxy(132,16);
    printf("Ketik 0 untuk keluar");
    arspalat = fopen("../Database/Dat/alatkesehatan.dat", "ab+");
    i = 0;
    while (fread(&alt, sizeof(alt), 1, arspalat)) {
        id = alt.id_Alat; // Get the last ID
        i++;
    }
    // Generate the new ID
    if (i == 0) {
        alt.id_Alat = 1;
    } else {
        alt.id_Alat = id + 1;
    }

    gotoxy(40, 17);
    printf("I D   A L A T         : ");
    gotoxy(79, 17);
    printf("ALT%03d", alt.id_Alat); // Contoh: ID001

    fflush(stdin);
    showCursor();
    gotoxy(40, 19);
    printf("N A M A  A L A T      : ");
    gotoxy(79, 19);
    fgets(alt.nama_Alat, sizeof(alt.nama_Alat), stdin);
    alt.nama_Alat[strcspn(alt.nama_Alat, "\n")] = 0; // Hapus newline

    fflush(stdin);
    showCursor();
    gotoxy(40, 21);
    printf("H A R G A  A L A T            :  Rp.");
    gotoxy(79, 21);
    getRp(&alt.harga_Alat,4,9,79,21);

    gotoxy(40, 23);
    printf("J U M L A H  A L A T  : ");
    gotoxy(79, 23);
    scanf("%d", &alt.jumlahAlat);
    hideCursor();
    if (alt.jumlahAlat == 0) {
        BlankDashboard();
        dataPenjualanMenu();
    }
    // Tulis data baru ke file
    fwrite(&alt, sizeof(alt), 1, arspalat);
    fclose(arspalat);
    BlankDashboard();
    dataPenjualanMenu();
}


// Utility function to generate ID (simple implementation)
void generateId(const char *prefix, int id) {
    printf("%s%03d", prefix, id); // Example: ID001,ID002,etc.
}