#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	// dosya �ekme ve olu�turma i�lemleri ba�lad�

	printf("Dosya adi: %s\n",argv[0]);
	printf("Girdi sayisi: %d\n",argc);
	
	FILE *pDosyaOku = fopen(argv[1],"r+");
	FILE *pDosyaYaz = fopen(argv[2],"w+");
	
	
	if(pDosyaOku == NULL){	printf("okuma dosyasi acilmadi");  exit(1);	}
	
	
	if(pDosyaYaz == NULL){	printf("yazma dosyas� ac�lmad�2"); exit(1); }
	
		
	// dosya �ekme ve olu�turma i�lemleri bitti
	
	
	
	// sutunlar� tutmak i�in dizi olu�tur ve ka� sutun oldu�unu bul ba�lad�
	
	//sutun sayisi "," say�s�ndan bir fazla olaca��ndan doly� sutun say�s� = 1 den ba�lat�l�yor
	int i, j, sutunSayisi=1;
	char icerik=' ', tumSatir[500];
	
	fscanf(pDosyaOku, "%s", &tumSatir);
	
	for(i=0;i<500;i++){
		
		icerik = tumSatir[i];
		if(icerik == ','){
			
		sutunSayisi++;
		}
	}
	
	char sutunlariSakla[sutunSayisi][100];
	
	for(i=0;i<(sutunSayisi);i++){
		for(j=0;j<50;j++){
			sutunlariSakla[i][j]=NULL;
		}
	} 	
	
	// sutunlar� tutmak i�in dizi olu�tur ve ka� sutun oldu�unu bul bitti
	
	
	
	// header on ve off parametresine g�re sutun olu�tur veya var olan sutunun isimlerini diziye at ba�lad�
	
	int yazdirmaIndisi=0, sutununSirasi=0;
	char header[10], sutunIsmi[8]="Sutun", sutunIsmiSayi[5]; //sutunIsmi ve sutunIsmiSayi : sutun1-sutun2 gibi de�i�kenler olu�turmak i�in kullan�lacakt�r.
	
	for(i=0;i<10);i++){		header[i] = NULL;	}
	
	strcpy(header,argv[3]);
	
	if(header[7] == 'O'  && header[8] == 'N'){
		
		rewind(pDosyaOku);
		
		fscanf(pDosyaOku, "%s", &tumSatir);
		
		for(i=0;1;i++){
		
			icerik = tumSatir[i];
		
			if(icerik == '\n'){  break; }
		
			if(icerik != ','){
			
				sutunlariSakla[sutununSirasi][yazdirmaIndisi]=icerik;     yazdirmaIndisi++;// sutunlar� sakla dizisinin icerisine sutunlar�n isimleri eklenitor
			}
			else{
			
				yazdirmaIndisi=0;		sutununSirasi++;		
			}	
		}
	}
	else if(header[7] == 'O' && header[8] == 'F' && header[9] == 'F'){
		
		rewind(pDosyaOku);
		
		for(i=1;i<=sutunSayisi;i++){
			
		itoa(i,sutunIsmiSayi,10);
		strcat(sutunIsmi,sutunIsmiSayi);
			
		strcpy(sutunlariSakla[sutununSirasi], sutunIsmi);	sutununSirasi++;
		
		sutunIsmi[5] = NULL;	sutunIsmi[6] = NULL;	sutunIsmi[7] = NULL;
	
		}
	}
	else{
	 	printf("Yanlis parametre girdiniz.");
	 	
	 	return 0;
	 }
	// header on ve off parametresine g�re sutun olu�tur veya var olan sutunun isimlerini diziye at bitti
	
	
	
	// i�eri�i jsona d�n��t�r ba�lad�
	
	int hangiSutundasin=0;	char ciftTirnak='"';
	

	fscanf(pDosyaOku, "%c", &icerik);//Sutun i�lemlerinden gelen \n bo�lu�unu tolere etmek i�in kullan�l�yor.
	
	fprintf(pDosyaYaz,"[\n");
	
	
	while((!feof(pDosyaOku))&&(!ferror(pDosyaOku))){
	
	fprintf(pDosyaYaz,"  {\n");
	
	
	for(i=0;i<sutunSayisi;i++){
		
		
		fprintf(pDosyaYaz,"\t %c%s%c : %c", ciftTirnak, sutunlariSakla[i], ciftTirnak, ciftTirnak);
		
		while(1){
			
			fscanf(pDosyaOku, "%c", &icerik);
			
			if(icerik != ',' && icerik != '\n'){
				
				fprintf(pDosyaYaz,"%c",icerik);
			}
			else{
				if(icerik == ','){
					
					fprintf(pDosyaYaz,"%c,\n",ciftTirnak);	break;
				}
				if(icerik == '\n'){
					
					fprintf(pDosyaYaz,"%c",ciftTirnak);	break;
				}
			
			}
			
			
		}
		
		hangiSutundasin++;
	}
		if(!feof(pDosyaOku))
		fprintf(pDosyaYaz,"\n  },\n");
		else
		fprintf(pDosyaYaz,"\n  }\n");
	}
	
	fprintf(pDosyaYaz,"]");
	// i�eri�i jsona d�n��t�r bitti
		
		fclose(pDosyaOku); 	 	fclose(pDosyaYaz);
		
		return 0;
	} 
