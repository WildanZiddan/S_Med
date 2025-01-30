/*-------------------------Menu Navigasi Bar--------------------------------------*/
void menuDashboardOwner(){
    gotoprinttext(12,10,"P R O F I L E");
    gotoprinttext(14,11,"O W N E R");
    gotoprinttext(15,15,"D A T A");
    gotoprinttext(14,16,"S T A F F");
    gotoprinttext(15,20,"D A T A");
    gotoprinttext(11,21,"S U P P L I E R");
    gotoprinttext(15,25,"D A T A");
    gotoprinttext(10,26,"P E M B E L I A N");\
    gotoprinttext(10,30,"A K T I F I T A S");
    gotoprinttext(13,31,"B I S N I S");
    gotoprinttext(13,39,"K E L U A R");
}

/*---------------------------------Menu Pilihan CRUD----------------------------*/
void menuDataSupplierOwner(){
    //DrawFile(70,19,"../Desaintxt/Dashboard/menuData.txt");
    gotoprinttext(80,25," L I H A T  D A T A");
    gotoprinttext(80,28,"T A M B A H  D A T A");
    gotoprinttext(80,31,"U P D A T E  D A T A");
    gotoprinttext(80,34," H A P U S  D A T A");
    gotoprinttext(80,37,"    K E M B A L I");
}

/*------------------------------------Menu Data Masing - Masing Karyawan-------------------*/
void menuUpdateDataSupplier(){
    gotoprinttext(134,21,"U B A H  N A M A  P R O D U S E R");
    gotoprinttext(141,23,"U B A H  C O M P A N Y");
    gotoprinttext(142, 25, "   K E M B A L I");
}

/*------------------------------------Menu Update Data-------------------------------------*/
void menuUpdateDataOwner(){
    gotoprinttext(137,19,"U B A H  N O  T E L E P O N");
    gotoprinttext(138,21,"U B A H  U S E R N A M E");
    gotoprinttext(138,23,"U B A H  P A S S W O R D");
    gotoprinttext(138,25,"     K E M B A L I ");
}

void menuUpdateDataAlat(){
    gotoprinttext(138,19,"U B A H  N A M A  A L A T");
    gotoprinttext(142,21,"U B A H  H A R G A");
    gotoprinttext(140,23,"U B A H  J U M L A H");
    gotoprinttext(140,25,"     K E M B A L I ");
}

/*------------------------------------Detail Update Data Staff-------------------------------------*/
void seluruhDataOwner(){
    SetColorBlock(15,12);
    gotoprinttext(70,12,"D E T A I L  D A T A");
    gotoprinttext(57,14,"ID STAFF   :");
    gotoprinttext(57,16,"NAMA STAFF :");
    gotoprinttext(57,18,"NO. TELEPON   :");
    gotoprinttext(57,20,"TANGGAL LAHIR :");
    gotoprinttext(57,22,"USERNAME      :");
    gotoprinttext(57,24,"PASSWORD      :");
    gotoprinttext(57,26,"ROLE         :");
}

/*------------------------------------Detail Update Data Alat-------------------------------------*/
void seluruhDataAlat(){
    SetColorBlock(15,12);
    gotoprinttext(66,12,"D E T A I L  D A T A");
    gotoprinttext(57,16,"ID ALAT     :");
    gotoprinttext(57,18,"NAMA ALAT   :");
    gotoprinttext(57,20,"HARGA ALAT  :");
    gotoprinttext(57,22,"JUMLAH ALAT :");
}


/*------------------------------------Detail Update Data Admin-------------------------------------*/
// void seluruhDataKasir(){
//     SetColorBlock(7,9);
//     gotoprinttext(70,12,"D E T A I L  D A T A");
//     gotoprinttext(57,14,"ID KARYAWAN   :");
//     gotoprinttext(57,16,"NAMA KARYAWAN :");
//     gotoprinttext(57,18,"NO. TELEPONE  :");
//     gotoprinttext(57,20,"TANGGAL LAHIR :");
//     gotoprinttext(57,22,"USERNAME      :");
//     gotoprinttext(57,24,"PASSWORD      :");
//     gotoprinttext(57,26,"GAJI          :");
//     gotoprinttext(57,28,"LOKET         :");
// }


