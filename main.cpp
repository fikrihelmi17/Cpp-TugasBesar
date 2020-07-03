#include <iostream>
#include <string>
#include <fstream> //standard input output file
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 

void loginUser();

// Changes colour of text
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int greentext(){SetConsoleTextAttribute(hConsole, 2);  };
int whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
int redtext (){SetConsoleTextAttribute(hConsole,  4);  };
int bluetext (){SetConsoleTextAttribute(hConsole, 11);  };
int yellowtext (){SetConsoleTextAttribute(hConsole, 14);  };
int darktext (){SetConsoleTextAttribute(hConsole, 8);  };

// Global Variables that need to be accessible throughout the different functions 
bool MenuLoop = true;
string name ("*****");    //Strings have default values so that the form can
string surname ("*****"); //be displayed with incomplete fields.
int address1 (00);
string address2 ("*****");
string address3 ("*****");
string address4 ("*****");
string postcode ("*****");
string telDay ("00");
string telEve("00");
int startDate(00);
int startMonth (00);
int startYear(00);
int endDate(00);
int endMonth(00);
int endYear(00);
int membershipNumber(00);
int membershipSelection;
string membershipType("*****");
string memberNotes("*****");
 
// Global activity variables
string activity ("*****");
int activityDate(00);
int activityMonth(00);
int activityYear(00);
double activityPrice(0.00);

//class utama
class userClass{
	public :
	
	string username, password, un;
	int pilihUser;
	
	void loginUser() {
		username = "\0";
		password = "\0";
	}; 
	
	//deklarasi fungsi yang akan di inheritance
	bool IsLoggedIn();
	void discover();
	void cariMakanan();
	void pesanan();
	void profil();
	void savefile();
		
	void menuUser(){
		do {
			system("cls");
			cout << "--------------- Welcome to Kedai Fajar ---------------\n";
			cout << "1. Discover\n";
			cout << "2. Book!\n";
			cout << "3. Pesanan\n";
			cout << "4. Profil\n";
			cout << "5. Exit\n";
			cout << "Pilih : "; cin >> pilihUser;
			
			switch(pilihUser) {
				case 1 : discover();
				system("pause");
				break;
				case 2 : cariMakanan();
				system("pause");
				break;
				case 3 : pesanan();
				system("pause");
				break;
				case 4 : profil();
				break;
			}
		} while(pilihUser >= 1 && pilihUser <=4);
	}
	 
};

bool userClass :: IsLoggedIn(){
	system("cls");
	string username, password, pw, filename;
	
	cout << "Username : "; cin >> username;
	cout << "Password : "; cin >> password;
	
	filename = "D:\\program\\c & c++\\semester 4\\tugas besar alpro\\useradmin\\" + username + ".txt";
	
	ifstream read(filename.c_str());
	getline(read, un);
	getline(read, pw);
	
	if(un == username && pw == password) {
		return true;
	} else {
		return false;
	}
}

