#include <locale.h>
#include <windows.h>
#include "matrix.h"
#include "output.h"

int main() {

    setlocale(LC_ALL, "C.UTF8");
    SetConsoleOutputCP(CP_UTF8);
    user_interface();


    return 0;
}
