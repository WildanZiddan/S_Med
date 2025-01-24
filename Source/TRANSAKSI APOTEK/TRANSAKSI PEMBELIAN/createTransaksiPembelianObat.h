void TambahDetailPembelianObat();
void BayarPO();
void dataPembelianObatTransaksi(){
    gotoxy(120, y);
    printf("%d", i);
    if (id == obt.id_Obat)
    gotoxy(126, y);
    generateid("OBT",obt.id_Obat);
    gotoxy(136, y);
    printf("%s\n", obt.nama_Obat);
    gotoxy(161, y);
    printf("%d",obt.jumlahObat);
}

void lihatMakanan(){
    tampilanTransaksiPembelianObat();
    i = 1;
    y = 15;
    arspobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/obat.dat", "rb+");
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
void TambahTPembelianObat() {
    found = 0;
    i = 0;
    total = 0;
    arskrj = fopen ("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/keranjang.dat", "wb");
    fclose(arskrj);
    trsbo.total_harga = 0;
    arspbeliobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/TransaksiObat.dat", "ab+");
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
    gotoxy(40, 17);
    printf("I D  T R A N S A K S I     :");
    gotoxy(59, 17);
    generateid("TRSBO",trsbo.id_transaksi);
    fclose(arspbeliobat);
    TambahDetailPembelianObat();
}

void TambahDetailPembelianObat(){
    FILE *Temp;
    found = 0;
    SetColorBlock(15,12);
    dtbo.id_transaksi = trsbo.id_transaksi;
    gotoxy(40,17);
    printf("I D  T R A N S A K S I     :");
    gotoxy(70,17);
    generateid("TRSBO",dtbo.id_transaksi);
    gotoxy(40, 19);
    printf("T G L  P E M B E L I A N   :");
    gotoxy(69, 19);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    trsbo.tgl_pembelian.hari = tm.tm_mday;
    trsbo.tgl_pembelian.bulan = tm.tm_mon + 1;
    trsbo.tgl_pembelian.tahun = tm.tm_year + 1900;
    printf("%02d/%02d/%04d",trsbo.tgl_pembelian.hari,trsbo.tgl_pembelian.bulan,trsbo.tgl_pembelian.tahun);
    lihatMakanan();
    SetColorBlock(15,12);
    gotoxy(40,23);
    printf("N A M A  M A K A N A N     :");
    gotoxy(40,25);
    printf("H A R G A  M A K A N A N   : ");
    gotoxy(40,27);
    printf("Q U A N T I T Y            : ");
    gotoxy(40,29);
    printf("S U B T O T A L            : ");
    gotoxy(40, 31);
    printf("T O T A L  H A R G A       : ");
    gotoxy(40, 33);
    printf("U A N G  T U N A I         : ");
    gotoxy(40, 35);
    printf("K E M B A L I A N          : ");
    showCursor();
    gotoxy(71,21);	printf("   ");
    gotoxy(40,21);
    printf("I D  O B A T            : OBT");
    gotoxy(71,21);
    getnum(&dtbo.id_Obat,3);
    hideCursor();
    fflush(stdin);
    // if (dtbo.id_Obat == 0){
    //     BlankDashboard();
    //     menuTransaksiMakananKasir();
    // }

    arspobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/obat.dat","rb");
    fread(&obt,sizeof(obt),1,arspobat);
    found = 0;
    while(!feof(arspobat) && !found){
        if (dtbo.id_Obat == obt.id_Obat && obt.jumlahObat < 5){
            strcpy(dtbo.nama_Obat,obt.nama_Obat);
            dtbo.harga_Obat = obt.harga_Obat;
            cekstok = obt.jumlahObat;
            found = 1;
        }else if(dtbo.id_Obat == obt.id_Obat && obt.jumlahObat >= 5){
            found = 2;
        }
        fread(&obt,sizeof(obt),1,arspobat);
    }
    fclose(arspobat);

    if (found == 0){
        MessageBoxA(NULL,"ID Obat tidak ada!","ATTENTION",MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
        TambahDetailPembelianObat();
    } else if( found == 2){
        MessageBoxA(NULL,"ID Obat Tersedia, stok masih cukup!","ATTENTION",MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
        TambahDetailPembelianObat();
    }

    clearTableTransaksi();
    SetColorBlock(15,12);
    gotoxy(69,23);
    printf("%s",dtbo.nama_Obat);
    gotoxy(69,25);
    rupiah(dtbo.harga_Obat,inputrp);
    printf("%s",inputrp);

    do {
        gotoxy(69,27);	printf("         ");
        showCursor();
        fflush(stdin);
        gotoxy(69,27);
        getnum(&dtbo.jumlahObat,3);
        hideCursor();

        if(dtbo.jumlahObat <= 0){
            clearTransaksi();
            TambahDetailPembelianObat();
        }
    } while (dtbo.jumlahObat < 5);

    dtbo.subtotal = dtbo.jumlahObat * dtbo.harga_Obat;
    rupiah(dtbo.subtotal,uang);
    gotoxy(40,29);
    printf("S U B T O T A L            : %s\n", uang);
    showDetail();
    SetColorBlock(15,12);
    total = total + dtbo.subtotal;
    gotoxy(120,17);	rupiah(total,uang); printf("Total Harga = %s", uang);

    strcpy(krj.nama,dtbo.nama_Obat);
    krj.qty = dtbo.jumlahObat;

    /* buka file untuk menambah data */
    arsdetailbeliobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/detailpembelianobat.dat","ab+");
    fwrite(&dtbo,sizeof(dtbo),1,arsdetailbeliobat);
    fclose(arsdetailbeliobat);

    /* proses pengurangan stok */
    arspobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/obat.dat","rb");
    Temp  = fopen ("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/tempobat.dat","wb");
    fread(&obt,sizeof(obt),1,arspobat);
    while(!feof(arspobat)){
        if(dtbo.id_Obat == obt.id_Obat){
            obt.jumlahObat = obt.jumlahObat+dtbo.jumlahObat;
            fwrite(&obt,sizeof(obt),1,Temp);
        }else{
            fwrite(&obt,sizeof(obt),1,Temp);
        }
        fread(&obt,sizeof(obt),1,arspobat);
    }
    fclose(arspobat);
    fclose(Temp);

    /* mengganti data makanan terbaru */
    remove("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/obat.dat");
    rename("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/tempobat.dat","../TRANSAKSI BIOSKOP/../Source/../Database/Dat/obat.dat");

    gotoxy(120,23); printf("Keranjang Obat");

    arskrj = fopen ("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/Keranjang.dat", "ab");
    fwrite(&krj,sizeof(krj),1,arskrj);
    fclose(arskrj);

    int Baris=24, Kolom=120;
    arskrj = fopen ("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/Keranjang.dat", "rb");
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
        SpecialKeyYesorNoDashboard(145, 21,10,7,9,&output);
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

void BayarPO() {
    char ans, uang[25];
    SetColorBlock(15,12);
    gotoxy(40, 31);
    rupiah(trsbo.total_harga,inputrp);
    printf("T O T A L  H A R G A       : %s",inputrp);


    gotoxy(72, 33);
    printf("              ");
    showCursor();
    gotoxy(40, 33);
    printf("U A N G  T U N A I         : Rp.");
    fflush(stdin);
    getRp(&tunai, 4, 9, 73, 33);
    hideCursor();
    while (tunai < trsbo.total_harga) { /* perulangan jika uang tunai kurang dari total */
        MessageBox(NULL, "Uang yang anda input kurang", "NOTIFICATION!",
                   MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        gotoxy(72, 33);
        printf("              ");
        showCursor();
        gotoxy(40, 33);
        printf("U A N G  T U N A I         : Rp.");
        fflush(stdin);
        getRp(&tunai, 4, 9, 73, 33);
        hideCursor();
    }
    kembali = tunai - trsbo.total_harga;

    gotoxy(40, 35);
    rupiah(kembali, uang);
    printf("K E M B A L I A N          : %s", uang);

    strcpy(trsbo.FName, k.FName);
    gotoxy(40, 37);
    printf("S T A F F                  : %s", trsbo.FName);

    arspbeliobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/transaksibeliobat.dat", "ab");
    fwrite(&trsbo, sizeof(trsbo), 1, arspbeliobat);
    fclose(arspbeliobat);
    remove("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/Keranjang.dat");

    MessageBox(NULL, "Transaksi berhasil!", "NOTIFICATION", MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);

    do {
        gotoxy(132, 35);
        printf("Tambah transaksi lagi ? ");
        SpecialKeyYesorNoDashboard(145, 37,10,7,9,&output);
        switch (output) {
            case 1:
                clearTransaksi();
                clearTableTransaksi();
                TambahTPembelianObat();
                break;
            case 2:
                BlankDashboard();
                menuOpsiDashboardOwner();
                break;
        }
    } while (output == 1);

}
void createTransaksiMakanan(){
    frameTransaksi(42, 12, "../TRANSAKSI BIOSKOP/../Source/../Desaintxt/Dashboard/transaksiMakanan.txt");
    SetColorBlock(15,12);
    TambahTPembelianObat();
    fclose(arspbeliobat);
}
