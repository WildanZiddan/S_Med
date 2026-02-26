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


#include "Source/Tampilan.h"
#include "Source/Login.h"
#include "Source/Dashboard.h"


#include "Source/MenuOwner.h"


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
#include "Source/CRUD MASTER/CRUD MASTER OBAT/Updateobat.h"
#include "Source/CRUD MASTER/CRUD MASTER OBAT/Deleteobat.h"

#include "Source/CRUD MASTER/CRUD MASTER JENIS OBAT/Createjenis.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS OBAT/Readjenis.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS OBAT/Updatejenis.h"
#include "Source/CRUD MASTER/CRUD MASTER JENIS OBAT/Deletejenis.h"

#include "Source/CRUD MASTER/CRUD MASTER SUPPLIER/Createsupplier.h"
#include "Source/CRUD MASTER/CRUD MASTER SUPPLIER/Readsupplier.h"
#include "Source/CRUD MASTER/CRUD MASTER SUPPLIER/Updatesupplier.h"
#include "Source/CRUD MASTER/CRUD MASTER SUPPLIER/Deletesupplier.h"


#include "Source/TRANSAKSI APOTEK/TRANSAKSI PEMBELIAN/createTransaksiPembelianObat.h"
#include "Source/TRANSAKSI APOTEK/TRANSAKSI PEMBELIAN/readTransaksiPembelian.h"

#include "Source/TRANSAKSI APOTEK/TRANSAKSI PENERIMAAN/createTransaksiPenerimaan.h"
#include "Source/TRANSAKSI APOTEK/TRANSAKSI PENERIMAAN/readTransaksiPenerimaan.h"

// #include "Source/TRANSAKSI BIOSKOP/TRANSAKSI TIKET/createTransaksiTiket.h"
// #include "Source/TRANSAKSI BIOSKOP/TRANSAKSI TIKET/readTransaksiTiket.h"

#include "Source/LAPORAN APOTEK/laporanPembelian.h"
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
    tampilanAwal();
    //DashboardOwner();
}