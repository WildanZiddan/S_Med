cmake_minimum_required(VERSION 3.29)
project(S_Med C)

set(CMAKE_C_STANDARD 23)

add_executable(S_Med main.c
        Source/DeklarasiTipeData.h
        Interface/Interface.h
        Source/Tampilan.h
        Source/Login.h
        Source/keyUpDown.h
        Source/Dashboard.h
        Source/MenuOwner.h
        Interface/interfaceMenuOwner.h
        Source/keyUpDownOwner.h
        "Source/CRUD MASTER STAFF/Readstaff.h"
        "Source/CRUD MASTER STAFF/Updatestaff.h"
        "Source/CRUD MASTER STAFF/Deletestaff.h"
        "Source/CRUD MASTER/CRUD MASTER ALAT/Createalat.h"
        "Source/CRUD MASTER/CRUD MASTER ALAT/Readalat.h"
        "Source/CRUD MASTER/CRUD MASTER ALAT/Updatealat.h"
        "Source/CRUD MASTER/CRUD MASTER ALAT/Deletealat.h"
        "Source/CRUD MASTER/CRUD MASTER OBAT/Createobat.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS OBAT/Createjenis.h"
        "Source/CRUD MASTER/CRUD MASTER SUPPLIER/Createsupplier.h"
        "Source/CRUD MASTER/CRUD MASTER SUPPLIER/Readsupplier.h"
        "Source/CRUD MASTER/CRUD MASTER JENIS OBAT/Readjenis.h"
        "Source/CRUD MASTER/CRUD MASTER OBAT/Readobat.h"
        "Source/TRANSAKSI APOTEK/TRANSAKSI PEMBELIAN/createTransaksiPembelianObat.h"
        "Source/TRANSAKSI APOTEK/TRANSAKSI PEMBELIAN/readTransaksiPembelian.h"
        "Source/TRANSAKSI APOTEK/TRANSAKSI PENERIMAAN/createTransaksiPenerimaan.h"
        "Source/LAPORAN APOTEK/laporanPembelian.h"
        "Source/TRANSAKSI APOTEK/TRANSAKSI PENERIMAAN/readTransaksiPenerimaan.h"
)
target_link_libraries(S_Med winmm)