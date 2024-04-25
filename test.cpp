#include <iostream>
using namespace std;

struct Node {
    int noMhs;
    string name;
    Node* next;
};

Node* START = NULL;

void addNote() {
    int nim;
    string nama;
    Node* nodeBaru = new Node() ;
    cout<< "Masukkan NIM : ";
     cin >> nim;
     cout << "Masukkan Nama: ";
     cin >> nama;
     nodeBaru->noMhs = nim;
     nodeBaru->name = nama;

     if (START == NULL || nim <= START->noMhs) {
        if (START !=NULL && nim == START->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }

        nodeBaru->next =START;
        START= nodeBaru;
        return;
     } 

     Node* previous = START;
     Node* current = START;

     while ((current != NULL) && (nim >= current->noMhs)) 
     {
        if (nim == current->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }
     }  previous = current;
        current = current->next;

        nodeBaru-> =current;
        previous->next =nodeBaru;
     }


     bool serachNode(int nim, Node* current, Node* previous) {
        previous = START;
        current = START;
        while (current != NULL && nim > current->noMhs)
        {
            previous = current;
            current = current->next;
        }
        if (current == NULL)
        {
            return false;
        }
        else if (current->noMhs ==nim)
        {
            return true;
        }
        else
        {
            return false;
        }
     }
     bool deleteNode(int nik) {
        Node* current = START;
        Node* previous =START;
        if (current == START)
             START = current->next;
             return true;
     }
     bool listEmpty(){
        if (START ==NULL)
            return true;
        else
            return false;

     }

     void traverse () {
        if (listEmpty()) {
            cout << "List Kosong" << endl;
            system ("pause");
            system ("cls");
            return;
          }
          else {
               Node* currentNode =START;
               while (currentNode !=NULL) {
                cout << "NIM: " << currentNode->noMhs << ", Nama:" << currentNode->name << endl;
                currentNode = currentNode->next;
               }
          }
     }
     void searchData() {
        if (listEmpty()) {
            cout << "LisKosong" << endl;
            system ("pause");
            system ("cls");
            return;
        }
        else {
            int nim;
            cout << "Masukkan NIM: ";
            cin >> nim;
            Node* currentNode = START;
            while (currentNode ! = NULL) {
                if (currentNode->noMhs == nim) {
                    cout << "NIM:" << currentNode->noMhs << currentNode->name << endl;
                    return;
                }
                currentNode = currentNode->next;
            }
            cout<< "Data tidak ditemukan" << endl;
        }
     }

     int main() {
        int pilihan;
        do
        {
            try
             {
                cout << "1. Tambah Data" << endl;
                cout << "2. Hapus Data" << endl;
                cout << "3. Tampilkan Data" << endl;
                cout << "4. Cari Data" << endl;
                cout << "5. Keluar" << endl;
                cout << "Pilihan: ";
                cin >> pilihan;
                switch (pilihan)
                {
                    case 1:
                    addNode();
                    cout << "Data Berhasil ditemukan" << endl; 
                    system ("pause");
                    system ("cls");
                    break;
                }

                int nim;
                cout << "Masukka NIM: ";
                cin >> nim;
                if (deleteNode(nim)) {
                    cout << "nim:" << nim << "berhasil di hapus" << endl;
                    system ("pause");
                    system ("cls");
                }
                else
                     cout << "Data tidak ditemukan" << endl;
                break;
                case 3 :
                traverse();
                break;
                case 4:
                searchData();
                break;
                case 5:
                break;
            default: 
            cout <<"pilihan tidak ada" << endl;
            break;
             }
        
          }
          catch (exception e)
          {
            cout << "terjadi kesalahan" << endl;
          }


           }   while (pilihan !=5);
       
       }