void userClass :: discover() {
	
	string filename;
	filename = "tentangaplikasi.txt";
	ofstream myfile;
    myfile.open(filename.c_str());
	//fail() -> untuk memeriksa suatu kesalahan pada operasi file
		if(!myfile.fail())
	     {
	     	//menulis ke dalam file
	     	myfile << "\t\t\t--------- Tentang Aplikasi ---------\n";
			myfile << "\t________________________________________________________________\n\n";
			
			myfile << "\tAplikasi ini dibuat oleh Fikri dan Deni, dua orang mahasiswa\n";
			myfile << "\tdari universitas widyatama Reguler B2 Kelas A\n";
			myfile << "\tAplikasi ini dibuat untuk memenuhi tugas Pemrograman IV\n\n";
			myfile << "\tAplikasi ini berfungsi untuk memesan makanan di resto kedai Fajar\n";
			myfile << "\tDi dalam Aplikasi ini terdapat beberapa menu, diantaranya : \n\n";
			myfile << "\t1. Discovery\n\n";
			myfile << "\t- Anda bisa mengeksplor dan menemukan beberapa menu seperti\n";
			myfile << "\tInformasi Aplikasi, Berbagai makanan yang tersedia, dan Juga berbagai Promo\n\n";
			myfile << "\t2. Book!\n\n";
			myfile << "\t- Di menu inilah anda bisa memesan makanan, anda lihat makanan apa saja yang tersedia\n";
			myfile << "\tSetelah pemesanan maka keluar rincian pemesanan dan anda bisa transfer ke Rek Resto\n\n";
			myfile << "\t3.Pesanan\n\n";
			myfile << "\t- Disini letak history pemesanan yang telah anda lakukan\n";
			myfile << "\tTerlihat nama pemesanan, yang bayar, dan alamat, dan menu apa yang dipesan\n\n";
			myfile << "\t4. Profil\n\n";
			myfile << "\t- Anda bisa mengisi profil anda disini ";
			myfile << "atau Anda bisa juga melihat profil anda\n";
			    
			myfile << "\t________________________________________________________________";
		    
			
			myfile.close(); //menutup file
		}else{
            cout<<"File tidak ditemukan"<<endl;
	    }
	
	ofstream kmfile("kategorimakanan.txt");
		if(kmfile.is_open())
		{
			//menulis ke dalam file
			kmfile << "--------- Kategori Makanan ---------\n\n";
			kmfile << "\tSeafood\n\n";
			kmfile << "01\tKepiting\t25K\n" <<endl;
			kmfile << "02\tKerang\t\t20K\n" <<endl;
			kmfile << "03\tCumi\t\t15K\n\n" << endl;
			kmfile << "\tJuice\n\n";
			kmfile << "04\tAlpukat\t\t8K\n" <<endl;
			kmfile << "05\tJeruk\t\t6K\n" << endl;
			kmfile << "06\tSirsak\t\t10K\n" <<endl;
			kmfile.close(); //menutup file
		}else{
			cout<<"File tidak ditemukan"<<endl;
	    }

	string filenem;
	filenem = "promo.txt";
	ofstream prfile;
    prfile.open(filenem.c_str());
	    //fail() -> untuk memeriksa suatu kesalahan pada operasi file
	      if(!prfile.fail())
		  {
		        //menulis ke dalam file
		        prfile << "--------- Promo ---------\n\n";	
	            prfile<< "Sedang tidak ada promo" <<endl;
     	        prfile.close(); //menutup file
	           // cout << "File berhasil dibuat";
		  } else{
			    cout<<"File tidak ditemukan"<<endl;
		  }
	
	do {
		system("cls");
		cout << "1. Tentang Aplikasi\n";
		cout << "2. Kategori Makanan\n";
		cout << "3. Promo\n";
		cout << "4. Kembali\n";
		cout << "Menu : "; cin >> this->pilihUser;
		
		switch(pilihUser) {
			case 1 : 
			{
			system("cls");
			char ta_text;
			string fileapp;
			fileapp = "tentangaplikasi.txt";
			ifstream myapp;
    		myapp.open(fileapp.c_str());
			
				if(!myapp.fail()) {
			      //ulang selama program belum mencapai akhir konten dari file
			        while (!myapp.eof())
			        {
			                myapp.get(ta_text);
			                cout<<ta_text;
			        }
					myapp.close(); //menutup file
				}else{
			      cout<<"File tidak ditemukan"<<endl;
				}
			_getche();		
			break;
			
			}
			
			case 2 : 
			{
			system("cls");
					//ifstream untuk membaca file
			       char km_text;
					ifstream kmfile("kategorimakanan.txt");
			       //membuka file yang telah ada dan mencari titik akhir file			
			       if(!kmfile.fail())
			       {
			              //ulang selama program belum mencapai akhir konten dari file
			              while (!kmfile.eof())
			              {
			                     kmfile.get(km_text);
			                     cout<<km_text;
			              }
			              kmfile.close(); //menutup file
			       }else{
			              cout<<"File tidak ditemukan"<<endl;
			       }
			       _getche();
			}
			break;
			
			case 3 :
			{
			system("cls");
			
					//stream untuk membaca file
			       ifstream prfile;
			       char pr_text;
			
			       //membuka file yang telah ada
			       prfile.open("promo.txt");
			
			       //fail() -> untuk memeriksa suatu pada kesalahan operasi file
			       if(!prfile.fail())
			       {
			              //ulang selama program belum mencapai akhir konten dari file
			              while (!prfile.eof())
			              {
			                     prfile.get(pr_text);
			                     cout<<pr_text;
			              }
			              prfile.close(); //menutup file
			       }else{
			              cout<<"File tidak ditemukan"<<endl;
			       }
			       _getche();
			}
			break;
			
			case 4 : 
			this->menuUser();
			break;
		}
	} while (pilihUser >= 1 && pilihUser <=4); 
}

