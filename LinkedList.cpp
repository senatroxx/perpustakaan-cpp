#include <iostream>
#include <limits>

using namespace std;

struct Buku {
  string judul, pengarang;
  int tahunTerbit;

  Buku *next;
};

Buku *head, *tail, *current, *newNode, *temp, *temp2;

// Fungsi untuk inisialisasi node dummy
void dummyNode();

// Fungsi untuk membuat node dummy
void createDummyNode(string judul, string pengarang, int tahunTerbit);

// Menampilkan menu
int menu();

// Fungsi untuk membuat node
void createNode();

// Fungsi untuk print node
void printNode();

// Fungsi untuk menampilkan menu pencarian
void searchMenu();

// Fungsi untuk mencari node berdasarkan judul
void searchByJudul();

// Fungsi untuk mencari node berdasarkan pengarang
void searchByPengarang();

// Fungsi untuk mencari node berdasarkan tahun terbit
void searchByTahunTerbit();

// Fungsi untuk mengedit node berdasarkan judul
void updateNode();

// Fungsi untuk menampilkan menu hitung node
void countMenu();

// Fungsi untuk menghitung node berdasarkan judul
void countByJudul();

// Fungsi untuk menghitung node berdasarkan pengarang
void countByPengarang();

// Fungsi untuk menghitung node berdasarkan tahun terbit
void countByTahunTerbit();

// Fungsi untuk menghitung semua node
void countAll();

// Fungsi untuk menampilkan menu hapus node
void destroyMenu();

// Fungsi untuk menghapus node berdasarkan judul
void destroyLastNode();

// Fungsi untuk menghapus key pada node berdasarkan judul
void destroyByJudul();

// Fungsi untuk menghapus key pada node berdasarkan pengarang
void destroyByPengarang();

// Fungsi untuk menghapus key pada node berdasarkan tahun terbit
void destroyByTahunTerbit();

int main(){
  dummyNode();
  while(true){
    switch (menu()){
      case 1: // Tambah Buku
        createNode();
        continue;

      case 2: // Daftar Buku
        printNode();
        continue;

      case 3: // Hitung Buku
        countMenu();
        continue;

      case 4: // Cari Buku
        searchMenu();
        continue;

      case 5: // Edit Buku
        updateNode();
        continue;

      case 6: // Hapus Buku
        destroyMenu();
        continue;

      // Keluar
      case 7:
        break;
      default:
        break;
    }
    break;
  }



  return 0;
}

void dummyNode(){
  createDummyNode("This Earth of Mankind", "Pramoedya Ananta Toer", 1980);
  createDummyNode("Da Vinci Code", "Dan Brown", 2003);
  createDummyNode("Harry Potter and the Philosopher's Stone", "J. K. Rowling", 1997);
  createDummyNode("Harry Potter and the Chamber of Secrets", "J. K. Rowling", 1998);
  createDummyNode("Harry Potter and the Prisoner of Azkaban", "J. K. Rowling", 1999);
  createDummyNode("Harry Potter and the Goblet of Fire Literature Guide", "J. K. Rowling", 2000);
}

void createDummyNode(string judul, string pengarang, int tahunTerbit){
  newNode = new Buku();
  newNode->judul = judul;
  newNode->pengarang = pengarang;
  newNode->tahunTerbit = tahunTerbit;

  if (head == NULL) {
    head = newNode;
    tail = newNode;
    newNode->next = NULL;
  }
  else {
    tail->next = newNode;
    tail = newNode;
    newNode->next = NULL;
  }
}

