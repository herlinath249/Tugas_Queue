#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

typedef struct daftar{
	string nama;
	string posisi;
	int nomor;
}dData;

class simpul
{
	public :
		dData datapemain;
		simpul* pBerikutnya;
		
		
		simpul(string nama_pemain,string posisi_pemain, int no_pemain)
			{
				datapemain.nama = nama_pemain;
				datapemain.posisi = posisi_pemain;
				datapemain.nomor = no_pemain;
				pBerikutnya = NULL;
			}
		
		void tampilSimpul()
			{
				cout << datapemain.nomor << " ---> " << datapemain.nama << " ---> " << datapemain.posisi<<endl;
			}
};

class linkedlist
{
	private :
		simpul* pPertama;
		simpul* pAkhir;
	
	public :
		linkedlist() : pPertama(NULL)
		{}
		
		~linkedlist()
			{
				simpul* pSekarang = pPertama;
				while(pSekarang!=NULL)
					{
						simpul* pLama = pSekarang;
						pSekarang = pSekarang->pBerikutnya;
						delete pLama;
					}
			}
		
		bool apaKosong()
			{
				return (pPertama==NULL);
			}
		
		void sisipAkhir(string nama_pemain, string posisi_pemain, int no_pemain)
			{
				simpul* pSimpulBaru = new simpul(nama_pemain,posisi_pemain,no_pemain);
				if(apaKosong())
				{
					pPertama = pSimpulBaru;
				}
				else
				{
					pAkhir->pBerikutnya=pSimpulBaru;
				}
			pAkhir=pSimpulBaru;
			}
		
		void hapusPertama()
			{
				simpul* pTemp = pPertama;
				pPertama = pPertama->pBerikutnya;
				delete pTemp;
			}
		
		void tampilSenarai()
			{
				simpul* pSekarang = pPertama;
				
				if(pSekarang==NULL)
					{
						cout << "ANTRIAN DALAM KEADAAN KOSONG!!!";
					}
				while(pSekarang!=NULL)
					{
						pSekarang->tampilSimpul();
						pSekarang = pSekarang->pBerikutnya;
					}
			cout << endl;
			}
};

class queuelist
{
	private :
		linkedlist* pSenarai;
	
	public :
		queuelist()
			{
				pSenarai = new linkedlist;
			}
		
		~queuelist()
			{
				delete pSenarai;
			}
		
		void push(string nama_pemain, string posisi_pemain, int no_pemain)
			{
				pSenarai->sisipAkhir(nama_pemain,posisi_pemain,no_pemain);
			}
		
		void pop()
			{
				pSenarai->hapusPertama();	
			}
		
		bool apaKosong()
			{
				return (pSenarai->apaKosong());
			}
		
		void tampilTumpukan()
			{
				pSenarai->tampilSenarai();
			}
};

int main()
{
	queuelist queue;
	int pilih, noP;
	string namaP, posisiP;
	do 
	{
		cout << "\n=====================================================" << endl;
		cout << "Data Pemain Sepakbola Menggunakan Stack Linked List " << endl << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Tampil Data" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Masukkan Pilihan Anda : ";
		cin >> pilih;
	
		switch(pilih)
		{
			case 1 :
				cout << "Data pemain bola : ";
				cout << "\nMasukkan Nomor Punggung Pemain : "; cin >> noP;
				cin.ignore(256,'\n');
				cout << "Masukkan Nama Pemain : "; 
				getline(cin,namaP);
				cout << "Masukkan Posisi Pemain : "; 
				getline(cin,posisiP);
				queue.push(namaP,posisiP,noP);
				break;
				
			case 2 :
				queue.pop();
				break;
			
			case 3 :
				queue.tampilTumpukan();
				break;
				
			case 4 :
				exit(0);
				break;
				
			default :
				cout << "Maaf, pilihan Anda salah"<<endl;
		}
	} while (true);
	
	getch();
	return 0;
}
