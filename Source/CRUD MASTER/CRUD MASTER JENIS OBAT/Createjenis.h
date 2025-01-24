void createDataJenisObat() {
    SetColorBlock(4, 15);
    gotoxy(132, 16);
    printf("Ketik 0 untuk keluar");

    arspjenisobat = fopen("../Database/Dat/jenisobat.dat", "ab+");
    int i = 0, id = 0;
    while (fread(&jns_obt, sizeof(jns_obt), 1, arspjenisobat)) {
        id = jns_obt.id_JenisObat; // Get the last ID
        i++;
    }

    // Generate the new ID
    if (i == 0) {
        jns_obt.id_JenisObat = 1;
    } else {
        jns_obt.id_JenisObat = id + 1;
    }

    gotoxy(40, 17);
    printf("I D   J E N I S   O B A T   : ");
    gotoxy(79, 17);
    printf("JNS%03d", jns_obt.id_JenisObat); // Contoh: JNS001

    fflush(stdin);
    showCursor();
    gotoxy(40, 19);
    printf("N A M A   J E N I S   O B A T : ");
    gotoxy(79, 19);
    fgets(jns_obt.nama_Jenis, sizeof(jns_obt.nama_Jenis), stdin);
    jns_obt.nama_Jenis[strcspn(jns_obt.nama_Jenis, "\n")] = 0; // Hapus newline

    hideCursor();

    if (strcmp(jns_obt.nama_Jenis, "0") == 0) {
        BlankDashboard();
        dataJenisObatMenu();
    }

    // Tulis data baru ke file
    fwrite(&jns_obt, sizeof(jns_obt), 1, arspjenisobat);
    fclose(arspjenisobat);
    BlankDashboard();
    dataJenisObatMenu();
}