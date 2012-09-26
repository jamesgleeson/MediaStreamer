TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp


win32 {
    win32-g++ {

        OBJECTS_DIR =   "build/win32/gcc/temp/objs"
        MOC_DIR     =   "build/win32/gcc/temp/mocs"
        DESTDIR     =   "../build/win32/gcc"

        CONFIG ( debug, debug|release ) {
            TARGET =  test_d
        }

        CONFIG ( release, debug|release ) {

            TARGET =  test
        }

    }
}
