#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini struct ile tanımlama
struct DateTime {
    int year, month, day, hour, minute, second;
};

// Tarih bilgisini union ile alternatif şekilde saklama
union EpochTime {
    struct DateTime dt;
    time_t epoch;
};

// Kullanıcıdan tarih ve saat alacak fonksiyon
void getInput(struct DateTime *dt) {
    printf("Yıl (YYYY): ");
    scanf("%d", &dt->year);
    printf("Ay (1-12): ");
    scanf("%d", &dt->month);
    printf("Gün (1-31): ");
    scanf("%d", &dt->day);
    printf("Saat (0-23): ");
    scanf("%d", &dt->hour);
    printf("Dakika (0-59): ");
    scanf("%d", &dt->minute);
    printf("Saniye (0-59): ");
    scanf("%d", &dt->second);
}

// Struct'tan epoch zamanına çevirme fonksiyonu
time_t convertToEpoch(struct DateTime dt) {
    struct tm timeinfo = {0};
    
    timeinfo.tm_year = dt.year - 1900; // Yıl, 1900'den itibaren sayılıyor
    timeinfo.tm_mon = dt.month - 1;    // Aylar 0-11 arası olmalı
    timeinfo.tm_mday = dt.day;
    timeinfo.tm_hour = dt.hour;
    timeinfo.tm_min = dt.minute;
    timeinfo.tm_sec = dt.second;

    return mktime(&timeinfo); // Epoch zamanını döndür
}

int main() {
    struct DateTime dt1, dt2;
    union EpochTime t1, t2;

    printf("Birinci tarihi giriniz:\n");
    getInput(&dt1);
    printf("İkinci tarihi giriniz:\n");
    getInput(&dt2);

    // Epoch zamanına çevirme
    t1.epoch = convertToEpoch(dt1);
    t2.epoch = convertToEpoch(dt2);

    // Zaman farkını hesaplama
    double diff = difftime(t2.epoch, t1.epoch);

    // Sonuçları ekrana yazdırma
    printf("\nBirinci tarih Epoch zamanı: %ld saniye\n", t1.epoch);
    printf("İkinci tarih Epoch zamanı: %ld saniye\n", t2.epoch);
    printf("İki tarih arasındaki fark: %.0f saniye (%.2f saat)\n", diff, diff / 3600.0);

    return 0;
}