int menu(){
  cout << "\033[1;34m==============================\033[0m" << endl;
  cout << "\033[1;34m|    Perpustakaan Digital    |\033[0m" << endl;
  cout << "\033[1;34m==============================\033[0m" << endl;
  cout << "1. Tambah Buku" << endl;
  cout << "2. Daftar Buku" << endl;
  cout << "3. Hitung Buku" << endl;
  cout << "4. Cari Buku" << endl;
  cout << "5. Edit Buku" << endl;
  cout << "6. Hapus Buku" << endl;
  cout << "7. Keluar" << endl;
  cout << "==============================" << endl;
  while (true)
  {
    int menu;
    cout << "Pilih menu: "; cin >> menu;

    if(menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5 || menu == 6 || menu == 7){
      cout << "==============================" << endl << endl;    
      return menu;
    }
    else{
      cout << "Menu tidak tersedia" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}

void createNode(){
  string judul, pengarang; 
  int tahunTerbit;

  cout << "==============================" << endl;
  cout << "|      Tambah Buku Baru      |" << endl;
  cout << "==============================" << endl;
  cin.ignore();
  cout << "Judul: "; getline(cin, judul);
  cout << "Pengarang: "; getline(cin, pengarang);
  cout << "Tahun Terbit: "; cin >> tahunTerbit;
  if(!cin){
    cout << "Nilai salah, gunakan integer! (0-9)" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Tahun Terbit: "; cin >> tahunTerbit;
  }

  newNode = new Buku();
  newNode->judul = judul;
  newNode->pengarang = pengarang;
  newNode->tahunTerbit = tahunTerbit;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    tail = newNode;
  }
  else {
    tail->next = newNode;
    tail = newNode;
  }

  cout << "- Buku berhasil ditambahkan -" << endl << endl;
}

void printNode(){
  cout << "==============================" << endl;
  cout << "|        Daftar Buku         |" << endl;
  cout << "==============================" << endl;
  current = head;
  while (current != NULL) {
    cout << "Judul: " << current->judul << endl;
    cout << "Pengarang: " << current->pengarang << endl;
    cout << "Tahun Terbit: " << current->tahunTerbit << endl;
    cout << endl;

    current = current->next;
  }
}

void searchMenu(){
  int menu;
  cout << "==============================" << endl;
  cout << "|    Cari Buku Berdasarkan   |" << endl;
  cout << "==============================" << endl;
  cout << "1. Judul" << endl;
  cout << "2. Pengarang" << endl;
  cout << "3. Tahun Terbit" << endl;
  cout << "4. Kembali" << endl;
  cout << "==============================" << endl;
  while (true)
  {
    cout << "Pilih menu: "; cin >> menu;
    if(!cin){
      cout << "Nilai salah, gunakan integer! (0-9)" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    if(menu == 1 || menu == 2 || menu == 3 || menu == 4){
      break;
    }
    else{
      cout << "Menu tidak tersedia" << endl;
    }
  }
  cout << "==============================" << endl << endl;

  switch (menu){
  case 1: // Search by judul
    searchByJudul();
    break;
  case 2: // Search by pengarang
    searchByPengarang();
    break;
  case 3: // Search by tahun terbit
    searchByTahunTerbit();
    break;

  case 4:
    break;
  default:
    break;
  }
}

void searchByJudul(){
  string keyword;
  cin.ignore();
  cout << "Masukkan judul: "; getline(cin, keyword);
  cout << "Hasil pencarian: " << endl;
  current = head;
  while (current != NULL) {
    if (current->judul == keyword) {
      cout << "Judul: " << current->judul << endl;
      cout << "Pengarang: " << current->pengarang << endl;
      cout << "Tahun Terbit: " << current->tahunTerbit << endl;
      cout << endl;
    }
    current = current->next;
  }
}

void searchByPengarang(){
  string keyword;
  cin.ignore();
  cout << "Masukkan pengarang: "; getline(cin, keyword);
  cout << "Hasil pencarian: " << endl;
  // search node by pengarang
  current = head;
  while (current != NULL) {
    if (current->pengarang == keyword) {
      cout << "Judul: " << current->judul << endl;
      cout << "Pengarang: " << current->pengarang << endl;
      cout << "Tahun Terbit: " << current->tahunTerbit << endl;
      cout << endl;
    }
    current = current->next;
  }
}

void searchByTahunTerbit(){
  int keyword;
  cout << "Masukkan tahun terbit: "; cin >> keyword;
  cout << "Hasil pencarian: " << endl;
  // search node by tahunTerbit
  current = head;
  while (current != NULL) {
    if (current->tahunTerbit == keyword) {
      cout << "Judul: " << current->judul << endl;
      cout << "Pengarang: " << current->pengarang << endl;
      cout << "Tahun Terbit: " << current->tahunTerbit << endl;
      cout << endl;
    }
    current = current->next;
  }
}

void updateNode(){
  string keyword;
  cin.ignore();
  cout << "Masukkan judul buku yang ingin diedit: "; getline(cin, keyword);
  cout << "==============================" << endl;
  current = head;
  while (current != NULL) {
    if (current->judul == keyword) {
      cout << "==============================" << endl;
      cout << "|       Buku Ditemukan       |" << endl;
      cout << "==============================" << endl;
      cout << "Judul: " << current->judul << endl;
      cout << "Pengarang: " << current->pengarang << endl;
      cout << "Tahun Terbit: " << current->tahunTerbit << endl;
      cout << endl;
      cout << "Masukkan judul baru: "; getline(cin, current->judul);
      cout << "Masukkan pengarang baru: "; getline(cin, current->pengarang);
      cout << "Masukkan tahun terbit baru: "; cin >> current->tahunTerbit;
      cout << "- Buku berhasil diupdate -" << endl << endl;
    }
    current = current->next;
  }
}

void countMenu(){
  int menu;
  cout << "==============================" << endl;
  cout << "|  Hitung Buku Berdasarkan   |" << endl;
  cout << "==============================" << endl;
  cout << "1. Judul" << endl;
  cout << "2. Pengarang" << endl;
  cout << "3. Tahun Terbit" << endl;
  cout << "4. Hitung Semua" << endl;
  cout << "5. Kembali" << endl;
  cout << "==============================" << endl;
  while (true)
  {
    cout << "Pilih menu: "; cin >> menu;
    if(!cin){
      cout << "Nilai salah, gunakan integer! (0-9)" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    if(menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5){
      break;
    }
    else{
      cout << "Menu tidak tersedia" << endl;
    }
  }
  cout << "==============================" << endl << endl;

  switch (menu){
  case 1: // Count by judul
    countByJudul();
    break;
  case 2: // Count by pengarang
    countByPengarang();
    break;
  case 3: // Count by tahun terbit
    countByTahunTerbit();
    break;

  case 4: // Count All
    countAll();
    break;

  case 5:
    break;
  default:
    break;
  }
}

void countByJudul(){
  string keyword;
  int count = 0;
  cin.ignore();
  cout << "Masukkan judul: "; getline(cin, keyword);
  current = head;
  while (current != NULL) {
    if (current->judul == keyword) {
      count++;
    }
    current = current->next;
  }
  cout << "Jumlah yang ditemukan: " << count << " Buku" << endl << endl;
}

void countByPengarang(){
  string keyword;
  int count = 0;
  cin.ignore();
  cout << "Masukkan pengarang: "; getline(cin, keyword);
  current = head;
  while (current != NULL) {
    if (current->pengarang == keyword) {
      count++;
    }
    current = current->next;
  }
  cout << "Jumlah yang ditemukan: " << count << " Buku" << endl << endl;
}

void countByTahunTerbit(){
  int keyword, count = 0;
  cout << "Masukkan pengarang: "; cin >> keyword;
  current = head;
  while (current != NULL) {
    if (current->tahunTerbit == keyword) {
      count++;
    }
    current = current->next;
  }
  cout << "Jumlah yang ditemukan: " << count << " Buku" << endl << endl;
}

void countAll(){
  int count = 0;
  current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  cout << "Jumlah buku: " << count << endl << endl;
}

void destroyMenu(){
  int menu;
  cout << "==============================" << endl;
  cout << "|   Hapus Buku Berdasarkan   |" << endl;
  cout << "==============================" << endl;
  cout << "1. Judul" << endl;
  cout << "2. Pengarang" << endl;
  cout << "3. Tahun Terbit" << endl;
  cout << "4. Hapus Buku Terakhir" << endl;
  cout << "5. Kembali" << endl;
  cout << "==============================" << endl;
  while (true)
  {
    cout << "Pilih menu: "; cin >> menu;
    if(!cin){
      cout << "Nilai salah, gunakan integer! (0-9)" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    if(menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5){
      break;
    }
    else{
      cout << "Menu tidak tersedia" << endl;
    }
  }
  cout << "==============================" << endl << endl;

  switch (menu){
    case 1: // Destroy by judul
      destroyByJudul();
      break;
    case 2: // Destroy by pengarang
      destroyByPengarang();
      break;
    case 3: // Destroy by tahun terbit
      destroyByTahunTerbit();
      break;
    case 4: // Destroy node terakhir
      destroyLastNode();
      break;

    case 5:
      break;
    default:
      break;
  }
}

void destroyLastNode(){
  char choice;
  cin.ignore();
  cout << "Buku paling akhir akan dihapus dari perpustakaan." << endl;
  cout << "Lanjutkan? (y/n): "; cin >> choice;
  cout << "==============================" << endl;
  if(tolower(choice) == 'y'){
    if(head == NULL){
      cout << "- Tidak ada buku yang dapat dihapus -" << endl << endl;
    }
    else{
      temp = tail;
      current = head;
      while (current->next != tail) {
        current = current->next;
      }

      tail = current;
      tail->next = NULL;
      delete temp;
      cout << "- Buku berhasil dihapus -" << endl << endl;
    }
  }
  else{
    cout << "- Buku tidak jadi dihapus -" << endl << endl;
  }
}

void destroyByJudul(){
  string keyword;
  int len = 0, deleted = 0;
  cin.ignore();
  cout << "Masukkan judul: "; getline(cin, keyword);
  current = head;
  while (current != NULL) {
    if (current->judul == keyword) {
      deleted++;
      if(current == head){
        head = current->next;
        delete current;
        break;
      }
      else{
        temp2 = head;
        for (int i = 1; i < len; i++)
        {
          temp2 = temp2->next;
        }
        
        temp = current;
        temp2->next = current->next;
        current = current->next;
        delete temp;
        break;
      }
    }
    len++;
    current = current->next;
  }
  if(deleted == 0){
    cout << "- Buku tidak ditemukan -" << endl;
  }else {
    cout << "- Buku berhasil dihapus -" << endl;
  }
  cout << "- Jumlah buku yang dihapus: " << deleted << " -" << endl << endl;
}

void destroyByPengarang(){
  string keyword;
  int len = 0, deleted = 0;
  cin.ignore();
  cout << "Masukkan pengarang: "; getline(cin, keyword);
  current = head;
  while (current != NULL) {
    if (current->pengarang == keyword) {
      deleted++;
      if(current == head){
        head = current->next;
        delete current;
        continue;
      }
      else{
        temp2 = head;
        for (int i = 1; i < len; i++)
        {
          temp2 = temp2->next;
        }
        
        temp = current;
        temp2->next = current->next;
        current = current->next;
        delete temp;
        continue;
      }
    }
    len++;
    current = current->next;
  }
  if(deleted == 0){
    cout << "- Buku tidak ditemukan -" << endl;
  }else {
    cout << "- Buku berhasil dihapus -" << endl;
  }
  cout << "- Jumlah buku yang dihapus: " << deleted << " -" << endl << endl;
}

void destroyByTahunTerbit(){
  int keyword;
  int len = 0, deleted = 0;
  cin.ignore();
  cout << "Masukkan tahun terbit: "; cin >> keyword;
  current = head;
  while (current != NULL) {
    if (current->tahunTerbit == keyword) {
      deleted++;
      if(current == head){
        head = current->next;
        delete current;
        continue;
      }
      else{
        temp2 = head;
        for (int i = 1; i < len; i++)
        {
          temp2 = temp2->next;
        }
        
        temp = current;
        temp2->next = current->next;
        current = current->next;
        delete temp;
        continue;
      }
    }
    len++;
    current = current->next;
  }
  if(deleted == 0){
    cout << "- Buku tidak ditemukan -" << endl;
  }else {
    cout << "- Buku berhasil dihapus -" << endl;
  }
  cout << "- Jumlah buku yang dihapus: " << deleted << " -" << endl << endl;
}