void userClass :: cariMakanan(){
	int pilih3;
	int porsi;
	string pesanan;
	double jumlah = 0;
	char cm_text;
	system("cls");	
	
			cout << "---------------- BOOK! ----------------\n\n";
			cout << "\tSeafood\n\n";
			cout << "1. Kepiting \t(25k)\n";
			cout << "2. Kerang \t(20k)\n";
			cout << "3. Cumi \t(15k)\n\n";
			cout << "\tJuice\n\n";
			cout << "4. Alpukat \t(8k)\n";
			cout << "5. Jeruk \t(6k)\n";
			cout << "6. Sirsak \t(10k)\n";
			
		   	cout << "\nPilih Menu : "; cin >> pilih3;   	  
			cout << "\nBerapa porsi : "; cin >> porsi;	  
   	        system("cls");
   	        cout << "-------------- Rincian Pembelanjaan --------------\n";
   	        			if(pilih3 == 1) {
   	        				pesanan = "Kepiting";
							cout << "\nNama : " << pesanan;
							cout << "\nHarga : 25000\n";
							cout << "Jumlah Porsi : " << porsi;
							jumlah = 25000*porsi;
							cout << "\nJumlah Bayar : " << jumlah;
						}
						if(pilih3 == 2) {
							pesanan = "Kerang";
							cout << "\nNama : " << pesanan;
							cout << "\nHarga : 20000\n";
							cout << "Jumlah Porsi : " << porsi;
							jumlah = 20000*porsi;
							cout << "\nJumlah Bayar : " << jumlah;
						}
						if(pilih3 == 3) {
							pesanan = "Cumi";
							cout << "\nNama : " << pesanan;
							cout << "\nHarga : 15000\n";
							cout << "Jumlah Porsi : " << porsi;
							jumlah = 15000*porsi;
							cout << "\nJumlah Bayar : " << jumlah;
						}
						if(pilih3 == 4) {
							pesanan = "Jus Alpukat";
							cout << "\nNama : " << pesanan;
							cout << "\nHarga : 8000\n";
							cout << "Jumlah Porsi : " << porsi;
							jumlah = 8000*porsi;
							cout << "\nJumlah Bayar : " << jumlah;
						}
						if(pilih3 == 5) {
							pesanan = "Jus Jeruk";
							cout << "\nNama : " << pesanan;
							cout << "\nHarga : 6000\n";
							cout << "Jumlah Porsi : " << porsi;
							jumlah = 6000*porsi;
							cout << "\nJumlah Bayar : " << jumlah;
						}
						if(pilih3 == 6) {
							pesanan = "Jus Sirsak";
							cout << "\nNama : " << pesanan;
							cout << "\nHarga : 10000\n";
							cout << "Jumlah Porsi : " << porsi;
							jumlah = 10000*porsi;
							cout << "\nJumlah Bayar : " << jumlah;
						}
						
						char y;
						cout << "\n\nIngin pesan? (y/t) "; cin >> y;
						
						if(y == 'y' || y == 'Y') {
							string namaPesan, namaBayar,alamat, namafile;
							system("cls");
							cout << "Pesanan : " << pesanan;
							cout << "\nJumlah Bayar : " << jumlah;
							cout << "\nMasukkan Nama Pemesan : "; cin >> namaPesan;
							cout << "Masukkan nama pembayar : "; cin >> namaBayar;
							cout << "Masukkan alamat pengiriman : "; cin >> alamat;
							namafile = "D:\\program\\c & c++\\semester 4\\tugas besar alpro\\pesanan\\" + namaPesan + ".txt";
							
							ofstream bookfile;
							bookfile.open(namafile.c_str());
							
							if(!bookfile.fail()){
				      		 	//menulis ke dalam file
							  	bookfile << namaPesan << "\n";
							  	bookfile << namaBayar << "\n";
							  	bookfile << alamat << "\n";
							  	bookfile << pesanan << "\n";
							  	bookfile << jumlah << "\n";
				              	bookfile.close(); //menutup file
				              	cout << "\nMakanan berhasil dipesan\n";
				              	cout << "\nSegera lakukan pembayaran dengan transfer sejumlah " << jumlah << " ke rek berikut : 071756007\n\n"; 
					       	}else{
					              cout<<"File tidak ditemukan"<<endl;
					       }	
			       		 
			              
						} else {
							this->menuUser();
						}
	      
}