/*------------------------------------Interface Table---------------------------------------*/
void tampilanTableOwner(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 9; i <= 9;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,9,201);
    /*border sudut kanan atas*/
    gotoprintchar(167,9,187);
    /*border vertikal kebawah kiri*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,200);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,188);

    SetColorBlock(15,4);
    for(i = 10; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,11,"NO.");
    gotoprinttext(42,11,"I D  O W N E R");
    gotoprinttext(64,11,"N A M A  L E N G K A P");
    gotoprinttext(90,11,"T G L  L A H I R");
    gotoprinttext(113,11,"N O  T E L E P O N E");
    SetColorBlock(4,15);
}

void tampilanTableAlat(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 9; i <= 9;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,9,201);
    /*border sudut kanan atas*/
    gotoprintchar(167,9,187);
    /*border vertikal kebawah kiri*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,200);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,188);

    SetColorBlock(15,4);
    for(i = 10; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,11,"NO.");
    gotoprinttext(47,11,"I D  A L A T");
    gotoprinttext(60,11,"N A M A  A L A T");
    gotoprinttext(82,11,"H A R G A  A L A T");
    gotoprinttext(109,11,"J U M L A H  A L A T");
    SetColorBlock(4,15);
}

void tampilanTableObat(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 9; i <= 9;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,9,201);
    /*border sudut kanan atas*/
    gotoprintchar(167,9,187);
    /*border vertikal kebawah kiri*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,200);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,188);

    SetColorBlock(15,4);
    for(i = 10; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,11,"NO.");
    gotoprinttext(47,11,"I D  O B A T");
    gotoprinttext(60,11,"N A M A  O B A T");
    gotoprinttext(82,11,"J E N I S");
    gotoprinttext(92,11,"H A R G A");
    gotoprinttext(102,11,"E X P  D A T E");
    gotoprinttext(120,11,"J U M L A H  A L A T");
    SetColorBlock(4,15);
}

void tampilanTableJenis(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 9; i <= 9;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,9,201);
    /*border sudut kanan atas*/
    gotoprintchar(167,9,187);
    /*border vertikal kebawah kiri*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,200);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,188);

    SetColorBlock(15,4);
    for(i = 10; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,11,"NO.");
    gotoprinttext(47,11,"I D  A L A T");
    gotoprinttext(65,11,"N A M A  J E N I S");
    SetColorBlock(4,15);
}

void tampilanTableSupplier(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 9; i <= 9;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,9,201);
    /*border sudut kanan atas*/
    gotoprintchar(167,9,187);
    /*border vertikal kebawah kiri*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,200);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,188);

    SetColorBlock(15,4);
    for(i = 10; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,11,"NO.");
    gotoprinttext(47,11,"I D  S U P P L I E R");
    gotoprinttext(60,11,"N A M A  S U P P L I E R");
    gotoprinttext(82,11,"C O M P A N Y");
    gotoprinttext(109,11,"A L A M A T");
    SetColorBlock(4,15);
}



void seluruhDataSupplier(){
    SetColorBlock(15,12);
    gotoprinttext(70,12,"D E T A I L  D A T A");
    gotoprinttext(57,14,"ID SUPPLIER  :");
    gotoprinttext(57,16,"NAMA SUPPLIER:");
    gotoprinttext(57,18,"ALAMAT  :");
    gotoprinttext(57,20,"COMPANY      :");
}

void frameCRUD(int x, int y,char namafile[255]){
    SetColorBlock(4,15);
    //DrawFile(x,y,namafile);
    //DrawFile(130,22,"../Desaintxt/elemen/dataBook.txt");
    SetColorBlock(12,12);
    frameLayout(60,18,120,40,32);
    SetColorBlock(15,4);
    frameLayout(60,18,120,19,220);
    frameLayout(60,18,61,40,220);
    frameLayout(60,40,120,41,223);
    frameLayout(119,18,120,40,220);
}


void tampilanCRUDStaff(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 9; i <= 9;i++){
        for(j = 36; j <= 128; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(35,9,201);
    /*border sudut kanan atas*/
    gotoprintchar(128,9,187);
    /*border vertikal kebawah kiri*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(35,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(128,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(35,38,200);
    for(i = 38; i <= 38;i++){
        for(j = 36; j <= 128; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(128,38,188);

    SetColorBlock(15,4);
    for(i = 10; i <= 12;i++){
        for(j = 36; j < 128; j++){
            gotoprintchar(j,i,32);
        }
    }

    gotoprinttext(38,11,"NO.");
    gotoprinttext(42,11,"I D  O W N E R");
    gotoprinttext(64,11,"N A M A  L E N G K A P");
    gotoprinttext(90,11,"T G L  L A H I R");
}

void tampilanCRUDAlat(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 9; i <= 9;i++){
        for(j = 36; j <= 128; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(35,9,201);
    /*border sudut kanan atas*/
    gotoprintchar(128,9,187);
    /*border vertikal kebawah kiri*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(35,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(128,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(35,38,200);
    for(i = 38; i <= 38;i++){
        for(j = 36; j <= 128; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(128,38,188);

    SetColorBlock(15,4);
    for(i = 10; i <= 12;i++){
        for(j = 36; j < 128; j++){
            gotoprintchar(j,i,32);
        }
    }

    gotoprinttext(38,11,"NO.");
    gotoprinttext(42,11,"I D  A L A T");
    gotoprinttext(64,11,"N A M A  A L A T");
    gotoprinttext(90,11,"H A R G A  A L A T");
    gotoprinttext(110, 11, "J U M L A H  A L A T");
}

void tampilanTableAkunOwner(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 9; i <= 9;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,9,201);
    /*border sudut kanan atas*/
    gotoprintchar(167,9,187);
    /*border vertikal kebawah kiri*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 10; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,200);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,188);

    SetColorBlock(15,4);
    for(i = 10; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,11,"NO.");
    gotoprinttext(48,11,"I D  O W N E R");
    gotoprinttext(75,11,"N A M A  L E N G K A P");
    gotoprinttext(110,11,"U S E R N A M E");
    gotoprinttext(140,11,"P A S S W O R D");
    SetColorBlock(4,15);
}


void menuDataPenjualan(){
    //DrawFile(70,19,"../Desaintxt/Dashboard/menuData.txt");
    gotoprinttext(80,28,"D A T A  O B A T");
    gotoprinttext(80,31,"D A T A  A L A T");
    gotoprinttext(80,34," K E M B A L I ");
}

void menuDataTransaksi(){
    //DrawFile(70,19,"../Desaintxt/Dashboard/menuData.txt");
    gotoprinttext(80,28,"P E M B E L I A N");
    gotoprinttext(79,31,"P E N E R I M A A N");
    gotoprinttext(80,34," K E M B A L I ");
}

void menuDataTransaksiPembelian(){
    //DrawFile(70,19,"../Desaintxt/Dashboard/menuData.txt");
    gotoprinttext(76,28,"L I H A T  D A T A");
    gotoprinttext(74,31,"T A M B A H  T R A N S A K S I");
    gotoprinttext(80,34," K E M B A L I ");
}

void menuDataObat(){
    //DrawFile(70,19,"../Desaintxt/Dashboard/menuData.txt");
    gotoprinttext(80,28,"C R U D  O B A T");
    gotoprinttext(80,31,"J E N I S  O B A T");
    gotoprinttext(80,34," K E M B A L I ");
}

void menuDataAktifitas(){
    //DrawFile(70,19,"../Desaintxt/Dashboard/menuData.txt");
    gotoprinttext(80,28,"T R A N S A K S I");
    gotoprinttext(82,31,"L A P O R A N");
    gotoprinttext(82,34,"K E M B A L I");
}

// void tampilanTableAkunAdmin(){
//     SetColorBlock(1,7);
//     /*border atas*/
//     for(i = 9; i <= 9;i++){
//         for(j = 37; j < 167; j++){
//             gotoprintchar(j,i,205);
//         }
//     }
//     /*border sudut kiri atas*/
//     gotoprintchar(36,9,201);
//     /*border sudut kanan atas*/
//     gotoprintchar(167,9,187);
//     /*border vertikal kebawah kiri*/
//     for(i = 10; i <= 38;i++){
//         gotoprintchar(36,i,186);
//     }
//     /*border vertikal kebawah kanan*/
//     for(i = 10; i <= 38;i++){
//         gotoprintchar(167,i,186);
//     }
//     /*border sudut bawah kiri*/
//     gotoprintchar(36,38,200);
//     for(i = 38; i <= 38;i++){
//         for(j = 37; j < 167; j++){
//             gotoprintchar(j,i,205);
//         }
//     }
//     /*border sudut bawah kanan*/
//     gotoprintchar(167,38,188);
//
//     SetColorBlock(7,1);
//     for(i = 10; i <= 12;i++){
//         for(j = 37; j < 167; j++){
//             gotoprintchar(j,i,32);
//         }
//     }
//     gotoprinttext(38,11,"NO.");
//     gotoprinttext(48,11,"I D  A D M I N");
//     gotoprinttext(75,11,"N A M A  L E N G K A P");
//     gotoprinttext(110,11,"U S E R N A M E");
//     gotoprinttext(140,11,"P A S S W O R D");
//     SetColorBlock(1,7);
// }
//
// void tampilanTableAkunKasir(){
//     SetColorBlock(1,7);
//     /*border atas*/
//     for(i = 9; i <= 9;i++){
//         for(j = 37; j < 167; j++){
//             gotoprintchar(j,i,205);
//         }
//     }
//     /*border sudut kiri atas*/
//     gotoprintchar(36,9,201);
//     /*border sudut kanan atas*/
//     gotoprintchar(167,9,187);
//     /*border vertikal kebawah kiri*/
//     for(i = 10; i <= 38;i++){
//         gotoprintchar(36,i,186);
//     }
//     /*border vertikal kebawah kanan*/
//     for(i = 10; i <= 38;i++){
//         gotoprintchar(167,i,186);
//     }
//     /*border sudut bawah kiri*/
//     gotoprintchar(36,38,200);
//     for(i = 38; i <= 38;i++){
//         for(j = 37; j < 167; j++){
//             gotoprintchar(j,i,205);
//         }
//     }
//     /*border sudut bawah kanan*/
//     gotoprintchar(167,38,188);
//
//     SetColorBlock(7,1);
//     for(i = 10; i <= 12;i++){
//         for(j = 37; j < 167; j++){
//             gotoprintchar(j,i,32);
//         }
//     }
//     gotoprinttext(38,11,"NO.");
//     gotoprinttext(48,11,"I D  K A S I R");
//     gotoprinttext(75,11,"N A M A  L E N G K A P");
//     gotoprinttext(110,11,"U S E R N A M E");
//     gotoprinttext(140,11,"P A S S W O R D");
//     SetColorBlock(1,7);
// }

