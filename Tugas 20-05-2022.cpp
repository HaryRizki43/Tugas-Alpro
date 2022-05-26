/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

struct player_t {
  int id;
  string nama;
  string asalDaerah;
  string skill;
  int jumlahTugasYangDiselesaikan;
};

int main() {

  // lua, r, python, ruby
  // <namaVariabelnyaApa> = <nilaiVariabelnya>

  // c++, c, java
  // <tipeNyaApa> <namaVariabelnyaApa> = <nilaiVariabelnya>

  player_t player[] = {
    {
      1,
      "Julian",
      "Bogor",
      "Telepati",
      4
    },
    {
      2,
      "Zakky",
      "Palangkaraya",
      "Tanker",
      7
    },
    {
      3,
      "Bagas",
      "Garut",
      "Tinju Maut",
      9
    },
    {
      4,
      "Marsya",
      "Bogor",
      "Penyembuh",
      8
    },
    {
      5,
      "Ratna",
      "Surabaya",
      "Provokator",
      3
    },
    {
      6,
      "Septhy",
      "Jakarta",
      "Pengendali Boneka",
      2
    }
  };
  
  cout << "===========DAFTAR INFORMASI PEMAIN=========== \n" << endl;

  int idPlayerYangTelahDikeluarkan1 = 1;
  int idPlayerYangTelahDikeluarkan2 = 6;

  player[5].nama = "Septia";
  player[2].nama = "Rama";
  player[3].nama = "The Priest";

  for (int i = 0; i < 6; i++) 
  {

    if (player[i].id == idPlayerYangTelahDikeluarkan1) {
      cout << player[i].nama << " sang " << player[i].skill << " melakukan pelanggaran, didiskualifikasi dari permainan \n";
      continue;
      
    }
    
    if (player[i].id == idPlayerYangTelahDikeluarkan2) {
      cout << player[i].nama << " sang " << player[i].skill << " melakukan pelanggaran, didiskualifikasi dari permainan \n\n";
      break;
      
    }
    
    cout << "Pemain " << player[i].nama << " sang " << player[i].skill << " sedang menjalani tugas \n";
  }
  
  cout << "=====JUMLAH TUGAS HARI INI YANG DAPAT DIKERJAKAN=====" <<endl;
  int jumlahTugas = 10;
  
  while(jumlahTugas < 11) {
    cout << jumlahTugas << " tugas untuk dikerjakan setiap pemain\n\n";
    jumlahTugas++;
  }
  
  cout <<"===PEMAIN YANG MENDAPATKAN HADIAH TAMBAHAN===" <<endl;
  int jumlahmaksimaltugas= 8;
  
   for(int i = 0; i < 6; i++) {
        
        if(player[i].jumlahTugasYangDiselesaikan < jumlahmaksimaltugas) {
            continue;
        }
        
        cout << "Selamat, " << player[i].nama << " sang " << player[i].skill << " Anda mendapatkan hadiah\n";
    }
    

}