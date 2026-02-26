// void ownerLoginLayout();
// void dataKaryawanMenu();
// void laporanKeuanganLayout();
// void laporanFilmLayout();
// void profileManajer();
void menuOpsiDashboardOwner();
void profileOwner();
//
//
// void profileAdmin();
// void menuOpsiDashboardAdmin();
//
// void profileKasir();
// void menuOpsiDashboardKasirTiket();
// void profileKasirMakanan();
// void menuOpsiDashboardKasirMakanan();
void DashboardOwner(){
    blankScreen();
    Dashboard();
    gotoprinttext(10,4,"M E N U  O W N E R");
    gotoprinttext(14,6,"S - M E D");
    // DrawFile(40,3,"../Desaintxt/Dashboard/ManajerD.txt");
    // DrawFile(160,3,"../Desaintxt/Dashboard/user.txt");
    clearArea(140,4,15,1);
    Tanggal();
    /*Navbar Menu*/
    menuDashboardOwner();
    profileOwner();
    menuOpsiDashboardOwner();
}

void DashboardKasir(){
    blankScreen();
    Dashboard();
    gotoprinttext(10,4,"M E N U  K A S I R");
    gotoprinttext(14,6,"S - M E D");
    // DrawFile(40,3,"../Desaintxt/Dashboard/ManajerD.txt");
    // DrawFile(160,3,"../Desaintxt/Dashboard/user.txt");
    clearArea(140,4,15,1);
    Tanggal();
    /*Navbar Menu*/
    menuDashboardKasir();
    profileOwner();
    menuOpsiDashboardOwner();
}

// void DashboardAdmin(){
//     blankScreen();
//     Dashboard();
//     gotoprinttext(10,4,"M E N U  A D M I N");
//     gotoprinttext(11,6,"T A L I W A N G");
//     DrawFile(40,3,"../Desaintxt/Dashboard/AdminD.txt");
//     DrawFile(160,3,"../Desaintxt/Dashboard/user.txt");
//     clearArea(140,4,15,1);
//     Tanggal();
//     /*Navbar Menu*/
//     menuDashboardAdmin();
//     profileAdmin();
//     menuOpsiDashboardAdmin();
// }
//
// void DashboardKasirTiket(){
//     blankScreen();
//     Dashboard();
//     gotoprinttext(10,4,"M E N U  K A S I R");
//     gotoprinttext(11,6,"T A L I W A N G");
//     DrawFile(40,3,"../Desaintxt/Dashboard/dkasirtiket.txt");
//     DrawFile(160,3,"../Desaintxt/Dashboard/user.txt");
//     Tanggal();
//     /*Navbar Menu*/
//     menuDashboardKasirTiket();
//     profileKasir();
//     menuOpsiDashboardKasirTiket();
// }
//
// void DashboardKasirMakanan(){
//     blankScreen();
//     Dashboard();
//     gotoprinttext(10,4,"M E N U  K A S I R");
//     gotoprinttext(11,6,"T A L I W A N G");
//     DrawFile(40,3,"../Desaintxt/Dashboard/kasirmakananD.txt");
//     DrawFile(160,3,"../Desaintxt/Dashboard/user.txt");
//     clearArea(140,4,15,1);
//     Tanggal();
//     /*Navbar Menu*/
//     menuDashboardKasirMakanan();
//     profileKasirMakanan();
//     menuOpsiDashboardKasirMakanan();
// }