void tampilanTransaksiPembelianObat(){
    SetColorBlock(4,15);
    /*border atas*/
        for(j = 119; j <= 167; j++){
            gotoprintchar(j,11,205);
        }
    /*border sudut kiri atas*/
    gotoprintchar(118,11,201);
    /*border sudut kanan atas*/
    gotoprintchar(168,11,187);
    /*border vertikal kebawah kiri*/
    for(i = 12; i <= 38;i++){
        gotoprintchar(118,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 12; i <= 38;i++){
        gotoprintchar(168,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(118,39,200);
        for(j = 119; j <= 167; j++){
            gotoprintchar(j,39,205);
        }

    /*border sudut bawah kanan*/
    gotoprintchar(168,39,188);

    SetColorBlock(15,4);
    for(i = 12; i <= 14;i++){
        for(j = 119; j < 168; j++){
            gotoprintchar(j,i,32);
        }
    }

    gotoprinttext(120,13,"NO.");
    gotoprinttext(126,13,"ID OBAT");
    gotoprinttext(136,13,"NAMA OBAT");
    gotoprinttext(158,13,"STOK OBAT");
}

void tampilanTransaksiPembelianAlat(){
    SetColorBlock(4,15);
    /*border atas*/
    for(j = 119; j <= 167; j++){
        gotoprintchar(j,11,205);
    }
    /*border sudut kiri atas*/
    gotoprintchar(118,11,201);
    /*border sudut kanan atas*/
    gotoprintchar(168,11,187);
    /*border vertikal kebawah kiri*/
    for(i = 12; i <= 38;i++){
        gotoprintchar(118,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 12; i <= 38;i++){
        gotoprintchar(168,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(118,39,200);
    for(j = 119; j <= 167; j++){
        gotoprintchar(j,39,205);
    }

    /*border sudut bawah kanan*/
    gotoprintchar(168,39,188);

    SetColorBlock(15,4);
    for(i = 12; i <= 14;i++){
        for(j = 119; j < 168; j++){
            gotoprintchar(j,i,32);
        }
    }

    gotoprinttext(120,13,"NO.");
    gotoprinttext(126,13,"ID ALAT");
    gotoprinttext(136,13,"NAMA ALAT");
    gotoprinttext(158,13,"STOK ALAT");
}

void tampilanTableTransaksiPembelianObat(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 12; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,12,206);
    /*border sudut kanan atas*/
    gotoprintchar(167,12,206);
    /*border vertikal kebawah kiri*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,206);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,206);

    SetColorBlock(15,4);
    for(i = 13; i <= 15;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,14,"NO.");
    gotoprinttext(43,14,"ID TRANSAKSI");
    gotoprinttext(60,14,"TGL PEMBELIAN");
    gotoprinttext(80,14,"NAMA OWNER");
    gotoprinttext(120,14,"TOTAL HARGA");
    gotoprinttext(140,14,"STATUS");
}

void tampilanDetailTableTransaksiPembelianObat(){
    SetColorBlock(4,15);
    /*border atas*/
    for(i = 12; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,12,206);
    /*border sudut kanan atas*/
    gotoprintchar(167,12,206);
    /*border vertikal kebawah kiri*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,206);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,206);

    SetColorBlock(15,4);
    for(i = 13; i <= 15;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,14,"NO.");
    gotoprinttext(43,14,"ID TRANSAKSI");
        gotoprinttext(57,14,"ID OBAT");
        gotoprinttext(66,14,"NAMA OBAT");
        gotoprinttext(100,14,"HARGA OBAT");
        gotoprinttext(114,14,"QUANTITY");
        gotoprinttext(122,14,"SUB TOTAL");
}

void menuTransaksi(){
    DrawFile(70,18,"../Desaintxt/Dashboard/menuData.txt");
    gotoprinttext(73,24,"T R A N S A K S I  M A K A N A N");
    gotoprinttext(70,27,"T R A N S A K S I  M E R C H A N D I S E");
    gotoprinttext(80,30,"  K E M B A L I");
}

void menuTransaksiFilm(){
    DrawFile(70,19,"../Desaintxt/Dashboard/menuData.txt");
    gotoprinttext(81,25,"L I H A T  D A T A");
    gotoprinttext(74,28,"T A M B A H  T R A N S A K S I");
    gotoprinttext(83,31," K E M B A L I");
}