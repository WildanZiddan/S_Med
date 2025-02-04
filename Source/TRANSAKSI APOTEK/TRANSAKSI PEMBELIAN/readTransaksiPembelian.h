    void dataTransaksiPembelian(){
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(43, y);
    generateid("TRSBO",trsbo.id_transaksi);
    gotoxy(60, y);
    printf("%02d/%02d/%04d\n", trsbo.tgl_pembelian.hari,trsbo.tgl_pembelian.bulan,trsbo.tgl_pembelian.tahun);
    gotoxy(75, y);
    printf("%s\n", trsbo.FName);
        gotoxy(100, y);
        printf("SUP%03d\n", trsbo.id_Supplier);
    gotoxy(125, y);
    rupiah(trsbo.total_harga,inputrp);
    printf("%s",inputrp);
        gotoxy(144, y);
        printf("%s",trsbo.status);
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
    arspbeliobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/transaksibeli.dat", "rb+");
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
            SetColorBlock(15,12);
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
    arsdetailbeliobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/detailpembelian.dat", "rb+");
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
            readAllDataTransaksiPembelian();
            lihatDetailTransaksiPembelianOwner();
        } else if (cancel == IDCANCEL){
            BlankDashboard();
            dataTransaksiPembelianMenu();
        }
    }

    if(found == 1) {
        a = 1;
        y = 16;
        BlankDashboard();
        tampilanDetailTableTransaksiPembelian();
        /* buka file untuk dibaca */
        arsdetailbeliobat = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/detailpembelian.dat", "rb");
        fread(&dtbo, sizeof(dtbo), 1, arsdetailbeliobat);
        while (fread(&dtbo, sizeof(dtbo), 1, arsdetailbeliobat) == 1) {
            if (temptrsbo.id_transaksi == dtbo.id_transaksi) { /* munculkan data yang id nya sesuai saja */
                if (a % 2 == 0) {
                    SetColorBlock(15, 4);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiPembelian();
                } else {
                    SetColorBlock(15, 12);
                    for (x = y; x <= y; x++) {
                        for (j = 37; j < 167; j++) {
                            gotoprintchar(j, x, 32);
                        }
                    }
                    dataDetailTransaksiPembelian();
                }
                batasTable();
                a++;
                y++;
            }
        }
        fclose(arsdetailbeliobat);
    }
    SpecialKeyCariorBackDashboard(150, 40,10,12,15,&output);
    switch (output) {
        case 1 :
            SetColorBlock(4,15);
            readAllDataTransaksiPembelian();
            lihatDetailTransaksiPembelianOwner();
            break;

        case 2:
            BlankDashboard();
            dataTransaksiPembelianMenu();
            break;
    }

}

void readCreateTransaksiinPenjadwalan(){
        SetColorBlock(15,4);
        for(i = 17; i <= 19;i++){
            for(j = 130; j < 167; j++){
                gotoprintchar(j,i,32);
            }
        }

        gotoprinttext(131,18,"NO.");
        gotoprinttext(134,18,"ID TRANSAKSI");
        i = 1;
        y = 20;
        arspbeliobat = fopen("../CRUD MASTER/../Source/../Database/Dat/transaksibeli.dat", "rb+");
        while (fread(&trsbo, sizeof(trsbo), 1, arspbeliobat) == 1 ) {
            if (i % 2 == 0) {
                SetColorBlock(15,4);
                for(x = y; x <= y;x++){
                    for(j = 130; j < 167; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                gotoxy(131, y);
                printf("%d", i);
                gotoxy(134, y);
                generateid("TRSBO",trsbo.id_transaksi);
            } else {
                SetColorBlock(15,12);
                for(x = y; x <= y;x++){
                    for(j = 130; j < 167; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                gotoxy(131, y);
                printf("%d", i);
                gotoxy(134, y);
                generateid("TRSBO",trsbo.id_transaksi);
            }
            i++;
            y++;
        }
        fclose(arspbeliobat);
    }
/*
void lihatDetailTransaksiPembelianAdmin(){
    boxSearch();
    gotoprinttext(138,10,"CARI   : TRSBO");
    gotoprinttext(152, 10, "       ");
    gotoxy(152, 10);
    showCursor();
    getnum(&temptrsmc.id_transaksi, 3);
    hideCursor();
    arsdetail = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/DetailMerchandise.dat", "rb+");
    fread(&dtmc,sizeof(dtmc),1,arsdetail);
    found = 0;
    while(!feof(arsdetail) && found==0){
        if (temptrsmc.id_transaksi == dtmc.id_transaksi){ /* mengecek apakah id yang dicari ada dalam id transaksi #1#
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
        /* buka file untuk dibaca #1#
        arsdetail = fopen("../TRANSAKSI BIOSKOP/../Source/../Database/Dat/DetailMerchandise.dat", "rb");
        fread(&dtmc, sizeof(dtmc), 1, arsdetail);
        while (fread(&dtmc, sizeof(dtmc), 1, arsdetail) == 1) {
            if (temptrsmc.id_transaksi == dtmc.id_transaksi) { /* munculkan data yang id nya sesuai saja #1#
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
*/
