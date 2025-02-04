void TambahDetailPembelianObat();
void TambahDetailPembelianAlat();
void obat();
void alat();
void pilihan();
void tambah();
void BayarPO();
void readCreateSupplierinTransaksi();


void dataPembelianObatTransaksi(){
    gotoxy(120, y);
    printf("%d", i);
    gotoxy(126, y);
    generateid("OBT",obt.id_Obat);
    gotoxy(136, y);
    printf("%s\n", obt.nama_Obat);
    gotoxy(161, y);
    printf("%d",obt.jumlahObat);
}

void dataPembelianAlatTransaksi(){
    gotoxy(120, y);
    printf("%d", i);
    gotoxy(126, y);
    generateid("ALT",alt.id_Alat);
    gotoxy(136, y);
    printf("%s\n", alt.nama_Alat);
    gotoxy(161, y);
    printf("%d",alt.jumlahAlat);
}

void lihatObat(){
    tampilanTransaksiPembelianObat();
    i = 1;
    y = 15;
    arspobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/obat.dat", "rb+");
    while (fread(&obt, sizeof(obt), 1, arspobat) == 1 ) {
        if(obt.jumlahObat > 0) {
            if (i % 2 == 0) {
                SetColorBlock(15,4);
                for(x = y; x <= y;x++){
                    for(j = 119; j < 168; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                dataPembelianObatTransaksi();


            } else {
                SetColorBlock(15,12);
                for(x = y; x <= y;x++){
                    for(j = 119; j < 168; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                dataPembelianObatTransaksi();
            }
            batasTable();
            i++;
            y++;
        }
    }
    fclose(arspobat);
}

void lihatAlat(){
    tampilanTransaksiPembelianAlat();
    i = 1;
    y = 15;
    arspalat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/alatkesehatan.dat", "rb+");
    while (fread(&alt, sizeof(alt), 1, arspalat) == 1 ) {
        if(alt.jumlahAlat > 0) {
            if (i % 2 == 0) {
                SetColorBlock(15,4);
                for(x = y; x <= y;x++){
                    for(j = 119; j < 168; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                dataPembelianAlatTransaksi();


            } else {
                SetColorBlock(15,12);
                for(x = y; x <= y;x++){
                    for(j = 119; j < 168; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                dataPembelianAlatTransaksi();
            }
            batasTable();
            i++;
            y++;
        }
    }
    fclose(arspalat);
}

void TambahTPembelianObat() {
    found = 0;
    i = 0;
    total = 0;
    arskrj = fopen ("../TRANSAKSI APOTEK/../Source/../Database/Dat/keranjang.dat", "wb");
    fclose(arskrj);
    trsbo.total_harga = 0;
    arspbeliobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/transaksibeli.dat", "ab+");
    fread(&trsbo,sizeof(trsbo),1,arspbeliobat);
    while(!feof(arspbeliobat)){
        fread(&trsbo,sizeof(trsbo),1,arspbeliobat);
        id = trsbo.id_transaksi;
        i++;
    }
    if(i==0){
        trsbo.id_transaksi = 1;
    }else{
        trsbo.id_transaksi = id+1;
    }
    SetColorBlock(15,12);
    gotoxy(40, 13);
    printf("I D  T R A N S A K S I     :");
    gotoxy(70, 13);
    generateid("TRSBO",trsbo.id_transaksi);
    do{
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreateSupplierinTransaksi();
        gotoxy(40, 19);
        SetColorBlock(15,12);
        printf("I D  S U P P L I E R       :  SUP");
        gotoxy(73, 19);
        getnum(&trsbo.id_Supplier,3);
        found = 0;
        if(trsbo.id_Supplier == 0){
            fclose(arspsupplier);
            BlankDashboard();
            menuOpsiDashboardOwner();
        }
        arspsupplier = fopen("../CRUD MASTER/../Source/../Database/Dat/supplier.dat","rb");
        while(fread(&sp,sizeof (sp),1,arspsupplier)==1){
            if(trsbo.id_Supplier == sp.id_Supplier){
                found = 1;
                trsbo.id_Supplier = sp.id_Supplier;
            }
        }
        if (found == 0){
            MessageBox(NULL,"Maaf ID Supplier Tidak Tersedia","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(70,19,10,1);
        }
        BlankDesain();
        hideCursor();
    }while(found == 0);
        BlankTeks();
        fclose(arspbeliobat);
    TambahDetailPembelianObat();
}

void TambahDetailPembelianObat(){
    FILE *Temp;
    found = 0;
    SetColorBlock(15,12);
    dtbo.id_transaksi = trsbo.id_transaksi;
    gotoxy(40,13);
    printf("I D  T R A N S A K S I     :");
    gotoxy(70,13);
    generateid("TRSBO",dtbo.id_transaksi);

    gotoxy(40, 15);
    printf("T G L  P E M B E L I A N   :");
    gotoprinttext(69, 15, "  /  /     \n");
    do {
        gotoxy(69, 15);
        getnum(&trsbo.tgl_pembelian.hari,2);
        if(trsbo.tgl_pembelian.hari > 31 || trsbo.tgl_pembelian.hari < 1 ){
            MessageBox(NULL,"Jangka Inputan hari 1 - 31","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(69,15,2,1);
        }
    }
    while(trsbo.tgl_pembelian.hari > 31 || trsbo.tgl_pembelian.hari < 1 );
    do {
        gotoxy(72, 15);
        getnum(&trsbo.tgl_pembelian.bulan,2);
        if(trsbo.tgl_pembelian.bulan > 12 || trsbo.tgl_pembelian.bulan < 1 ){
            MessageBox(NULL,"Jangka Inputan bulan 1 - 12","NOTIFICATION!",MB_OK|MB_ICONINFORMATION|MB_DEFAULT_DESKTOP_ONLY);
            clearArea(72,15,2,1);
        }
    }while(trsbo.tgl_pembelian.bulan > 12 || trsbo.tgl_pembelian.bulan < 1);
    do {
        gotoxy(75, 15);
        getnum(&trsbo.tgl_pembelian.tahun, 4);
        hideCursor();
        if (trsbo.tgl_pembelian.tahun < 2024 || trsbo.tgl_pembelian.tahun > 2028) {
            MessageBox(NULL, "Jangka Inputan tahun 2024 - 2028", "NOTIFICATION!",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(75, 15, 4, 1);
        }
    }while(trsbo.tgl_pembelian.tahun < 2024  || trsbo.tgl_pembelian.tahun > 2028);
    gotoxy(40, 17);
    printf("T G L  P E N E R I M A A N :");
    gotoxy(40,19);
    printf("I D  S U P P L I E R       :");
    gotoxy(70,19);
    printf("SUP%03d",trsbo.id_Supplier);
    SetColorBlock(15,12);
    showCursor();
        tambah();
    }




void BayarPO() {
    char ans, uang[25];
    SetColorBlock(15,12);
    gotoxy(40, 31);
    rupiah(trsbo.total_harga,inputrp);
    printf("T O T A L  H A R G A       : %s",inputrp);

    strcpy(trsbo.status, status[0]);
    gotoxy(40, 33);
    printf("S T A T U S                : %s", trsbo.status);

    strcpy(trsbo.FName, k.FName);
    gotoxy(40, 35);
    printf("S T A F F                  : %s", trsbo.FName);

    arspbeliobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/transaksibeli.dat", "ab");
    fwrite(&trsbo, sizeof(trsbo), 1, arspbeliobat);
    fclose(arspbeliobat);
    remove("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/Keranjang.dat");

    MessageBox(NULL, "Transaksi berhasil!", "NOTIFICATION", MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);

    do {
        gotoxy(132, 35);
        printf("Tambah transaksi lagi ? ");
        SpecialKeyYesorNoDashboard(145, 37,10,4,15,&output);
        switch (output) {
            case 1:
                clearTransaksi();
                clearTableTransaksi();
                TambahTPembelianObat(); //Ganti ke opsi juga
                break;
            case 2:
                BlankDashboard();
                menuOpsiDashboardOwner();
                break;
        }
    } while (output == 1);

}
void createTransaksiObat(){
    frameTransaksi(42, 12);
    SetColorBlock(15,12);
    TambahTPembelianObat();
    fclose(arspbeliobat);
}

void obat() {
    showCursor();
    gotoxy(73,21);	printf("   ");
    gotoxy(40,21);
    printf("I D  O B A T               : OBT ");
    gotoxy(72,21);
    getnum(&dtbo.id_Obat,3);
    hideCursor();
    fflush(stdin);

    arspobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/obat.dat","rb");
    fread(&obt,sizeof(obt),1,arspobat);
    found = 0;
    while(!feof(arspobat) && !found){
        if (dtbo.id_Obat == obt.id_Obat && obt.jumlahObat < 5){
            strcpy(dtbo.nama,obt.nama_Obat);
            dtbo.harga = obt.harga_Obat;
            cekstok = obt.jumlahObat;
            found = 1;
        }else if(dtbo.id_Obat == obt.id_Obat && obt.jumlahObat > 3){
            found = 2;
        }
        fread(&obt,sizeof(obt),1,arspobat);
    }
    fclose(arspobat);
}

void alat() {
    showCursor();
    gotoxy(73,21);	printf("   ");
    gotoxy(40,21);
    printf("I D  A L A T               : ALT ");
    gotoxy(72,21);
    getnum(&dtbo.id_Alat,3);
    hideCursor();
    fflush(stdin);

    arspalat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/alatkesehatan.dat","rb");
    fread(&alt,sizeof(alt),1,arspalat);
    found = 0;
    while(!feof(arspalat) && !found){
        if (dtbo.id_Alat == alt.id_Alat && alt.jumlahAlat < 5){
            strcpy(dtbo.nama,alt.nama_Alat);
            dtbo.harga = alt.harga_Alat;
            cekstok = alt.jumlahAlat;
            found = 1;
        }else if(dtbo.id_Alat == alt.id_Alat && alt.jumlahAlat > 3){
            found = 2;
        }
        fread(&alt,sizeof(alt),1,arspalat);
    }
    fclose(arspalat);
}

void pilihan() {
    gotoxy(73,21);	printf("   ");
    gotoxy(40,21);
    printf("P I L I H A N              :  ");
    gotoxy(69,21);
    scanf("%d", &trsbo.pilihan);
    hideCursor();
}

void tambah(){
    gotoxy(40,23);
    printf("N A M A  B A R A N G       :");
    gotoxy(40,25);
    printf("H A R G A  B A R A N G     : ");
    gotoxy(40,27);
    printf("Q U A N T I T Y            : ");
    gotoxy(40,29);
    printf("S U B T O T A L            : ");
    gotoxy(40, 31);
    printf("T O T A L  H A R G A       : ");
    showCursor();

    do {
        pilihan();
        if(trsbo.pilihan == 1) {
            lihatObat();
            obat();
            while(found != 1) {
                if (found == 0){
                    MessageBoxA(NULL,"ID Obat tidak ada!","ATTENTION",MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
                    obat();
                }
                else if( found == 2){
                    MessageBoxA(NULL,"ID Obat Tersedia, stok masih cukup!","ATTENTION",MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
                    obat();
                }
            }
        }
        else if(trsbo.pilihan == 2) {
            lihatAlat();
            alat();
            while(found != 1) {
                if (found == 0){
                    MessageBoxA(NULL,"ID Alat tidak ada!","ATTENTION",MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
                    alat();
                }
                else if( found == 2){
                    MessageBoxA(NULL,"ID Alat Tersedia, stok masih cukup!","ATTENTION",MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
                    alat();
                }
            }
        }
        else {
            MessageBoxA(NULL,"Pilihan tidak ada!","ATTENTION",MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
            clearArea(69,21,1,1);
        }
    }while(trsbo.pilihan != 1 && trsbo.pilihan != 2);


    clearTableTransaksi();
    SetColorBlock(15,12);
    gotoxy(69,23);
    printf("%s",dtbo.nama);
    gotoxy(69,25);
    rupiah(dtbo.harga,inputrp);
    printf("%s",inputrp);

    do {
        gotoxy(69,27);	printf("         ");
        showCursor();
        fflush(stdin);
        gotoxy(69,27);
        getnum(&dtbo.jumlah,3);
        hideCursor();
    } while (dtbo.jumlah  <= 0);

    dtbo.subtotal = dtbo.jumlah * dtbo.harga;
    gotoxy(40,29);
    rupiah(dtbo.subtotal,uang);
    printf("S U B T O T A L            : %s\n", uang);
    showDetail();
    SetColorBlock(15,12);
    total = total + dtbo.subtotal;
    gotoxy(120,19);	rupiah(total,uang); printf("Total Harga = %s", uang);

    strcpy(krj.nama,dtbo.nama);
    krj.qty = dtbo.jumlah;

    /* buka file untuk menambah data */
    arsdetailbeliobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/detailpembelian.dat","ab+");
    fwrite(&dtbo,sizeof(dtbo),1,arsdetailbeliobat);
    fclose(arsdetailbeliobat);

    if(trsbo.pilihan == 1) {
        arspobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/obat.dat","rb");
        Temp  = fopen ("../TRANSAKSI APOTEK/../Source/../Database/Dat/tempobat.dat","wb");
        fread(&obt,sizeof(obt),1,arspobat);
        while(!feof(arspobat)){
            if(dtbo.id_Obat == obt.id_Obat){
                obt.jumlahObat = obt.jumlahObat+dtbo.jumlah;
                fwrite(&obt,sizeof(obt),1,Temp);
            }else{
                fwrite(&obt,sizeof(obt),1,Temp);
            }
            fread(&obt,sizeof(obt),1,arspobat);
        }
        fclose(arspobat);
        fclose(Temp);

        /* mengganti data makanan terbaru */
        remove("../TRANSAKSI APOTEK/../Source/../Database/Dat/obat.dat");
        rename("../TRANSAKSI APOTEK/../Source/../Database/Dat/tempobat.dat","../TRANSAKSI APOTEK/../Source/../Database/Dat/obat.dat");

    }
    else if(trsbo.pilihan == 2) {
        arspalat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/alatkesehatan.dat","rb");
        Temp  = fopen ("../TRANSAKSI APOTEK/../Source/../Database/Dat/tempalat.dat","wb");
        fread(&alt,sizeof(alt),1,arspalat);
        while(!feof(arspalat)){
            if(dtbo.id_Alat == alt.id_Alat){
                alt.jumlahAlat = alt.jumlahAlat+dtbo.jumlah;
                fwrite(&alt,sizeof(alt),1,Temp);
            }else{
                fwrite(&alt,sizeof(alt),1,Temp);
            }
            fread(&alt,sizeof(alt),1,arspalat);
        }
        fclose(arspalat);
        fclose(Temp);

        /* mengganti data makanan terbaru */
        remove("../TRANSAKSI APOTEK/../Source/../Database/Dat/alatkesehatan.dat");
        rename("../TRANSAKSI APOTEK/../Source/../Database/Dat/tempalat.dat","../TRANSAKSI APOTEK/../Source/../Database/Dat/alatkesehatan.dat");
    }


    gotoxy(120,23); printf("Keranjang Belanja");
    arskrj = fopen ("../TRANSAKSI APOTEK/../Source/../Database/Dat/Keranjang.dat", "ab");
    fwrite(&krj,sizeof(krj),1,arskrj);
    fclose(arskrj);

    int Baris=24, Kolom=120;
    arskrj = fopen ("../TRANSAKSI APOTEK/../Source/../Database/Dat/Keranjang.dat", "rb");
    fread(&krj,sizeof(krj),1,arskrj);
    while(!feof(arskrj)){
        Baris++;
        if(Baris%2==0)
        {
            gotoxy(Kolom,Baris);
        }
        else
        {
            gotoxy(Kolom,Baris);
        }
        gotoxy(Kolom,Baris); printf("- %s X %d\n", krj.nama,krj.qty);
        fread(&krj,sizeof(krj),1,arskrj);
    }
    fclose(arskrj);

    do {
        gotoxy(143,19); printf("   ");
        gotoxy(134,19); printf("Tambah item lagi?");
        SpecialKeyYesorNoDashboard(145, 21,10,15,12,&output);
        switch(output){
            case 1 :
                clearTableTransaksi();
                clearTransaksi();
            TambahDetailPembelianObat();
                break;
            case 2 :
                trsbo.total_harga = total;
                BayarPO();
                break;
        }
        } while (output == 1);
}