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
void fiyatGuncelle(int deger);//deger olan kısım ya alım yada satım olacak 0-1 seklinde
void satis(int tur)
{
	cout << "Kaç TL lik Yakıt Alacaksınız...:";
	cin >> tl;
	litre = tl / yakit[tur][0];
	tutar = yakit[tur][2] * yakit[tur][0];
	if (litre > yakit[tur][2])
	{
		cout << "\nDepoda Yeterli Miktarda Yakıt YOK..";
		cout << "\nDilerseniz " << tutar << " Değerinde Yaakıt Alabilirsiniz...";
	}
	else
	{
		yakit[tur][3] += litre;
		yakit[tur][2] -= litre;
		cout << litre << " Litre Yakıt Aracınıza Doldurulmuştur...";
		secim1=0;
	}
}
void al(int tur)
{
	do
	{
		tutar = (depo_limit - yakit[tur][2]) *yakit[tur][0];
		cout << "\nDepodaki Boşluk Durumuna Göre";
		cout << "\n" << tutar << " TL lik Yakıt Alabilirsiniz...";
		cout << "\nKaç TL lik Yakıt Alacaksınız... : ";
		cin >> tl;
		if (tl > tutar)
		{
			cout << "\nDepoda Yeterince Yer Yok";
		}
		else
		{
			litre = tl / yakit[tur][0];
			cout << "\n" << litre << " Litre Yakıt Depoya Eklenmiştir...";
			yakit[tur][2] += litre;
			secim1=0;
		}
	}while(tl>tutar);
}
void depoDurum()
{
	cout << "Depodaki yakıt durumu.... " << endl;
	cout << "Benzin... (lt): " << yakit[0][2] << endl;
	yuzde = (100 * yakit[0][2]) / depo_limit;
	cout << "Benzin Deposunun doluluk oranı... (%): " << yuzde << endl;
	cout << "----------------------------------------" << endl;
	cout << "Dizel... (lt): " << yakit[1][2] << endl;
	yuzde = (100 * yakit[1][2]) / depo_limit;
	cout << "Dizel Deposunun doluluk oranı... (%): " << yuzde << endl;
	cout << "----------------------------------------" << endl;
	cout << "LPG... (lt): " <<yakit[2][2] << endl;
	yuzde = (100 * yakit[2][2]) / depo_limit;
	cout << "LPG Deposunun doluluk oranı... (%): " << yuzde << endl;
}
void gunlukKazanc(int tur)
{
	fark =yakit[tur][0] - yakit[tur][1];
	kar = fark * yakit[tur][3];
}
void fiyatGuncelle(int deger)
{
	cout << "\nBenzin için fiyat bilgisi giriniz... : ";
	cin >> yakit[0][deger];
	cout << "\nDizel için fiyat bilgisi giriniz... : ";
	cin >> yakit[1][deger];
	cout << "\nLPG için fiyat bilgisi giriniz... : ";
	cin >> yakit[2][deger];
	cout << "\nFiyatlar Güncellenmiştir...."<<endl;
}
void anaMenu()
{
	cout << "\n-------------------------------------------------";
	cout << "\n---   1 - Ürün Sat                            ---";
	cout << "\n---   2 - Ürün Al                             ---";
	cout << "\n---   3 - Depo Durum                          ---";
	cout << "\n---   4 - Günlük Kazanç                       ---";
	cout << "\n---   5 - Fiyat Güncelle                      ---";
	cout << "\n---   6 - Depo Kapasitesi Güncelle            ---";
	cout << "\n---   0 - Programı Kapat                      ---";
	cout << "\n-------------------------------------------------";
	cout << "\nSeçiminiz... : ";
}
int main()
{
	setlocale(LC_ALL,"Turkish");
	yakit[0][0]=6.89;//birim benzin(b_benzin)
	yakit[0][1]=6.09;	 //alım fiyatı(a_benzin)
	yakit[0][2]=0;		//depo benzin(d_benzin)
	yakit[0][3]=0;		//satılan benzin(s_benzin)
	
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
				cout << "\n---   0 - Çıkış        ---";
				cout << "\n--------------------------";
				cout << "\nSeçiminiz... : ";
				cin >> secim1;
				if(secim1==0)
				{
					cout << "Ana Menüye Dönüyorsunuz...";
				}
				else if(secim1>0&&secim1<4)
				{
					satis(secim1-1);
				}
				else
				{
					cout << "Aralık Dışı Değer Girdiniz... !!!";
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
					cout << "\n---   0 - Çıkış        ---";
					cout << "\n--------------------------";
					cout << "\nSeçiminiz... : ";
					cin >> secim1;
					
						if(secim1==0)
						{
							cout << "Ana Menüye Dönüyorsunuz...";
						}
						else if(secim1>0&&secim1<4)
						{
							al(secim1-1);	
						}
						else
						{
							cout << "Aralık Dışı Değer Girdiniz... !!!";	
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
			cout << "Benzin için toplam Kar miktarı... : " << kar << " TL" << endl;
			gunlukKazanc(1);
			cout << "Dizel için toplam Kar miktarı...  : " << kar << " TL" << endl;
			gunlukKazanc(2);
			cout << "LPG için toplam Kar miktarı...    : " << kar << " TL"<<endl;
			}break;
		case 5:
			{
					cout << "\n-------------------------------";
					cout << "\n---   1 - Satış Fiyat       ---";
					cout << "\n---   2 - Alış Fiyat        ---";
					cout << "\n---   0 - Çıkış             ---";
					cout << "\n-------------------------------";
					cout << "\nSeçiminiz... : ";
					cin >> secim1;
					if(secim1==0)
					{
						cout << "Ana Menüye Dönüyor...."<<endl;
					}
					else if(secim1==1||secim1==2)
					{
						fiyatGuncelle(secim1-1);
					}
					else
					{
						cout << "Aralık dışı bir değer girdiniz...." << endl;
					}
			}break;
		case 6:
			{
					cout << "\nYeni Depo kapasitesini giriniz..... : ";
					cin >> depo_limit;
					cout << "\nDepo Kapasitesi başarı ile güncellenmiştir.... " << endl;
			}break;
		case 0:
			{
				cout << "\n\tProgram Kapatılıyor\n\tİyi Günler.... !!!";
			}break;
		default:
			{
				cout << "\nAralık Dışı Bir Değer Girdiniz.... !!!";
			}break;
	}
	} while (secim != 0);
}
