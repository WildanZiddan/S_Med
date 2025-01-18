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
)
target_link_libraries(S_Med winmm)