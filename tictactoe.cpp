#include <iostream>
using namespace std;

char baskom[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player_jalan = 'X';

void tabel() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++)
            cout << baskom[i][j] << " | ";
        cout << endl;
		cout << "-------------" << endl;
    }
}

bool cekmenang() {
    for (int i = 0; i < 3; i++)
        if ((baskom[i][0] == player_jalan && baskom[i][1] == player_jalan && baskom[i][2] == player_jalan) ||
            (baskom[0][i] == player_jalan && baskom[1][i] == player_jalan && baskom[2][i] == player_jalan))
            return true;
    if ((baskom[0][0] == player_jalan && baskom[1][1] == player_jalan && baskom[2][2] == player_jalan) ||
        (baskom[0][2] == player_jalan && baskom[1][1] == player_jalan && baskom[2][0] == player_jalan))
        return true;
    return false;
}

bool seri() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (baskom[i][j] == ' ')
                return false;
    return true;
}

int main() {
    cout << "Selamat datang di permainan Tic-Tac-Toe!" << endl;

    do {
        tabel();
        cout << "Giliran pemain " << player_jalan << "!" << endl;
		cout << "Silahkan masukkan baris dan kolom yang ingin diisi (0-2), pisahkan dengan spasi: ";
        
        int baris, kolom;
        cin >> baris >> kolom;

        if (baskom[baris][kolom] == ' ') {
            baskom[baris][kolom] = player_jalan;

            if (cekmenang()) {
                tabel();
                 cout << "hasil permainan : " << endl;
                cout << "Selamat, pemain " << player_jalan << " menang!" << endl;
                break;
            }

            if (seri()) {
                tabel();
                cout << "hasil permainan : " << endl;
                cout << "Permainan seri!" << endl;
                break;
            }

            player_jalan = (player_jalan == 'X') ? 'O' : 'X';
        } else
            cout << "Posisi sudah terisi, pilih lagi." << endl;
    } while (true);

    return 0;
}

