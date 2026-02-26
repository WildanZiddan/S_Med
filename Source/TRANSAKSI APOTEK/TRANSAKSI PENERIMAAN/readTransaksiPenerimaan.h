//#include "../../../Interface/interfaceMenuOwner.h"
void tampilanTableTransaksiPenerimaan();

void dataTransaksiPenerimaan(){
    gotoxy(38, y);
    printf("%d", i);
    gotoxy(43, y);
    generateid("TRSPO",trspo.id_transaksi);
    gotoxy(60, y);
    generateid("TRSBO",trspo.id_transaksi);
    gotoxy(75, y);
    printf("%s\n", trspo.FName);
    gotoxy(100, y);
    printf("%02d/%02d/%04d\n", trspo.tgl_pembelian.hari,trspo.tgl_pembelian.bulan,trspo.tgl_pembelian.tahun);
    gotoxy(125, y);
    printf("%02d/%02d/%04d\n", trspo.tgl_penerimaan.hari,trspo.tgl_penerimaan.bulan,trspo.tgl_penerimaan.tahun);
    gotoxy(144, y);
    printf("%s",trspo.status);
}

void readAllDataTransaksiPenerimaan(){
    i = 1;
    y = 16;
    arsppenerimaan = fopen("../TRANSAKSI APOTEK/../Source/../Database/Dat/transaksiterima.dat", "rb+");
    while (fread(&trspo, sizeof(trspo), 1, arsppenerimaan) == 1 ) {
        if (i % 2 == 0) {
            SetColorBlock(15,4);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            dataTransaksiPenerimaan();
        } else {
            SetColorBlock(15,12);
            for(x = y; x <= y;x++){
                for(j = 37; j < 167; j++){
                    gotoprintchar(j,x,32);
                }
            }
            dataTransaksiPenerimaan();
        }
        batasTable();
        i++;
        y++;
    }
    fclose(arsppenerimaan);
    SetColorBlock(15,12);
    gotoprinttext(150,40,"K E M B A L I");
    if(getch()){
        BlankDashboard();
        clearArea(5,29,28,4);
        profileOwner();
        menuOpsiDashboardOwner();
    }
}