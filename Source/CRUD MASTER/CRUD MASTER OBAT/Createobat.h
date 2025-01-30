void readCreateJenisinObat();
void createDataObat(){;
    SetColorBlock(4,15);
    //DrawFile(50,9,"../CRUD MASTER/../Source/../Desaintxt/Dashboard/tambahData.txt");
    //DrawFile(130,21,"../CRUD MASTER/../Source/../Desaintxt/elemen/pensil.txt");
    gotoxy(135,16);
    printf("Ketik 0 lalu enter untuk Batal");
    gotoxy(135,17);
    printf("Hanya pada inputan alphanumber");
    arspobat = fopen("../CRUD MASTER/../Source/../Database/Dat/obat.dat", "ab+");
    i = 0;
    fread(&obt,sizeof(obt),1,arspobat);
    while(!feof(arspobat)){
        fread(&obt,sizeof(obt),1,arspobat);
        id = obt.id_Obat;
        i++;
    }

    if(i==0){
        obt.id_Obat = 1;
    }else{
        obt.id_Obat = id + 1;
    }
    gotoxy(40, 17);
    printf("I D   O B A T                  :");
    gotoxy(73, 17);
    generateid("OBT",obt.id_Obat);
    fflush(stdin);
    showCursor();
    gotoxy(40, 19);
    printf("N A M A  O B A T               :");
    gotoxy(73, 19);
    getinput(&obt.nama_Obat,20,2);
    hideCursor();
    if(strcmp(obt.nama_Obat,"0")==0){
        fclose(arspobat);
        BlankDashboard();
        dataObatMenu();
    }
    fflush(stdin);
    hideCursor();
    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreateJenisinObat();
        gotoxy(40, 21);
        SetColorBlock(4,15);
        printf("I D  J E N I S                 : JNS");
        gotoxy(76, 21);
        getnum(&obt.id_JenisObat,3);
        found = 0;
        if(strcmp(obt.nama_Obat,"0")==0){
            fclose(arspjenisobat);
            BlankDashboard();
            dataObatMenu();
        }
        arspjenisobat = fopen("../CRUD MASTER/../Source/../Database/Dat/jenisobat.dat","rb");
        while(fread(&jns_obt,sizeof (jns_obt),1,arspjenisobat)==1){
            if(obt.id_JenisObat == jns_obt.id_JenisObat){
                found = 1;
                obt.id_JenisObat = jns_obt.id_JenisObat;
                strcpy(obt.nama_Jenis,jns_obt.nama_Jenis);
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID Jenis Obat Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(75,29,3,1);
        }
        BlankDesain();
        hideCursor();
    }while(found == 0);
    SetColorBlock(4,15);
    fclose(arspjenisobat);
    fflush(stdin);
    gotoxy(40, 23);
    printf("N A M A  J E N I S             :");
    gotoxy(73, 23);
    printf("%s",obt.nama_Jenis);

    fflush(stdin);
    showCursor();
    gotoxy(40, 25);
    printf("H A R G A  O B A T             : Rp.");
    gotoxy(77, 25);
    getRp(&obt.harga_Obat,4,9,77,25);
    hideCursor();
    //cancelCharFilm(mk.nama_Makanan);
    do{
        found = 0;
        fflush(stdin);
        showCursor();
        gotoxy(40, 27);
        printf("T A N G G A L  K E D A L U W A R S A:");
        gotoxy(79, 27);
        getyear(&obt.tanggalKedaluwarsa.tahun,4);
        if(obt.tanggalKedaluwarsa.tahun < 2025 ){
            clearArea(79,27,6,1);
            MessageBox(NULL,"Maaf, Obat sudah kedaluwarsa.","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            found = 1;
        }else if(obt.tanggalKedaluwarsa.tahun > 2028){
            clearArea(79,27,6,1);
            MessageBox(NULL,"Maaf, obat tidak bisa bertahan lebih dari 3 tahun!","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            found = 1;
        }
    }while(found);

    fflush(stdin);
    showCursor();
    gotoxy(40, 29);
    printf("J U M L A H  O B A T           :");
    do {
        gotoxy(73, 29);
        scanf("%d", &obt.jumlahObat);
        fflush(stdin);
    }while(obt.jumlahObat <= 0);
    hideCursor();
    fflush(stdin);
    hideCursor();

    fwrite(&obt, sizeof(obt), 1, arspobat);
    fclose(arspobat);
    BlankDashboard();
    dataObatMenu();
}
