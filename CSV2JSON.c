#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	// dosya çekme ve oluþturma iþlemleri baþladý

	printf("Dosya adi: %s\n",argv[0]);
	printf("Girdi sayisi: %d\n",argc);
	
	FILE *pDosyaOku = fopen(argv[1],"r+");
	FILE *pDosyaYaz = fopen(argv[2],"w+");
	
	
	if(pDosyaOku == NULL){	printf("okuma dosyasi acilmadi");  exit(1);	}
	
	
	if(pDosyaYaz == NULL){	printf("yazma dosyasý acýlmadý2"); exit(1); }
	
		
	// dosya çekme ve oluþturma iþlemleri bitti
	
	
	
	// sutunlarý tutmak için dizi oluþtur ve kaç sutun olduðunu bul baþladý
	
	//sutun sayisi "," sayýsýndan bir fazla olacaðýndan dolyý sutun sayýsý = 1 den baþlatýlýyor
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
	
	// sutunlarý tutmak için dizi oluþtur ve kaç sutun olduðunu bul bitti
	
	
	
	// header on ve off parametresine göre sutun oluþtur veya var olan sutunun isimlerini diziye at baþladý
	
	int yazdirmaIndisi=0, sutununSirasi=0;
	char header[10], sutunIsmi[8]="Sutun", sutunIsmiSayi[5]; //sutunIsmi ve sutunIsmiSayi : sutun1-sutun2 gibi deðiþkenler oluþturmak için kullanýlacaktýr.
	
	for(i=0;i<10);i++){		header[i] = NULL;	}
	
	strcpy(header,argv[3]);
	
	if(header[7] == 'O'  && header[8] == 'N'){
		
		rewind(pDosyaOku);
		
		fscanf(pDosyaOku, "%s", &tumSatir);
		
		for(i=0;1;i++){
		
			icerik = tumSatir[i];
		
			if(icerik == '\n'){  break; }
		
			if(icerik != ','){
			
				sutunlariSakla[sutununSirasi][yazdirmaIndisi]=icerik;     yazdirmaIndisi++;// sutunlarý sakla dizisinin icerisine sutunlarýn isimleri eklenitor
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
	// header on ve off parametresine göre sutun oluþtur veya var olan sutunun isimlerini diziye at bitti
	
	
	
	// içeriði jsona dönüþtür baþladý
	
	int hangiSutundasin=0;	char ciftTirnak='"';
	

	fscanf(pDosyaOku, "%c", &icerik);//Sutun iþlemlerinden gelen \n boþluðunu tolere etmek için kullanýlýyor.
	
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
	// içeriði jsona dönüþtür bitti
		
		fclose(pDosyaOku); 	 	fclose(pDosyaYaz);
		
		return 0;
	} 