void userClass :: pesanan(){
	int pilihPesan;
	string namefile;
	ifstream read(namefile.c_str());
	char pes_text;
	string name, namaPesan, namaBayar, alamat, pesanan, jumlah;
	
	system("cls");
		cout << "----------- History Pemesanan -----------";
		cout << "\n\nMasukkan nama pemesan : "; cin >> namaPesan;
		cout << endl << endl;
		namefile = "D:\\program\\c & c++\\semester 4\\tugas besar alpro\\pesanan\\" + namaPesan + ".txt";
		//membuka file yang telah ada
		read.open(namefile.c_str());
			       
		//fail() -> untuk memeriksa suatu pada kesalahan operasi file
		if(!read.fail())
			{
				getline(read, namaPesan);
				cout << "Nama Pesan : " << namaPesan <<endl;
				getline(read, namaBayar);
				cout << "Nama Bayar : " << namaBayar <<endl;
				getline(read, alamat);
				cout << "Alamat : " << alamat <<endl;
				getline(read, pesanan);
				cout << "Pesanan : " << pesanan <<endl;
				getline(read, jumlah);
				cout << "Jumlah Bayar : " << jumlah << endl << endl;
			              
			    read.close(); //menutup file
			}else{
	        	cout<<"File tidak ditemukan"<<endl;
			}			
}	 

void MemberForm(){
    system ("cls");
    bluetext();
    cout << "\t\t\t      Member Details\n";
    whitetext();
    cout << "\t________________________________________________________________\n\n";
    cout << "\tMember Form   \t";
    cout << "\t  Member: ";
    if (name != "*****"){greentext();};   // If the field is not the default
    cout << name << " ";                  // value use green text, then
    whitetext();                          // revert back to white text.
    if (surname != "*****"){greentext();};
    cout << surname << "\n";
    whitetext();
    cout << "\t\t\t";
    cout << "\t Address: ";
    if (address1 != 00){greentext();};
    cout << address1 << " ";
    whitetext();
    if (address2 != "*****"){greentext();};
    cout << address2 << "\n";
    whitetext();
    cout << "\t\t";
    cout << "\t\t          ";
    if (address3 != "*****"){greentext();};
    cout << address3 << "\n";
    whitetext();
    cout << "\t\t\t\t          ";
    if (address4 != "*****"){greentext();};
    cout << address4 << "\n";
    whitetext();
    cout << "\t\t\t\t          ";
    if (postcode != "*****"){greentext();};
    cout << postcode << "\n";
    whitetext();
    cout << "\t\t\t   Day Telephone: ";
    if (telDay != "00"){greentext();};
    cout << telDay;
    whitetext();
    cout << "\n\t\t       Evening Telephone: ";
    if (telEve != "00"){greentext();};
    cout << telEve << "\n";
    whitetext();
        cout << "\t\t\t      Start date: ";
    if (startDate != 00){greentext();};
    cout << startDate << "/";
    whitetext();
    if (startMonth != 00){greentext();};
    cout << startMonth << "/";
    whitetext();
    if (startYear != 00){greentext();};
    cout << startYear;
    whitetext();
    cout << "\tEnd date: ";
    whitetext();
    if (endDate != 00){greentext();};
    cout << endDate << "/";
    whitetext();
    if (endMonth != 00){greentext();};
    cout << endMonth << "/";
    whitetext();
    if (endYear != 00){greentext();};
    cout << endYear << "\n";
    whitetext();
    cout << "\t________________________________________________________________\n\n";
    cout << "\t\t       Membership number: ";
    if (membershipNumber != 00){greentext();};
    cout << membershipNumber;
    whitetext();
    cout << "\n\t\t         Membership Type: ";
    if (membershipType != "*****"){greentext();};
    cout << membershipType;
    whitetext();
    cout << "\n\n\tNotes: ";
    if (memberNotes != "*****"){greentext();};
    cout << memberNotes;
    whitetext();
    cout << "\n\t________________________________________________________________\n\n";
    cout << "\n";
};

