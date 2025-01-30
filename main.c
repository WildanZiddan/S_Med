#include <stdio.h>
#include<windows.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <mmsystem.h>


#include "Source/DeklarasiTipeData.h"
#include "Interface/Interface.h"
#include "Interface/interfaceMenuOwner.h"

#include "Source/keyUpDown.h"
#include "Source/keyUpDownOwner.h"
// #include "Source/keyUpDownKasirTiket.h"
// #include "Source/keyUpDownKasirMakanan.h"
//
#include "Source/Tampilan.h"
#include "Source/Login.h"
#include "Source/Dashboard.h"

#include "Source/MenuOwner.h"
// #include "Source/MenuKasir.h"
// #include "Source/MenuKasirMakanan.h"
//
#include "Source/CRUD MASTER STAFF/Createstaff.h"
#include "Source/CRUD MASTER STAFF/Readstaff.h"
#include "Source/CRUD MASTER STAFF/Updatestaff.h"
#include "Source/CRUD MASTER STAFF/Deletestaff.h"

#include "Source/CRUD MASTER/CRUD MASTER ALAT/Createalat.h"
#include "Source/CRUD MASTER/CRUD MASTER ALAT/Readalat.h"
#include "Source/CRUD MASTER/CRUD MASTER ALAT/Updatealat.h"
#include "Source/CRUD MASTER/CRUD MASTER ALAT/Deletealat.h"

#include "Source/CRUD MASTER/CRUD MASTER OBAT/Createobat.h"
#include "Source/CRUD MASTER/CRUD MASTER OBAT/Readobat.h"
// #include "Source/CRUD MASTER/CRUD MASTER ALAT/Updatealat.h"
// #include "Source/CRUD MASTER/CRUD MASTER ALAT/Deletealat.h"

#include "Source/CRUD MASTER/CRUD MASTER JENIS OBAT/Createjenis.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS OBAT/Readjenis.h"
// #include "Source/CRUD MASTER/CRUD MASTER ALAT/Updatealat.h"
// #include "Source/CRUD MASTER/CRUD MASTER ALAT/Deletealat.h"

#include "Source/CRUD MASTER/CRUD MASTER SUPPLIER/Createsupplier.h"
#include "Source/CRUD MASTER/CRUD MASTER SUPPLIER/Readsupplier.h"
//#include "Source/CRUD MASTER/CRUD MASTER SUPPLIER/UpdateMakanan.h"
//#include "Source/CRUD MASTER/CRUD MASTER SUPPLIER/DeleteMakanan.h"

// #include "Source/CRUD MASTER/CRUD MASTER MEMBERSHIP/CreateMembership.h"
// #include "Source/CRUD MASTER/CRUD MASTER MEMBERSHIP/ReadMembership.h"
// #include "Source/CRUD MASTER/CRUD MASTER MEMBERSHIP/UpdateMembership.h"
// #include "Source/CRUD MASTER/CRUD MASTER MEMBERSHIP/DeleteMembership.h"
//
// #include "Source/CRUD MASTER/CRUD MASTER FILM/CreateFilm.h"
// #include "Source/CRUD MASTER/CRUD MASTER FILM/ReadFilm.h"
// #include "Source/CRUD MASTER/CRUD MASTER FILM/UpdateFilm.h"
// #include "Source/CRUD MASTER/CRUD MASTER FILM/DeleteFilm.h"
//
// #include "Source/CRUD MASTER/CRUD MASTER JAM TAYANG/CreateJamTayang.h"
// #include "Source/CRUD MASTER/CRUD MASTER JAM TAYANG/ReadJamTayang.h"
// #include "Source/CRUD MASTER/CRUD MASTER JAM TAYANG/UpdateJamTayang.h"
// #include "Source/CRUD MASTER/CRUD MASTER JAM TAYANG/DeleteJamTayang.h"
// #include "Source/CRUD MASTER/CRUD MASTER JAM TAYANG/detailJamTayang.h"
//
// #include "Source/CRUD MASTER/CRUD MASTER MERCHANDISE/CreateMerchandise.h"
// #include "Source/CRUD MASTER/CRUD MASTER MERCHANDISE/ReadMerchandise.h"
// #include "Source/CRUD MASTER/CRUD MASTER MERCHANDISE/UpdateMerchandise.h"
// #include "Source/CRUD MASTER/CRUD MASTER MERCHANDISE/DeleteMerchandise.h"
//
// #include "Source/CRUD MASTER/CRUD MASTER PRODUSER/CreateProduser.h"
// #include "Source/CRUD MASTER/CRUD MASTER PRODUSER/ReadProduser.h"
// #include "Source/CRUD MASTER/CRUD MASTER PRODUSER/UpdateProduser.h"
// #include "Source/CRUD MASTER/CRUD MASTER PRODUSER/DeleteProduser.h"
//
// #include "Source/CRUD MASTER/CRUD MASTER STUDIO/CreateStudio.h"
// #include "Source/CRUD MASTER/CRUD MASTER STUDIO/ReadStudio.h"
// #include "Source/CRUD MASTER/CRUD MASTER STUDIO/UpdateStudio.h"
// #include "Source/CRUD MASTER/CRUD MASTER STUDIO/DeleteStudio.h"
//
// #include "Source/CRUD MASTER/CRUD MASTER TIKET/CreateTiket.h"
// #include "Source/CRUD MASTER/CRUD MASTER TIKET/ReadTiket.h"
// #include "Source/CRUD MASTER/CRUD MASTER TIKET/UpdateTiket.h"
// #include "Source/CRUD MASTER/CRUD MASTER TIKET/DeleteTiket.h"
//
//
#include "Source/TRANSAKSI APOTEK/TRANSAKSI PEMBELIAN/createTransaksiPembelianObat.h"
#include "Source/TRANSAKSI APOTEK/TRANSAKSI PEMBELIAN/readTransaksiPembelian.h"
//
// #include "Source/TRANSAKSI BIOSKOP/TRANSAKSI MERCHANDISE/createTransaksiMerchandise.h"
// #include "Source/TRANSAKSI BIOSKOP/TRANSAKSI MERCHANDISE/readTransaksiMerchandise.h"
//
// #include "Source/TRANSAKSI BIOSKOP/TRANSAKSI TIKET/createTransaksiTiket.h"
// #include "Source/TRANSAKSI BIOSKOP/TRANSAKSI TIKET/readTransaksiTiket.h"
//
// #include "Source/LAPORAN BIOSKOP/LAPORAN KEUANGAN/LaporanKeuanganMakanan.h"
// #include "Source/LAPORAN BIOSKOP/LAPORAN KEUANGAN/LaporanKeuanganMerchandise.h"
// #include "Source/LAPORAN BIOSKOP/LAPORAN KEUANGAN/LaporanKeuanganTiket.h"
//
// #include "Source/LAPORAN BIOSKOP/LAPORAN FILM/laporanFilmTerfavorit.h"
int main() {
    hideCursor();
    setConsoleFont(0,16,L"Cascadia Code Bold");
    disableScrollBar();
    fullscreen();
    system("color fc");
    //tampilanAwal();
    DashboardOwner();
}