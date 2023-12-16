#include <iostream>
using namespace std;

struct DataMahasiswa{
  string nama;
  string jurusan;
  string npm;

  // pointer
  DataMahasiswa *prev;
  DataMahasiswa *next;
};

DataMahasiswa *head, *tail, *cur, *newNode, *del;
int maksimalData = 6;


void createData(string nama, string jurusan, string npm){
  head = new DataMahasiswa();
  head->nama = nama;
  head->jurusan = jurusan;
  head->npm = npm;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int countData()
{
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

bool isFullData()
{
  if( countData() == maksimalData ){
    return true;
  }else{
    return false;
  }
}

bool isEmptyData()
{
  if( countData() == 0 ){
    return true;
  }else{
    return false;
  }
}

void pushData( string nama, string jurusan, string npm ){

  if( isFullData() ){
    cout << "Data Stack Full!!" << endl;
  }else{
    if( isEmptyData() ){
      createData(nama, jurusan,npm);
    }else{
      newNode = new DataMahasiswa();
      newNode->nama = nama;
      newNode->jurusan = jurusan;
      newNode->npm = npm;
      newNode->prev = tail;
      tail->next = newNode;
      newNode->next = NULL;
      tail = newNode;
    }
  }

}

void popData()
{
  del = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete del;
}

void displayData()
{
  if( isEmptyData() ){
    cout << "Data Mahasiswa Kosong" << endl;
  }else{
    cur = tail;
    while( cur != NULL ){
      cout << "\nNama Mahasiswa : " << cur->nama << "\nJurusan : " << cur->jurusan <<"\nNPM : "<<cur->npm<< endl;
      cur = cur->prev;
    }
  }
}

void peekData(int posisi){

  if( isEmptyData() ){
    cout << "Data Mahasiswa kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cout << "Data Mahasiswa Posisi ke-" << posisi << " Nama Mahasiswa : " << cur->nama << " Jurusan : " << cur->jurusan <<"NPM : "<<cur->npm<< endl;
  }

}

void changeData(string nama, string jurusan, string npm, int posisi){

  if( isEmptyData() ){
    cout << "Data Mahasiswa kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cur->nama = nama;
    cur->jurusan = jurusan;
    cur->npm = npm;
  }

}

void destroyData()
{
  cur = head;
  while( cur != NULL ){
    del = cur;
    head = head->next;
    delete del;
    cur = cur->next;
  }
}

int main(){

    // Delkarasi Variabel
    int pilihan;
    string nama,npm,jurusan;
    string data[3];
    
    // STACK GOTO
    stack :
        // DASHBOARD
        system("cls");
        int posisi;
        int banyakData = countData();
        cout<<"Jumlah Data : "<<banyakData<<endl;

        // KONDISI DATA BELUM PENUH
        if(banyakData<6)
        {
          displayData();
          cout << "\nMenu Utama\n1. Data Baru\n2. Tambahkan\n3. Hapus Data paling atas\n4. Format Data\n5. Ubah Data\n6. Keluar\n";
          cout<<"Pilih Menu : "<<endl; 
          cin >> pilihan;
          cin.ignore(); // Clear the newline character from the input buffer

            // Menu Pilihan 1 -> Data Baru
              if(pilihan==1)
              {
                system("cls");
                cout << "Masukkan Nama : ";
                getline(cin, nama);

                // Input for Jurusan
                cout << "Masukkan Jurusan : ";
                getline(cin, jurusan);

                // Input for NPM
                cout << "Masukkan NPM : ";
                getline(cin, npm);
                createData(nama,jurusan,npm);
                goto stack;

              // Menu Pilihan 2 -> Tambah Data
              }else if(pilihan==2){
                system("cls");
                cout << "Masukkan Nama : ";
                getline(cin, nama);

                // Input for Jurusan
                cout << "Masukkan Jurusan : ";
                getline(cin, jurusan);

                // Input for NPM
                cout << "Masukkan NPM : ";
                getline(cin, npm);
                pushData(nama,jurusan,npm);
                goto stack;

              // Menu Pilihan 3 -> Hapus data paling atas
              }else if(pilihan==3){
                system("cls");
                popData();
                goto stack;

              // Menu Pilihan 4 -> Format Data
              }else if(pilihan==4){
                system("cls");
                destroyData();
                goto stack;

              // Menu Pilihan 5 -> Ubah Data
              }else if(pilihan==5){
                system("cls");
                cout<<"Ubah data ke : "<<endl;
                cin >> posisi;
                cin.ignore();
                cout << "Masukkan Nama : ";
                getline(cin, nama);
                // Input for Jurusan
                cout << "Masukkan Jurusan : ";
                getline(cin, jurusan);
                // Input for NPM
                cout << "Masukkan NPM : ";
                getline(cin, npm);
                changeData(nama, jurusan,npm,posisi);
                goto stack;

              // Menu Pilihan 6 -> Keluar Program
              }else if(pilihan==6){

              // Input diluar MENU
              }else{
                system("cls");
                cout<<"Pilihan yang anda masukan salah\n";
              }
      
          // KONDISI DATA PENUH
        }else{
            cout<<"Data sudah penuh, tidak bisa menambahkan"<<endl;
            cout << "\nPilih Menu\n1. Kembali ke Menu\n2. Format Data\n3. Keluar\n";
            cout<<"Pilih Menu : "<<endl; 
            cin >> pilihan;
            }if(pilihan==1){
            system("cls");
            popData();
            goto stack;
        }else if(pilihan==2){
              system("cls");
              destroyData();
              goto stack;
        }else{
          cout<<"Program Selesai"<<endl;
        }

}

  