void userClass :: savefile(){
    string saveFileName;
    stringstream out;
    saveFileName = "D:\\program\\c & c++\\semester 4\\tugas besar alpro\\profil\\"  + un + ".txt";
    ofstream myfile;                                  //Save file structure
    myfile.open (saveFileName.c_str(), ios::out);
    myfile << name << "\n";
    myfile << surname << "\n";
    myfile << address1 << "\n";
    myfile << address2 << "\n";
    myfile << address3 << "\n";
    myfile << address4 << "\n";
    myfile << postcode << "\n";
    myfile << telDay << "\n";
    myfile << telEve << "\n";
    myfile << startDate << "\n";
    myfile << startMonth << "\n";
    myfile << startYear << "\n";
    myfile << endDate << "\n";
    myfile << endMonth << "\n";
    myfile << endYear << "\n";
    myfile << membershipNumber << "\n";
    myfile << membershipType << "\n";
    myfile << memberNotes << "\n";
    myfile.close();
    MemberForm();
    greentext();
    cout << "\tDetails have been saved\n\n\t";
    whitetext();
    system ("pause");
    }

void userClass :: profil(){
	string filename, user;
	int menu;
	system("cls");
	cout << "---------------- Profil ----------------\n";
		
	filename = "D:\\program\\c & c++\\semester 4\\tugas besar alpro\\useradmin\\" + un + ".txt";
	ifstream read(filename.c_str());
	getline(read, un);
	
	cout << "Hello " << un << endl;
	cout << "\n1. Lihat Profil";
	cout << "\n2. Isi Profil";
	cout << "\nMenu : "; cin >> menu;
	
	if(menu == 1) {
		system("cls");
					//stream untuk membaca file
			       ifstream profile;
			       char pro_text;
					filename =  "D:\\program\\c & c++\\semester 4\\tugas besar alpro\\profil\\"  + un + ".txt";
			       //membuka file yang telah ada
			       profile.open(filename.c_str());
			
			       //fail() -> untuk memeriksa suatu pada kesalahan operasi file
			       if(!profile.fail())
			       {
			       	
			       		system ("cls");
						    bluetext();
						    cout << "\t\t\t      Member Details\n";
						    whitetext();
						    cout << "\t________________________________________________________________\n\n";
						    cout << "\tMember Form   \t";
						    cout << "\t  Member: ";
						    getline(profile, name); {greentext();};
			       												   // If the field is not the default
						    cout << name << " ";                  // value use green text, then
						    whitetext();                          // revert back to white text.
						    getline(profile, surname);{greentext();};
						    cout << surname << "\n";
						    whitetext();
						    cout << "\t\t\t";
						    cout << "\t Address: ";
						    profile >> address1; {greentext();};
						    cout << address1 << " ";
						    whitetext();
						    profile >> address2; {greentext();};
						    cout << address2 << "\n";
						    whitetext();
						    cout << "\t\t";
						    cout << "\t\t          ";
						    profile >> address3; {greentext();};
						    cout << address3 << "\n";
						    whitetext();
						    cout << "\t\t\t\t          ";
						    profile >> address4; {greentext();};
						    cout << address4 << "\n";
						    whitetext();
						    cout << "\t\t\t\t          ";
						    profile >> postcode; {greentext();};
						    cout << postcode << "\n";
						    whitetext();
						    cout << "\t\t\t   Day Telephone: ";
						    profile >> telDay; {greentext();};
						    cout << telDay;
						    whitetext();
						    cout << "\n\t\t       Evening Telephone: ";
						    profile >> telEve; {greentext();};
						    cout << telEve << "\n";
						    whitetext();
						        cout << "\t\t\t      Start date: ";
						    profile >> startDate; {greentext();};
						    cout << startDate << "/";
						    whitetext();
						    profile >> startMonth; {greentext();};
						    cout << startMonth << "/";
						    whitetext();
						    profile >> startYear; {greentext();};
						    cout << startYear;
						    whitetext();
						    cout << "\tEnd date: ";
						    whitetext();
						    profile >> endDate; {greentext();};
						    cout << endDate << "/";
						    whitetext();
						    profile >> endMonth; {greentext();};
						    cout << endMonth << "/";
						    whitetext();
						    profile >> endYear; {greentext();};
						    cout << endYear << "\n";
						    whitetext();
						    cout << "\t________________________________________________________________\n\n";
						    cout << "\t\t       Membership number: ";
						    profile >> membershipNumber; {greentext();};
						    cout << membershipNumber;
						    whitetext();
						    cout << "\n\t\t         Membership Type: ";
						    profile >> membershipType; {greentext();};
						    cout << membershipType;
						    whitetext();
						    cout << "\n\n\tNotes: ";
						    profile >> memberNotes; {greentext();};
						    cout << memberNotes;
						    whitetext();
						    cout << "\n\t________________________________________________________________\n\n";
						    cout << "\n";
			       	
			              profile.close(); //menutup file
			       }else{
			              cout<<"File tidak ditemukan"<<endl;
			       }
			       _getche();		       
	} 
	
	 else if (menu == 2){
		char saveYN;
 		char yes;		
		    MemberForm();
	    
	    	cout << "\tIngin mengisi data? (Y/N) "; cin >> yes;
	    	if(yes == 'n' || yes == 'N') {
	    		profil();
			} else {
	    	cout << endl;
		    cout << "\tPlease enter customers first name: ";
		    cin >> ws;
		    getline (cin, name);
		    MemberForm();
		    cout << "\tPlease enter customers surname: ";
		    cin >> surname;
		    MemberForm();
		    cout << "\tPlease enter customers house number: ";
		    cin >> address1;
		                while (cin.fail()||  address1 < 1)  // Checks for invalid entry.
		    {cin.clear(); cin.ignore();
		    cout << "\n\tPlease enter a valid house number: "; cin >> address1;}
		    MemberForm();
		    cout << "\tPlease enter customers street: ";
		    cin >> ws;                        // Allows the user to enter more than one word
		    getline (cin, address2);          // in a string by allowing white spaces.
		    MemberForm();
		    cout << "\tPlease enter customer area: ";
		    getline (cin, address3);
		    MemberForm();
		    cout << "\tPlease enter customer city: ";
		    getline (cin, address4);
		    MemberForm();
		    cout << "\tPlease enter customer postcode: ";
		    cin >> ws;
		    getline (cin, postcode);
		    MemberForm();
		    cout << "\tPlease enter Daytime Telephone Number: ";
		    //cin >> ws;
		    getline (cin, telDay);
		    while (cin.fail()){ //Handles character in integer variable
		        cin.clear();
		        cin.ignore();
		        cout << "\tPlease enter Daytime Telephone Number: ";
		        cin >> telDay;
		    };
		    MemberForm();
		    cout << "\tPlease enter Evening Telephone Number: ";
		    //cin >> ws;
		    getline (cin, telEve);
		    while (cin.fail()){
		        cin.clear();
		        cin.ignore();
		        cout << "\tPlease enter Evening Telephone Number: ";
		        cin >> telEve;
		    };
		    MemberForm();
		    cout << "\tPlease enter Membership Start Date(DD): ";
		    cin >> startDate;
		    while (cin.fail() || startDate > 31 || startDate < 1){//Catches invalid date
		        cin.clear(); cin.ignore();
		        cout << "\n\tPlease enter a valid date (1-31): ";
		        cin >> startDate;
		    };
		    MemberForm();
		    cout << "\tPlease enter Membership Start Month(MM): ";
		    cin >> startMonth;
		    while (cin.fail() || startMonth > 12 || startMonth < 1){//Catches invalid month
		        cin.clear(); cin.ignore();
		        cout << "\n\tPlease enter a valid month (1-12): ";
		        cin >> startMonth;}
		    MemberForm();
		    cout << "\tPlease enter Membership Start Year(YY): ";
		    cin >> startYear;
		    while (cin.fail() || startYear > 99 || startYear < 1){//Catches invalid year
		        cin.clear(); cin.ignore();
		        cout << "\n\tPlease enter a valid Year (1-99): ";
		        cin >> startYear;}
		    MemberForm();
		    cout << "\tPlease enter Membership End Date(DD): ";
		    cin >> endDate;
		    while (cin.fail() || endDate > 31 || endDate < 1){
		        cin.clear(); cin.ignore();
		        cout << "\n\tPlease enter a valid date (1-31): ";
		        cin >> endDate;}
		    MemberForm();
		    cout << "\tPlease enter Membership End Month(MM): ";
		    cin >> endMonth;
		    while (cin.fail() || endMonth > 12 || endMonth < 1){
		        cin.clear(); cin.ignore();
		        cout << "\n\tPlease enter a valid month (1-12): ";
		        cin >> endMonth;}
		    MemberForm();
		    cout << "\tPlease enter Membership End Year(YY): ";
		    cin >> endYear;
		    while (cin.fail() || endYear > 99 || endYear < 1){
		        cin.clear(); cin.ignore();
		        cout << "\n\tPlease enter a valid year (1-99): ";
		        cin >> endYear;}
		    MemberForm();
		    cout << "\tEnter 6 Digit membership card number: ";
		    cin >> membershipNumber;
		    while (cin.fail() || membershipNumber < 100000 || membershipNumber > 999999){
		        cin.clear(); cin.ignore();      //Ensures membership numbers are 6 digits
		        cout << "\n\tPlease enter a valid membership card number (6 Digits): ";
		        cin >> membershipNumber;
		    };
		    MemberForm();
		    cout << "\tPlease enter membership type:\n\t1 - Bronze\n\t2 - Silver\n\t3 - Gold\n\t> : ";
		    cin >> membershipSelection;
		    while (cin.fail() || membershipSelection < 1 || membershipSelection >3){
		 
		        cin.clear();
		        cin.ignore();           //Handles invalid membership selection
		 
		 
		        cout << "\n\tPlease enter a valid membership type.\n\t1 - Bronze - 10.00 Per month\n\t2 - Silver - 15.00 Per month\n\t3 - Gold  - 20.00 Per month\n\t> : ";
		        cin >> membershipSelection;
		    };
		    switch (membershipSelection){
		    case 1 :
		        membershipType = "Bronze";
		        break;
		    case 2 :
		        membershipType = "Silver";
		        break;
		    case 3 :
		        membershipType = "Gold";
		        break;
		    //default :
		 
		    };
		    MemberForm();
		    cout << "\tPlease enter any additional notes:\n\t";
		    cin.ignore();
		    getline (cin, memberNotes);
		    MemberForm();
		    cout << "\tSave these details to a file? <Y/N> ";
		 
		    //Confirmation before saving a file
		    cin >> saveYN;
		    if (saveYN == 'y' || saveYN == 'Y'){
		        savefile();
		    };
		}
	}
	
	else {
		cout << "salah";
	}
}

