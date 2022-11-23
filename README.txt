CSV2JSON uygulaması csv dosyasını json formatına çevirmek için yazılmış bir uygulamadır.
Uygulamanın kullanımı için şu adımları takip edebilirsiniz;

1.komut istemini açınız.

2.Komut isteminin dosyayı nerede çalıştıracağına bakarak CSV2JSON.exe uygulamamızı komut 
isteminin çalıştıreceğı yere taşıyalım.
 
örneğin; komut isteminde

Microsoft Windows [Version 10.0.19044.2130]
(c) Microsoft Corporation. Tüm hakları saklıdır.

C:\Users\mehmt>

yazıyor ise CSV2JSON.exe uygulamamızı "C:\Users\mehmt" adresine taşıyalım.

3.CSV dosyamızı da komut isteminin çalışacağı adrese yani "C:\Users\mehmt" adresine taşıyalım.

4.Komut istemimize "C:\> CSV2JSON dosya1.csv dosya2.json header=ON" yazalım

dosya1: csv dosyanızın ismidir
dosya2: json dosyanızın isimidir
header ise eğer csv dosyanızın içerisinde ilk satırda sutunların ismi yer alıyorsa "ON"
yer almıyorsa "OFF" olmalıdır.

5.Bu adımda 4. adımdaki verilen parametreyi kesinlikle bozmamanız tavsiye edilmektedir.
Eğer ekranınızda yanlış parametre yazıyorsa header=ON veya header=OFF yazıp yazmadığınızı
tekrar kontrol ediniz.