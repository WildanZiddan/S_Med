void readCreateTransaksiinPenjadwalan();
void TambahDetailPenerimaan();
void dataTransaksiPembelianBarang() {
    gotoxy(120, y);
    printf("%d", i);
    gotoxy(126, y);
    generateid("TRSBO",trsbo.id_transaksi);
    gotoxy(136, y);
    printf("%s\n", trsbo.status);
}

void lihatTransaksiPembelianBarang() {
    tampilanTransaksiPembelianBarang();
    i = 1;
    y = 15;
    arspbeliobat = fopen ("../TRANSAKSI APOTEK/../Source/../Database/Dat/transaksibeli.dat", "rb+");
    while (fread(&trsbo, sizeof(trsbo), 1, arspbeliobat) == 1 ) {
            if (i % 2 == 0) {
                SetColorBlock(15,4);
                for(x = y; x <= y;x++){
                    for(j = 119; j < 168; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                dataTransaksiPembelianBarang();


            } else {
                SetColorBlock(15,12);
                for(x = y; x <= y;x++){
                    for(j = 119; j < 168; j++){
                        gotoprintchar(j,x,32);
                    }
                }
                dataTransaksiPembelianBarang();
            }
            batasTable();
            i++;
            y++;
    }
    fclose(arspbeliobat);
}

void TambahTPenerimaan() {
    found = 0;
    i = 0;
    total = 0;


    arsppenerimaan = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/transaksiterima.dat", "ab+");
    fread(&trspo,sizeof(trspo),1,arsppenerimaan);
    while(!feof(arsppenerimaan)){
        fread(&trspo,sizeof(trspo),1,arsppenerimaan);
        id = trspo.id_transaksi;
        i++;
    }
    if(i==0){
        trspo.id_transaksi = 1;
    }else{
        trspo.id_transaksi = id+1;
    }
    SetColorBlock(15,12);
    gotoxy(40, 13);
    printf("I D  P E N E R I M A A N   :");
    gotoxy(70, 13);
    generateid("TRSPO",trspo.id_transaksi);
    BlankTeks();
    fclose(arsppenerimaan);
    TambahDetailPenerimaan();
}

void TambahDetailPenerimaan() {
    FILE *Temp;
    found = 0;
    SetColorBlock(15,12);
    gotoxy(40,13);
    printf("I D  P E N E R I M A A N   :");
    gotoxy(70,13);
    generateid("TRSPO",trspo.id_transaksi);


    do {
        fflush(stdin);
        showCursor();
        BlankDesain();
        readCreateTransaksiinPenjadwalan();

        gotoxy(40, 15);
        SetColorBlock(15,12);
        printf("I D  T R A N S A K S I     :  TRSBO");

        gotoxy(75, 15);
        getnum(&trspo.id_transaksiBeli, 3);

        found = 0;
        if (trspo.id_transaksiBeli == 0) {
            BlankDashboard();
            menuOpsiDashboardOwner();
            return;  // Exit the function to prevent further execution
        }

        arspbeliobat = fopen("../CRUD MASTER/../Source/../Database/Dat/transaksibeli.dat", "rb");
        if (!arspbeliobat) {
            MessageBox(NULL, "Gagal membuka file transaksi beli", "ERROR!", MB_OK | MB_ICONERROR);
            return;
        }

        while (fread(&trsbo, sizeof(trsbo), 1, arspbeliobat) == 1) {
            if (trspo.id_transaksiBeli == trsbo.id_transaksi) {
                found = 1;

                arsppenerimaan = fopen("../CRUD MASTER/../Source/../Database/Dat/transaksiterima.dat", "rb");
                if (arsppenerimaan) {
                    while (fread(&trspo, sizeof(trspo), 1, arsppenerimaan) == 1) {
                        if (trspo.id_transaksiBeli == trsbo.id_transaksi) {
                            found = 2;
                            MessageBox(NULL, "Transaksi Telah Diterima", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION);
                            clearArea(70, 15, 10, 1);
                        }
                    }
                    fclose(arsppenerimaan);
                }

                trspo.id_transaksiBeli = trsbo.id_transaksi;
                trspo.tgl_pembelian = trsbo.tgl_pembelian;
            }
        }

        fclose(arspbeliobat);

        if (found == 0) {
            MessageBox(NULL, "Maaf, ID Transaksi Tidak Tersedia", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION);
            clearArea(70, 15, 10, 1);
        }

        BlankDesain();
        hideCursor();

    } while (found == 0 || found == 2);


    SetColorBlock(15,12);
    strcpy(trspo.FName, k.FName);
    gotoxy(40,17);
    printf("N A M A  S T A F F       :");
    gotoxy(70,17);
    printf("%s",trspo.FName);


    SetColorBlock(15,12);
    gotoxy(40, 19);
    printf("T G L  P E M B E L I A N   :");
    gotoxy(69, 19);
    printf(" %02d/%02d/%04d\n",trspo.tgl_pembelian.hari, trspo.tgl_pembelian.bulan, trspo.tgl_pembelian.tahun);


    gotoxy(40, 21);
printf("T G L  P E N E R I M A A N :");

do {
    gotoprinttext(69, 21, "   /  /     \n");

    // Input validation for day
    do {
        gotoxy(70, 21);
        getnum(&trspo.tgl_penerimaan.hari, 2);
        if (trspo.tgl_penerimaan.hari < 1 || trspo.tgl_penerimaan.hari > 31) {
            MessageBox(NULL, "Jangka Inputan hari 1 - 31", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION);
            clearArea(70, 21, 2, 1);
        }
    } while (trspo.tgl_penerimaan.hari < 1 || trspo.tgl_penerimaan.hari > 31);

    // Input validation for month
    do {
        gotoxy(73, 21);
        getnum(&trspo.tgl_penerimaan.bulan, 2);
        if (trspo.tgl_penerimaan.bulan < 1 || trspo.tgl_penerimaan.bulan > 12) {
            MessageBox(NULL, "Jangka Inputan bulan 1 - 12", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION);
            clearArea(73, 21, 2, 1);
        }
    } while (trspo.tgl_penerimaan.bulan < 1 || trspo.tgl_penerimaan.bulan > 12);

    // Input validation for year
    do {
        gotoxy(76, 21);
        getnum(&trspo.tgl_penerimaan.tahun, 4);
        hideCursor();
        if (trspo.tgl_penerimaan.tahun < 2024 || trspo.tgl_penerimaan.tahun > 2028) {
            MessageBox(NULL, "Jangka Inputan tahun 2024 - 2028", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION);
            clearArea(76, 21, 4, 1);
        }
    } while (trspo.tgl_penerimaan.tahun < 2024 || trspo.tgl_penerimaan.tahun > 2028);

    // Ensure penerimaan date is not before pembelian date
    if (
        (trspo.tgl_penerimaan.tahun < trspo.tgl_pembelian.tahun) ||
        (trspo.tgl_penerimaan.tahun == trspo.tgl_pembelian.tahun && trspo.tgl_penerimaan.bulan < trspo.tgl_pembelian.bulan) ||
        (trspo.tgl_penerimaan.tahun == trspo.tgl_pembelian.tahun && trspo.tgl_penerimaan.bulan == trspo.tgl_pembelian.bulan && trspo.tgl_penerimaan.hari < trspo.tgl_pembelian.hari)
    ) {
        MessageBox(NULL, "Tanggal penerimaan harus lebih besar atau sama dengan tanggal pembelian!", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION);
        clearArea(70, 21, 15, 1);
    } else {
        break;  // Exit loop when the date is valid
    }

} while (1);

    strcpy(trspo.status, status[1]);
    gotoxy(40, 23);
    printf("S T A T U S                : %s", trsbo.status);

    arsppenerimaan = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/transaksiterima.dat", "ab");
    fwrite(&trspo, sizeof(trspo), 1, arsppenerimaan);
    fclose(arsppenerimaan);

    MessageBox(NULL, "Penerimaan telah dikonfirmasi!", "NOTIFICATION", MB_OK |MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
    BlankDashboard();
    clearArea(5,29,28,4);
    menuOpsiDashboardOwner();
}

void createTransaksiPenerimaan(){
    frameTransaksi(42, 12);
    SetColorBlock(15,12);
    TambahTPenerimaan();
    fclose(arsppenerimaan);
}