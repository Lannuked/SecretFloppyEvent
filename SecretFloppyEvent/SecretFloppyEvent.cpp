#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    char* secretChar;
    string SecretCode = "youfoundthesecret!";
    secretChar = &SecretCode[0];
    MessageBox(NULL, TEXT("Please insert disk with the secret code"), TEXT(""), MB_OK);

    FILE* dummy;
    errno_t err;
    int errnom = 1;
    string SecretContainer;
    while (1) {
        err = fopen_s(&dummy, "A:/supersecret.txt", "r");
        int errnom = err;
        if (errnom == 0)
        {
            if (dummy != NULL) {
                fread(secretChar, SecretCode.length(), 1, dummy);
            }
            SecretContainer = string(secretChar);
        }
        if (SecretContainer == SecretCode) {
            ShellExecute(0, 0, L"https://www.youtube.com/watch?v=dQw4w9WgXcQ", 0, 0, SW_SHOW);
            cout << "success!!";

            if (dummy != NULL) {
                fclose(dummy);
            }
            break;
        }
        Sleep(300);
    }
}