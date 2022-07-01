#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

// Warna game
void setcolor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}


const int panjangPeta = 20;
const int lebarPeta = 16;
int posisiKarakterX = 0;
int posisiKarakterY = 0;
int arrowKey = ' ';

 int peta[lebarPeta][panjangPeta] = {
        {1,1,1,1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
        {1,1,1,1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
        {1,1,1,1,1,4,4,4,4,1,1,4,8,8,4,4,4,4,4,4},
        {1,1,1,1,1,4,4,4,4,1,1,4,8,8,4,4,4,4,4,4},
        {5,5,1,1,1,4,4,4,4,1,1,4,8,8,1,1,6,6,6,6},
        {5,5,1,1,1,4,4,4,4,1,1,5,8,8,1,1,6,6,6,6},
        {8,8,1,1,1,4,4,4,4,1,1,5,8,8,1,1,1,1,1,6},
        {8,8,8,8,8,5,5,5,5,4,4,5,8,8,1,1,1,1,1,6},
        {8,8,8,8,8,8,8,8,5,4,4,5,8,8,2,1,1,1,1,6},
        {8,8,8,8,8,8,8,8,5,4,4,5,8,8,2,2,1,1,1,6},
        {8,8,8,8,8,8,8,8,5,4,4,5,8,8,2,2,1,1,1,6},
        {8,8,8,8,8,8,8,8,4,4,4,1,1,2,2,2,2,1,1,6},
        {8,8,8,8,8,8,8,8,4,4,4,1,1,2,2,2,2,2,2,6},
        {8,8,8,8,8,8,8,8,8,8,8,5,5,5,2,2,2,2,2,6},
        {8,8,8,8,8,8,8,8,8,8,8,8,8,5,5,5,5,2,2,6},
        {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,5,2,2,9},
    };

// Structur Hero
struct Player{
	string nama;
    int power;
    int hp;
	int armor;

	void playerAttack(int *monster_hp, int *monster_armor)
	{*monster_hp = *monster_hp - (power - *monster_armor); }
};

// Structur monster
struct Monster{
	string jenismonster;
    int power;
    int hp;
	int armor;

	void monsterAttack(int *hero_hp, int *hero_armor)
	{ *hero_hp = *hero_hp - (power - *hero_armor); }
};

//Controller
void arrowKeyPlayer(int key)
{
  	 if ((arrowKey == 'w' || arrowKey == 'W' || arrowKey == KEY_UP) && (peta[posisiKarakterY-1][posisiKarakterX] == 1 || peta[posisiKarakterY-1][posisiKarakterX] == 2 || peta[posisiKarakterY-1][posisiKarakterX] == 4 || peta[posisiKarakterY-1][posisiKarakterX] == 8 || peta[posisiKarakterY-1][posisiKarakterX] == 9) && posisiKarakterY >= 0) {
            // Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY-1;
        }

        // Aturan menggerakkan karakter ke bawah
        if ((arrowKey == 's' || arrowKey == 'S' || arrowKey == KEY_DOWN) && (peta[posisiKarakterY+1][posisiKarakterX] == 1 || peta[posisiKarakterY+1][posisiKarakterX] == 2 || peta[posisiKarakterY+1][posisiKarakterX] == 4 || peta[posisiKarakterY+1][posisiKarakterX] == 8 || peta[posisiKarakterY+1][posisiKarakterX] == 9) && posisiKarakterY < lebarPeta) {
            // Gerakkan karakter ke bawah
            posisiKarakterY = posisiKarakterY+1;
        }

        // Aturan menggerakkan karakter ke kiri
        if ((arrowKey == 'a' || arrowKey == 'A' || arrowKey == KEY_LEFT) && (peta[posisiKarakterY][posisiKarakterX-1] == 1 || peta[posisiKarakterY][posisiKarakterX-1] == 2 || peta[posisiKarakterY][posisiKarakterX-1] == 4 || peta[posisiKarakterY][posisiKarakterX-1] == 8 || peta[posisiKarakterY][posisiKarakterX-1] == 9) && posisiKarakterX >= 0) {
            // Gerakkan karakter ke kiri
            posisiKarakterX = posisiKarakterX-1;
        }

        // Aturan menggerakkan karakter ke kanan
        if ((arrowKey == 'd' || arrowKey == 'D' || arrowKey == KEY_RIGHT) && (peta[posisiKarakterY][posisiKarakterX+1] == 1 || peta[posisiKarakterY][posisiKarakterX+1] == 2 || peta[posisiKarakterY][posisiKarakterX+1] == 4 || peta[posisiKarakterY][posisiKarakterX+1] == 8 || peta[posisiKarakterY][posisiKarakterX+1] == 9) && posisiKarakterX < panjangPeta) {
            // Gerakkan karakter ke kanan
            posisiKarakterX = posisiKarakterX+1;
        }

        if (arrowKey == 'x' || arrowKey == 'X' || arrowKey == KEY_ESC) {
            exit(0);
        }
    };  

// Tampilan game
void tampilanGame()
{
	int koordinat = peta[posisiKarakterY][posisiKarakterX];
	
	cout << "==============================================="<< endl;
    cout << "========Selamat datang di Baron of Down========"<< endl;
    cout << "==============================================="<< endl;
	cout << "Berjalanlah terus hingga mencapai garis finish" << endl;
	cout << "Dan bertahanlah dari monster yang akan muncul" << endl;
		
for(int y=0; y<lebarPeta; y++) 
   {
            for(int x=0; x<panjangPeta; x++) {
                
                if(posisiKarakterX == x && posisiKarakterY == y) {
                	setcolor(3);
                    cout << "0" << " ";
                    setcolor(7);
                } 
				
				else if(peta[y][x]==1){
                	setcolor(0);
                    cout << peta[y][x] << " ";
                    setcolor(7);
                }
                
                else if(peta[y][x]==2){
                	setcolor(12);
                    cout << "#" << " ";
                    setcolor(7);
                }
                
                else if(peta[y][x]==5){
                	setcolor(6);
                    cout << "O" << " ";
                    setcolor(7);
                }
                
                else if(peta[y][x]==8){
                	setcolor(16);
                    cout << "_" << " ";
                    setcolor(7);
                }
                
                else if(peta[y][x]==4){
                	setcolor(2);
                    cout << "^" << " ";
                    setcolor(7);
                }
                
                else if(peta[y][x]==6){
                	setcolor(10);
                    cout << "|" << " ";
                    setcolor(7);
                }
                
                 else if(peta[y][x]==9){
                	setcolor(15);
                    cout << "=" << " ";
                    setcolor(7);
                }
            }
            cout << "\n";
               
    }
}

int main()
{
		
	while (true)
	{
		// Tampilan Game
		tampilanGame();
		arrowKeyPlayer(arrowKey);
		arrowKey = getch();


		// Hero Object
		Player hero;
		hero.nama = "Cyruss";
        hero.power = 350;
        hero.hp = 1200;
        hero.armor = 150;

    	//Membesihkan layar
		system("cls");

		// Pertarungan Monster
		if (peta[posisiKarakterY][posisiKarakterX] == 4)
		{
		    int chance;
			srand(time(NULL));
			chance = rand() % 10;

			if (chance < 3)
			{
			   while (true)
		       {
					system("cls");
					int choice;
					cout << "Instingmu mendeteksi bahwa terdapat kejanggalan pada area..."<<endl;
	      			cout << "1. Mencari tau lebih lanjut" << endl;
	      			cout << "2. Abaikan" << endl;
					choice = getch();
				
	      			if (choice == '1')
					{
	      			    //Monster Semak Belukar
						Monster m1;
                        m1.jenismonster = "Goblin" ;
                        m1.power =150;
                        m1.hp =500;
                        m1.armor = 150;
						
						while(true)
						{	
							system("cls");
							char input_battle = ' ';
							cout << "Kamu menemukan " << m1.jenismonster << " ditempat tersebut !" << endl;
							cout << hero.nama << ": " << hero.hp << endl;
							cout << m1.jenismonster << ": " << m1.hp << endl;
							cout << "Tekan F untuk Menyerang" << endl;
							input_battle = getch();
							
							if (input_battle == 'f' || input_battle == 'F')
							{
								hero.playerAttack(&m1.hp, &m1.armor);
								m1.monsterAttack(&hero.hp, &hero.armor);
							}
							if (m1.hp <= 0)
							{
								cout << m1.jenismonster << " Telah tumbang " << endl;
								cout << "Membersihkan arena pertarungan..." << endl;
								Sleep(2000);
								system("cls");
								break;
							}
						}
						break;
					}
					else if (choice == '2')
				    {
					break;
				    }
			    }
		    }
		}
  	    if (peta[posisiKarakterY][posisiKarakterX] == 8)
		{
		    int chance;
			srand(time(NULL));
			chance = rand() % 10;

			if (chance < 3)
			{
			   while (true)
		       {
					system("cls");
					int choice;
					cout << "Instingmu mendeteksi bahwa terdapat kejanggalan pada area..."<<endl;
	      			cout << "1. Mencari tau lebih lanjut" << endl;
	      			cout << "2. Abaikan" << endl;
					choice = getch();
				
	      			if (choice == '1')
					{
	      			    //Monster Perairan
						Monster m2;
                        m2.jenismonster = "Lizardman" ;
                        m2.power =250;
                        m2.hp =750;
                        m2.armor = 150;
						
						while(true)
						{	
							system("cls");
							char input_battle = ' ';
							cout << "Kamu menemukan " << m2.jenismonster << " ditempat tersebut !" << endl;
							cout << hero.nama << ": " << hero.hp << endl;
							cout <<  m2.jenismonster << ": " << m2.hp << endl;
							cout << "Tekan F untuk Menyerang" << endl;
							input_battle = getch();
							
							if (input_battle == 'f' || input_battle == 'F')
							{
								hero.playerAttack(&m2.hp, &m2.armor);
								m2.monsterAttack(&hero.hp, &hero.armor);
							}
							if (m2.hp <= 0)
							{
								cout <<  m2.jenismonster << " Telah tumbang " << endl;
								cout << "Membersihkan arena pertarungan..." << endl;
								Sleep(2000);
								system("cls");
								break;
							}
						}
						break;
					}
					else if (choice == '2')
				    {
					break;
				    }
			    }
		    }
		}
		if (peta[posisiKarakterY][posisiKarakterX] == 2)
		{
            int chance;
			srand(time(NULL));
			chance = rand() % 10;

			if (chance < 5)
			{
			   while (true)
		       {
					system("cls");
					int choice;
				    cout << "Instingmu mendeteksi bahwa menemukan kejanggalan pada area..."<<endl;
	      			cout << "1. Mencari tau lebih lanjut" << endl;
	      			cout << "2. Abaikan" << endl;
					choice = getch();
				
	      			if (choice == '1')
					{
	      			    //Monster Sarang Iblis
						Monster m3;
                        m3.jenismonster = "Demon" ;
                        m3.power = 350;
                        m3.hp = 1000;
                        m3.armor = 150;
						
						while(true)
						{	
							system("cls");
							char input_battle = ' ';
							cout << "Kamu menemukan " << m3.jenismonster << " ditempat tersebut !" << endl;
							cout << "Hati-hatilah karena " << m3. jenismonster << " merupakan moster terkuat" << endl;
							cout << hero.nama << ": " << hero.hp << endl;
							cout << m3.jenismonster << ": " << m3.hp << endl;
							cout << "Tekan F untuk Menyerang" << endl;
							input_battle = getch();
							
							if (input_battle == 'f' || input_battle == 'F')
							{
								hero.playerAttack(&m3.hp, &m3.armor);
								m3.monsterAttack(&hero.hp, &hero.armor);
							}
							if (m3.hp <= 0)
							{
								cout << m3.jenismonster << " Telah tumbang " << endl;
								cout << "Membersihkan arena pertarungan..." << endl;
								Sleep(2000);
								system("cls");
								break;
							}
						}
						break;
					}
					else if (choice == '2')
				    {
				     cout << "\nTiba-tiba kamu dihalang oleh seorang monster yang sedang bersembunyi..." << endl;
				     cout << "DIA ADALAH IBLIS, monster terkuat di didunia ini... KALAHKAN DIAA!!!" << endl ;
				     Sleep(3000);
				     
	      			    //Monster Sarang Iblis
						Monster m3;
                        m3.jenismonster = "Demon" ;
                        m3.power = 350;
                        m3.hp = 1000;
                        m3.armor = 150;
					    while(true)
						{	
							system("cls");
							char input_battle = ' ';
							cout << "Hati-hatilah karena " << m3. jenismonster << " merupakan moster terkuat" << endl;
							cout << hero.nama << ": " << hero.hp << endl;
							cout << m3.jenismonster << ": " << m3.hp << endl;
							cout << "Tekan F untuk Menyerang" << endl;
							input_battle = getch();
							
							if (input_battle == 'f' || input_battle == 'F')
							{
								hero.playerAttack(&m3.hp, &m3.armor);
								m3.monsterAttack(&hero.hp, &hero.armor);
							}
							if (m3.hp <= 0)
							{
								cout << m3.jenismonster << " Telah tumbang " << endl;
								cout << "Membersihkan arena pertarungan..." << endl;
								Sleep(2000);
								system("cls");
								break;
							}
						}
						break;
				    }
			    }  
		     }
		}
		 if (peta[posisiKarakterY][posisiKarakterX] == 9) {
            system ("cls");
            cout << "=========================================================================\n";
            cout << "=========================================================================\n";
            cout << "=============================Mission Success!!!!=========================\n";
            cout << "=========================================================================\n";
            cout << "=========================================================================\n";
            _getch();
            exit(0);
        }

        if (hero.hp <= 0) {
            _getch();
            system("cls");
            cout << "=========================================================================\n";
            cout << "=========================================================================\n";
            cout << "===============================GAME OVER!!!!=============================\n";
            cout << "=========================================================================\n";
            cout << "=========================================================================\n";
            _getch();
            exit(0);
        }
	};
	
	
    getch();
	return 0;
};

