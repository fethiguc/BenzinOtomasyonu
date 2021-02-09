#include <iostream>
#include<locale.h>
using namespace std;
double yakit[3][4];
double fark,kar,yuzde,litre;
double depo_limit = 10000;
int secim,secim1,tl,tutar;
void satis(int tur);
void al(int tur);
void anaMenu();
void depoDurum();
void gunlukKazanc(int tur);
void fiyatGuncelle(int deger);//deger olan k�s�m ya al�m yada sat�m olacak 0-1 seklinde
void satis(int tur)
{
	cout << "Ka� TL lik Yak�t Alacaks�n�z...:";
	cin >> tl;
	litre = tl / yakit[tur][0];
	tutar = yakit[tur][2] * yakit[tur][0];
	if (litre > yakit[tur][2])
	{
		cout << "\nDepoda Yeterli Miktarda Yak�t YOK..";
		cout << "\nDilerseniz " << tutar << " De�erinde Yaak�t Alabilirsiniz...";
	}
	else
	{
		yakit[tur][3] += litre;
		yakit[tur][2] -= litre;
		cout << litre << " Litre Yak�t Arac�n�za Doldurulmu�tur...";
		secim1=0;
	}
}
void al(int tur)
{
	do
	{
		tutar = (depo_limit - yakit[tur][2]) *yakit[tur][0];
		cout << "\nDepodaki Bo�luk Durumuna G�re";
		cout << "\n" << tutar << " TL lik Yak�t Alabilirsiniz...";
		cout << "\nKa� TL lik Yak�t Alacaks�n�z... : ";
		cin >> tl;
		if (tl > tutar)
		{
			cout << "\nDepoda Yeterince Yer Yok";
		}
		else
		{
			litre = tl / yakit[tur][0];
			cout << "\n" << litre << " Litre Yak�t Depoya Eklenmi�tir...";
			yakit[tur][2] += litre;
			secim1=0;
		}
	}while(tl>tutar);
}
void depoDurum()
{
	cout << "Depodaki yak�t durumu.... " << endl;
	cout << "Benzin... (lt): " << yakit[0][2] << endl;
	yuzde = (100 * yakit[0][2]) / depo_limit;
	cout << "Benzin Deposunun doluluk oran�... (%): " << yuzde << endl;
	cout << "----------------------------------------" << endl;
	cout << "Dizel... (lt): " << yakit[1][2] << endl;
	yuzde = (100 * yakit[1][2]) / depo_limit;
	cout << "Dizel Deposunun doluluk oran�... (%): " << yuzde << endl;
	cout << "----------------------------------------" << endl;
	cout << "LPG... (lt): " <<yakit[2][2] << endl;
	yuzde = (100 * yakit[2][2]) / depo_limit;
	cout << "LPG Deposunun doluluk oran�... (%): " << yuzde << endl;
}
void gunlukKazanc(int tur)
{
	fark =yakit[tur][0] - yakit[tur][1];
	kar = fark * yakit[tur][3];
}
void fiyatGuncelle(int deger)
{
	cout << "\nBenzin i�in fiyat bilgisi giriniz... : ";
	cin >> yakit[0][deger];
	cout << "\nDizel i�in fiyat bilgisi giriniz... : ";
	cin >> yakit[1][deger];
	cout << "\nLPG i�in fiyat bilgisi giriniz... : ";
	cin >> yakit[2][deger];
	cout << "\nFiyatlar G�ncellenmi�tir...."<<endl;
}
void anaMenu()
{
	cout << "\n-------------------------------------------------";
	cout << "\n---   1 - �r�n Sat                            ---";
	cout << "\n---   2 - �r�n Al                             ---";
	cout << "\n---   3 - Depo Durum                          ---";
	cout << "\n---   4 - G�nl�k Kazan�                       ---";
	cout << "\n---   5 - Fiyat G�ncelle                      ---";
	cout << "\n---   6 - Depo Kapasitesi G�ncelle            ---";
	cout << "\n---   0 - Program� Kapat                      ---";
	cout << "\n-------------------------------------------------";
	cout << "\nSe�iminiz... : ";
}
int main()
{
	setlocale(LC_ALL,"Turkish");
	yakit[0][0]=6.89;//birim benzin(b_benzin)
	yakit[0][1]=6.09;	 //al�m fiyat�(a_benzin)
	yakit[0][2]=0;		//depo benzin(d_benzin)
	yakit[0][3]=0;		//sat�lan benzin(s_benzin)
	
	yakit[1][0]=6.14;
	yakit[1][1]=5.14;
	yakit[1][2]=0;
	yakit[1][3]=0;
	
	yakit[2][0]=3.56;
	yakit[2][1]=3.06;
	yakit[2][2]=0;
	yakit[2][3]=0;
	do
	{ 
	anaMenu();
	cin >> secim;
	switch (secim)
	{
		case 1:
			{
				do
				{
				cout << "\n--------------------------";
				cout << "\n---   1 - Benzin       ---";
				cout << "\n---   2 - Dizel        ---";
				cout << "\n---   3 - LPG          ---";
				cout << "\n---   0 - ��k��        ---";
				cout << "\n--------------------------";
				cout << "\nSe�iminiz... : ";
				cin >> secim1;
				if(secim1==0)
				{
					cout << "Ana Men�ye D�n�yorsunuz...";
				}
				else if(secim1>0&&secim1<4)
				{
					satis(secim1-1);
				}
				else
				{
					cout << "Aral�k D��� De�er Girdiniz... !!!";
				}	
				} while (secim1!=0);
			}break;
		case 2:
			{
				do
				{
					cout << "\n--------------------------";
					cout << "\n---   1 - Benzin       ---";
					cout << "\n---   2 - Dizel        ---";
					cout << "\n---   3 - LPG          ---";
					cout << "\n---   0 - ��k��        ---";
					cout << "\n--------------------------";
					cout << "\nSe�iminiz... : ";
					cin >> secim1;
					
						if(secim1==0)
						{
							cout << "Ana Men�ye D�n�yorsunuz...";
						}
						else if(secim1>0&&secim1<4)
						{
							al(secim1-1);	
						}
						else
						{
							cout << "Aral�k D��� De�er Girdiniz... !!!";	
						}	
				} while (secim1!=0);		
			}break;
		case 3:
			{
				depoDurum();
			}break;
		case 4:
			{
			gunlukKazanc(0);
			cout << "Benzin i�in toplam Kar miktar�... : " << kar << " TL" << endl;
			gunlukKazanc(1);
			cout << "Dizel i�in toplam Kar miktar�...  : " << kar << " TL" << endl;
			gunlukKazanc(2);
			cout << "LPG i�in toplam Kar miktar�...    : " << kar << " TL"<<endl;
			}break;
		case 5:
			{
					cout << "\n-------------------------------";
					cout << "\n---   1 - Sat�� Fiyat       ---";
					cout << "\n---   2 - Al�� Fiyat        ---";
					cout << "\n---   0 - ��k��             ---";
					cout << "\n-------------------------------";
					cout << "\nSe�iminiz... : ";
					cin >> secim1;
					if(secim1==0)
					{
						cout << "Ana Men�ye D�n�yor...."<<endl;
					}
					else if(secim1==1||secim1==2)
					{
						fiyatGuncelle(secim1-1);
					}
					else
					{
						cout << "Aral�k d��� bir de�er girdiniz...." << endl;
					}
			}break;
		case 6:
			{
					cout << "\nYeni Depo kapasitesini giriniz..... : ";
					cin >> depo_limit;
					cout << "\nDepo Kapasitesi ba�ar� ile g�ncellenmi�tir.... " << endl;
			}break;
		case 0:
			{
				cout << "\n\tProgram Kapat�l�yor\n\t�yi G�nler.... !!!";
			}break;
		default:
			{
				cout << "\nAral�k D��� Bir De�er Girdiniz.... !!!";
			}break;
	}
	} while (secim != 0);
}
