# Epoch Zaman Farkı Hesaplayıcı

Bu proje, kullanıcının girdiği iki farklı tarih ve saat için epoch zamanlarını hesaplayan ve iki zaman arasındaki farkı saniye cinsinden gösteren bir C programıdır. Ayrıca, epoch kavramı ve `struct` & `union` kullanımı detaylı olarak ele alınmaktadır.

## Proje Özellikleri

- Kullanıcıdan iki tarih ve saat alır.
- `mktime()` fonksiyonunu kullanarak epoch zamanına çevirir.
- İki epoch zamanı arasındaki farkı hesaplar.
- `struct` ve `union` veri yapıları ile alternatif saklama yöntemleri içerir.

## Kullanılan Teknolojiler

- C Programlama Dili
- Epoch (Unix Time)
- Struct ve Union
- `mktime()` ve `difftime()` fonksiyonları

## Kurulum ve Çalıştırma

1. **Projeyi klonlayın**

   ```bash
   git clone https://github.com/AdemCosar/epoch-anlat-m-/blob/main/odev/main.c
   ```

2. **Kodu derleyin ve çalıştırın**

   ```bash
   gcc main.c -o main
   ./main
   ```

3. **Kullanıcıdan tarih girişleri istenecek, ardından epoch zamanları ve fark ekrana yazdırılacaktır.**

---

## Kullanım Örneği

### Girdi:

```
Birinci tarihi giriniz:
Yıl (YYYY): 2024
Ay (1-12): 2
Gün (1-31): 10
Saat (0-23): 14
Dakika (0-59): 30
Saniye (0-59): 0

İkinci tarihi giriniz:
Yıl (YYYY): 2024
Ay (1-12): 2
Gün (1-31): 11
Saat (0-23): 16
Dakika (0-59): 45
Saniye (0-59): 30
```

### Çıktı:

```
Birinci tarih Epoch zamanı: 1707575400 saniye
İkinci tarih Epoch zamanı: 1707662730 saniye
İki tarih arasındaki fark: 87330 saniye (24.26 saat)
```

---

## Epoch Zamanı Nedir?

Epoch, **1 Ocak 1970 00:00:00 UTC** zamanını baz alan ve o tarihten itibaren geçen saniye sayısını temsil eden bir sistemdir. Bilgisayar sistemlerinde zaman hesaplamaları için yaygın olarak kullanılır.

## Yapılandırma

Kod içerisinde aşağıdaki veri yapıları kullanılmıştır:

- `struct DateTime`: Kullanıcıdan alınan tarih ve saat bilgisini saklar.
- `union EpochTime`: Hem `struct` hem de `time_t` tipiyle epoch zamanı saklamak için kullanılır.

---

## Gerçek Hayat Uygulaması

Bu program, iş takip sistemlerinde kullanılabilecek bir örnektir. Örneğin, bir çalışan belirli bir göreve başlama ve bitirme saatlerini girerek, bu iki zaman arasındaki farkı hesaplayabilir. Böylece, bir görevin ne kadar sürdüğü ölçülebilir ve iş verimliliği takip edilebilir.

### **Senaryo:**
Bir çalışanın görev başlangıç ve bitiş zamanlarını kaydedip, geçen süreyi hesaplamak için aşağıdaki gibi bir kullanım gerçekleştirilebilir:

### Girdi:
```
Görev başlangıç zamanını giriniz:
Yıl (YYYY): 2024
Ay (1-12): 2
Gün (1-31): 10
Saat (0-23): 09
Dakika (0-59): 00
Saniye (0-59): 00

Görev bitiş zamanını giriniz:
Yıl (YYYY): 2024
Ay (1-12): 2
Gün (1-31): 10
Saat (0-23): 17
Dakika (0-59): 30
Saniye (0-59): 00
```

### Çıktı:
```
Görev başlangıç epoch zamanı: 1707555600 saniye
Görev bitiş epoch zamanı: 1707586200 saniye
Görev süresi: 30600 saniye (8.5 saat)
```

Bu tür bir sistem, iş yerlerinde çalışanların mesai sürelerini takip etmek, proje yönetiminde görev tamamlama sürelerini ölçmek ve üretkenlik analizleri yapmak için kullanılabilir.