// Resets variables to default values
void resetMemberDetails(){
 
     name =     "*****";
     surname =  "*****";
     address1 = 00;
     address2 = "*****";
     address3 = "*****";
     address4 = "*****";
     postcode = "*****";
     startDate  = 00;
     startMonth = 00;
     startYear  = 00;
     endDate  = 00;
     endMonth = 00;
     endYear  = 00;
     telDay = "00";
     telEve = "00";
     membershipNumber = 00;
     membershipType   = "*****";
     memberNotes      = "*****";
 
     activity = "*****";
     activityDate = 00;
     activityMonth = 00;
     activityYear = 00;
     activityPrice = 00;
};


int main() {
	userClass user;
		int menu2;
		system("cls");
		resetMemberDetails();
		cout << "--------------- Welcome to Kedai Fajar ---------------\n";
				cout << "1. Registration\n";
				cout << "2. Login\n";
				cout << "Menu : "; cin >> menu2;
				
				if(menu2 == 1){
					system("cls");
					string username, password, filename;
					cout << "Select a username : "; cin >> username;
					cout << "Select a password : "; cin >> password;
					
					filename = "D:\\program\\c & c++\\semester 4\\tugas besar alpro\\useradmin\\" + username + ".txt";
					ofstream file;
					file.open(filename.c_str());
					file << username << endl << password;
					file.close();
					
					main();
				} else if(menu2 == 2) {
					bool status = user.IsLoggedIn();
					
					if(!status) {
						cout << "False Login" << endl;
						system("pause");
						main(); 
					} else {
						cout << "Succesfully Logged In" << endl;
						system("pause");
						user.menuUser();
					}
				}
	return 0;
}
