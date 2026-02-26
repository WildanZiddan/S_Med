void createDataSupplier(){
    SetColorBlock(4,15);
    //DrawFile(50,9,"../CRUD MASTER/../Source/../Desaintxt/Dashboard/tambahData.txt");
    //DrawFile(130,21,"../CRUD MASTER/../Source/../Desaintxt/elemen/pensil.txt");
    gotoxy(132,16);
    printf("Ketik 0 untuk keluar");
    arspsupplier = fopen("../Database/Dat/supplier.dat", "ab+");
    i = 0;
    while (fread(&sp, sizeof(sp), 1, arspsupplier)) {
        id = sp.id_Supplier; // Get the last ID
        i++;
    }
    // Generate the new ID
    if (i == 0) {
        sp.id_Supplier = 1;
    } else {
        sp.id_Supplier = id + 1;
    }

    gotoxy(40, 17);
    printf("I D   S U P P L I E R         : ");
    gotoxy(79, 17);
    printf("SUP%03d", sp.id_Supplier); // Contoh: ID001

    fflush(stdin);
    showCursor();
    gotoxy(40, 19);
    printf("N A M A  S U P P L I E R      : ");
    gotoxy(79, 19);
    getinput(sp.nama_Supplier, 50, 2);

    fflush(stdin);
    showCursor();
    gotoxy(40, 21);
    printf("C O M P A N Y                 :  ");
    gotoxy(79, 21);
    getinput(sp.company, 50, 2);

    gotoxy(40, 23);
    printf("A L A M A T                   : ");
    gotoxy(79, 23);
    getinput(sp.alamat, 50, 2);
    
    hideCursor();
    // Tulis data baru ke file
    fwrite(&sp, sizeof(sp), 1, arspsupplier);
    fclose(arspsupplier);
    BlankDashboard();
    dataSupplierMenu();
}
