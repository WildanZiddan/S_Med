    void dataTransaksiPembelian(){
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(43, y);
    generateid("TRSBO",trsbo.id_transaksi);
    gotoxy(60, y);
    printf("%02d/%02d/%04d\n", trsbo.tgl_pembelian.hari,trsbo.tgl_pembelian.bulan,trsbo.tgl_pembelian.tahun);
    gotoxy(80, y);
    printf("%s\n", trsbo.FName);
    gotoxy(120, y);
    rupiah(trsbo.total_harga,inputrp);
    printf("%s",inputrp);
}

void dataDetailTransaksiPembelian(){
    gotoxy(38, y);
    printf("%d", a);
    gotoxy(43, y);
    generateid("TRSBO",dtbo.id_transaksi);
        if(dtbo.id_transaksi && dtbo.id_Obat) {
            gotoxy(57, y);
            generateid("OBT",dtbo.id_Obat);
        }
        else if (dtbo.id_transaksi && dtbo.id_Alat) {
            gotoxy(57, y);
            generateid("ALT",dtbo.id_Alat);
        }
    gotoxy(69, y);
    printf("%s\n", dtbo.nama);
    gotoxy(100, y);
    rupiah(dtbo.harga,inputrp);
    printf("%s",inputrp);
    gotoxy(128, y);
    printf("%d\n", dtbo.jumlah);
    gotoxy(140, y);
    rupiah(dtbo.subtotal,inputrp);
    printf("%s",inputrp);

}

void readAllDataTransaksiPembelian(){
    boxSearch();
    gotoprinttext(138,10,"CARI   : TRSBO");
    tampilanTableTransaksiPembelianObat();
    i = 1;
    y = 16;
    arspbeliobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/transaksibeli.dat", "rb+");
    while (fread(&trsbo, sizeof(trsbo), 1, arspbeliobat) == 1 ) {
        if (i % 2 == 0) {
            SetColorBlock(15,4);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            dataTransaksiPembelian();
        } else {
            SetColorBlock(7,9);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            dataTransaksiPembelian();
        }
        batasTable();
        i++;
        y++;
    }
    fclose(arspbeliobat);
}

void lihatDetailTransaksiPembelianOwner(){
    boxSearch();
    gotoprinttext(138,10,"CARI   : TRSBO");
    gotoprinttext(152, 10, "       ");
    gotoxy(152, 10);
    showCursor();
    getnum(&temptrsbo.id_transaksi, 3);
    hideCursor();
    arsdetailbeliobat = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/detailpembelian.dat", "rb+");
    fread(&dtbo,sizeof(dtbo),1,arsdetailbeliobat);
    found = 0;
    while(!feof(arsdetailbeliobat) && found==0){
        if (temptrsbo.id_transaksi == dtbo.id_transaksi){ /* mengecek apakah id yang dicari ada dalam id transaksi */
            found = 1;
        }else {
            fread(&dtbo, sizeof(dtbo), 1, arsdetailbeliobat);
        }
    }
    fclose(arsdetailbeliobat);
    if(found == 0) {
        cancel = MessageBoxA(NULL,"ID Transaksi Tidak ada!, Anda ingin mencari lagi?","ATTENTION",MB_OKCANCEL |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
        if(cancel == IDOK) {
            BlankDashboard();
            readAllDataTransaksiMerchandise();
            lihatDetailTransaksiMerchandiseKasir();
        } else if (cancel == IDCANCEL){
            BlankDashboard();
            transaksiMerchandiseMenuKasir();
        }
    }

    if(found == 1) {
        a = 1;
        y = 16;
        BlankDashboard();
        tampilanDetailTableTransaksiMerchandise();
        /* buka file untuk dibaca */
        arsdetail = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/DetailMerchandise.dat", "rb");
        fread(&dtmc, sizeof(dtmc), 1, arsdetail);
        while (fread(&dtmc, sizeof(dtmc), 1, arsdetail) == 1) {
            if (temptrsmc.id_transaksi == dtmc.id_transaksi) { /* munculkan data yang id nya sesuai saja */
                if (a % 2 == 0) {
                    SetColorBlock(7, 1);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiMerchandise();
                } else {
                    SetColorBlock(7, 9);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiMerchandise();
                }
                batasTable();
                a++;
                y++;
            }
        }
        fclose(arsdetail);
    }
    SpecialKeyCariorBackDashboard(150, 40,10,9,7,&output);
    switch (output) {
        case 1 :
            SetColorBlock(1,7);
            readAllDataTransaksiMerchandise();
            lihatDetailTransaksiMerchandiseKasir();
            break;

        case 2:
            BlankDashboard();
            transaksiMerchandiseMenuKasir();
            break;
    }

}


void lihatDetailTransaksiMerchandiseAdmin(){
    boxSearch();
    gotoprinttext(138,10,"CARI   : TRSMC");
    gotoprinttext(152, 10, "       ");
    gotoxy(152, 10);
    showCursor();
    getnum(&temptrsmc.id_transaksi, 3);
    hideCursor();
    arsdetail = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/DetailMerchandise.dat", "rb+");
    fread(&dtmc,sizeof(dtmc),1,arsdetail);
    found = 0;
    while(!feof(arsdetail) && found==0){
        if (temptrsmc.id_transaksi == dtmc.id_transaksi){ /* mengecek apakah id yang dicari ada dalam id transaksi */
            found = 1;
        }else {
            fread(&dtmc, sizeof(dtmc), 1, arsdetail);
        }
    }
    fclose(arsdetail);
    if(found == 0) {
        cancel = MessageBoxA(NULL,"ID Transaksi Tidak ada!, Anda ingin mencari lagi?","ATTENTION",MB_OKCANCEL |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
        if(cancel == IDOK) {
            BlankDashboard();
            readAllDataTransaksiMerchandise();
            lihatDetailTransaksiMerchandiseAdmin();
        } else if (cancel == IDCANCEL){
            BlankDashboard();
            dataTransaksiMenuAdmin();
        }
    }

    if(found == 1) {
        a = 1;
        y = 16;
        BlankDashboard();
        tampilanDetailTableTransaksiMerchandise();
        /* buka file untuk dibaca */
        arsdetail = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/DetailMerchandise.dat", "rb");
        fread(&dtmc, sizeof(dtmc), 1, arsdetail);
        while (fread(&dtmc, sizeof(dtmc), 1, arsdetail) == 1) {
            if (temptrsmc.id_transaksi == dtmc.id_transaksi) { /* munculkan data yang id nya sesuai saja */
                if (a % 2 == 0) {
                    SetColorBlock(7, 1);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiMerchandise();
                } else {
                    SetColorBlock(7, 9);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiMerchandise();
                }
                batasTable();
                a++;
                y++;
            }
        }
        fclose(arsdetail);
    }
    SpecialKeyCariorBackDashboard(150, 40,10,9,7,&output);
    switch (output) {
        case 1 :
            SetColorBlock(1,7);
            readAllDataTransaksiMerchandise();
            lihatDetailTransaksiMerchandiseAdmin();
            break;

        case 2:
            BlankDashboard();
            dataTransaksiMenuAdmin();
            break;
    }

}
